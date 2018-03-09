/*
 * MenuAndSubmenu.h
 *
 *  Created on: 30.11.2017
 *      Author:
 */

#ifndef MENUANDSUBMENU_H_
#define MENUANDSUBMENU_H_
#include <stdbool.h>
#include "stm32f4xx_hal.h"
#include "hd44780.h"
#include "pcf8574.h"

extern volatile uint16_t pulse_count; // Licznik impulsow TRZEBA PODPI�� D8 (A) i D7  volatile uint16_t pulse_count; // Licznik impulsow TRZEBA PODPI�� D8 (A) i D7 (B)volatile uint16_t pulse_count; // Licznik impulsow TRZEBA PODPI�� D8 (A) i D7 (B)
extern volatile uint16_t positions; //licznik enkodera
extern volatile uint16_t valueToSet;
extern bool isPressed, backPressed; //czy guzik wcisniety

//------------------------Menu--------------------------------------

struct menu {
   void (*zaprogram)(LCD_PCF8574_HandleTypeDef* lcd);
   void (*tryb)(LCD_PCF8574_HandleTypeDef* lcd);
   void (*hold)(LCD_PCF8574_HandleTypeDef* lcd);
   void (*adjust)(LCD_PCF8574_HandleTypeDef* lcd);
   void (*zamknij)(LCD_PCF8574_HandleTypeDef* lcd);
 };
typedef struct menu menu;

menu stworzMenu(void);

//---------------------SubMenu1------------------------------------------------------

struct submenu {
   void (*action1)(LCD_PCF8574_HandleTypeDef* lcd);
   void (*action2)(LCD_PCF8574_HandleTypeDef* lcd);
   void (*action3)(LCD_PCF8574_HandleTypeDef* lcd);
 };

typedef struct submenu submenu;

submenu stworzSubMenuTrybuPracy(void);

#endif /* MENUANDSUBMENU_H_ */
