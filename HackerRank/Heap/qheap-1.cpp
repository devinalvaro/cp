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

    void insert_key(int value)
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

    int extract_min()
    {
        if (heap_size <= 0)
            return INT_MAX;

        if (heap_size == 1) {
            heap_size--;

            return heap[0];
        }

        int root = heap[0];
        heap[0] = heap[heap_size - 1];

        heap_size--;

        min_heapify(0);

        return root;
    }

    void delete_key(int node)
    {
        change_value(node, INT_MIN);

        extract_min();
    }

    void delete_value(int value)
    {
        for (int i = 0; i < heap_size; i++) {
            if (heap[i] == value) {
                delete_key(i);

                break;
            }
        }
    }

    int get_min_element() { return heap[0]; }
};

int main()
{
    ios_base::sync_with_stdio(0);

    int q;
    cin >> q;

    Heap heap(100000);

    while (q--) {
        int c;
        cin >> c;

        if (c == 1) {
            int v;
            cin >> v;

            heap.insert_key(v);
        } else if (c == 2) {
            int v;
            cin >> v;

            heap.delete_value(v);
        } else if (c == 3) {
            cout << heap.get_min_element() << '\n';
        }
    }
}
