#include <GxEPD.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>
#include <GxGDEW0213Z16/GxGDEW0213Z16.h> // For SPI e-paper panels 2.13" b/w/r (use GDEW0213Z16)

/* Configure pins for display */
GxIO_Class io(SPI, 15, 4, 5);
GxEPD_Class display(io,  5,  16);

/* modified font created at http://oleddisplay.squix.ch/ */
#include "DialogInput_Bold_16.h"
#include "Moon_Phases.h"

/* FreeFonts from Adafruit_GFX */
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>



//=====================================================================SETUP
void setup()
{
  display.init(); //Initialize display
  
  showText("It's working");
}

//=====================================================================LOOP
void loop()
{
  //showText("It's working");
}

//=====================================================================SHOWTEXT
void showText(char *text)
{
  display.setRotation(3); //even = portrait, odd = landscape
  display.fillScreen(GxEPD_WHITE);
  const GFXfont* f = &FreeMonoBold9pt7b ;
  display.setTextColor(GxEPD_BLACK);
  display.setFont(f);
  display.setCursor(0,15);
  display.println(text);
  display.update();
}
