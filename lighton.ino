int yellow = 11;
int green = 12;
int red = 13;

void setup() 
{
  Serial.begin(9600);
  pinMode(red , OUTPUT);
  pinMode(green , OUTPUT);
  pinMode(yellow , OUTPUT);
}

void loop() 
{
  if (Serial.available())
  {
    String var = Serial.readStringUntil('\n');
    Serial.println(var);
    if (var == "green")
    {
      Serial.println("hi green");
      digitalWrite(green, HIGH);
      digitalWrite(red, LOW);
      digitalWrite(yellow, LOW);
    }
    else if (var == "red colour")
    {
      Serial.println("hi red");
      digitalWrite(red, HIGH);
      digitalWrite(green, HIGH);
      digitalWrite(yellow, LOW);
    }
    else if (var == "yellow")
    {
      Serial.println("hi yellow");
      digitalWrite(yellow, HIGH);
      digitalWrite(green, LOW);
      digitalWrite(red, LOW);
    }
    
    else if (var == "turn on")
    {
      Serial.println("hi yellow");
      digitalWrite(yellow, HIGH);
      digitalWrite(green, HIGH);
      digitalWrite(red, HIGH);
    }
    else if (var == "turn off")
    {
      Serial.println("hi yellow");
      digitalWrite(yellow, LOW);
      digitalWrite(green, LOW);
      digitalWrite(red, LOW);
    }
  }
}
