/*
	Filename: Widget.cpp
	Written and Modified By: Logan Davis
	Last Date Modified: 10/07/2016
*/

#include "Widget.h"

Widget::Widget(double cst)
{
	setCost(cst);
}

Widget::~Widget()
{
}

void Widget::setCost(double cst)
{
	cost = cst;
}

double Widget::getCost()
{
	return cost;
}