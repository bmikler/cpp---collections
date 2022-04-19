#include <iostream>

using namespace std;

template<typename T>
struct Node{
    Node(T data) {
        this->data = data;
        next = nullptr;
    }
    T data;
    Node *next;
};

template<typename T>
class List{
public:
    List(){
        head = nullptr;
        size = 0;
    };
    ~List() {};

    T get(int index){
        int counter  = 0;

        Node<T> *pointer = head;

        while(counter != index) {
            pointer = pointer->next;
            counter++;
        }

        return pointer->data;

    }
    void add(const T &element){

        if (head == nullptr) {
            head = new Node(element);
        } else {
            Node<T> *pointer = head;

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

            Node<T> *previousNode = setPointerToPreviosuNode(index);
            Node<T> *nodeToRemove = previousNode->next;


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
    Node<T> *head;

    void removeFirstNode() {
        Node<T> *nodeToRemove = head;
        head = head->next;

        delete nodeToRemove;
    }
    Node<T> *setPointerToPreviosuNode(int index) {
        int counter = 0;
        Node<T> *pointer = head;

        while(counter != (index - 1)) {
            pointer = pointer->next;
            counter++;
        }
        return pointer;
    }


};
