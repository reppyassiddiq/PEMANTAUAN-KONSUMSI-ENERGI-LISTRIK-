#include <Servo.h> 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 

LiquidCrystal_I2C lcd(0x27, 16, 2); // Ganti ke 0x3F jika 0x27 tidak tampil 
Servo fanServo; 
int servoPin = 3; 
int ledPin = 9;
 
void setup() { 
fanServo.attach(servoPin); 
pinMode(ledPin, OUTPUT); 
fanServo.write(0); 
digitalWrite(ledPin, LOW); 
Serial.begin(9600); 
 
lcd.begin(16, 2); // Inisialisasi LCD  
lcd.backlight(); //Nyalakan lampu latar  
lcd.setCursor(0, 0); 
lcd.print("Sistem Aktif"); 
delay(2000); // Tampilkan selama 2 detik 
lcd.clear();  
} 

void loop() { 
fanServo.write(90); 
delay(1000); 

float energyGenerated = 0.5; 

if (energyGenerated > 0.8) { 
digitalWrite(ledPin, HIGH); 
} else { 
digitalWrite(ledPin, LOW); 
}

lcd.setCursor(0, 0);  
lcd.print("Energi: "); 
lcd.print(energyGenerated, 1); // Tampilkan 1 angka desimal 

lcd.setCursor(0, 1); 
lcd.print("Watt-hour "); // Spasi untuk menghapus sisa karakter 
 
fanServo.write(0); 
delay(1000); 
} 
