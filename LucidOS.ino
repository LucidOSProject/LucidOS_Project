/*
Lucid OS - Developed by Blake Sekelsky
Frequent updates being made on Twitter @LucidOS_Project and on GitHub and Youtube.
GitHub - https://github.com/LucidOSProject/LucidOS_Project/blob/master/LucidOS.ino
Youtube - http://www.youtube.com/playlist?list=PLwBbXoTme4Hra0Lc5wSkfXOc5po9NYJ1R
Twitter - https://twitter.com/LucidOS_Project
*/ 

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
  void CookieClicker();
  void Stopwatch();
  void LastApp();
  
  int buttonState = 0;
  int buttonState2 = 0;
  int MenuChoice = 1;
  String recentApp;
  
  void setup()  
  {
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    pinMode(12, OUTPUT);
    TV.begin(NTSC, 126, 96);
    TV.select_font(font4x6);
    TV.clear_screen();
  }
  //Draws the logo and splash screen
  void loop() 
  { 
    //Draws the L
    for (int a = 10; a < 15; a++)
    {
      for (int b = 10; b < 51; b++)
      {
       TV.set_pixel(a, b, 1); 
      }
    }
    for (int c = 10; c < 95; c++)
    {
       for (int d = 51; d < 56; d++)
      {
       TV.set_pixel(c, d, 1);
      } 
    }
    //Draws the U
    for (int e = 25; e < 28; e++)
    {
       for(int f = 10; f < 40; f++)
      {
         TV.set_pixel(e, f, 1);
      } 
    }
    for (int g = 27; g < 34; g++)
    {
       for(int h = 40; h < 43; h++)
      {
         TV.set_pixel(g, h, 1);
      } 
    }
    for (int i = 32; i < 35; i++)
    {
       for(int j = 10; j < 40; j++)
      {
         TV.set_pixel(i, j, 1);
      } 
    }
    //Draws the C
    for (int k = 40; k < 43; k++)
    {
       for (int l = 13; l < 39; l++)
      {
         TV.set_pixel(k, l, 1);
      } 
    }
    for (int m = 41; m < 51; m++)
    {
       for (int n = 10; n < 13; n++)
      {
         TV.set_pixel(m, n, 1);
      } 
    }
    for (int o = 41; o < 51; o++)
    {
       for (int p = 39; p < 42; p++)
      {
         TV.set_pixel(o, p, 1);
      } 
    }
    //Draws the I
    for (int q = 61; q < 64; q++)
    {
       for (int r = 10; r < 41; r++)
       {
          TV.set_pixel(q, r, 1); 
       }
    }
    for (int s = 54; s < 71; s++)
    {
       for (int t = 10; t < 13; t++)
      {
         TV.set_pixel(s, t, 1);
      } 
    }
    for (int u = 54; u < 71; u++)
    {
       for (int v = 39; v < 42; v++)
      {
         TV.set_pixel(u, v, 1);
      } 
    }
    //Draws the D
    for (int w = 74; w < 84; w++)
    {
       for (int x = 10; x < 13; x++)
      {
         TV.set_pixel(w, x, 1);
      } 
    }
    for (int y = 74; y < 84; y++)
    {
       for (int z = 39; z < 42; z++)
      {
         TV.set_pixel(y, z, 1);
      } 
    }
    for (int aa = 74; aa < 76; aa++)
    {
      for (int ab = 13; ab < 42; ab++)
      {
         TV.set_pixel(aa, ab, 1); 
      }
    }
    for (int bb = 90; bb < 93; bb++)
    {
       for (int bc = 21; bc < 32; bc++)
      {
         TV.set_pixel(bb,bc, 1);
         TV.draw_line(84, 12, 91, 21, 1);
         TV.draw_line(84, 11, 92, 21, 1);
         TV.draw_line(84, 13, 92, 21, 1);
         TV.draw_line(83, 40, 90, 32, 1);
         TV.draw_line(83, 41, 91, 32, 1);
      } 
    }
    TV.println(11, 60, "Operating System v.01");
    TV.println(20, 80, "Button 2 to Start");

    buttonState2 = digitalRead(3);
    if (buttonState2 == HIGH)
    {
     delay(500);
     TV.clear_screen();
     program();
    }
  }
  //Main Menu Function
  void program()
  {
    MenuChoice = 1;
    
    while(true)
    { 
     TV.println(5, 45, MenuChoice); 
     TV.println(5, 5, "Menu: ");
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
  //Shows thw Applications that are available
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
    TV.println(5, 35, "3. Cookie Clicker");
    TV.println(5, 45, "4. Stopwatch");
    TV.println(5, 55, "5. Last App Used");
    TV.println(5, 65, "6. Back");
    TV.println(5, 75, MenuChoice);

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
       MenuChoice++;
      delay(500); 
      }
      else if (MenuChoice == 4)
      {
       MenuChoice++;
       delay(500); 
      }
      else if (MenuChoice == 5)
      {
       MenuChoice++;
       delay(500); 
      }
      else if (MenuChoice == 6)
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
        CookieClicker(); 
      }
      else if (MenuChoice == 4)
      {
       delay(500);
       TV.clear_screen();
       Stopwatch(); 
      }
      else if (MenuChoice == 5)
      {
       delay(500);
       TV.clear_screen();
       LastApp(); 
      }
      else if (MenuChoice == 6)
      {
       delay(500);
       TV.clear_screen();
       program(); 
      }
     } 
    }
   }
  //Shows Recommended Hardware
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
    recentApp = "3DBox";
  }
  
  void LED()
  {
    MenuChoice = 1;
    TV.clear_screen();
    delay(500);
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
    recentApp = "LED";
  }
  
  void CookieClicker()
  {
     int btn_press = 0;
     MenuChoice = 1;
     int Cookies = 0;
     TV.clear_screen();
     TV.draw_circle(45, 20, 15, 1);
     TV.set_pixel(45, 20, 1);
     TV.set_pixel(42, 30, 1);
     TV.set_pixel(46, 8, 1);
     TV.set_pixel(36, 20, 1);
     TV.set_pixel(50, 30, 1);
     TV.set_pixel(46, 35, 1);
     TV.set_pixel(53, 25, 1);
     TV.set_pixel(48, 15, 1);
     TV.println(5, 55, "1. Back");
    while (true)
    {      
     TV.println(5, 10, Cookies);
     buttonState = digitalRead(2);
     if (buttonState == HIGH)
     {
       if(btn_press == 0)
       {
        btn_press = 1; 
        Cookies++; 
       }
       else
       {
       }
     }
     else
     {
       btn_press = 0;
       Cookies = Cookies;
     }   
     buttonState2 = digitalRead(3);
     
     if (buttonState2 == HIGH)
    { 
     if  (MenuChoice == 1)
     {
      delay(500);
      TV.clear_screen();
      Apps(); 
     }
    }
   }
   recentApp = "CookieClicker";
  }
  void Stopwatch()
  {
    int ms = 0;
    int s = 0;
    int m = 0;
    int h = 0;
    int d = 0;
    
    while(true)
    {
    TV.println(5, 5, "Button 1 To Start, Button 2 to quit");
    buttonState = digitalRead(2);
    buttonState2 = digitalRead(3);
    if (buttonState == HIGH)
    {
     break; 
    }
    else
    {
      
    }
    if (buttonState2 == HIGH)
    {
     TV.clear_screen();
     Apps();
     delay(500); 
    }
    else
    {
      
    }
    }
    
    while(true)
     {
     ms++;
     if (ms == 1000)
    {
     s++;
     if (s == 60)
     {
      m++;
     if (m == 60)
     {
      h++;
      if (h == 24)
      {
       d++;
       if (d == 1000)
       {
         TV.clear_screen();
         Apps();
         delay(500);
       }  
      }
      } 
      }
      } 
     }
     TV.println(5, 15, "Days:");
     TV.println(20, 15, d);
     TV.println(5, 25, "Hours:");
     TV.println(20, 25, h);
     TV.println(5, 35, "Minutes:");
     TV.println(20, 35, m);
     TV.println(5, 45, "Seconds:");
     TV.println(20, 45, s);
     TV.println(5, 55, "Milliseconds:");
     TV.println(20, 55, ms);
     delay(1);
     recentApp = "Stopwatch";
  }
  void LastApp()
  {
    char lastApp[20];
    recentApp.toCharArray(lastApp, 20);
    for (int a = 0; a < 20; a++)
    {
      for (int b = 5; b < a; b++)
      {
        TV.print_char(5, b, lastApp[a]);
      }
    }
  }
