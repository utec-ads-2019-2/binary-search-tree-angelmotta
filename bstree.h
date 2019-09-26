#ifndef BSTREE_H
#define BSTREE_H

#include "node.h"
#include "iterator.h"

template <typename T>
class BSTree {
    Node<T> *root;
    int nodes;

    bool find_implementation(Node<T>* node, T data){
        if(!node) return false;
        if(node->data == data) return true;
        if(data < node->data){
            return find_implementation(node->left, data);
        }
        else{
            return find_implementation(node->right, data);
        }
    }

    void insert_node(Node<T>** root_temp, T data){
        if(*root_temp == nullptr){
            auto temp_node = new Node<T>(data);
            *root_temp = temp_node;
            this->nodes++;
        }
        else if(data <= (*root_temp)->data){
            auto nextLeft = &(*root_temp)->left;
            insert_node(nextLeft, data);
        }
        else{
            auto nextRight = &(*root_temp)->right;
            insert_node(nextRight, data);
        }
    }

    Node<T>* FindMaxFromLeft(Node<T>* tmp_root){
        cout << "receive as root: " << tmp_root->data << '\n';
        while(tmp_root->right){
            tmp_root = tmp_root->right;
        }
        return tmp_root;
    }

    bool remove_node(Node<T>** root_temp, T data){
        if(!(*root_temp)) return false;    // tree is empty
        else if(data < (*root_temp)->data){
            auto nextLeft = &(*root_temp)->left;
            remove_node(nextLeft, data);
        }
        else if(data > (*root_temp)->data){
            auto nextRight = &(*root_temp)->right;
            remove_node(nextRight, data);
        }
        else{   // I found the number! I will delete the node
            // Case 1: Node is leaf
            if((*root_temp)->left == nullptr && (*root_temp)->right == nullptr){
                cout << "found case 1 \n";
                delete *root_temp;
                *root_temp = nullptr;
                this->nodes--;
                return true;
            }
                // Case 2: One child
            else if((*root_temp)->left == nullptr){     // only a child at right
                cout << "found case 2 - only a child at right \n";
                Node<T> *temp = *root_temp;
                *root_temp = (*root_temp)->right;
                delete temp;   // delete the previous root
                this->nodes--;
                return true;
            }
            else if((*root_temp)->right == nullptr){     // only a child at left
                cout << "found case 2 - only a child at left \n";
                Node<T> *temp = *root_temp;
                *root_temp = (*root_temp)->left;
                delete temp;   // delete the previous root
                this->nodes--;
                return true;
            }
                // Case 3: two children
            else{
                cout << "found case 3\n";
                Node<T> *temp = FindMaxFromLeft((*root_temp)->left);    // find the max from left
                cout << "copy to root: " << temp->data << '\n';
                (*root_temp)->data = temp->data;
                remove_node(&(*root_temp)->left, temp->data);  // This remove is now case 1 or case 2
            }
        }
    }

    size_t height_calculate(Node<T> *node){
        int height_left, height_right;
        if(node == nullptr){
            return -1;
        }
        height_left = height_calculate(node->left)+1;
        height_right = height_calculate(node->right)+1;
        return max(height_left, height_right);
    }

    void print_traversePreOrder(Node<T> *node){
        cout << node->data << " ";
        if(node->left){
            print_traversePreOrder(node->left);
        }
        if(node->right){
            print_traversePreOrder(node->right);
        }
    }

    void print_traverseInOrder(Node<T> *node){
        if(node->left){
            print_traverseInOrder(node->left);
        }
        cout << node->data << " ";
        if(node->right){
            print_traverseInOrder(node->right);
        }
    }

    void print_traversePostOrder(Node<T> *node){
        if(node->left){
            print_traversePostOrder(node->left);
        }
        if(node->right){
            print_traversePostOrder(node->right);
        }
        cout << node->data << " ";
    }

    void clear(Node<T> *node){
        if(node->left){
            clear(node->left);
        }
        if(node->right){
            clear(node->right);
        }
        delete node;
    }

public:
    BSTree() : root(nullptr), nodes(0) {};

    bool find(T data) {
        if(!root) return false;
        return find_implementation(root, data);
    }

    void insert(T data) {
        insert_node(&root, data);
    }

    bool remove(T data) {
        return remove_node(&(this->root), data);
    }

    size_t size() {
        return this->nodes;
    }

    size_t height() {
        if(!root) return 0;
        return height_calculate(root);
    }

    void traversePreOrder() {
        if(!root) return;
        print_traversePreOrder(root);
        cout << '\n';
    }

    void traverseInOrder() {
        if(!root) return;
        print_traverseInOrder(root);
        cout << '\n';
    }

    void traversePostOrder() {
        if(!root) return;
        print_traversePostOrder(root);
        cout << '\n';
    }

    void print_root(){
        cout << root->data;
    }

    Iterator<T> begin() {
        return Iterator<T>(this->root);
    }

    Iterator<T> end() {
        return {};
    }

    ~BSTree() {
        if(root) clear(this->root);
    }
};

#endif
