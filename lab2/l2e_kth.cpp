#include <iostream>
#include <vector>
 
using namespace std;
 
int k;
 
int partition(vector<int> &value, int left, int right) {
    int key = value[(right + left) / 2];
    int i = left;
    int j = right;
    while (i <= j) {
        while (value[i] < key)
            i++;
        while (value[j] > key)
            j--;
        if (i >= j) {
            break;
        }
        if (i <= j) {
            swap(value[i], value[j]);
            i++;
            j--;
        }
    }
    return j;
}
 
int kth_statistics(vector<int> &value, int left, int right) {
    if (left < right) {
        int position = partition(value, left, right);
        if ((position + 1) >= k)
            kth_statistics(value, left, position);
        else
            kth_statistics(value, position + 1, right);
    } else return value[left];
}
 
int main() {
    freopen("kth.in", "r", stdin);
    freopen("kth.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n >> k;
    int A, B, C, a1, a2;
    cin >> A >> B >> C >> a1 >> a2;
    vector<int> value(n);
    value[0] = a1;
    value[1] = a2;
    for (int i = 2; i < n; i++)
        value[i] = A * value[i - 2] + B * value[i - 1] + C;
    cout << kth_statistics(value, 0, n - 1);
    return 0;
}
