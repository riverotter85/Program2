#include "InventoryManager.h"

#include "QueueDeque.h"
#include "StackDeque.h"

#include "Widget.h"

InventoryManager::InventoryManager(int inv_choice)
{
	if (inv_choice != 0 || inv_choice != 1)
	{
		inv_choice = 0; // Use FIFO management by default
	}
	
	inventory_choice = inv_choice;
	
	if (inventory_choice == 0)
	{
		qd = new QueueDeque<Widget>();
		sd = NULL;
	}
	else
	{
		sd = new StackDeque<Widget>();
		qd = NULL;
	}
}

InventoryManager::~InventoryManager()
{
	if (inventory_choice == 0)
	{
		delete qd;
	}
	else
	{
		delete sd;
	}
}

void InventoryManager::buyWidgets(float cost, int num_to_buy)
{
	if (num_to_buy < 1)
	{
		return; // Nothing to add
	}
	
	for (int i = 0; i < num_to_buy; i++)
	{
		Widget* item = new Widget(cost);
		
		if (inventory_choice == 0)
		{
			qd->enqueue(item);
		}
		else
		{
			sd->push(item);
		}
	}
}

// NOTE: Complete code later
float InventoryManager::getTotalProfit()
{
	if (inventory_choice == 0)
	{
		while (qd->size() != 0)
		{
			
		}
	}
	else
	{
		
	}
}

float InventoryManager::sellWidgets(float price, int num_to_sell)
{
	if (num_to_sell < 1)
	{
		return 0.0; // Nothing to sell
	}
	
	float profit = 0.0;
	
	if (inventory_choice == 0)
	{
		if (num_to_sell > qd->size())
		{
			num_to_sell = qd->size(); // Can only sell as many items that are in the list
		}
		
		for (int i = 0; i < num_to_sell; i++)
		{
			Widget* item = qd->pop();
			profit = profit + (price - item->getCost());
		}
	}
	else
	{
		if (num_to_sell > sd->size())
		{
			num_to_sell = sd->size(); // Can only sell as many items that are in the list
		}
		
		for (int i = 0; i < num_to_sell; i++)
		{
			Widget* item = sd->pop();
			profit = profit + (price - item->getCost());
		}
	}
	
	return profit;
}