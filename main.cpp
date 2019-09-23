#include <iostream>
#include "tester/tester.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "===========================================================" << endl;
    cout << "Binary Search Tree Practice" << endl;
    cout << "===========================================================" << endl << endl;

    Tester::execute();

    /*BSTree<int> binarySearchTree;
    binarySearchTree.insert(8);
    binarySearchTree.insert(3);
    binarySearchTree.insert(10);
    binarySearchTree.insert(1);
    binarySearchTree.insert(6);
    binarySearchTree.insert(4);
    binarySearchTree.insert(7);
    binarySearchTree.insert(14);
    binarySearchTree.insert(13);
    binarySearchTree.traversePostOrder();
    binarySearchTree.traverseInOrder();
    binarySearchTree.traversePreOrder();
    cout << "size: " << binarySearchTree.size() << '\n';
    cout << "height: " << binarySearchTree.height() << '\n';
    cout << "find: " << binarySearchTree.find(13) << '\n';
    //binarySearchTree.remove(13); // case 1: a leaf
    //binarySearchTree.remove(14); // case 2: one child
    //binarySearchTree.remove(6); // case 3: two child
    binarySearchTree.remove(8); // case 3: two child
    binarySearchTree.traverseInOrder();
    cout << "size: " << binarySearchTree.size() << '\n';
    cout << "root: ";
    binarySearchTree.print_root();*/
    return EXIT_SUCCESS;
}
