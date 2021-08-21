#include <iostream>
 
using namespace std;
 
int main() {
    freopen("antiqs.in", "r", stdin);
    freopen("antiqs.out", "w", stdout);
    int n;
    cin >> n;
    int value[n];
    for (int i = 0; i < n; i++)
        value[i] = i + 1;
    for (int i = 1; i < n; i++)
        swap(value[i / 2], value[i]);
    for (int i = 0; i < n; i++)
        cout << value[i] << " ";
}
