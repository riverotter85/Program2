/*
	Filename: InventoryManager.h
	Written and Modified By: Logan Davis
	Last Date Modified: 10/07/2016
*/

#if !defined NULL
#define NULL 0
#endif

#if !defined _INVENTORY_MANAGER_H
#define _INVENTORY_MANAGER_H

#include "QueueDeque.h"
#include "StackDeque.h"

#include "Widget.h"

class InventoryManager
{
	private:
		QueueDeque<Widget>* qd;
		StackDeque<Widget>* sd;
		double profit;
		int inventory_choice; // 1 for LIFO management (StackDeque), 2 for FIFO (QueueDeque)
	
	public:
		// Pre: inv_choice has to be either 1 (LIFO) or 2 (FIFO) for how the data added
		//		to the inventory will be stored. If an invalid number is passed, inv_choice
		//		is LIFO by default.
		// Post: A stack is instantiated if inv_choice is LIFO or a queue if it was FIFO.
		//		 Profits are initialized to 0.
		InventoryManager(int inv_choice);
		~InventoryManager();
		
		// Pre: The cost for each item must be passed, and the number of items to be bought (num_to_buy)
		//		must be greater than 0. Otherwise, buyWidgets returns early.
		// Post: The number of widgets according to num_to_buy is generated with the corresponding
		//		 cost, and is stored in the main stack or queue depending on how InventoryManager
		//		 was constructed.
		void buyWidgets(double cost, int num_to_buy);
		
		// Pre: N/A.
		// Post: The current profit given from the widgets sold is returned.
		double getTotalProfit();
		
		// Pre: The price for each item must be passed, and number of items being sold must be
		//		greater than 0. Otherwise, sellWidgets does nothing. If the number of items being
		//		sold exceeds that of the inventory's size, then all of the inventory's contents
		//		are sold. However, nothing is oversold.
		// Post: The total profit from each widget sold is returned.
		double sellWidgets(double price, int num_to_sell);
};

#endif