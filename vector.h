#include<iostream>

using namespace std;

template<typename T>
class Vector{
public:
    Vector(){
        capacity = 5;
        size = 0;
        data = new T[capacity];

    };
    ~Vector(){};

    void add(T element) {

        add(element, size);

    };

    void add(T element, int index) {

        if (index > size) {
            index = size;
        }

        if (size == capacity) {
            increaseStorageSpace();
        }

        for (int i = size; i >= index; i--) {
            data[i + 1] = data[i];
        }

        data[index] = element;
        size++;

    }

    T get(int index){
        return data[index];
    };

    void remove(int index){

        if(index > size){
            throw runtime_error("Index out of range");
        }

        for (int i = index; i < size; i++) {
            data[i] = data[i + 1];
        }

        size--;

       if ((capacity - size) > 10) {
           decreaseStorageSpace();
       }
    };


    int getSize(){
        return size;
    };
    bool isEmpty() {
        return size = 0;
    };


private:

    void increaseStorageSpace(){

        capacity = capacity + capacity/2;
        T *newArr = new T[capacity];

        copy(data, newArr);
        delete[] data;

        data = newArr;

    };
    void decreaseStorageSpace(){

        capacity = capacity - capacity/2;
        T *newArr = new T[capacity];

        copy(data, newArr);
        delete[] data;

        data = newArr;

    };
    void copy(T source[], T target[]) {
        for (int i = 0; i < size; i++) {
            target[i] = source[i];
        }
    }
    int size;
    int capacity;
    T *data;

};
