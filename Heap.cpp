#include <bits/stdc++.h>
using namespace std;

class Heap {
private:
    int array[100005];
    int size;

public:
    Heap() {
        array[0] = -1;
        size = 0;
    }

    void Insert(int value) {
        size = size + 1;
        int index = size;
        array[index] = value;
        while (index > 1) {
            int parent = index / 2;
            if (array[parent] > array[index]) {
                swap(array[parent], array[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    void Delete() {
        if (size == 0) {
            cout << "Heap Is Empty";
        }
        size = size - 1;
    }

    void Print() {
        for (int i = 1; i <= size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int size, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= size && arr[left] > arr[largest])
        largest = left;
    if (right <= size && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}

void heapsort(int array[], int size) {
    for (int i = size / 2; i >= 1; i--) {
        heapify(array, size, i);
    }
    while (size > 1) {
        swap(array[size], array[1]); 
        size--;
        heapify(array, size, 1);
    }
}
