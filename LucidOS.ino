/*
Lucid OS - Developed by Blake Sekelsky
Frequent updates being made on Twitter @LucidOS_Project and on GitHub and Youtube.
GitHub - https://github.com/LucidOSProject/LucidOS_Project/blob/master/LucidOS.ino
Youtube - http://www.youtube.com/playlist?list=PLwBbXoTme4Hra0Lc5wSkfXOc5po9NYJ1R
Twitter - https://twitter.com/LucidOS_Project
*/ 

#include <LucidLogo.h>
#include <font4x6.h>
#include <font6x8.h>
#include <font8x8.h>
#include <font8x8ext.h>
#include <fontALL.h>
#include <TVout.h>
#include <avr/pgmspace.h>
#include <arduino.h>

  TVout TV;
  void setup();
  void loop();
  void program();
   
  void setup()  
  {
    TV.begin(NTSC, 126, 96);
    TV.select_font(font4x6);
    TV.clear_screen();
  }
  //Draws the logo and splash screen
  void loop() 
  { 
    TV.bitmap(-20, 5, logo);
  }
  void program()
  {
  
  }
