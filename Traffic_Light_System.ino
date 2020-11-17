//Pin Declarations
const int button = 12;  // Button connected to Digital Pin 12
const int red = 10;     // Red LED connected to Digital Pin 10
const int yellow = 9;   // Orange LED connected to Digital Pin 9
const int green = 8;    // Green LED connected to Digital Pin 8

int button_state = 0;   // To store the state of the pushbutton

void setup()
{
    
    pinMode(red, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(green, OUTPUT);
   
    pinMode(button, INPUT);
    Serial.begin (9600);
    Serial.println ("Traffic Light System");
}
void loop()
{
  button_state = digitalRead(button);
    if (button_state == HIGH)
    {
      changeLights();
    }
    else
    {
      Serial.println("Pedestrians can't cross");
      normalLights();
      
    }  
}

//Change Lights when button is pressed
void changeLights()
{
    
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    delay(2000);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    Serial.println("Pedestrians can cross");
    delay(3000);
}

void normalLights()
{
  digitalWrite(yellow, HIGH);
  delay(2000);
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
  delay(3000);
  digitalWrite(red, LOW);
  digitalWrite(yellow, HIGH);
  delay(2000);
  digitalWrite(yellow, LOW);
  digitalWrite(green, HIGH);
  delay(3000);
  digitalWrite(green, LOW);
}
