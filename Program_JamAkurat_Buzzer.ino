#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"

RTC_DS1307 rtc;
LiquidCrystal_I2C lcd(0x27, 16, 2);

char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
const int buzzerPin = 8;  // Pin untuk buzzer

void setup () 
{
  Serial.begin(9600);
  lcd.begin();  // Initialize the LCD 
  lcd.backlight();  // To power ON the backlight
  
  pinMode(buzzerPin, OUTPUT);  // Set buzzer pin as output
  
  if (!rtc.begin()) 
  {
    lcd.print("Couldn't find RTC");
    while (1);
  }

  if (!rtc.isrunning()) 
  {
    lcd.print("RTC is NOT running!");
  }
  
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); //Set tanggal dan waktu secara otomatis di komputer
  //rtc.adjust(DateTime(2024, 11, 25, 11, 14, 00));  //Set tanggal dan waktu ke 25 November 2024, 11:14:00
}

void loop () 
{
  DateTime now = rtc.now();

  // Tampilkan waktu di LCD
  lcd.setCursor(0, 1);
  lcd.print("TIME");
  lcd.print(" ");
  lcd.print(now.hour());
  lcd.print(':');
  lcd.print(now.minute());
  lcd.print(':');
  lcd.print(now.second());
  lcd.print("  ");

  lcd.setCursor(0, 0);
  lcd.print("DATE");
  lcd.print(" ");
  lcd.print(now.day());
  lcd.print('/');
  lcd.print(now.month());
  lcd.print('/');
  lcd.print(now.year());
  lcd.print("  "); 

  // Cek kondisi waktu tertentu untuk mengaktifkan buzzer pengingat sholat subuh
  if (now.hour() == 03 && now.minute() == 40 && now.second() == 0) 
  {
    // Jika jam menunjukkan 03:40:00, aktifkan buzzer selama 5 detik
    tone(buzzerPin, 1000);  // Frekuensi 1000 Hz
    delay(5000);  // Durasi buzzer berbunyi 5 detik
    noTone(buzzerPin);  // Matikan buzzer
  }

  // Cek kondisi waktu tertentu untuk mengaktifkan buzzer pengingat sholat dzuhur
  if (now.hour() == 11 && now.minute() == 15 && now.second() == 0) 
  {
    // Jika jam menunjukkan 11:15:00, aktifkan buzzer selama 5 detik
    tone(buzzerPin, 1000);  // Frekuensi 1000 Hz
    delay(5000);  // Durasi buzzer berbunyi 5 detik
    noTone(buzzerPin);  // Matikan buzzer
  }

  // Cek kondisi waktu tertentu untuk mengaktifkan buzzer pengingat sholat asar
  if (now.hour() == 14 && now.minute() == 35 && now.second() == 0) 
  {
    // Jika jam menunjukkan 14:35:00, aktifkan buzzer selama 5 detik
    tone(buzzerPin, 1000);  // Frekuensi 1000 Hz
    delay(5000);  // Durasi buzzer berbunyi 5 detik
    noTone(buzzerPin);  // Matikan buzzer
  }

   // Cek kondisi waktu tertentu untuk mengaktifkan buzzer pengingat sholat maghrib
  if (now.hour() == 17 && now.minute() == 30 && now.second() == 0) 
  {
    // Jika jam menunjukkan 17:30:00, aktifkan buzzer selama 5 detik
    tone(buzzerPin, 1000);  // Frekuensi 1000 Hz
    delay(5000);  // Durasi buzzer berbunyi 5 detik
    noTone(buzzerPin);  // Matikan buzzer
  }

   // Cek kondisi waktu tertentu untuk mengaktifkan buzzer pengingat sholat isya'
  if (now.hour() == 18 && now.minute() == 41 && now.second() == 0) 
  {
    // Jika jam menunjukkan 18:41:00, aktifkan buzzer selama 5 detik
    tone(buzzerPin, 1000);  // Frekuensi 1000 Hz
    delay(5000);  // Durasi buzzer berbunyi 5 detik
    noTone(buzzerPin);  // Matikan buzzer
  }
  delay(1000);  // Delay 1 detik sebelum pembaruan waktu berikutnya
}
