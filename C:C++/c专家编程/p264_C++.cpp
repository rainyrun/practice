#include <stdio.h>

class Fruit
{
public: 
	void peel(); 
	void slice(int i);
	void juice(double f);
	~Fruit() { printf("~Fruit\n"); }
private: 
	int weight = 11;
	int calories_per_oz;
};
void Fruit::peel()
{
	printf("in peel\n");
	printf("the weight of this fruit is %d\n", weight);
	printf("this ptr is %p\n", this);
	this->weight--;
	weight--;
	printf("the weight of this fruit is %d\n", weight);
}
void Fruit::slice(int i)
{
	printf("in slice %d\n", i);
}
void Fruit::juice(double f)
{
	printf("in juice %fml\n", f);
}

void main()
{
	Fruit melon;
	int i = 3;
	melon.slice(i);
	melon.peel();
}
