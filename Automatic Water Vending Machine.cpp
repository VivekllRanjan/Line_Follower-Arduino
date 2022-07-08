const int COIN = 2;
const int TRIAC = 6;
const int LED=12;
boolean Coin_insert = false;
int count=0;
void setup() 
{
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(COIN), coinInterrupt, RISING);
  pinMode(TRIAC, OUTPUT);
  pinMode(LED, OUTPUT);
}
 
void loop() 
{
  if(Coin_insert)
  {
     digitalWrite(LED, HIGH);
     delay(1000);
     digitalWrite(TRIAC, HIGH);
     delay(12000);
     digitalWrite(TRIAC, LOW);
     delay(2000);
     Coin_insert = false; 
  }
  else
  { 
  digitalWrite(LED, LOW);
  digitalWrite(TRIAC, LOW);
  } 
  }
 
void coinInterrupt()
{
 Coin_insert = true;
}