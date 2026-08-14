<<<<<<< HEAD
#include <iostream>
#include <utility>   // for std::swap
using namespace std;

// ---------------------------------------------------------
// The heap class we built together, step by step.
// ---------------------------------------------------------
template <typename E, typename Comp>
class heap {
private:
    E* Heap;
    int n;
    int maxsize;

    void siftdown(int pos);

public:
    // Wraps an already-allocated array `h` of capacity `max`,
    // currently holding `num` real elements (num can be 0).
    heap(E* h, int num, int max) : Heap(h), n(num), maxsize(max) {
        buildHeap();
    }

    int leftchild(int pos) const  { return 2*pos + 1; }
    int rightchild(int pos) const { return 2*pos + 2; }
    int parent(int pos) const     { return (pos - 1) / 2; }
    bool isLeaf(int pos) const    { return (pos >= n/2) && (pos < n); }

    void buildHeap();
    bool insert(const E& elem);
    bool removefirst(E& it);
    int size() const { return n; }
};

// -----------------------------------------------------------------
// siftdown: fix ONE broken node moving DOWN (children already valid)
// -----------------------------------------------------------------
template <typename E, typename Comp>
void heap<E,Comp>::siftdown(int pos) {
    while (!isLeaf(pos)) {
        int j = leftchild(pos);
        if ((j+1 < n) && Comp::prior(Heap[j+1], Heap[j]))
            j = j+1;                       // right child is the "winner" instead
        if (Comp::prior(Heap[pos], Heap[j]))
            return;                        // already valid here, stop
        std::swap(Heap[pos], Heap[j]);
        pos = j;
    }
}

// -----------------------------------------------------------------
// buildHeap: siftdown from the LAST non-leaf up to the root -> O(n)
// -----------------------------------------------------------------
template <typename E, typename Comp>
void heap<E,Comp>::buildHeap() {
    for (int i = n/2 - 1; i >= 0; i--)
        siftdown(i);
}

// -----------------------------------------------------------------
// insert: place at the end, then sift UP toward the root
// -----------------------------------------------------------------
template <typename E, typename Comp>
bool heap<E,Comp>::insert(const E& elem) {
    if (n >= maxsize) return false;

    int curr = n++;
    Heap[curr] = elem;

    while ((curr != 0) && Comp::prior(Heap[curr], Heap[parent(curr)])) {
        std::swap(Heap[curr], Heap[parent(curr)]);
        curr = parent(curr);
    }
    return true;
}

// -----------------------------------------------------------------
// removefirst: swap root with last, shrink n, siftdown the new root
// -----------------------------------------------------------------
template <typename E, typename Comp>
bool heap<E,Comp>::removefirst(E& it) {
    if (n == 0) return false;
    std::swap(Heap[0], Heap[n-1]);
    n--;
    if (n != 0) siftdown(0);
    it = Heap[n];
    return true;
}

// ---------------------------------------------------------
// The Comp "policy" struct: this is what YOU write to choose
// max-heap vs min-heap behavior, without touching heap code.
// It just needs one static function: prior(a, b) ->
//   "is a MORE important than b?"
// ---------------------------------------------------------
template <typename E>
struct Max {
    static bool prior(E a, E b) { return a > b; }
};

template <typename E>
struct Min {
    static bool prior(E a, E b) { return a < b; }
};

// ---------------------------------------------------------
// main(): try inserting, removing, watch the array change
// ---------------------------------------------------------
int main() {
    const int MAXSIZE = 20;
    int arr[MAXSIZE];       // raw array the heap will manage
    int count = 0;          // starts empty

    heap<int, Max<int>> h(arr, count, MAXSIZE);

    int values[] = {3, 1, 6, 5, 2, 4, 7, 9, 0, 8};
    for (int v : values) {
        h.insert(v);
        cout << "inserted " << v << " -> array now: ";
        for (int i = 0; i < h.size(); i++) cout << arr[i] << " ";
        cout << "\n";
    }

    cout << "\nRemoving elements in priority order:\n";
    int out;
    while (h.removefirst(out)) {
        cout << "removed " << out << " -> array now: ";
        for (int i = 0; i < h.size(); i++) cout << arr[i] << " ";
        cout << "\n";
    }

    return 0;
}
=======
#include <iostream>
#include <utility>   // for std::swap
using namespace std;

