// Uncomment next line to use class GFX of library GFX_Root instead of Adafruit_GFX.
#include <GFX.h>

#define ENABLE_GxEPD2_GFX 0
#include <GxEPD2_BW.h> // including both doesn't hurt
#include <GxEPD2_3C.h> // including both doesn't hurt
#include "bitmaps/Bitmaps3c104x212.h" // 2.13" b/w/r

#include <Fonts/FreeMonoBold9pt7b.h>

// Constructor for e-paper, and for AVR needed #defines.
GxEPD2_3C<GxEPD2_213c, GxEPD2_213c::HEIGHT> display(GxEPD2_213c(/*CS=15*/ SS, /*DC=4*/ 4, /*RST=5*/ 5, /*BUSY=16*/ 16));


//=====================================================================SETUP
void setup()
{
  display.init();
  // Comment out next line to have no or minimal Adafruit_GFX code.
  display.setTextColor(GxEPD_BLACK);
  display.firstPage();
  do
  {
    display.fillScreen(GxEPD_WHITE);
    // Comment out next line to have no or minimal Adafruit_GFX code.
    display.print("Hello World!");
  }
  while (display.nextPage());
}

//=====================================================================LOOP
void loop() {};

//=====================================================================WIP
