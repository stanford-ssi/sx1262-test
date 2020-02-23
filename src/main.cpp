#include <Arduino.h>
#include "ff.h"
#include "hal_mci_sync.h"
#include "hpl_sdhc_config.h"
#include "hal_gpio.h"
#include "sd_mmc_start.h"
#include "fatfs_main.h"
#include "sd_mmc.h"
#include "conf_sd_mmc.h"




FATFS fs;
FIL file_object;




void setup() {
  MCI_0_init();
  sd_mmc_stack_init();
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

  
  while (SD_MMC_OK != sd_mmc_check(0)) {
		Serial.println("Waiting...");
    delay(100);
	}

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



