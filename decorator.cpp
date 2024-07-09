#include<bits/stdc++.h>
using namespace std;

#define FARMHOUSE  100
#define MARGHERITA 50
#define MUSHROOM 20
#define CHESSE 35

class Basepizza
{
public:
	 virtual int cost() = 0;
	
};

class Topping : public Basepizza
{
      
};

class Farmhouse : public Basepizza{
public:
	
    int cost() override{
    	return FARMHOUSE;
    }
};

class Margherita : public Basepizza{
public:
	int cost() override{
		return MARGHERITA;
	}
};

class Mushroom : public Topping{
   
   Basepizza* basepizza;
 public:
 	Mushroom(Basepizza* basepizza):basepizza(basepizza){};

 	int cost() override{
 		return basepizza->cost() + MUSHROOM;
 	}

};

class Chesseburst : public Topping{

 Basepizza* basepizza;
 public:
 	Chesseburst(Basepizza* basepizza):basepizza(basepizza){};

 	int cost() override{
 		return basepizza->cost() + CHESSE;
 	}

};

int main()
{
	Farmhouse farmhouse;
	Chesseburst chesseburst(&farmhouse);
	cout<<chesseburst.cost()<<"\n";

	Margherita margherita;
    cout<<margherita.cost();

}
