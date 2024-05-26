// MAx using array
#include <iostream>
#include<cmath>
using namespace std;
class Heap {
private:
	int* arr;
	int capacity;
	int size;
	int left(int a) { return 2 * a + 1; }
	int right(int a) { return 2 * a + 2; }
	int parent(int a) { return (a-1) / 2; }
	void swap(int &b, int &c) {
		int temp = b;
		b = c;
		c = temp;
	}
	void heapify(int i) {
    int largest = i;
    int l = left(i);
    int r = right(i);
    if (l < size && arr[l] > arr[largest]) { 
        largest = l;
    }
    if (r < size && arr[r] > arr[largest]) { 
        largest = r;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(largest);
    }
}

public:
	Heap(int capa) {
		capacity = capa;
		size = 0;
		arr = new int(capa);
	}
	bool isEMpty(){return size==0;}
	void insert(int data) {
		if (size==capacity) {
			cout << "Everflow.....";
			return;
		}
		arr[size] = data;
		size++;
		int i = size - 1;
		while (i > 0 && arr[parent(i)] < arr[i]) {
			swap(arr[i], arr[parent(i)]);
			i = parent(i);
		}
	}
	int root() {
		
			if (isEMpty()) {
				cout << "Everflow.....";
				return -1;
			}
			int root = arr[0];
			arr[0] = arr[size - 1];
			size--;
			heapify(0);
			return root;
	}
	void display() {
		int level = 0;
		int i = 0;
		while (i <size) {
			for (int j = 0; j < pow(2, level) && i < size; j++) {
				cout << arr[i] << " ";
				i++;
			}
				cout << endl;
		level++;
		}
	
		


	}
};
int main() {
	Heap h(10);
	h.insert(10);
	h.insert(30);
	h.insert(89);

	h.display();
	cout<<"ROOT: "<<h.root();
	return 0;

}