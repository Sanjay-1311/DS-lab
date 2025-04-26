#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ---------------- Class Declaration ----------------

class PriorityQueue {
private:
    vector<int> heap;

    void heapifyUp(int index);
    void heapifyDown(int index);
    void deleteMaxInternal();
    void displayInternal();
    void searchInternal(int key);
    void sortHeapInternal();

public:
    void insert(int value);
    void deleteMax();
    void display();
    void search(int key);
    void sortHeap();
};

// ---------------- Main Function ----------------

int main() {
    PriorityQueue pq;
    int choice, value;

    while (true) {
        cout << "\n----- Priority Queue Menu -----\n";
        cout << "1. Insert\n";
        cout << "2. Delete Max\n";
        cout << "3. Display\n";
        cout << "4. Search\n";
        cout << "5. Sort (Heap Sort)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            pq.insert(value);
            break;
        case 2:
            pq.deleteMax();
            break;
        case 3:
            pq.display();
            break;
        case 4:
            cout << "Enter value to search: ";
            cin >> value;
            pq.search(value);
            break;
        case 5:
            pq.sortHeap();
            break;
        case 6:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}

// ---------------- Function Definitions ----------------

// Maintain max-heap property after insertion
void PriorityQueue::heapifyUp(int index) {
    while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
        swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// Maintain max-heap property after deletion
void PriorityQueue::heapifyDown(int index) {
    int size = heap.size();
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;
    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != index) {
        swap(heap[index], heap[largest]);
        heapifyDown(largest);
    }
}

// Insert value into heap
void PriorityQueue::insert(int value) {
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}

// Delete max element (root)
void PriorityQueue::deleteMax() {
    deleteMaxInternal();
}

// Display heap
void PriorityQueue::display() {
    displayInternal();
}

// Search for a key
void PriorityQueue::search(int key) {
    searchInternal(key);
}

// Sort heap using heap sort (non-destructive)
void PriorityQueue::sortHeap() {
    sortHeapInternal();
}

// Actual delete logic
void PriorityQueue::deleteMaxInternal() {
    if (heap.empty()) {
        cout << "Heap is empty.\n";
        return;
    }
    cout << "Deleted max element: " << heap[0] << endl;
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
}

// Actual display logic
void PriorityQueue::displayInternal() {
    if (heap.empty()) {
        cout << "Heap is empty.\n";
        return;
    }
    cout << "Current Heap: ";
    for (int val : heap)
        cout << val << " ";
    cout << endl;
}

// Actual search logic
void PriorityQueue::searchInternal(int key) {
    auto it = find(heap.begin(), heap.end(), key);
    if (it != heap.end()) {
        cout << "Element found at index: " << (it - heap.begin()) << endl;
    } else {
        cout << "Element not found.\n";
    }
}

// Actual sort logic (descending)
void PriorityQueue::sortHeapInternal() {
    if (heap.empty()) {
        cout << "Heap is empty.\n";
        return;
    }

    vector<int> sortedHeap = heap;
    sort(sortedHeap.begin(), sortedHeap.end(), greater<int>());

    cout << "Heap Sorted (Descending): ";
    for (int val : sortedHeap)
        cout << val << " ";
    cout << endl;
}
