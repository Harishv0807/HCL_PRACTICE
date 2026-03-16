#include <iostream>
using namespace std;

class Deep {
public:
    int *data;

    Deep(int value) {
        data = new int;
        *data = value;
    }

    Deep(const Deep &obj) {
        data = new int;
        *data = *obj.data;
    }

    void display() {
        cout << *data << endl;
    }
};

int main() {
    Deep obj1(20);
    Deep obj2 = obj1;

    obj1.display();
    obj2.display();
}