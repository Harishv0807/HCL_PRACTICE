#include <iostream>
using namespace std;

class Shallow {
public:
    int *data;

    Shallow(int value) {
        data = new int;
        *data = value;
    }

    Shallow(const Shallow &obj) {
        data = obj.data;   // shallow copy
    }

    void display() {
        cout << *data << endl;
    }
};

int main() {
    Shallow obj1(10);
    Shallow obj2 = obj1;

    obj1.display();
    obj2.display();
}