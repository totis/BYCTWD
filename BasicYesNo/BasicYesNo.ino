// Uses a PIR sensor to detect movement, buzzes a buzzer
// more info here: http://blog.makezine.com/projects/pir-sensor-arduino-alarm/
 
int ledPin = 13;
int pirPin = 2;
int speakerPin = 10;
int buttonPin = 5;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if (motionDetected())
  {
    Serial.println("Yes");
  }
  else
  {
    Serial.println("No");
  }
  delay(100);  
}

bool motionDetected()
{
  if (digitalRead(pirPin) == HIGH)
    return true;
  else
    return false;
}

bool buttonPressedDown()
{
  if (digitalRead(buttonPin) == LOW)
    return true;
  else
    return false;
}


void snooze(int snoozeSeconds) 
{
  Serial.println("*********** SNOOZE! **************************");
  for (int i=0; i<snoozeSeconds*2; i++) {
    turnLightsOn();
    delay(250);
    turnLightsOff();
    delay(250); 
  }
}

void turnLightsOn()
{
  digitalWrite(ledPin, HIGH);
}

void turnLightsOff()
{
  digitalWrite(ledPin, LOW);
}
