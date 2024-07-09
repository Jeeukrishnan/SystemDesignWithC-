#include<bits/stdc++.h>
using namespace std;

class Ilogger{

public :
    virtual void log(string message) = 0;
    virtual ~Ilogger(){};
};

class Console : public Ilogger{

public:
	void log(string message) override{
		cout<<"Here I am "<<message;
	}

};


class Consoleagain : public Ilogger{

public:
	void log(string message) override{
		cout<<"yellow "<<message;
	}

};

class Service : public Ilogger{

public:

	//dependecy injection, use of interface variable
	Ilogger* jeeu;
    
    //constructor injection
	Service(Ilogger* logger) : jeeu(logger){};

	//dependency injection done : next override pure virtual function

	void log(string message) override {
        jeeu->log(message); // Delegating logging to injected logger
    }

	void action()
	{
		log("Performing action");
		cout<<"In second place"<<"\n";
	}
};


int main()
{
	Console console;
	Consoleagain a;
	Service service(&console);
	Service servicea(&a);
    
    servicea.action();
	service.action();
}