#include<iostream>

using namespace std;

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

    bool search(const T &element) {
        search(element, root);
    }

    bool search(const T &element, Node<T> *parent){

        if(parent == nullptr) {
            return false;
        }
        if (element > parent->data){
            return search(element, parent->right);
        }

        if (element < parent->data){
            return search(element, parent->left);
        }

        return true;

    };
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
