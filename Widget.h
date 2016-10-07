/*
	Filename: Widget.h
	Written and Modified By: Logan Davis
	Last Date Modified: 10/07/2016
*/

#if !defined _WIDGET_H
#define _WIDGET_H

class Widget
{
	private:
		double cost;
	
	public:
		Widget(double cst);
		~Widget();
		
		void setCost(double cst);
		double getCost();
};

#endif