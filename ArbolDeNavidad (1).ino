/*
   Arbol De Navidad with Hershey's Kiss Commerial Jingle
   by Paola Diaz and Jennifer Vazquez
  
*/


// the setup function runs once when you press reset or power the board
void setup() {
  //RED LEDS
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);

  //GREEN LEDS
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

  //YELLOW LED
  pinMode(13, OUTPUT);

}

// the loop function runs over and over again forever
void loop() {


  blinkTree();
  rowByRow();
  yellowBlinkFast();
  allRedsOns();
  delay(100);
  allRedsOns();
  delay(100);
  allRedsOns();
  delay(100);
  allGreensOn();
  delay(100);
  allGreensOn();
  delay(100);
  allGreensOn();
  yellowBlinkFast();
  rowByRow();
  blinkTree();
  yellowBlinkFast();
}

void allRedsOns() {
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  delay(500);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);

}

void allGreensOn() {
  for (int i = 3; i < 13; i++) {
    digitalWrite(i, HIGH);
  }
  delay(500);
  for (int index = 3; index < 13; index++) {
    digitalWrite(index, LOW);
  }
}

void yellowBlinkFast() {
  for (int i = 0; i < 15; i++) {
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(100);
    i++;
  }
}
void rowByRow() {

  for (int index = 1; index < 3; index++) {
    digitalWrite(index, HIGH);
    delay(500);
  }
  for (int index = 3; index < 14; index++) {
    digitalWrite(index, HIGH);
    delay(100);
  }
  for (int index = 1; index < 14; index++) {
    digitalWrite(index, LOW);
  }
  delay(1000);

}
void blinkYellowWithTree() {
  for (int index = 1; index < 3; index++) {
    digitalWrite(index, HIGH);
    delay(500);
  }
  for (int index = 3; index < 14; index++) {
    digitalWrite(index, HIGH);
    delay(100);
  }

}



void blinkTree() {
  struct lightColor {
    int arrayRed[2] = {1, 2}; ;
    int arrayGreen[5] = { 8, 9, 10, 11, 12};
    int arrayYellow[1] = {13};
  };
  //WARNING: THIS PROGRAM CONTAINS FAST FLASHING LIGHTS, MAY CAUSE DISCOMFORT
  //AND TRIGGER EPILEPSY. VIEWER DISCRETION IS ADVISED.
  struct lightColor color;
  union color {
    char colorName;
    int colorTotal;
  };
  int count = 0;
  while (count != 10) {
    union color value = {'R'};
    if (value.colorName == 'R') {
      for (int x = 0; x < 2; x++) {
        digitalWrite(color.arrayRed[x], HIGH);
      }
    }
    value.colorName = 'G';
    if (value.colorName == 'G') {
      for (int y = 0; y < 5; y++) {
        digitalWrite(color.arrayGreen[y], HIGH);
      }
    }
    value.colorName = 'Y';
    if (value.colorName == 'Y') {
      digitalWrite(color.arrayYellow[0], HIGH);
    }
    delay(100);
    digitalWrite(color.arrayYellow[0], LOW);
    for (int z = 0; z < 2; z++) {
      digitalWrite(color.arrayRed[z], LOW);
    }
    for (int pp = 0; pp < 5; pp++) {
      digitalWrite(color.arrayGreen[pp], LOW);
    }
    count++;
    delay(100);
  }
  count = 0;

}










