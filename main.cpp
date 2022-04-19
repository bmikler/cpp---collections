#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    List<int> list;

    //TESTS
    //get size empty
    cout << "get size empty: " << list.getSize() << endl;

    //is empty empty
    cout << "is empty - true: " << list.isEmpty() << endl;

    //add element on begining
    cout << "add element on begining: " << endl;
    list.add(2);
    list.add(1, 0);

        for (int i = 0; i < list.getSize(); i++) {
            cout << list.get(i) << endl;
        }
    //add element in the end
        cout << "add element in the end" << endl;

        list.add(3, list.getSize());

        for (int i = 0; i < list.getSize(); i++) {
            cout << list.get(i) << endl;
        }

    //add element in the middle

    cout << "add element in the middle" << endl;

    list.add(20, 1);
    list.add(100, 2);
    for (int i = 0; i < list.getSize(); i++) {
        cout << list.get(i) << endl;
    }


    //remove first element

    cout << "remove first element" << endl;
    list.remove(0);
    for (int i = 0; i < list.getSize(); i++) {
        cout << list.get(i) << endl;
    }

    //remove last element
    cout << "remove last element" << endl;
    list.remove(list.getSize() - 1);

    for (int i = 0; i < list.getSize(); i++) {
        cout << list.get(i) << endl;
    }


    //remove middle element

    cout << "remove middle element" << endl;
    list.remove(1);
    for (int i = 0; i < list.getSize(); i++) {
        cout << list.get(i) << endl;
    }

    // is empty false

    cout << "is empty false" << list.isEmpty();




}
