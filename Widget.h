#if !defined _WIDGET_H
#define _WIDGET_H

class Widget
{
	private:
		float cost;
	
	public:
		Widget(float cst);
		~Widget();
		
		void setCost(float cst);
		float getCost();
};

#endif