// ---------------------------------------------------------
// The heap class we built together, step by step.
// ---------------------------------------------------------
template <typename E, typename Comp>
class heap {
private:
    E* Heap;
    int n;
    int maxsize;

    void siftdown(int pos);

public:
    // Wraps an already-allocated array `h` of capacity `max`,
    // currently holding `num` real elements (num can be 0).
    heap(E* h, int num, int max) : Heap(h), n(num), maxsize(max) {
        buildHeap();
    }

    int leftchild(int pos) const  { return 2*pos + 1; }
    int rightchild(int pos) const { return 2*pos + 2; }
    int parent(int pos) const     { return (pos - 1) / 2; }
    bool isLeaf(int pos) const    { return (pos >= n/2) && (pos < n); }

    void buildHeap();
    bool insert(const E& elem);
    bool removefirst(E& it);
    int size() const { return n; }
};

// -----------------------------------------------------------------
// siftdown: fix ONE broken node moving DOWN (children already valid)
// -----------------------------------------------------------------
template <typename E, typename Comp>
void heap<E,Comp>::siftdown(int pos) {
    while (!isLeaf(pos)) {
        int j = leftchild(pos);
        if ((j+1 < n) && Comp::prior(Heap[j+1], Heap[j]))
            j = j+1;                       // right child is the "winner" instead
        if (Comp::prior(Heap[pos], Heap[j]))
            return;                        // already valid here, stop
        std::swap(Heap[pos], Heap[j]);
        pos = j;
    }
}

// -----------------------------------------------------------------
// buildHeap: siftdown from the LAST non-leaf up to the root -> O(n)
// -----------------------------------------------------------------
template <typename E, typename Comp>
void heap<E,Comp>::buildHeap() {
    for (int i = n/2 - 1; i >= 0; i--)
        siftdown(i);
}

// -----------------------------------------------------------------
// insert: place at the end, then sift UP toward the root
// -----------------------------------------------------------------
template <typename E, typename Comp>
bool heap<E,Comp>::insert(const E& elem) {
    if (n >= maxsize) return false;

    int curr = n++;
    Heap[curr] = elem;

    while ((curr != 0) && Comp::prior(Heap[curr], Heap[parent(curr)])) {
        std::swap(Heap[curr], Heap[parent(curr)]);
        curr = parent(curr);
    }
    return true;
}

// -----------------------------------------------------------------
// removefirst: swap root with last, shrink n, siftdown the new root
// -----------------------------------------------------------------
template <typename E, typename Comp>
bool heap<E,Comp>::removefirst(E& it) {
    if (n == 0) return false;
    std::swap(Heap[0], Heap[n-1]);
    n--;
    if (n != 0) siftdown(0);
    it = Heap[n];
    return true;
}

// ---------------------------------------------------------
// The Comp "policy" struct: this is what YOU write to choose
// max-heap vs min-heap behavior, without touching heap code.
// It just needs one static function: prior(a, b) ->
//   "is a MORE important than b?"
// ---------------------------------------------------------
template <typename E>
struct Max {
    static bool prior(E a, E b) { return a > b; }
};

template <typename E>
struct Min {
    static bool prior(E a, E b) { return a < b; }
};

// ---------------------------------------------------------
// main(): try inserting, removing, watch the array change
// ---------------------------------------------------------
int main() {
    const int MAXSIZE = 20;
    int arr[MAXSIZE];       // raw array the heap will manage
    int count = 0;          // starts empty

    heap<int, Max<int>> h(arr, count, MAXSIZE);

    int values[] = {3, 1, 6, 5, 2, 4, 7, 9, 0, 8};
    for (int v : values) {
        h.insert(v);
        cout << "inserted " << v << " -> array now: ";
        for (int i = 0; i < h.size(); i++) cout << arr[i] << " ";
        cout << "\n";
    }

    cout << "\nRemoving elements in priority order:\n";
    int out;
    while (h.removefirst(out)) {
        cout << "removed " << out << " -> array now: ";
        for (int i = 0; i < h.size(); i++) cout << arr[i] << " ";
        cout << "\n";
    }

    return 0;
}
>>>>>>> 92017d6 (Add Bubble Sorting Simple implementation)
