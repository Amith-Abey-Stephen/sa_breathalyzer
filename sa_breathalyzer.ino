#define MQ2pin A0
int rled= 3;
int yled= 4;
int gled= 5;
int buzzer= 6;

void setup() {
  Serial.begin(9600);
  pinMode(gled, OUTPUT);
  pinMode(yled, OUTPUT);
  pinMode(rled, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.print("Warming up");;
  delay(10000);
  digitalWrite(yled, HIGH);
  delay(1000);
  digitalWrite(yled, LOW);
  Serial.println();
}

void loop() {
  int sensorValue = analogRead(MQ2pin);
  Serial.print("Analog Value: ");
  Serial.print(sensorValue);
  Serial.println();
  if (sensorValue > 200 && sensorValue <= 325)
  {
    digitalWrite(gled,HIGH);
  }
  else
  {
    digitalWrite(gled, LOW);
  }
  if (sensorValue > 325 && sensorValue <= 450)
  {
    digitalWrite(yled,HIGH);
  }
  else
  {
    digitalWrite(yled, LOW);
  }  
  if (sensorValue > 450)
  {
    digitalWrite(rled,HIGH);
    digitalWrite(buzzer,HIGH);
  }
  else
  {
    digitalWrite(rled, LOW);
    digitalWrite(buzzer,LOW);
  }
  delay(400);
}

