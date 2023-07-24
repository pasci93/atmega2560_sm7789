#include <Arduino.h>
#include "Adafruit_ST7789.h"

using namespace std;

// Define Pins for the interface

#define TFT_DC 49
#define TFT_CS 47
#define TFT_RST 48
//#define TFT_SCLK 52 //Hardware SPI pin for SCLK. Any PIN can be used, but it will be slower
//#define TFT_MOSI 51 //Hardware SPI pin for MOSI. Any PIN can be used, but it will be slower

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

// If using the breakout, change pins as desired
//Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

//Define color Array for rainbow rectancles

uint16_t rainbow[7] = {ST77XX_RED, ST77XX_ORANGE, ST77XX_YELLOW, ST77XX_GREEN, ST77XX_CYAN,ST77XX_BLUE,ST77XX_MAGENTA};

void setup()
{
  Serial.begin(9600);

  tft.init(240, 320);

  tft.invertDisplay(0); //Uncomment or change to tft.invertDisplay(1) if the colors are inverted
  tft.setRotation(1); //Orientation of the screen

  tft.fillScreen(ST77XX_BLACK);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);
  
}

void loop(void)
{

  tft.setCursor(80,120);
  tft.print("Hello World");
  delay(1000);
  tft.setCursor(0,0);
  for (int i=0; i<7;i++){
    tft.fillRect(i*45,0,45,240,rainbow[i]);
  }
  delay(1000);
  tft.fillScreen(ST77XX_BLACK);
}
