#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 9
#define SS_PIN 10

MFRC522 mfrc522(SS_PIN, RST_PIN);   

void setup(){
  Serial.begin(9600);  
  while (!Serial);     
  SPI.begin();         
  mfrc522.PCD_Init();  
  }

void loop(){
  if( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial()  ){
    delay(50);
    return;
    }
   for(byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i],HEX);
    }
    Serial.println();
  }
