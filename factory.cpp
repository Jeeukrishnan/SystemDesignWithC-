#include<bits/stdc++.h>
using namespace std;

class Shape{
public:
	virtual void draw() = 0;
};

class Circle : public Shape{
public:
	void draw() override{
		cout<<"circle";
	}
};

class  Triangle : public Shape{
public:
	void draw() override{
		cout<<"triangle"; 
	}
};


class FactoryShape{
public:
	Shape* object_return(int input)
	{
		switch(input){
		case 0:
			return new Circle();
		case 1:
			return new Triangle();
	    default :
	    	return nullptr;
		}
	}
};


int main()
{

	FactoryShape getshape;
	Shape* shape = getshape.object_return(1);

	shape->draw();
}



