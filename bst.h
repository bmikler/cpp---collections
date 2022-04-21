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
    ~BST(){

    };
    void add(const T &element){

        Node<T> *newNode = new Node(element);

        if (root == nullptr){
            root = newNode;
        } else {
            appendChild(root, newNode);
        }

    };
    void remove(const T &element){

        Node<T> *parent = findParent(element, root, root);
        Node<T> *nodeToRemove;
        bool left = false;
        bool right = false;

        if (parent->left->data == element) {
            nodeToRemove = parent->left;
            left = true;
        } else {
            nodeToRemove = parent->right;
            right = true;
        }

        // both children null
        if (nodeToRemove->left == nullptr | nodeToRemove->right == nullptr){

            Node<T> *nodeToRemoveChild;

            if (nodeToRemove->left != nullptr) {
                nodeToRemoveChild = nodeToRemove->left;
            } else {
                nodeToRemoveChild = nodeToRemove ->right;
            }

            if (left) {
                parent->left = nodeToRemoveChild;
            }

            if (right) {
                parent->right = nodeToRemoveChild;
            }

        }

        //one child null one not null


        //both children not null

       delete nodeToRemove;

    };

    bool contains(const T &element) {
        return search(element, root) != nullptr;
    };


    void print(){
        printChildren(root, "");

    };
//private:
    Node<T> *root;

    Node<T> * findParent(const T &element, Node<T> *node, Node<T> *parent) {

        if (node == nullptr) {
            return nullptr;
        }

        else if (node->data == element) {
            return parent;
        }

        else if (node->data < element) {
            return findParent(element, node->right, node);
        }

        else if (node->data > element) {
            return findParent(element, node->left, node);
        }


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

    void printChildren(Node<T> *parent, string space){

        //├── └── │

        if (parent != nullptr) {

            cout << parent->data;
            cout << endl;

            string pointer = "└──";


            if (parent->right != nullptr) {
                if (parent->left != nullptr) {
                    pointer = "├──";
                }

                cout << space + pointer;
                printChildren(parent->right, space + "   ");

            }

            if (parent->left != nullptr) {
                cout << space + "└──";;
                printChildren(parent->left, space + "   ");
            }

        }

    }

};
