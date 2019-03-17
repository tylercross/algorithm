#ifndef HEAP_H
#define HEAP_H

class BinaryHeap {
	int * heap;
	int heapSize;
	int current;//÷∏œÚholeŒª÷√
public:
	BinaryHeap();

	// Insert an element into the heap, and resize the heap array if necessary
	bool insert(int element);

	// Resizes the heap array to 2 * heapSize
	void resize();

	// Retrieves the current size of our heap array
	int getHeapSize();

	// Retrieves the ptr to the heap
	int * getHeap();

	// Returns the size of the heap
	int getSize();

	// Deletes the minimum element from the heap and returns it
	int deleteMin();

	// Percolate an element down to the bottom of the tree, switching with the smallest child until it's in the correct position
	void percolateDown0(int index);
	void percolateDown1(int index);

	// Percolate an element up the tree until it is in the proper location, switching only with elements that are larger than it
	void percolateUp0(int index);
	void percolateUp1(int index);

	// Sorts the array which is passed in by inserting it into the heap and then removing elements and replacing them in the array
	void sort(int * array, int arraySize);
	void print();
};

#endif
