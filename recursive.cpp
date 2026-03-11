#include <iostream>
using namespace std;

void reverseString(string &s, int start, int end)
{
    if(start >= end)
        return;

    char temp = s[start];
    s[start] = s[end];
    s[end] = temp;

    reverseString(s, start + 1, end - 1);
}

int main()
{
    string s = "HELLO";

    reverseString(s, 0, s.length() - 1);

    cout << "Reversed string: " << s;

    return 0;
}