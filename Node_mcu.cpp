#define BLYNK_TEMPLATE_NAME "GARBAGE MONITORING"
#define BLYNK_AUTH_TOKEN "LSzlPLKajOZF9VQD9tt8QM3KS7HmQeBb"
#define BLYNK_TEMPLATE_ID "TMPL3c133mphW"
#include <LiquidCrystal_I2C.h>
#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define BLYNK_PRINT Serial
char ssid[] = "Mohammed";
char pass[] = "12345678";

const int trigerpin = 14;
const int echo = 12;
long duration;
int distance;
int percent;

#define TANK_MAX_HEIGHT 20  // Maximum height of the tank in cm
#define gas A0
#define flame D7
BlynkTimer timer;

void setup() {
  Serial.begin(9600);
  pinMode(trigerpin, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(flame, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("     GARBAGE    ");
  lcd.setCursor(0, 1);
  lcd.print("   MONITORING   ");
  delay(3000);
  lcd.clear();
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L, sendUltrasonicData);  // Interval to send ultrasonic data to Blynk app
}

void loop() {
  Blynk.run();
  timer.run();
  sendUltrasonicData();
}

void sendUltrasonicData() {
  int gas_value = analogRead(gas);
  int gas_value1 = map(gas_value, 0, 1023, 0, 100);
  int flame_state = digitalRead(flame);

  digitalWrite(trigerpin, LOW);
  delayMicroseconds(2);                                                    
  digitalWrite(trigerpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigerpin, LOW);

  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;

  percent = ((float)distance / TANK_MAX_HEIGHT) * 100;
  lcd.setCursor(0, 0);
  lcd.print("Capacity=");
  lcd.print(percent);
  lcd.print(" %    ");

  //Serial.print("\t gas: ");
  //Serial.println(gas_value);
 /*  Serial.print("Distance: ");
  Serial.println(distance);
 Serial.print(" cm, Filled: ");
  Serial.print(percent);
  Serial.println(" %");
   Serial.print("flame: ");
  Serial.print(flame_state);  
  Serial.print("\t gas: ");
  Serial.print(gas_value);
  Serial.print(",\t  ");
  Serial.println(gas_value1);
*/

  Blynk.virtualWrite(V0, percent);
  Blynk.virtualWrite(V2, gas_value1);

  if (flame_state == 0) {
    Blynk.virtualWrite(V1, "FLAME DETECTED");
     Serial.println("E");
  
  } else if (flame_state == 1) {
    Blynk.virtualWrite(V1, "NO FLAME DETECTED");
     Serial.println("F");
  }      
  if (percent < 15.00) {
      Serial.println("A");
  } else if (percent > 15.00) {
     Serial.println("B");
  }

  if (gas_value1 > 60) {
     Serial.println("C");
  }
   else if (percent < 60) {
    Serial.println("D");
  }
  delay(300);
}
