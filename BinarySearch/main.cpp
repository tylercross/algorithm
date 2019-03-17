
#include "BinarySearchTree.h"
#include "../heapSort/permutation.h"

int main() {

    std::srand(std::time(0));

    int N = 10;
    int *nodes = Permutation3(N);

    BinarySearchTree<int> bt;

    for (int i = 0; i < N; ++i) {
        bt.insert(nodes[i]);
    }
    std::cout<<"contain 2 is "<<bt.contains(2)<<std::endl;
    bt.printTree();

    delete[] nodes;

    return 0;
}
