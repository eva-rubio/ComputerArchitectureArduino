/*
Example sketch 06
*/

// First we'll set up constants for the pin numbers.
// This will make it easier to follow the code below.

 // pushbutton pin
 const int buttonPin = A0;
 // potentiometer ("dimmer")
 const int pentoPin = A5;

 //RGB LED pins
 const int redPin = 11;
 const int greenPin = 10;
 const int bluePin = 9;

 int redValue;
 int greenValue;
 int blueValue;


//create a variable to store a counter and set it to 0
int counter = 0;
void setup()
{
  // Set up the pushbutton pins to be an input:
  pinMode(pentoPin, INPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin,HIGH);   // set Internal pull-up

  // Set up the RGB pins to be an outputs:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
}

/** r, g, b are values in the range 0..255
 *  set the values of the color intensity to each of the r g b
 *  si r es 255 y b y g son cero, la LED seria un rojo muy brillante
 *  segun vas añadiendo valores el color va cambiando
**/
void setColor(int r, int g, int b){
   analogWrite(redPin,r);
   analogWrite(greenPin,g);
   analogWrite(bluePin,b);
}

void loop()
{
  int pentValue = analogRead(pentoPin); // 0..1023  // si lo giramos, esta funcion reads the value
  pentValue = pentValue / 4;        // to make range smaller

 // local variable to hold the pushbutton states
  int buttonState;

  //read the digital state of buttonPin with digitalRead() function and store the           //value in buttonState variable
  buttonState = digitalRead(buttonPin);

  //if the button is pressed increment counter and wait a tiny bit to give us some          //time to release the button
  if (buttonState == LOW) // light the LED
  {
    counter++;
    delay(150);
  }

  //use the if satement to check the value of counter. If counter is equal to 0 all pins are off
  // si es cero hacemos que este off con setColor
  if(counter == 0)
  {
   setColor(0,0,0);
   
  }

  //else if counter is equal to 1, redPin is HIGH
  else if(counter == 1)
  {
    setColor(pentValue,0,0);
    // create a variable to store the value of the intensity of the red pin
    // setcolor pone la intensidad del rojo, y estamos guardando esa intensidad en esta variable
   redValue = pentValue;
  }

  //else if counter is equal to 2 greenPin is HIGH
  else if(counter ==2)
  {
    setColor(0,pentValue,0);
    greenValue = pentValue;
  }

  //else if counter is equal to 3 bluePin is HIGH
  else if(counter ==3)
  {
    setColor(0,0,pentValue);
    blueValue = pentValue;
  }

  else if (counter== 4){
    setColor(redValue, greenValue, blueValue);
    }

  //else reset the counter to 0 (which turns all pins off)
  else
  {
   counter =0;
  }

  
}
