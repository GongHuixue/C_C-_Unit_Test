#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef enum ProductType{
	TYPEA,
	TYPEB,
}PDTYPE;

class Product {
	public:
		virtual void show() = 0;
};

class ProductA : public Product {
	public:
	void show () {
		cout << "I am product A" << endl;
	}
};

class ProductB : public Product {
	public:
	void show () {
		cout << "I am product B" << endl;
	}
};

class Factory {
	public:
		Product * Create_Product( PDTYPE type) {
			switch (type)
			{
				case TYPEA:
					return new ProductA();
				case TYPEB:
					return new ProductB();
				default:
					return NULL;
			}
		}	
};

int main()
{
	Factory *Product_Factory = new Factory();
	
	Product *PA = Product_Factory->Create_Product(TYPEA);
	if(PA != NULL)
		PA->show();

 
	Product *PB = Product_Factory->Create_Product(TYPEB);
	if(PB != NULL)
		PB->show();

	delete PA; delete PB; delete Product_Factory;

	return 0;
}
