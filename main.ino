nt trigPin = 6;
int echoPin = 5;
int buzzer = A0;
int greenPin = 8;
int green2Pin = 9;
int yellow2Pin = 11;
int redPin = 12;

void setup()
{
  pinMode(greenPin, OUTPUT);
  pinMode(green2Pin, OUTPUT);
  pinMode(yellow2Pin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{  
    long t, cm;
    
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(20);
    
    digitalWrite(trigPin, LOW);
    
    t = pulseIn(echoPin, HIGH);
    
    cm = (t / 2) / 29;

  if((cm > 25) && (cm <= 50))
  {
    digitalWrite(greenPin, HIGH);
    digitalWrite(green2Pin, LOW);
    digitalWrite(yellow2Pin, LOW);
    digitalWrite(redPin, LOW);
	
    noTone(buzzer);
  }

  if((cm > 15) && (cm <= 25))
  {
    digitalWrite(greenPin, LOW);
    digitalWrite(green2Pin, HIGH);
    digitalWrite(yellow2Pin, LOW);
    digitalWrite(redPin, LOW);
    
    tone(buzzer, 50);
  }  

  if((cm > 5) && (cm <= 15))
  {
    digitalWrite(greenPin, LOW);
    digitalWrite(green2Pin, LOW);
    digitalWrite(yellow2Pin, HIGH);
    digitalWrite(redPin, LOW);
    
    tone(buzzer, 400);
  }

  if (cm <= 5)
  {
    digitalWrite(greenPin, LOW);
    digitalWrite(green2Pin, LOW);
    digitalWrite(yellow2Pin, LOW);
    digitalWrite(redPin, HIGH);
    
    tone(buzzer, 500);
  } else
  {
    digitalWrite(greenPin, LOW);
    digitalWrite(green2Pin, LOW);
    digitalWrite(yellow2Pin, LOW);
    digitalWrite(redPin, LOW);
    
    noTone(buzzer);
  }
}
