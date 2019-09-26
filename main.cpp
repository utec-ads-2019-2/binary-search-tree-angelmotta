#include <iostream>
#include "tester/tester.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "===========================================================" << endl;
    cout << "Binary Search Tree Practice" << endl;
    cout << "===========================================================" << endl << endl;

    Tester::execute();
    BSTree<int> binarySearchTree;
    cout << "size: " << binarySearchTree.size() << '\n';
    binarySearchTree.insert(8);
    cout << "size: " << binarySearchTree.size() << '\n';
    binarySearchTree.insert(3);
    cout << "size: " << binarySearchTree.size() << '\n';
    binarySearchTree.insert(10);
    cout << "size: " << binarySearchTree.size() << '\n';
    binarySearchTree.insert(1);
    cout << "size: " << binarySearchTree.size() << '\n';
    binarySearchTree.insert(6);
    cout << "size: " << binarySearchTree.size() << '\n';
    binarySearchTree.insert(4);
    cout << "size: " << binarySearchTree.size() << '\n';
    binarySearchTree.insert(7);
    cout << "size: " << binarySearchTree.size() << '\n';
    binarySearchTree.insert(14);
    cout << "size: " << binarySearchTree.size() << '\n';
    binarySearchTree.insert(13);
    cout << "size: " << binarySearchTree.size() << '\n';
    binarySearchTree.traversePostOrder();
    binarySearchTree.traverseInOrder();
    binarySearchTree.traversePreOrder();
    cout << "size: " << binarySearchTree.size() << '\n';
    cout << "height: " << binarySearchTree.height() << '\n';
    cout << "find: " << binarySearchTree.find(13) << '\n';
    binarySearchTree.remove(13); // case 1: a leaf
    cout << "size: " << binarySearchTree.size() << '\n';
    binarySearchTree.remove(14); // case 2: one child
    cout << "size: " << binarySearchTree.size() << '\n';
    binarySearchTree.remove(6); // case 3: two child
    cout << "size: " << binarySearchTree.size() << '\n';
    binarySearchTree.remove(8); // case 3: two child
    binarySearchTree.traverseInOrder();
    cout << "size: " << binarySearchTree.size() << '\n';
    cout << "root: ";
    binarySearchTree.print_root();
    cout << '\n';
    cout << "-- Iterators --" << '\n';
    Iterator<int> itr = binarySearchTree.begin();
    cout << (*itr) << '\n';
    for (auto it = binarySearchTree.begin(); it != binarySearchTree.end(); ++it) {
        cout << *it << ' ';
    }
    return EXIT_SUCCESS;
}
