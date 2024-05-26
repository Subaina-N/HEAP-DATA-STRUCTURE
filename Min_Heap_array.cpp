// min using array
# include <iostream>
#include <cmath>
using namespace std;
// using array
class Heap {
private:
	int* arr;
	int capacity;
	int Size;
	int left(int a) { return 2 * a + 1; }
	int right(int a) { return 2 * a + 2; }
	int parent(int a) { return (a - 1) / 2; }
	void swap(int& f, int& t) {
		int temp = f;
		f = t;
		t = temp;
	}



	void heapify(int i) {
		int smallest = i;
		int l = left(i);
		int r = right(i);
		// if left child is small
		if (l<Size && arr[l] <arr[smallest]) {
			smallest = l;
		}
		// right larger
		if (r<Size && arr[r] < arr[smallest]) {
			smallest = r;
		}
		// swap if needed
		if (smallest != i) {
			swap(arr[i], arr[smallest]);
			heapify(smallest);
		}


	}

public:
	Heap(int capa) {
		capacity = capa;
		Size = 0;
		arr = new int[capa];
	}
	bool isEmpty() { return Size = 0; }
	void insert(int data) {
		if (Size == capacity) {
			cout << "Overflow";
			return;
		}
		arr[Size] = data;
		Size++;
		int i = Size - 1;
		// to maintain property
		while (i > 0 && arr[parent(i)] > arr[i]) {
			swap(arr[i], arr[parent(i)]);
			i = parent(i);
		}
	}
	int extractRoot() {
		if (isEmpty()) { cout << "Overflow"; return -1; }
		int root = arr[0];
		//replace with last element
		arr[0] = arr[Size - 1];
		Size--;
		heapify(0);
		return root;
	}
	void displayHeap() {
		int level = 0;
		int i = 0; 

		while (i < Size) {
			
			for (int j = 0; j < pow(2, level) && i < Size; j++) { // Print elements at current level
				cout << arr[i] << " ";
				i++;
			}
			level++;
			cout << endl;
		}
	}
};
int main() {
	Heap heap(11);
	heap.insert(3);
	
	heap.insert(4);
	heap.insert(45);
	heap.displayHeap();
	cout << "ROOT: " << heap.extractRoot() << endl;
	return 0;

}