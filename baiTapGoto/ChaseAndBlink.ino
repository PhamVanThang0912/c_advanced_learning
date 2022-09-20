   byte ledPin[] = {4,5,6,7,8,9,10,11};
byte count;
byte statusOfLed = 1;
int numberOfRepeat, periodOfTime = 500;
int numberBlink, numberChase;
byte temporary = 1;

#define buttonBlinkLed 2
#define buttonChaseLed 3

void turnOffAll();
void turnOnAll();
int blinkLed();
int chaseLed();
void checkStatusOfLed(int numberBlink, int numberChase);
void delayMSFunction(byte periodOfTime);
void setup() {
  count = sizeof(ledPin);
  for(int i = 0; i < count; i++)
  {
    pinMode(ledPin[i], OUTPUT);
    pinMode(buttonBlinkLed, INPUT_PULLUP);
    pinMode(buttonChaseLed, INPUT_PULLUP);
    digitalWrite(ledPin[i], LOW);
  }
}
void turnOffAll()
{
  for(int i = 0; i < count; i++)
  {
    digitalWrite(ledPin[i], LOW);
  }
}
void turnOnAll()
{
  for(int i = 0; i < count; i++)
  {
    digitalWrite(ledPin[i], HIGH);
  }
}
int blinkLed(void)
{
    while(true)
    {
    turnOnAll();
    
    for(int j = 0; j < periodOfTime; j++)
    {
    delay(1);
      if(digitalRead(buttonChaseLed) == 0)
      {
        goto label;
      }
    }
    
    turnOffAll();
  
    for(int j = 0; j < periodOfTime; j++)
    {
    
      if(digitalRead(buttonChaseLed) == 0)
      {
        goto label;
      }
      delay(1);
    }
    }
  label:
  temporary = 2;
}

int chaseLed(void)
{
    while(true)
    {
    turnOffAll();
    for(int i = 0; i < count; i++)
    {
      digitalWrite(ledPin[i], HIGH);
      for(int j = 0; j < periodOfTime; j++)
      {
      
        if(digitalRead(buttonBlinkLed) == 0)
        {
          goto label;
        }
        delay(1);
      }
      digitalWrite(ledPin[i], LOW);
    }
    }
  label:
  temporary = 1;
}

void loop() {
 if(temporary == 1)
 {
  blinkLed();
 }
  if(temporary == 2)
 {
  chaseLed();
 }  
}
