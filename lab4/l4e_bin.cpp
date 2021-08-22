#include <iostream>
 
using namespace std;
 
int binsearch_first(int request, int value[], int n) {
    int left = -1;
    int right = n;
    int middle;
    while ((right - 1) > left) {
        middle = (right + left) / 2;
        if (value[middle] >= request)
            right = middle;
        else left = middle;
    }
    if ((right < n) && (value[right] == request))
        return right + 1;
    else return -1;
}
 
int binsearch_last(int request, int value[], int n) {
    int left = -1;
    int right = n;
    int middle;
    while ((right - 1) > left) {
        middle = (right + left) / 2;
        if (value[middle] > request)
            right = middle;
        else left = middle;
    }
    if ((left > -1) && (value[left] == request))
        return left + 1;
    else return -1;
}
 
int main() {
    freopen("binsearch.in", "r", stdin);
    freopen("binsearch.out", "w", stdout);
    int n, m;
    cin >> n;
    int value[n];
    for (int i = 0; i < n; i++)
        cin >> value[i];
    cin >> m;
    int request;
    for (int i = 0; i < m; i++) {
        cin >> request;
        cout << binsearch_first(request, value, n) << " " << binsearch_last(request, value, n) << "\n";
    }
    return 0;
}
