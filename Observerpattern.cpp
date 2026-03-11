#include <iostream>
#include <vector>
using namespace std;

class Observer
{
public:
    virtual void update(int price)=0;
};

class App : public Observer
{
    string name;
public:
    App(string n)
    {
        name=n;
    }

    void update(int price)
    {
        cout<<name<<" received price "<<price<<endl;
    }
};

class Stock
{
    vector<Observer*> obs;
    int price;

public:
    void addObserver(Observer* o)
    {
        obs.push_back(o);
    }

    void setPrice(int p)
    {
        price=p;
        notify();
    }

    void notify()
    {
        for(auto o:obs)
            o->update(price);
    }
};

int main()
{
    Stock s;

    App a1("App1");
    App a2("App2");

    s.addObserver(&a1);
    s.addObserver(&a2);

    s.setPrice(100);
    s.setPrice(120);

    return 0;
}