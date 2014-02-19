#include <font4x6.h>
#include <font6x8.h>
#include <font8x8.h>
#include <font8x8ext.h>
#include <fontALL.h>
#include <TVout.h>
#include <avr/pgmspace.h>
#include <arduino.h>

  TVout TV;
  void Apps();
  void recHard();
  void setup();
  void loop();
  void program();
  void Box();
  void LED();
  
  int buttonState = 0;
  int buttonState2 = 0;
  int MenuChoice = 1;

  
  void setup()  
  {
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    pinMode(12, OUTPUT);
    TV.begin(NTSC, 126, 96);
    TV.select_font(font4x6);
    TV.clear_screen();
  }
    
  void loop() 
  { 
     program();
  }
  
  void program()
  {
    MenuChoice = 1;
    
    while(true)
    {
     TV.println(5, 45, MenuChoice); 
     TV.println(5, 5, "Applications: ");
     TV.println(5, 15, "1. Apps");
     TV.println(5, 25, "2. Recommended Hardware");

      buttonState = digitalRead(2);
      if (buttonState == HIGH)
      {
        if (MenuChoice == 1)
        {
          MenuChoice++;
          delay(500);
        }
        else if (MenuChoice == 2)
        {
          MenuChoice--;
          delay(500);
        }
      }
      buttonState2 = digitalRead(3);
      if (buttonState2 == HIGH)
      {
       if (MenuChoice == 1)
        {
         Apps();
        }
       else if (MenuChoice == 2)
        {
         recHard();
        } 
      } 
    }
  }
  
  void Apps()
  {
    MenuChoice = 1;
    TV.clear_screen();
    delay(500);
    while (true)
    {
    TV.println(5, 5, "Available Applications: ");
    TV.println(5, 15, "1. 3D Box");
    TV.println(5, 25, "2. LED");
    TV.println(5, 35, "3. Back");
    TV.println(5, 55, MenuChoice);

     buttonState = digitalRead(2);
     if (buttonState == HIGH)
     {
      if (MenuChoice == 1)
      {
       MenuChoice++; 
       delay(500);
      }
      else if(MenuChoice == 2)
      {
       MenuChoice++; 
       delay(500);
      }
      else if(MenuChoice == 3)
      {
       MenuChoice = 1;
      delay(500); 
      }
     }
      
     buttonState2 = digitalRead(3);
    if (buttonState2 == HIGH)
    {
      if (MenuChoice == 1)
      {
        delay(500);
        TV.clear_screen();
        Box(); 
      }
      else if(MenuChoice == 2)
      {
        delay(500);
        TV.clear_screen();
        LED();
      }
      else if(MenuChoice == 3)
      {
        delay(500);
        TV.clear_screen();
        program(); 
      }
     } 
    }
   }
  
  void recHard()
  {
    MenuChoice = 1;
    TV.clear_screen(); 
    TV.println(5, 5, "Recommended Hardware:");
    TV.println(5, 15, "Chip: ATmega328p");
    TV.println(5, 25, "Operating Volts:  5V");
    TV.println(5, 35, "Flash Mem: 32 kb");
    TV.println(5, 45, "SRAM: 2 kb");
    TV.println(5, 55, "Clock Speed: 16 MHz");
    TV.println(5, 75, "1. Back");
    TV.println(5, 85, MenuChoice);
    delay(500);
    while(true)
    {
      buttonState2 = digitalRead(3);
      if (buttonState2 == HIGH)
      {
         delay(500);
         TV.clear_screen();
         program();
      }
    }
  }
  void Box()
  {
    MenuChoice = 1;
    TV.clear_screen();
    TV.draw_line(15, 15, 15, 40, 1);
    TV.draw_line(40, 40, 15, 40, 1);
    TV.draw_line(40, 15, 40, 40, 1);
    TV.draw_line(15, 15, 40, 15, 1);
    TV.draw_line(15, 15, 40, 40, 1);
    TV.draw_line(40, 15, 15, 40, 1);
    TV.draw_line(40, 40, 45, 35, 1);
    TV.draw_line(40, 15, 45, 10, 1);
    TV.draw_line(15, 15, 20, 10, 1);
    TV.draw_line(45, 10, 20, 10, 1);
    TV.draw_line(15, 15, 45, 10, 1);
    TV.draw_line(20, 10, 40, 15, 1);
    TV.draw_line(45, 10, 45, 35, 1);
    TV.draw_line(40, 40, 45, 10, 1);
    TV.draw_line(40, 15, 45, 35, 1);
    TV.println(5, 65, "1. Back");
    TV.println(5, 75, MenuChoice);
    delay(500);   
    while(true)
    {
    buttonState2 = digitalRead(3);
    if (buttonState2 == HIGH)
    {
      if (MenuChoice == 1)
      {
        delay(500);
        TV.clear_screen();
        Apps(); 
      }
     }
    }
  }
  
  void LED()
  {
    MenuChoice = 1;
    TV.clear_screen();
    while(true)
    {
    TV.println(5, 5, "Hold BUTTON1 To Turn On LED");
    TV.println(5, 35, MenuChoice);
    
    buttonState2 = digitalRead(3);
    if (buttonState2 == HIGH)
    {
      if (MenuChoice == 1)
      {
        delay(500);
        TV.clear_screen();
        Apps(); 
      }
    }
    buttonState = digitalRead(2);
    if (buttonState == HIGH)
    {
       digitalWrite(12, HIGH); 
    }
    else
    {
       digitalWrite(12, LOW); 
    }
    }
  }


