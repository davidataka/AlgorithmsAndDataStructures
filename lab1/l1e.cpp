#include <iostream>

using namespace std;

int main() {
    freopen("sortland.in", "r", stdin);
    freopen("sortland.out", "w", stdout);
    int n;
    cin >> n;
    float M[n];
    for (int i = 0; i < n; i++) {
        cin >> M[i];
    }
    int number[n];
    for (int i = 0; i < n; i++) {
        number[i] = i + 1;
    }
    for (int i = 0; i < (n - 1); i++) {
        for (int j = 0; j < (n - 1); j++) {
            if (M[j + 1] < M[j]) {
                swap(M[j + 1], M[j]);
                swap(number[j + 1], number[j]);
            }
        }
    }
    cout << number[0] << " " << number[n / 2] << " " << number[n - 1];
    return 0;
}
