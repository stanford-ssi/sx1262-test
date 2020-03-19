#include <Arduino.h>

#include "ff.h"
#include "SSISD.hpp"

FATFS fs;
FIL file_object;

SSISD sdcard;

void setup() {
  sdcard.init();
  Serial.begin(9600);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);

  delay(3000);
  digitalWrite(1,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  delay(1000);
  digitalWrite(1,LOW);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  delay(1000);

  FRESULT res;

  Serial.println("Starting");

  //Clear file system object
  memset(&fs, 0, sizeof(FATFS));
  Serial.println("A");

  delay(1000);


  Serial.println("B");
  

  res = f_mount(&fs, "", 1);
  if (res != FR_OK)
  {
    Serial.println("Could not Mount!");
  }
  else
  {
    Serial.println("Mounted SD card");
  }

  Serial.println("C");
  

}

void loop(){

  f_open(&file_object, "test3.txt", FA_WRITE | FA_CREATE_ALWAYS);

  
  char string[] = "fjdkasljfdklajflkjdklasjflkdklafkldjaklfkldklaflkadsfldjklajfldsjklfjkladsklajffjdkasljfdklajflkjdklasjflkfjdkasljfdklajflkjdklasjflkdklafkldjaklfkldklaflkadsfldjklajfldsjklfjkladsklajffjdkasljfdklajflkjdklasjflkfjdkasljfdklajflkjdklasjflkdklafkldjaklfkldklaflkadsfldjklajfldsjklfjkladsklajffjdkasljfdklajflkjdklasjflkfjdkasljfdklajflkjdklasjflkdklafkldjaklfkldklaflkadsfldjklajfldsjklfjkladsklajffjdkasljfdklajflkjdklasjflkfjdkasljfdklajflkjdklasjflkdklafkldjaklfkldklaflkadsfldjklajfldsjklfjkladsklajffjdkasljfdklajflkjdklasjflkdklafkldjaklfkldklaflkadsfldjklajfldsjklfjkladsklajffjdkasljfdklajflkjdklasjflkdklafkldjaklfkldklaflkadsfldjklajfldsjklfjkladsklajffjdkasljfdklajflkjdklasjflkdklafkldjaklfkldklaflkadsfldjklajfldsjklfjkladsklajffjdkasljfdklajflkjdklasjflkdklafkldjaklfkldklaflkadsfldjklajfldsjklfjkladsklajffjdkasljfdklajflkjdklasjflkdklafkldjaklfkldklaflkadsfldjklajfldsjklfjkladsklajffjdkasljfdklajflkjdklasjflkdklafkldjaklfkldklaflkadsfldjklajfldsjklfjkladsklajfdjfdlksajflkdjskljaflkdjslkafjkl;dsajkl;fjdl;ksajflk;dsj;lkafjd;klsjakl;fjkldsjjfhkjhdfjkghfdkjghljkfdshkgljfdjklshgjkfdshjklgfdlkjshgkfjdklsghljkfsdhgkjfhdlkjsghd";
  

  f_puts(string, &file_object);
  f_sync(&file_object);
  f_close(&file_object);

  Serial.println("Lol");
  digitalWrite(1,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  delay(500);
  digitalWrite(1,LOW);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  delay(500);
}