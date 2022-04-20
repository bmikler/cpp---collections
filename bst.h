#include<iostream>

template<typename T>
struct Node{
    Node(const T &data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
    T data;
    Node<T> *left;
    Node<T> *right;
};

template<typename T>
class BST{
public:
    BST() {
        this->root = nullptr;
    }
    ~BST(){};
    void add(const T &element){

        Node<T> *newNode = new Node(element);

        if (root == nullptr){
            root = newNode;
        } else {
            appendChild(root, newNode);
        }

    };
    void remove(const T &element);
    T search(const T &element);
    void print(){


    };
//private:
    Node<T> *root;
    void appendChild(Node<T> *parent, Node<T> *newNode){
        if (newNode->data > parent->data) {

            if (parent->right == nullptr){
                parent->right = newNode;
            } else {
                appendChild(parent->right, newNode);
            }

        }

        if (newNode->data < parent-> data){

            if(parent->left == nullptr) {
                parent->left = newNode;
            } else {
                appendChild(parent->left, newNode);
            }

        }

    };

};
