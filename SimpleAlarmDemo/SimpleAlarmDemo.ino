// Uses a PIR sensor to detect movement, buzzes a buzzer
// more info here: http://blog.makezine.com/projects/pir-sensor-arduino-alarm/

int ledPin = 13;
int pirPin = 2;
int speakerPin = 10;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600);
  snooze(5);
  turnAlarmOn();
  turnAlarmOff();
}

void loop()
{
  if (motionDetected())
  {
    turnAlarmOn();
    turnAlarmOff();
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

void turnLightsOn()
{
  digitalWrite(ledPin, HIGH);
}

void turnLightsOff()
{
  digitalWrite(ledPin, LOW);
}

void snooze(int snoozeSeconds)
{
  Serial.println("*********** SNOOZE! **************************");
  for (int i = 0; i < snoozeSeconds * 2; i++) {
    turnLightsOn();
    delay(250);
    turnLightsOff();
    delay(250);
  }
  Serial.println("Alarm is armed!");
}

void turnAlarmOn()
{
  turnLightsOn();
  playTone(500, 250);
}

void turnAlarmOff()
{
  turnLightsOff();
}

void playTone(long durationMilliseconds, int frequencyHz)
{
  if (frequencyHz > 0)
    Serial.println("*********** BEEP BEEP BEEP BEEP **************");

  long durationMicroseconds = durationMilliseconds * 1000;
  int loopPeriod = (1.0 / frequencyHz) * 1000000;
  long elapsedTime = 0;

  while (elapsedTime < durationMicroseconds)
  {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(loopPeriod / 2);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(loopPeriod / 2);
    elapsedTime += (loopPeriod);
  }
}
