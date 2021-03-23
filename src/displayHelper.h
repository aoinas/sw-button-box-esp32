#include <Adafruit_SSD1306.h>


void showSplashScreen(Adafruit_SSD1306& display) {

    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);

    // Main title
    display.setTextSize(1); 
    display.setCursor(0, 0);
    display.println(F("Softhare Industries"));
    
    // Version no
    display.setTextSize(2); 
    display.setCursor(0, 16);
    display.println(F("Wheel Box"));

    display.display();      
    delay(1000);

    // Initialising text
    display.setTextSize(1);
    display.setCursor(0, 50);
    display.println(F("Version 0.02"));
    display.display();
}

void showMainScreen(Adafruit_SSD1306& display, const float temperature, const float humidity  ) {

    //const int16_t humPosX = 64;

    display.clearDisplay();

/*
    // Temperature label
    display.setTextSize(2); 
    display.setCursor(0, 0);
    display.println(F("Temp:"));

    // Humidity label
    display.setTextSize(2); 
    display.setCursor(humPosX, 0);
    display.println(F("Hum:"));
*/
    // Temperature value
    display.setTextSize(3); 
    display.setCursor(5, 5);
    display.print( String(temperature,1) );
    display.println( "`C" );
    
    // Humidity value
    display.setTextSize(3); 
    display.setCursor(5, 32);
    display.print(String(humidity,1));
    display.println("%");

    display.display();
    
}