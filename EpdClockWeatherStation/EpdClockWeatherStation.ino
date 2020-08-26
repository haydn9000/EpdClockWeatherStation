#define ENABLE_GxEPD2_GFX 0
#include <GxEPD2_BW.h> // including both doesn't hurt
#include <GxEPD2_3C.h> // including both doesn't hurt
#include "bitmaps/Bitmaps3c104x212.h" // 2.13" b/w/y

GxEPD2_3C<GxEPD2_213c, GxEPD2_213c::HEIGHT> display(GxEPD2_213c(/*CS=15*/ SS, /*DC=4*/ 4, /*RST=5*/ 5, /*BUSY=16*/ 16));

// Fonts
#include <Fonts/FreeMonoBold9pt7b.h>

//===================================================================== SETUP
void setup()
{
  display.init();
  display.setRotation(3);

  printTest();
 
}

//===================================================================== PrintText
void printTest()
{
  display.setTextColor(GxEPD_BLACK);
  display.setFont(&FreeMonoBold9pt7b);
  
  display.firstPage();
  do
  {
    display.fillScreen(GxEPD_YELLOW);
    display.setCursor(0,15);
    display.print("Hello World!");
  }
  while (display.nextPage());
}

//===================================================================== LOOP
void loop() 
{
  
}
