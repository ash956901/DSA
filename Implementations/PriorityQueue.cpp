#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Min Heap
class PriorityQueue
{

    vector<int> heap;

public:
    void insert(int v)
    {
        heap.push_back(v);
        int i = heap.size() - 1;

        while (i > 0)
        {
            int parent = (i - 1) / 2;
            if (heap[parent] <= heap[i])
                break;
            swap(heap[parent], heap[i]);
            i = parent;
        }
    }

    void heapify(int i)
    {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        int size = heap.size();
        if (left < size && heap[left] < heap[smallest])
        {
            smallest = left;
        }
        if (right < size && heap[right] < heap[smallest])
        {
            smallest = right;
        }

        if (smallest != i)
        {
            swap(heap[smallest], heap[i]);
            heapify(smallest);
        }
    }

    int extractMin()
    {
        int temp = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
        return temp;
    }
};
int main()
{
    PriorityQueue pq;
    pq.insert(5);
    pq.insert(1);
    pq.insert(-10);
    pq.insert(26);
    pq.insert(15);
    pq.insert(35);

    cout << "Minimum element:" << pq.extractMin() << endl;
    cout << "Minimum element:" << pq.extractMin() << endl;
    cout << "Minimum element:" << pq.extractMin() << endl;
    cout << "Minimum element:" << pq.extractMin() << endl;
    cout << "Minimum element:" << pq.extractMin() << endl;

    return 0;
}