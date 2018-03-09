/*
 * MenuAndSubMenu.c
 *
 *  Created on:
 *      Authors: Dawid and Michal
 */

#include <stdbool.h>
#include <string.h>
#include "MenuAndSubMenu.h"

//------------------------Menu Glowne--------------------------------------

 void moje_urzadzenie_zaprogram(LCD_PCF8574_HandleTypeDef* lcd)
 {
	 LCD_SetLocation(lcd, 0, 0);
	 LCD_WriteString(lcd, "1. Program     ");
	 if(isPressed)
	 {
		 /* sth to do */
	 }
 }

void moje_urzadzenie_tryb_pracy(LCD_PCF8574_HandleTypeDef* lcd)
{
	 LCD_SetLocation(lcd, 0, 0);
	 LCD_WriteString(lcd, "2. Mode        ");

	if (isPressed)
	{
		submenu trybPracy = stworzSubMenuTrybuPracy();
		isPressed = 0;
		TIM1->CNT = 0;
		while(1)
		{
			pulse_count = TIM1->CNT; // przepisanie wartosci z rejestru timera
			positions = pulse_count/4; // zeskalowanie impulsow do liczby stabilnych pozycji walu enkodera

			switch( positions % 3)
			{
				case 0 :
					trybPracy.action1(lcd); // automat
					break;
				case 1 :
					trybPracy.action2(lcd); // manual
					break;
				case 2 :
					trybPracy.action3(lcd); // powrot
					break;
			}
			isPressed = 0;
			if(backPressed)
			{
				backPressed = 0;
				TIM1->CNT = 4;  // powrot do drugiej pozycji w glownym menu
				return;
			}
		}
	}
}

void moje_urzadzenie_adjust(LCD_PCF8574_HandleTypeDef* lcd)
{
	 LCD_SetLocation(lcd, 0, 0);
	 LCD_WriteString(lcd, "3. Set value     "); // przykladowa pozycja w menu do ustawiania jakiejs wartosci
	 if (isPressed)
	 {
		 isPressed = 0;
		 TIM1->CNT = 0;  // zerowanie pozycji enkodera
		 LCD_ClearDisplay(lcd);
		 LCD_SetLocation(lcd, 0, 0);
		 LCD_WriteString(lcd, "Current val: ");
		 char str[6];
		 sprintf(str, "%d", valueToSet); // zamiana valueToSet na ciag znakow i wpisywanie go do tablicy str

		 const char *strPom = "  ";      // do zmiennej doklejane sa dwa biale znaki by nadpisywac zbedne
		                                 // cyfry pozostale po przeskoczeniu np z trzycyfrowej liczby na jednocyfrowa
		 LCD_WriteString(lcd, strcat(str,strPom));
		 LCD_SetLocation(lcd, 0, 1);
		 LCD_WriteString(lcd, "New value: ");
		 while(1)
		 {
			 LCD_SetLocation(lcd, 11, 1);
			 pulse_count = TIM1->CNT;     // przepisanie wartosci z rejestru timera
			 positions = pulse_count/4;   // positions zmienia sie w zakresie od 0 do 100
			 char str1[6];
			 sprintf(str1, "%d", positions); // zamiana positions na ciag znakow i wpisywanie go do tablicy str1
			 LCD_WriteString(lcd,strcat(str1, strPom));
			 if(isPressed){        // zatwierdzenie i zapis
				 valueToSet = positions;
				 isPressed = 0;
				 backPressed = 0;
				 LCD_ClearDisplay(lcd);
				 TIM1->CNT = 8;      // powrot na 3 pozycje glownego menu
				 return;
			 } else if(backPressed){ // powrot bez zapisu
				 backPressed = 0;
				 LCD_ClearDisplay(lcd);
				 TIM1->CNT = 8;
				 return;
			 }
		 }
	 }
}

void moje_urzadzenie_hold(LCD_PCF8574_HandleTypeDef* lcd)
{
	 LCD_SetLocation(lcd, 0, 0);
	 LCD_WriteString(lcd, "4. Hold         ");
	 if (isPressed)
	 {
		 /* sth to do */
	 }
}

void moje_urzadzenie_zamknij(LCD_PCF8574_HandleTypeDef* lcd)
{
	 LCD_SetLocation(lcd, 0, 0);
	 LCD_WriteString(lcd, "5. Exit         ");
	 if (isPressed)
	 {
	 	 /* sth to do */
	 }
}

menu stworzMenu(void)
 {
   menu moje_menu;
   moje_menu.zaprogram = moje_urzadzenie_zaprogram;
   moje_menu.tryb = moje_urzadzenie_tryb_pracy;
   moje_menu.hold = moje_urzadzenie_hold;
   moje_menu.adjust = moje_urzadzenie_adjust;
   moje_menu.zamknij = moje_urzadzenie_zamknij;
   return moje_menu;
 }

 //---------------------SubMenu1 - menu wyboru trybu ------------------------------------------------------

void tryb_manual (LCD_PCF8574_HandleTypeDef* lcd)
  {
 	 LCD_SetLocation(lcd, 0, 0);
 	 LCD_WriteString(lcd, "1. Manual      ");
 	 if (isPressed)
 	 {
 		/* sth to do */
 	 }
  }

  void tryb_automat (LCD_PCF8574_HandleTypeDef* lcd)
  {
 	 LCD_SetLocation(lcd, 0, 0);
 	 LCD_WriteString(lcd, "2. Automat      ");
 	if (isPressed){

 	 	/* sth to do */

 	}
  }
  void powrot (LCD_PCF8574_HandleTypeDef* lcd)
  {
  	 LCD_SetLocation(lcd, 0, 0);
  	 LCD_WriteString(lcd, "3. Exit        ");
  	if(isPressed == 1)
  	{
  		isPressed = 0;
  		backPressed = 1;
  	}
  }

  submenu stworzSubMenuTrybuPracy(void)
  {
    submenu moje_submenu;
    moje_submenu.action1 = tryb_manual;
    moje_submenu.action2 = tryb_automat;
    moje_submenu.action3 = powrot;
    return moje_submenu;
  }

  //---------------------SubMenu2 - menu ... ------------------------------------------------------
  /* Prototypy funkcji
  void action1()
  {

  }

  void action2()
  {

  }

  void action3()
  {

  }

  **Tworzenie submenu**

  submenu stworzSubMenu...(void)
  {
    submenu moje_submenu;
    moje_submenu.action1 = action1;
    moje_submenu.action2 = action2;
    moje_submenu.action3 = action3;
    return moje_submenu;

  } */
