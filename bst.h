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
        clear(root);
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

        if (parent->data == element){
            nodeToRemove = root;
        }

        else if (parent->left->data == element) {
            nodeToRemove = parent->left;
        } else {
            nodeToRemove = parent->right;
        }

        if (nodeToRemove->left == nullptr || nodeToRemove->right == nullptr){

            removeNodeWithOneChild(nodeToRemove, parent);
            delete nodeToRemove;
        }
        if (nodeToRemove->left != nullptr && nodeToRemove->right != nullptr) {

            Node<T> *lowestValue = findLowestValueInBranch(nodeToRemove->right);
            Node<T> *lowestValueParent = findParent(lowestValue->data, root, root);
            nodeToRemove->data = lowestValue->data;

            removeNodeWithOneChild(lowestValue, lowestValueParent);
            delete lowestValue;
        }
    };

    bool contains(const T &element) {
        return search(element, root) != nullptr;
    };


    void print(){
        printChildren(root, "");

    };
//private:
    Node<T> *root;

    void clear(Node<T> * node) {
        if (node->left != nullptr) {
            clear(node->left);
        }

        if (node->right != nullptr) {
            clear(node->right);
        }
        delete node;
    }

    void removeNodeWithOneChild(Node<T> *nodeToRemove, Node<T> *parent){
        Node<T> *nodeToRemoveChild;

        if (nodeToRemove->left != nullptr) {
            nodeToRemoveChild = nodeToRemove->left;
        } else {
            nodeToRemoveChild = nodeToRemove ->right;
        }

        if (parent->left->data == nodeToRemove->data) {
            parent->left = nodeToRemoveChild;
        } else {
            parent->right = nodeToRemoveChild;
        }
    };


    Node<T> *findLowestValueInBranch(Node<T> *node) {

        if (node->left == nullptr){
            return node;
        } else  {
            return findLowestValueInBranch(node->left);
        }
    }

    Node<T> *findParent(const T &element, Node<T> *node, Node<T> *parent) {

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
