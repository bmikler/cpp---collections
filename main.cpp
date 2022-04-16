#include <iostream>
#include "vector.h"

using namespace std;

int main()
{
    Vector<string> v;

    v.add("aaaa");
    v.add("hello", 1);

    cout << "first:" << endl;
    for (int i = 0; i < v.getSize(); i++) {
        cout << v.get(i) << endl;
    }

    cout << v.getSize() << endl;

    v.add("koniec", 50);

    cout << "second:" << endl;
    for (int i = 0; i < v.getSize(); i++) {
        cout << v.get(i) << endl;
    }

    v.remove(10);
    cout << "remove:" << endl;
    for (int i = 0; i < v.getSize(); i++) {
        cout << v.get(i) << endl;
    }

}
