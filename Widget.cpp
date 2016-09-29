#include "Widget.h"

Widget::Widget(float cst)
{
	setCost(cst);
}

Widget::~Widget()
{
}

void Widget::setCost(float cst)
{
	cost = cst;
}

void Widget::getCost()
{
	return cost;
}