#include <bits/stdc++.h>

using namespace std;

class Heap
{
private:
    vector<double> heap;
    int heap_capacity;
    int heap_size;
    bool is_min_heap;

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

    void max_heapify(int parent)
    {
        int l = left_child(parent);
        int r = right_child(parent);

        int largest = parent;
        if (l < heap_size && heap[l] > heap[largest])
            largest = l;
        if (r < heap_size && heap[r] > heap[largest])
            largest = r;

        if (largest != parent) {
            int temp = heap[largest];
            heap[largest] = heap[parent];
            heap[parent] = temp;

            max_heapify(largest);
        }
    }

public:
    Heap(int _heap_capacity, bool _is_min_heap)
    {
        heap_capacity = _heap_capacity;
        heap_size = 0;

        heap.assign(heap_capacity, 0);

        is_min_heap = _is_min_heap;
    }

    void insert_value(int value)
    {
        if (heap_size == heap_capacity)
            return;

        heap_size++;

        int node = heap_size - 1;
        heap[node] = value;

        while (node != 0 && (is_min_heap ? heap[parent(node)] > heap[node]
                                         : heap[parent(node)] < heap[node])) {
            int temp = heap[parent(node)];
            heap[parent(node)] = heap[node];
            heap[node] = temp;

            node = parent(node);
        }
    }

    void change_value(int node, int new_value)
    {
        heap[node] = new_value;

        while (node != 0 && (is_min_heap ? heap[parent(node)] > heap[node]
                                         : heap[parent(node)] < heap[node])) {
            int temp = heap[parent(node)];
            heap[parent(node)] = heap[node];
            heap[node] = temp;

            node = parent(node);
        }
    }

    int extract_root()
    {
        if (heap_size <= 0)
            return (is_min_heap ? INT_MAX : INT_MIN);

        int root = heap[0];
        heap[0] = heap[heap_size - 1];

        heap_size--;

        if (is_min_heap) {
            min_heapify(0);
        } else {
            max_heapify(0);
        }

        return root;
    }

    void delete_key(int node)
    {
        change_value(node, (is_min_heap ? INT_MIN : INT_MAX));

        extract_root();
    }

    double get_root_element() { return heap[0]; }

    int get_heap_size() { return heap_size; }
};

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    Heap min_heap(n, true), max_heap(n, false);

    while (n--) {
        double a;
        cin >> a;

        if (a < max_heap.get_root_element()) {
            max_heap.insert_value(a);
        } else {
            min_heap.insert_value(a);
        }

        if (min_heap.get_heap_size() > max_heap.get_heap_size() + 1) {
            int root = min_heap.extract_root();
            max_heap.insert_value(root);
        } else if (min_heap.get_heap_size() + 1 < max_heap.get_heap_size()) {
            int root = max_heap.extract_root();
            min_heap.insert_value(root);
        }

        cout << fixed << setprecision(1);
        if (min_heap.get_heap_size() == max_heap.get_heap_size()) {
            cout << (min_heap.get_root_element() +
                     max_heap.get_root_element()) /
                        2;
        } else if (min_heap.get_heap_size() > max_heap.get_heap_size()) {
            cout << min_heap.get_root_element();
        } else if (min_heap.get_heap_size() < max_heap.get_heap_size()) {
            cout << max_heap.get_root_element();
        }
        cout << '\n';
    }
}
