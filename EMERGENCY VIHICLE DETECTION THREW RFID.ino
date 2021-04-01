#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
int redled = 3;
int yellowled = 4;
int greenled = 5;
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.


void setup() {
Serial.begin(115200);
SPI.begin();
mfrc522.PCD_Init();
Serial.println("emergency vihicle detection");
pinMode (3, OUTPUT);
pinMode (4, OUTPUT);
pinMode (5, OUTPUT);
}

void loop(){
digitalWrite (redled, HIGH);
//delay (10000);
//digitalWrite (redled, LOW); //stopped  
//digitalWrite (yellowled, HIGH); 
//delay(5000);
//digitalWrite (yellowled, LOW);
//digitalWrite (greenled, HIGH);
//delay(10000);
//digitalWrite (greenled, LOW);
  //Look for new cards
if ( !mfrc522.PICC_IsNewCardPresent() ){
return;
  }
  //Select one of the cards
if ( !mfrc522.PICC_ReadCardSerial() ) {
return;
  }

  String content= "";
byte letter;
for( byte i = 0; i< mfrc522.uid.size; i++ ){0
content.concat(String(mfrc522.uid.uidByte[i], HEX));
if(i< mfrc522.uid.size-1 ) content+="-";
  }
content.toUpperCase();
Serial.println();
Serial.println("UID tag :'" + content + "'");
if( content == "51 AA 66 1B" || "D9 FD OD 5D" )
    {
    Serial.println("Authorized access");
    digitalWrite (redled, LOW);
    digitalWrite(greenled,HIGH);
    delay(5000);
    digitalWrite (greenled, LOW);
    digitalWrite (redled, HIGH);
    delay (4000);
    digitalWrite (redled, LOW); //stopped  
     digitalWrite (yellowled, HIGH); 
     delay(2500);
     digitalWrite (yellowled, LOW);
     digitalWrite (greenled, HIGH);
     delay(5000);
     digitalWrite (greenled, LOW);
 }
}

