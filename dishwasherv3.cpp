//set water off to begin
int waterAllowed = 0;
//set motor off to begin
int motorAllowed =0;
int motorSignal = 0;
//dryer flag
int dryerReady=0;


unsigned long startMillis;
unsigned long currentMillis;
const unsigned long period = 1; //the value is a number of milliseconds, ie- 1 second

//Turn on dishwasher
int flag;
void isr(void) {
  flag = 1;
};


void runDryer(void) {

  digitalWrite(50, HIGH);

  
      delay(3000);

      
      digitalWrite(50, LOW);
      

  
}


// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(46, OUTPUT);
  pinMode(50, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(33, OUTPUT);
  //39 and 41 are clk
  pinMode(39, OUTPUT);
  pinMode(41, OUTPUT);
  //button pin
  pinMode(2, INPUT_PULLUP);

  startMillis = millis();  //initial start time

  //motor settings
  //Motor driver settings, amperage-1.6
  //excitation 0 AKA excitation mode 1
  //decay 10, AKA decay 25%
  //clockwise
  digitalWrite(31, LOW);
  //enable, LOW=quicker, HIGH=SLOWER
  digitalWrite(33, HIGH);

//Infareed works, but useless
//pinMode(53,OUTPUT);
//digitalWrite(53, HIGH);
//infareed recieve
//pinMode(43, INPUT_PULLUP);



  //water allowed to be on
  waterAllowed = 1;
  //motor allowed to be on
  motorAllowed=1;

}

// the loop function run
void loop() {


  currentMillis = millis();


//Infareed detector
//if (digitalRead(43) == 0) {
//      delay(50);
//      Serial.println("Infarred Detected");
//      Serial.println(currentMillis);
//isr();
 //   }

  //Interrupt statement
  if (currentMillis - startMillis >= period) {

    //Check to see if button was pressed
      if (digitalRead(2) == 0) {
      //isr();
      Serial.println("Button");
      Serial.println(currentMillis);
    }

    //delay to start dishwasher
    if (currentMillis == 108000 && waterAllowed == 1 )  {
    //110000, 105000, 107500,108000

 Serial.println("Start Water");
      Serial.println(currentMillis);
      isr();
     delay(3000);
   
    }

    



    
    
    //water 2
    if (currentMillis == 145000 && waterAllowed == 1 )  {
    //  isr();
     delay(3000);
    }

    //waste time at starting point
    if (currentMillis == 410000)  {
//267358, 250000
      motorAllowed=0;
    }




    //start dishwasher if true
    if (flag) {
      Serial.println("Start Water");
      Serial.println(currentMillis);
      flag = 0;
      
    //start water
      digitalWrite(46, HIGH);
      //delay(300000); is effective but long. 150000 is nearly perfect
      delay(150000);
      digitalWrite(46, LOW);
      delay(2000);



//signal dryer to start
//dryerReady=1;


//end flag end dishwasher
    }






    if (currentMillis == 247000 && waterAllowed == 1 )  {
    //Next dryer
    motorAllowed=0;
    digitalWrite(50, HIGH);
   
    }

    
    if (currentMillis == 250000 && waterAllowed == 1 )  {
    //Next dryer
    digitalWrite(50, LOW);
    motorAllowed=1;
    }

    if (currentMillis == 253000 && waterAllowed == 1 )  {
    //Next dryer
    motorAllowed=0;
    digitalWrite(50, HIGH);
   
    }

    
    if (currentMillis == 256000 && waterAllowed == 1 )  {
    //Next dryer
    digitalWrite(50, LOW);
    motorAllowed=1;
    }




    if (currentMillis == 259000 && waterAllowed == 1 )  {
    //Next dryer
    motorAllowed=0;
    digitalWrite(50, HIGH);
   
    }

    
    if (currentMillis == 262000 && waterAllowed == 1 )  {
    //Next dryer
    digitalWrite(50, LOW);
    motorAllowed=1;
    }



    if (currentMillis == 265000 && waterAllowed == 1 )  {
    //Next dryer
    motorAllowed=0;
    digitalWrite(50, HIGH);
   
    }

    
    if (currentMillis == 268000 && waterAllowed == 1 )  {
    //Next dryer
    digitalWrite(50, LOW);
    motorAllowed=1;
    }



    if (currentMillis == 270000 && waterAllowed == 1 )  {
    //Next dryer
    motorAllowed=0;
    digitalWrite(50, HIGH);
    

    }

    
    if (currentMillis == 273000 && waterAllowed == 1 )  {
    //Next dryer
    digitalWrite(50, LOW);
    motorAllowed=1;
    }

    
    if (currentMillis == 276000 && waterAllowed == 1 )  {
    //Next dryer
    motorAllowed=0;
    digitalWrite(50, HIGH);
    

    }

    
    if (currentMillis == 279000 && waterAllowed == 1 )  {
    //Next dryer
    digitalWrite(50, LOW);
    motorAllowed=1;
    }



    if (currentMillis == 282000 && waterAllowed == 1 )  {
    //Next dryer
    motorAllowed=0;
    digitalWrite(50, HIGH);
    

    }

    
    if (currentMillis == 285000 && waterAllowed == 1 )  {
    //Next dryer
    digitalWrite(50, LOW);
    motorAllowed=1;
    }






    

    if (motorSignal == 0 && motorAllowed==1) {
      digitalWrite(39, HIGH);
      motorSignal = 1;
    }

    if (motorSignal == 1 && motorAllowed==1) {
      digitalWrite(39, LOW);
      motorSignal = 0;
    }

    startMillis = currentMillis;  //IMPORTANT to save the start time of the current state.
  }


}



