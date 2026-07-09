/*
   Setiap sketch yang menggunakan PulseSensor Playground harus
   mendefinisikan USE_ARDUINO_INTERRUPTS sebelum mengikutkan PulseSensorPlayground.h.
   Di sini, #define USE_ARDUINO_INTERRUPTS true memberi tahu pustaka untuk menggunakan
   interrupt untuk secara otomatis membaca dan memproses data PulseSensor.
*/
#define USE_ARDUINO_INTERRUPTS true
#include <PulseSensorPlayground.h>

/*
   Setel ini ke PROCESSING_VISUALIZER jika Anda ingin menjalankan plotter Processing.
   Setel ini ke SERIAL_PLOTTER jika Anda akan menjalankan
   Serial Plotter dari IDE Arduino.
*/
const int OUTPUT_TYPE = SERIAL_PLOTTER;

/*
   Pinout:
     PULSE_INPUT = Input Analog. Dihubungkan ke kabel sensor detak jantung
      ungu (sinyal).
*/
const int PULSE_INPUT = A0;        // Pin input untuk sensor detak jantung
const int PULSE_BLINK = 13;        // Pin 13 adalah LED onboard untuk indikator detak jantung
const int PULSE_FADE = 5;          // Pin 5 untuk LED yang memudar sesuai dengan detak jantung
const int THRESHOLD = 550;         // Ambang batas deteksi, sesuaikan jika terlalu banyak noise saat idle

/*
   Semua fungsi yang diperlukan oleh PulseSensor Playground.
*/
PulseSensorPlayground pulseSensor;

void setup() {
  /*
     Gunakan baud rate 115200 karena itu yang diharapkan oleh Processing Sketch
     dan baud rate ini memberikan sekitar 11 byte per milidetik.

     Jika menggunakan baud rate lebih rendah, mungkin pengiriman data akan lebih cepat
     daripada yang dapat ditransmisikan, yang dapat mengacaukan waktu pembacaan
     dan membuat pengukuran detak jantung tidak berfungsi dengan benar.
  */
  Serial.begin(115200);

  // Mengonfigurasi manajer PulseSensor.
  pulseSensor.analogInput(PULSE_INPUT);   // Menetapkan input analog untuk sensor detak jantung
  pulseSensor.blinkOnPulse(PULSE_BLINK);  // Mengonfigurasi LED untuk berkedip saat ada detak
  pulseSensor.fadeOnPulse(PULSE_FADE);   // Mengonfigurasi LED untuk memudar saat ada detak

  pulseSensor.setSerial(Serial);          // Menetapkan serial output
  pulseSensor.setOutputType(OUTPUT_TYPE); // Menetapkan tipe output (Serial Plotter)
  pulseSensor.setThreshold(THRESHOLD);    // Menetapkan ambang batas deteksi detak

  // Mulai membaca sinyal dari sensor detak jantung.
  if (!pulseSensor.begin()) {
    /*
       Jika inisialisasi PulseSensor gagal,
       kemungkinan karena platform Arduino kita tidak mendukung interrupt.

       Jika sketch terhenti di sini, coba PulseSensor_BPM_Alternative.ino,
       yang tidak menggunakan interrupt.
    */
    for(;;) {
      // Berkedipkan LED untuk menunjukkan bahwa ada masalah.
      digitalWrite(PULSE_BLINK, LOW);
      delay(50);
      digitalWrite(PULSE_BLINK, HIGH);
      delay(50);
    }
  }
}

void loop() {
  /*
     Tunggu sejenak.
     Kita tidak mengirimkan data setiap sampel, karena baud rate kita tidak
     akan mendukung kecepatan I/O sebanyak itu.
  */
  delay(20);

  // Kirimkan sampel terbaru ke Serial.
  pulseSensor.outputSample();

  /*
     Jika ada detak yang terjadi sejak pemeriksaan terakhir,
     kirimkan informasi detak tersebut ke Serial.
   */
  if (pulseSensor.sawStartOfBeat()) {
    pulseSensor.outputBeat();  // Kirim data detak ke Serial
  }
}
