#include <iostream>
#include <vector>
 
using namespace std;
 
struct Priorityqueue {
    int number_str;
    int value;
};
 
void decrease_key(vector<Priorityqueue> &data, int position, int key) {
    data[position].value = key;
    while ((position > 0) && (data[position].value < data[(position - 1) / 2].value)) {
        swap(data[position], data[(position - 1) / 2]);
        position = (position - 1) / 2;
    }
}
 
void insert(vector<Priorityqueue> &data, int number_current, int key) {
    data.resize(data.size() + 1);
    data[data.size() - 1].number_str = number_current;
    decrease_key(data, data.size() - 1, key);
}
 
void min_heapify(vector<Priorityqueue> &data, int current) {
    int heap_size = data.size();
    int smallest;
    int left = 2 * current + 1;
    int right = 2 * current + 2;
    if ((left < heap_size) && (data[left].value < data[current].value))
        smallest = left;
    else
        smallest = current;
    if ((right < heap_size) && (data[right].value < data[smallest].value))
        smallest = right;
    if (smallest != current) {
        swap(data[current], data[smallest]);
        min_heapify(data, smallest);
    }
}
 
 
int main() {
    freopen("priorityqueue.in", "r", stdin);
    freopen("priorityqueue.out", "w", stdout);
    vector<Priorityqueue> data(0);
    string str;
    int number_str = 0;
    while (cin >> str) {
        number_str++;
        if (str == "push") {
            int key;
            cin >> key;
            insert(data, number_str, key);
        }
        if (str == "extract-min") {
            if (data.size() > 0) {
                cout << data[0].value << "\n";
                swap(data[0], data[data.size() - 1]);
                data.pop_back();
                min_heapify(data, 0);
            } else
                cout << "*" << "\n";
        }
        if (str == "decrease-key") {
            int x, y;
            cin >> x >> y;
            for (int i = 0; i < data.size(); i++)
                if (data[i].number_str == x) {
                    data[i].value = y;
                    decrease_key(data, i, y);
                }
        }
    }
}
