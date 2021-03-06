/*
	Filename: InventoryDriver.cpp
	Modified By: Logan Davis
	Last Date Modified: 10/07/2016
*/

#include "InventoryManager.h"
#include "Text.h"
using CSC2110::String;
#include "Keyboard.h"
using CSC2110::Keyboard;

#include <iostream>
#include <iomanip>
using namespace std;

int inventoryChoice()
{
   Keyboard* kb = Keyboard::getKeyboard();
   int inv_choice = kb->getValidatedInt("Are you using (1) LIFO or (2) FIFO inventory management? ", 1, 2);
   return inv_choice;
}

//DO THIS
//buy Widgets (check invalid input and reprompt if necessary)
void buyWidgets(InventoryManager* im)
{
	Keyboard* kb = Keyboard::getKeyboard();
	int num_widgets = kb->getValidatedInt("How many widgets do you wish to buy? ", 1, 100);
	double widget_cost = kb->getValidatedDouble("What is the cost for each widget? ", 0.01, 1000.0);
	
	im->buyWidgets(widget_cost, num_widgets);
}

//DO THIS
//sell Widgets and return the profit (check invalid input and reprompt if necessary)
double sellWidgets(InventoryManager* im)
{
	Keyboard* kb = Keyboard::getKeyboard();
	int num_widgets = kb->getValidatedInt("How many widgets do you wish to sell? ", 1, 100);
	double widget_price = kb->getValidatedDouble("What is the selling price for each widget? ", 0.01, 1000.0);
	
	double profit = im->sellWidgets(widget_price, num_widgets);
	return profit;
}

bool mainMenu(InventoryManager* im)
{
   Keyboard* kb = Keyboard::getKeyboard();
   int menu_choice = kb->getValidatedInt("1. Buy Widgets \r\n2. Sell Widgets\r\n3. Quit\r\nWhat would you like to do? ", 1, 3);

   double profit = 0;

   if (menu_choice == 1)
   {
      buyWidgets(im);
      return 1;
   }
   else if(menu_choice == 2)
   {
      sellWidgets(im);
      return 1;
   }
   else 
   {
      return 0;
   }
}

int main()
{
   cout << setprecision(2) << fixed;

   int inv_choice = inventoryChoice();
   InventoryManager* im = new InventoryManager(inv_choice);

   bool ask = 1;
   while (ask)
   {
      ask = mainMenu(im);
   }

   double running_total = im->getTotalProfit();
   cout << "Your total profit for all transactions is $" << running_total << endl;

   delete im;
}
