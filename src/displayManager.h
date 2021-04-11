#pragma once

#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>
/* 
#define SCREEN_WIDTH  240 // OLED display width, in pixels
#define SCREEN_HEIGHT 135 // OLED display height, in pixels

// Hardwired in TTGO
#define PIN_MOSI 19
#define PIN_SCLK 18
#define PIN_CS 5
#define PIN_DC 16
#define PIN_RST 23
#define PIN_BL 14
 */

class DisplayManager 
{
    public:
    DisplayManager() : display_()
    {

    }

    bool begin()
    {
        display_.init();
        display_.setRotation(3);
        display_.fillScreen(TFT_ORANGE);

        /* if(!display_.begin(SSD1306_SWITCHCAPVCC, 0x3D, false, false)) { 
            
            Serial.println(F("SSD1306 allocation failed"));
            return false;
        }

        showSplashScreen(display_); */
        Serial.println("DisplayManager initialised.");
        return true;
    }

    

    TFT_eSPI& getDisplay()
    {
        return display_;
    }

    private:

    TFT_eSPI display_;

};
