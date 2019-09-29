#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include <vector>
#include <stack>

template <typename T> 
class Iterator {
    private:
        Node<T> *current;
        std::stack<Node<T>*, std::vector<Node<T>*>> prevNodes;
        std::stack<Node<T>*, std::vector<Node<T>*>> memNodes;

        Node<T>* nextNode(Node<T>* initPosition) {
            if (initPosition->left) {
                prevNodes.push(initPosition);
                return nextNode(initPosition->left);
            } else {
                return initPosition;
            }
        }
    public:
    Iterator(): current(nullptr) {
        prevNodes.push(nullptr);
    }

    Iterator(Node<T> *node): current(node) {
        prevNodes.push(nullptr);
        if (this->current && this->current->left) {
            ++*this;
        }
        memNodes.push(this->current);
    }

    Iterator<T>& operator=(const Iterator<T> &other) {
        this->current = other;
        return *this;
    }

    bool operator!=(Iterator<T> other) {
        return this->current != other.current;
    }

    Iterator<T>& operator++() {
        if (this->current->left && prevNodes.top() != this->current) {
            prevNodes.push(this->current);
            this->current = nextNode(this->current->left);
        } else {
            if (this->current == prevNodes.top()) {
                prevNodes.pop();
            }
            if (this->current->right) {
                this->current = nextNode(this->current->right);
            } else {
                this->current = prevNodes.top();
            }
        }
        memNodes.push(this->current);
        return *this;
    }

    Iterator<T>& operator--() {
        memNodes.pop();
        this->current = memNodes.top();
        return *this;
    }

    T operator*() {
        // Caso vacío?
        return this->current->data;
    }
};

#endif
