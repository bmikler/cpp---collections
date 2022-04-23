#include<iostream>

template<typename T>
struct Node{
    Node(const T &data){
        this->data = data;
    }
    T data;
    Node<T> *next;
};

template<typename T>
class Queue {
public:
    Queue() {
        head = tail = nullptr;
        size = 0;
    }
    ~Queue(){
        while(head != nullptr){
            remove();
        }
    };
    void getFirst() {
        return head->data;
    }
    void add(const T &element){

        Node<T> *newNode = new Node(element);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        size++;

    };
    void remove(){
        Node<T> *nodeToRemove = head;
        head = head->next;
        std::cout << "delete " << nodeToRemove->data << std::endl;
        delete nodeToRemove;

        size--;
    };
    int getSize(){
        return size;
    };
//private:
    Node<T> *head;
    Node<T> *tail;
    int size;
};
