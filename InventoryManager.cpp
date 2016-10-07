/*
	Filename: InventoryManager.cpp
	Written and Modified By: Logan Davis
	Last Date Modififed: 10/07/2016
*/

#include "InventoryManager.h"

#include "QueueDeque.h"
#include "StackDeque.h"
#include "Widget.h"

InventoryManager::InventoryManager(int inv_choice)
{
	if (inv_choice != 1 && inv_choice != 2)
	{
		inv_choice = 1; // Use LIFO management by default
	}
	
	inventory_choice = inv_choice;
	profit = 0.0;
	
	if (inventory_choice == 1)
	{
		sd = new StackDeque<Widget>();
	}
	else
	{
		qd = new QueueDeque<Widget>();
	}
}

InventoryManager::~InventoryManager()
{
	if (inventory_choice == 1)
	{
		delete sd;
	}
	else
	{
		delete qd;
	}
}

void InventoryManager::buyWidgets(double cost, int num_to_buy)
{
	if (num_to_buy < 1)
	{
		return; // Nothing to add
	}
	
	for (int i = 0; i < num_to_buy; i++)
	{
		Widget* item = new Widget(cost);
		
		if (inventory_choice == 1)
		{
			sd->push(item);
		}
		else
		{
			qd->enqueue(item);
		}
	}
}

double InventoryManager::getTotalProfit()
{
	return profit;
}

double InventoryManager::sellWidgets(double price, int num_to_sell)
{
	if (num_to_sell >= 1) // Only modify profit if there are items to sell
	{
		if (inventory_choice == 1)
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
		else
		{
			if (num_to_sell > qd->size())
			{
				num_to_sell = qd->size(); // Can only sell as many items that are in the list
			}
			
			for (int i = 0; i < num_to_sell; i++)
			{
				Widget* item = qd->dequeue();
				profit = profit + (price - item->getCost());
			}
		}
	}
	
	return profit;
}