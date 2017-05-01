import processing.serial.*;

Serial myPort; 
byte val[]; 

void setup() {
  size(500, 500);
  String portName = Serial.list()[1];
  myPort = new Serial(this, portName, 9600);
}

void draw() {
  while (myPort.available() > 0) {
    String inBuffer = myPort.readString();   
    if (inBuffer != null)
      println(inBuffer);
  }
}