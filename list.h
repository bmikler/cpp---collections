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
        size = 0;
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

        size++;

    };

    void remove(int index) {

        if(index < 0 || index > size){
            throw runtime_error("Wrong index");
        }

        if (index == 0) {
            removeFirstNode();
        }

        else {

            Node* previousNode = setPointerToPreviosuNode(index);
            Node* nodeToRemove = previousNode->next;

            if (index == size) {
                previousNode->next = nullptr;
            } else {
                previousNode->next = nodeToRemove->next;
            }

            delete nodeToRemove;
        }

        size--;
    };


    int getSize() {
        return size;
    }

    bool isEmpty() {
        return head = nullptr;
    }


private:
    int size;
    Node *head;

    void removeFirstNode() {
        Node * nodeToRemove = head;
        head = head->next;

        delete nodeToRemove;
    }
    Node* setPointerToPreviosuNode(int index) {
        int counter = 0;
        Node *pointer = head;

        while(counter != (index - 1)) {
            pointer = pointer->next;
            counter++;
        }
        return pointer;
    }


};
