#include <iostream>

using namespace std;

struct Node{
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
    int data;
    Node *next;
};


class List{
public:
    List(){
        head = nullptr;
    };
    ~List() {};

    int get(int index){
        int counter  = 0;

        Node *pointer = head;

        while(counter != index) {
            pointer = pointer->next;
            counter++;
        }

        return pointer->data;

    }
    void add(int element){

        if (head == nullptr) {
            head = new Node(element);
        } else {
            Node *pointer = head;

            while(pointer->next != nullptr) {
                pointer = pointer->next;
            }

            pointer->next = new Node(element);

        }

    };
    //void remove(int index);



//private:
    Node *head;

};
