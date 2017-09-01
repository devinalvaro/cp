#include <bits/stdc++.h>

using namespace std;

class Heap
{
private:
    vector<int> heap;
    int heap_capacity;
    int heap_size;

    int parent(int parent) { return (parent - 1) / 2; }

    int left_child(int parent) { return (parent << 1) + 1; }

    int right_child(int parent) { return (parent << 1) + 2; }

    void min_heapify(int parent)
    {
        int l = left_child(parent);
        int r = right_child(parent);

        int smallest = parent;
        if (l < heap_size && heap[l] < heap[parent])
            smallest = l;
        if (r < heap_size && heap[r] < heap[smallest])
            smallest = r;

        if (smallest != parent) {
            int temp = heap[smallest];
            heap[smallest] = heap[parent];
            heap[parent] = temp;

            min_heapify(smallest);
        }
    }

public:
    Heap(int _heap_capacity)
    {
        heap_capacity = _heap_capacity;
        heap_size = 0;

        heap.assign(heap_capacity, 0);
    }

    void insert_value(int value)
    {
        if (heap_size == heap_capacity)
            return;

        heap_size++;

        int node = heap_size - 1;
        heap[node] = value;

        while (node != 0 && heap[parent(node)] > heap[node]) {
            int temp = heap[parent(node)];
            heap[parent(node)] = heap[node];
            heap[node] = temp;

            node = parent(node);
        }
    }

    void change_value(int node, int new_value)
    {
        heap[node] = new_value;

        while (node != 0 && heap[parent(node)] > heap[node]) {
            int temp = heap[parent(node)];
            heap[parent(node)] = heap[node];
            heap[node] = temp;

            node = parent(node);
        }
    }

    void extract_min()
    {
        if (heap_size <= 0)
            return;

        heap[0] = heap[heap_size - 1];

        heap_size--;

        min_heapify(0);
    }

    void delete_key(int node)
    {
        change_value(node, INT_MIN);

        extract_min();
    }

    int get_min_element() { return heap[0]; }

    int get_heap_size() { return heap_size; }
};

int main()
{
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    Heap heap(n);

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        heap.insert_value(a);
    }

    int step = 0;
    while (heap.get_min_element() < k) {
        if (heap.get_heap_size() <= 1) {
            cout << -1 << '\n';

            return 0;
        }

        int first_min_element = heap.get_min_element();
        heap.delete_key(0);

        int second_min_element = heap.get_min_element();
        heap.delete_key(0);

        int sweetness = first_min_element + (2 * second_min_element);
        heap.insert_value(sweetness);

        step += 1;
    }
    cout << step << '\n';
}
