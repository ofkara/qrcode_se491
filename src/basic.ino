#include <Arduino.h>
#include <ESP32QRCodeReader.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

ESP32QRCodeReader reader(CAMERA_MODEL_AI_THINKER);

void onQrCodeTask(void *pvParameters)
{
  struct QRCodeData qrCodeData;
  char *check;
  char *temp; 

Serial.println("Searching for QR");
  while (true)
  {
    if (reader.receiveQrCode(&qrCodeData, 10))
    {
      if (qrCodeData.valid)
      {
        temp = (char *)qrCodeData.payload;
        //todo - aes_decryption(temp, publickey);
        check = strstr(temp, "valid");
        if(check){
          Serial.print("Door is opened! The account is valid.");
        }else{
          Serial.print("Door is closed! The account is not valid.");
        }
      }
    }
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}

void setup()
{
  Serial.begin(115200);
  
  Serial.println();

  reader.setup();

  Serial.println("Setup QRCode Reader");

  reader.beginOnCore(1);

  xTaskCreate(onQrCodeTask, "onQrCode", 4 * 1024, NULL, 4, NULL);
}

void loop()
{
  delay(100);
}