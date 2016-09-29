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
		QueueDeque<Widget> qd;
		StackDeque<Widget> sd;
		int inventory_choice; // 0 for FIFO management (QueueDeque), 1 for LIFO (StackDeque)
	
	public:
		InventoryManager(int inv_choice);
		~InventoryManager();
		
		void buyWidgets(float cost, int num_to_buy);
		float getTotalProfit();
		float sellWidgets(float price, int num_to_sell);
};

#endif