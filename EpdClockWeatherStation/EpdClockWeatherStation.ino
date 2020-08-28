#define ENABLE_GxEPD2_GFX 0
#include <GxEPD2_BW.h> // including both doesn't hurt
#include <GxEPD2_3C.h> // including both doesn't hurt
#include "bitmaps/Bitmaps3c104x212.h" // 2.13" b/w/y

GxEPD2_3C<GxEPD2_213c, GxEPD2_213c::HEIGHT> display(GxEPD2_213c(/*CS=15*/ SS, /*DC=4*/ 4, /*RST=5*/ 5, /*BUSY=16*/ 16));

// Images
#include "marioImage.h"
// Fonts
#include <Fonts/FreeMonoBold9pt7b.h>

//===================================================================== SETUP
void setup()
{
  display.init();
  display.setRotation(3); 

  printTest();
}

//===================================================================== Print Test
void printTest()
{
  display.setTextColor(GxEPD_BLACK);
  display.setFont(&FreeMonoBold9pt7b);
  
  display.firstPage();
  do
  {
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(0, 15);
    display.print("Hello World!");
  }
  while (display.nextPage());
}

//===================================================================== Bitmap Test
// This currently doesn't work :( 
void bitmapTest()
{
  display.drawBitmap(0, 0, marioBitmap, display.epd2.WIDTH, display.epd2.HEIGHT, GxEPD_BLACK);
}

//===================================================================== Shape Functions
void rectangleShapeTest()
{ 
  // Rectangle position and dimension.
  uint16_t x = 22;
  uint16_t y = 22;
  uint16_t w = 40;
  uint16_t h = 40;

//  display.setPartialWindow(x, y, w, h);

  display.firstPage();
  do
  {
     display.fillScreen(GxEPD_WHITE);
     //display.drawrect(x, y, w, h, GxEPD_BLACK)
     display.fillRect(x, y, w, h, GxEPD_BLACK);
  }
  while (display.nextPage());
}

//------------------------------------------------------ Circle

void circleShapeTest()
{ 
  // Circle position and dimension.
  uint16_t x = 35;
  uint16_t y = 35;
  uint16_t w = 20;
  uint16_t h = 20;


//  display.setPartialWindow(x, y, w, h);

  display.firstPage();
  do
  {
     display.fillScreen(GxEPD_WHITE);
     display.drawCircle(x, y, w, GxEPD_BLACK);
     //display.fillCircle(x, y, w, GxEPD_BLACK);
  }
  while (display.nextPage());
}


//===================================================================== Partial mode update test
void helloFullScreenPartialMode()
{
  //Serial.println("helloFullScreenPartialMode");
  const char fullscreen[] = "full screen update";
  const char fpm[] = "fast partial mode";
  const char spm[] = "slow partial mode";
  const char npm[] = "no partial mode";
  const char helloWorld[] = "Hello World!";
  display.setPartialWindow(0, 0, display.width(), display.height());
  display.setRotation(3);
  display.setFont(&FreeMonoBold9pt7b);
  display.setTextColor(GxEPD_BLACK);
  const char* updatemode;
  if (display.epd2.hasFastPartialUpdate)
  {
    updatemode = fpm;
  }
  else if (display.epd2.hasPartialUpdate)
  {
    updatemode = spm;
  }
  else
  {
    updatemode = npm;
  }
  // do this outside of the loop
  int16_t tbx, tby; uint16_t tbw, tbh;
  // center update text
  display.getTextBounds(fullscreen, 0, 0, &tbx, &tby, &tbw, &tbh);
  uint16_t utx = ((display.width() - tbw) / 2) - tbx;
  uint16_t uty = ((display.height() / 4) - tbh / 2) - tby;
  // center update mode
  display.getTextBounds(updatemode, 0, 0, &tbx, &tby, &tbw, &tbh);
  uint16_t umx = ((display.width() - tbw) / 2) - tbx;
  uint16_t umy = ((display.height() * 3 / 4) - tbh / 2) - tby;
  // center HelloWorld
  display.getTextBounds(helloWorld, 0, 0, &tbx, &tby, &tbw, &tbh);
  uint16_t hwx = ((display.width() - tbw) / 2) - tbx;
  uint16_t hwy = ((display.height() - tbh) / 2) - tby;
  display.firstPage();
  do
  {
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(hwx, hwy);
    display.print(helloWorld);
    display.setCursor(utx, uty);
    display.print(fullscreen);
    display.setCursor(umx, umy);
    display.print(updatemode);
  }
  while (display.nextPage());
}

//===================================================================== LOOP

void loop()
{
   
}
