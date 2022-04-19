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
    ~List() {
        Node<T> *deletePointer = head;

        while(head->next != nullptr) {
            head = head->next;
            delete deletePointer;
            deletePointer = head;
        }

    };

    T get(int index){

        Node<T> *pointer = setPointerToNode(index);
        return pointer->data;

    }
    void add(const T &element){

        add(element, size);

    };

    void add(const T &element, int index) {

        if (index < 0 || index > size) {
            throw runtime_error("Wrong index");
        }

        Node<T> *newNode = new Node(element);

        if (index == 0) {

            newNode->next = head;
            head = newNode;

        } else {

            Node<T> *previousNode = setPointerToNode(index - 1);

            newNode->next = previousNode->next;
            previousNode->next = newNode;

        }

        size++;

    }

    void remove(int index) {

        if(index < 0 || index > size - 1){
            throw runtime_error("Wrong index");
        }

        if (index == 0) {
            Node<T> *nodeToRemove = head;
            head = head->next;

            delete nodeToRemove;
        }

        else {

            Node<T> *previousNode = setPointerToNode(index - 1);
            Node<T> *nodeToRemove = previousNode->next;

            previousNode->next = nodeToRemove->next;

            delete nodeToRemove;
        }

        size--;
    };


    int getSize() {
        return size;
    }

    bool isEmpty() {
        return head == nullptr;
    }


private:
    int size;
    Node<T> *head;

    Node<T> *setPointerToNode(int index) {
        int counter = 0;
        Node<T> *pointer = head;

        while(counter < (index)) {
            pointer = pointer->next;
            counter++;
        }
        return pointer;
    }

};
