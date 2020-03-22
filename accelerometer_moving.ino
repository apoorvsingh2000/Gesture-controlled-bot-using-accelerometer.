// these constants describe the pins. They won't change:
const int xpin = A1;                  // x-axis
const int ypin = A2;                  // y-axis
const int zpin = A3;                  // z-axis (only on 3-axis models)of the accelerometer

void setup() 
{
  // initialize the serial communications:
  Serial.begin(9600);

  // Provide ground and power by using the analog inputs as normal
  // digital pins.  This makes it possible to directly connect the
  // breakout board to the Arduino.  If you use the normal 5V and
  // GND pins on the Arduino, you can remove these lines.
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() 
{
  // print the sensor values:
  int x=analogRead(xpin);
  int y=analogRead(ypin);
  int z=analogRead(zpin);
  Serial.print(x);
  // print a tab between values:
  Serial.print("\t");
  Serial.print(y);
  // print a tab between values:
  Serial.print("\t");
  Serial.print(z);
  Serial.println();
  
  if((x>400) && (x<450))
    {
      Serial.print("Forward");
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
    }
   else if((x>250) && (x<300))
    {
    Serial.print("Backward");
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    }
   else if((y>400) && (y<450))
    {
      Serial.print("Left");
   digitalWrite (10, LOW);
   digitalWrite (11, LOW);
   digitalWrite (12, HIGH);
   digitalWrite (13, LOW);
    }
   else if((y>250) && (y<300))
    {
      Serial.print("Right");
          digitalWrite (10, HIGH);
    digitalWrite (11, LOW);
    digitalWrite (12, LOW);
    digitalWrite (13, LOW);
    }
   else if((x>300) && (x<400) && (y>300) && (y<400))
    {
      Serial.print("Stop");
    }
}
