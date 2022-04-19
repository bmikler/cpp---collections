#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    List<int> list;

    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);

    for (int i = 0; i < list.getSize(); i++) {
        cout << list.get(i) << endl;
    }

    cout << endl;
    list.remove(3);


    for (int i = 0; i < list.getSize(); i++) {
        cout << list.get(i) << endl;
    }


}
