#include <iostream>
using namespace std;

class Shape
{
public:
    virtual void draw() = 0;
};

class Circle : public Shape
{
public:
    void draw()
    {
        cout<<"Circle"<<endl;
    }
};

class Rectangle : public Shape
{
public:
    void draw()
    {
        cout<<"Rectangle"<<endl;
    }
};

class ShapeFactory
{
public:
    Shape* getShape(string type)
    {
        if(type=="circle")
            return new Circle();
        else if(type=="rectangle")
            return new Rectangle();
        else
            return NULL;
    }
};

int main()
{
    ShapeFactory factory;

    Shape* s1 = factory.getShape("circle");
    s1->draw();

    Shape* s2 = factory.getShape("rectangle");
    s2->draw();

    return 0;
}