//Initialising the pins

#define MQ2pin A0 //pin on the MQ2 sensor
int rled= 3;     //pin for red led
int yled= 4;     //pin for yellow led
int gled= 5;     //pin for green led
int buzzer= 6;   //pin for buzzer


void setup() {
  Serial.begin(9600);
  pinMode(gled, OUTPUT);
  pinMode(yled, OUTPUT);
  pinMode(rled, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.print("Warming up");;
  delay(7000);
  digitalWrite(gled, HIGH);
  delay(1000);
  digitalWrite(gled, LOW);
  digitalWrite(yled, HIGH);
  delay(1000);
  digitalWrite(yled, LOW);
  digitalWrite(rled, HIGH);
  delay(1000);
  digitalWrite(rled, LOW);
  Serial.println();
  
}

void loop() {
  int sensorValue = analogRead(MQ2pin);
  Serial.print("Analog Value: ");
  Serial.print(sensorValue);
  Serial.println();
  

   // Blink LEDs based on alcohol level
    if (sensorValue > 200 && sensorValue < 325)
    {
      digitalWrite(gled,HIGH);// Green LED for low alcohol level
    }
    else
    {
      digitalWrite(gled, LOW);
    }
 
 
    if (sensorValue > 325 && sensorValue <= 450)
    {
      digitalWrite(yled,HIGH); // Yellow LED for moderate alcohol level
    }
    else
    {
      digitalWrite(yled, LOW);
    }
  
    if (sensorValue > 450)
    {
      digitalWrite(rled,HIGH); // Red LED for high alcohol level
      digitalWrite(buzzer,HIGH); // Beep the buzzer
    }
    else
    {
      digitalWrite(rled, LOW);
      digitalWrite(buzzer,LOW);
    }
  
  delay(400);  // Delay for stability
}
