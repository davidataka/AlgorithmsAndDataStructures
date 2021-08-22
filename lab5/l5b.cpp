#include <iostream>
 
using namespace std;
 
struct info {
    int key;
    int left = -1;
    int right = -1;
    int parent = -1;
};
 
int check(info data[], int i, int min, int max) {
    if ((data[i].key < max) && (data[i].key > min)) {
        if (data[i].left > -1)
            if (check(data, data[i].left, min, data[i].key) == 0)
                return 0;
        if (data[i].right > -1)
            if (check(data, data[i].right, data[i].key, max) == 0)
                return 0;
        return 1;
    } else return 0;
}
 
int main() {
    freopen("check.in", "r", stdin);
    freopen("check.out", "w", stdout);
    int n;
    cin >> n;
    info data[n];
    int key, left, right;
    for (int i = 0; i < n; i++) {
        cin >> key >> left >> right;
        data[i].key = key;
        if (left > 0) {
            data[i].left = left - 1;
            data[left - 1].parent = i;
        }
        if (right > 0) {
            data[i].right = right - 1;
            data[right - 1].parent = i;
        }
    }
    for (int i = 0; i < n; i++)
        if (data[i].parent == -1) {
            if (check(data, i, -1000000001, 1000000001) == 1)
                cout << "YES";
            else cout << "NO";
        }
    if (n == 0)
        cout << "YES";
    return 0;
}
