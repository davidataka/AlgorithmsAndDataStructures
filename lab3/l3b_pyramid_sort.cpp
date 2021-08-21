#include <iostream>
#include <vector>
 
using namespace std;
 
int heap_size;
 
void max_heapify(vector<int> &value, int current) {
    int largest;
    int left = 2 * current + 1;
    int right = 2 * current + 2;
    if ((left < heap_size) && (value[left] > value[current]))
        largest = left;
    else
        largest = current;
    if ((right < heap_size) && (value[right] > value[largest]))
        largest = right;
    if (largest != current) {
        swap(value[current], value[largest]);
        max_heapify(value, largest);
    }
}
 
void build_max_heap(vector<int> &value) {
    heap_size = value.size();
    for (int i = (value.size() - 1) / 2; i >= 0; i--)
        max_heapify(value, i);
}
 
void heap_sort(vector<int> &value) {
    build_max_heap(value);
    for (int i = (value.size() - 1); i > 0; i--) {
        swap(value[i], value[0]);
        heap_size = i;
        max_heapify(value, 0);
    }
}
 
int main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> value(n);
    for (int i = 0; i < n; i++)
        cin >> value[i];
    heap_sort(value);
    for (int i = 0; i < n; i++)
        cout << value[i] << " ";
}
