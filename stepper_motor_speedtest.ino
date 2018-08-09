#include <AFMotor.h>

//Declare variables for functions
char user_input;

AF_Stepper motor(200, 2);

void setup() {
  Serial.begin(9600);
  Serial.println("Begin motor control");
  Serial.println();
  //Print function list for user selection
  Serial.println("Enter number for control option:");
  Serial.println("1. Turn one full revolution - single.");
  Serial.println("2. Turn one full revolution - double.");
  Serial.println("3. Turn one full revolution - interleave.");
  Serial.println("4. Turn one full revolution - microstep.");
  Serial.println("5. Turn one full revolution - 20rpm.");
//  Serial.println("6. Reverse direction full revolution.");
//  Serial.println("7. Reverse direction half revolution.");
//  Serial.println("8. Reverse direction quarter revolution.");
//  Serial.println("9. Reverse direction 1/8th revolution.");
//  Serial.println("0. Reverse direction one step.");
  Serial.println();
}

//Main loop
void loop() {
  while(Serial.available()){
      user_input = Serial.read(); //Read user input and trigger appropriate function
      if (user_input =='1')
      {
         FullRevSingle();
      }
      else if(user_input =='2')
      {
        FullRevDouble();
      }
      else if(user_input =='3')
      {
        FullRevInterleave();
      }
      else if(user_input =='4')
      {
        FullRevMicro();
      }
      else if(user_input =='5')
      {
        FullRevFast();
      }
//      else if(user_input =='6')
//      {
//        ReverseFullRev();
//      }
//      else if(user_input =='7')
//      {
//        ReverseHalfRev();
//      }
//      else if(user_input =='8')
//      {
//        ReverseQuarterRev();
//      }
//      else if(user_input =='9')
//      {
//        ReverseEighthRev();
//      }
//      else if(user_input =='0')
//      {
//        ReverseOneStep();
//      }
      else
      {
        Serial.println("Invalid option entered.");
      }
  }
}
//One full revolution
void FullRevSingle() {
  Serial.println("Moving forward at default step mode.");
  
  motor.setSpeed(10); // 10rpm

  motor.step(200, FORWARD, SINGLE);
  delay(1000);

  Serial.println("Enter new option");
  Serial.println();
}

//Half revolution
void FullRevDouble() {
  Serial.println("Moving forward to half revolution");

  motor.setSpeed(10);

  motor.step(200, FORWARD, DOUBLE);
  delay(1000);

  Serial.println("Enter new option");
  Serial.println();
}

//Quarter revolution
void FullRevInterleave() {
  Serial.println("Moving forward to quarter revolution");

  motor.setSpeed(10);

  motor.step(200, FORWARD, INTERLEAVE);
  delay(1000);

  Serial.println("Enter new option");
  Serial.println();
}

//Eighth revolution
void FullRevMicro() {
  Serial.println("Moving forward to quarter revolution");

  motor.setSpeed(10);

  motor.step(200, FORWARD, MICROSTEP);
  delay(1000);

  Serial.println("Enter new option");
  Serial.println();
}

//One forward step
void FullRevFast() {
  Serial.println("Moving forward one step.");

  motor.setSpeed(20);

  motor.step(200, FORWARD, SINGLE);
  delay(1000);

  Serial.println("Enter new option");
  Serial.println();
}

////Reverse full revolution
//void ReverseFullRev() {
//  Serial.println("Moving in reverse at default step mode.");
//
//  motor.setSpeed(10); // 10rpm
//
//  motor.step(200, BACKWARD, SINGLE);
//  delay(1000);
//
//  Serial.println("Enter new option");
//  Serial.println();
//}
//
////Reverse Half revolution
//void ReverseHalfRev() {
//  Serial.println("Moving backward to half revolution");
//
//  motor.setSpeed(10);
//
//  motor.step(100, BACKWARD, SINGLE);
//  delay(1000);
//
//  Serial.println("Enter new option");
//  Serial.println();
//}
//
////Reverse Quarter revolution
//void ReverseQuarterRev() {
//  Serial.println("Moving backward to quarter revolution");
//
//  motor.setSpeed(10);
//
//  motor.step(50, BACKWARD, SINGLE);
//  delay(1000);
//
//  Serial.println("Enter new option");
//  Serial.println();
//}
//
////Eighth revolution
//void ReverseEighthRev() {
//  Serial.println("Moving backward to quarter revolution");
//
//  motor.setSpeed(10);
//
//  motor.step(25, BACKWARD, SINGLE);
//  delay(1000);
//
//  Serial.println("Enter new option");
//  Serial.println();
//}
//
////One backward step
//void ReverseOneStep() {
//  Serial.println("Moving backward one step.");
//
//  motor.setSpeed(10);
//
//  motor.step(1, BACKWARD, SINGLE);
//  delay(1000);
//
//  Serial.println("Enter new option");
//  Serial.println();
//}
