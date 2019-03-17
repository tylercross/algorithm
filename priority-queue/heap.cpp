#define INITIAL_HEAP_SIZE 10

#include <limits.h>
#include <iostream>
#include "heap.h"

/*
A BinaryHeap which can take any element except for INT_MIN
*/

// Helper methods to get the indexes of parents and children
int getLeftChildIndex(int index) { return index * 2; }

int getRightChildIndex(int index) { return index * 2 + 1; }

int getParentIndex(int index) { return index / 2; }

BinaryHeap::BinaryHeap() {
	heapSize=INITIAL_HEAP_SIZE;
	heap = new int[heapSize];
	current=1;
	for(int i=0;i<heapSize;++i)
    {
        heap[i]=INT_MIN;

    }

}
void BinaryHeap::percolateUp1(int index) {
	if (index==1) return;
	int temp = heap[index];
	int i=index;
	//heap[0]=temp;//из╠Ь
	for(;temp<heap[i/2];i/=2)
        heap[i]=heap[i/2];
    heap[i]=temp;
    }
void BinaryHeap::percolateUp0(int index) {
	/*int temp = heap[current];
	heap[0]=temp;
	for(;temp<heap[current/2];current/=2)
        heap[current]=heap[current/2];
    heap[current]=temp;*/
    int parentIndex = getParentIndex(index);

	// We have percolated all the way to the top of the tree
	if (parentIndex <= 0) {
		return;
	}

	int parent = heap[parentIndex];
	int current = heap[index];
	// Swap elements if the parent is greater than the current element
	if (parent > current) {
		heap[parentIndex] = current;
		heap[index] = parent;

		percolateUp0(parentIndex);
	}
}
// Insert an element into the heap, and resize the heap array if necessary
bool BinaryHeap::insert(int element) {
	// Resize the heap if we need to
	if (current + 1 == heapSize) {
		if (heapSize * 2 > INT_MAX) {
			return false;
		} else {
			resize();
		}
	}

	// Add the element at the end of the tree
	heap[current] = element;

	// Percolate it up the tree until it's at the correct position
	percolateUp1(current);

	current++;

	return true;
}

// Resizes the heap array to 2 * heapSize
void BinaryHeap::resize() {
	int * oldArr = heap;
	int * newArr = new int[heapSize * 2];

	for (int i = 0; i < heapSize; i++) {
		newArr[i] = oldArr[i];
	}

	heapSize *= 2;
	std::cout<<"resize()"<<std::endl;
	heap = newArr;
}

// Retrieves the current size of our heap array
int BinaryHeap::getHeapSize() {
	return heapSize;
}

// Retrieves the ptr to the heap
int * BinaryHeap::getHeap() {
	return heap;
}

// Returns the size of the heap
int BinaryHeap::getSize() {
	return current - 1;
}

// Deletes the minimum element from the heap and returns it
int BinaryHeap::deleteMin() {
	if (getSize() == 0) {
		return INT_MIN;
	}

	int min = heap[1];
	heap[1] = heap[--current];

	// Set the last element to null, because we've moved it to the root of the "tree"
	heap[current] = INT_MIN;
	percolateDown1(1);
	return min;
}
void BinaryHeap::percolateDown0(int index) {
    int parent = heap[index];

	int leftChildIndex = getLeftChildIndex(index);
	int rightChildIndex = getRightChildIndex(index);

	// Set left/right children to INT_MIN if their index is out of bounds
	int leftChild = leftChildIndex < current ? heap[leftChildIndex] : INT_MIN;
	int rightChild = rightChildIndex < current ? heap[rightChildIndex] : INT_MIN;

	// If the parent is bigger, swap it down
	if (parent > leftChild && leftChild < rightChild && leftChild != INT_MIN) {
		heap[leftChildIndex] = parent;
		heap[index] = leftChild;
		percolateDown0(leftChildIndex);
		return;
	}

	if (parent > rightChild && rightChild <= leftChild && rightChild != INT_MIN) {
		heap[rightChildIndex] = parent;
		heap[index] = rightChild;
		percolateDown0(rightChildIndex);
		return;
	}
}

// Percolate an element down to the bottom of the tree, switching with the smallest child it is greater than
void BinaryHeap::percolateDown1(int index) {
  //   std::cout<<"using down1"<<std::endl;

    int parent,child;
    int temp =heap[index];
    for(parent=1;parent*2<heapSize; parent=child)
    {
        child = parent*2;
        if(child!=heapSize&&heap[child+1]<heap[child])
        child++;
        if(temp<parent||heap[child]==INT_MIN) break;
        else heap[parent]=heap[child];


    }
    heap[parent]=temp;

}

// Percolate an element up the tree until it is in the proper location, switching only with elements that are larger than it


// Sorts the array which is passed in by inserting it into the heap and then removing elements and replacing them in the array
void BinaryHeap::sort(int * array, int arraySize) {

}
void BinaryHeap::print()
{
    for(int i=0;i<heapSize;i++)
        std::cout<<heap[i]<<" ";
    std::cout<<std::endl;


}
