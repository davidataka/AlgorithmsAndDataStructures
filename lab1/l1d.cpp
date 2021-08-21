#include <iostream>

using namespace std;

int main() {
    freopen("smallsort.in", "r", stdin);
    freopen("smallsort.out", "w", stdout);
    int n;
    cin >> n;
    int value[n];
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }
    for (int i = 0; i < (n - 1); i++) {
        for (int j = 0; j < (n - 1); j++) {
            if (value[j + 1] < value[j]) {
                swap(value[j + 1], value[j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << value[i] << " ";
    }
}
