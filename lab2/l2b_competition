#include <iostream>
 
using namespace std;
 
void merge(string data[][2], int left, int middle, int right) {
    int size1 = middle - left + 1;
    int size2 = right - middle;
    string left_part[size1][2];
    string right_part[size2][2];
    for (int i = 0; i < size1; i++)
        for (int j = 0; j < 2; j++)
            left_part[i][j] = data[i + left][j];
    for (int i = 0; i < size2; i++)
        for (int j = 0; j < 2; j++)
            right_part[i][j] = data[i + middle + 1][j];
    int i = 0;
    int j = 0;
    int k = left;
    while ((i < size1) && (j < size2)) {
        if (left_part[i][0] <= right_part[j][0]) {
            data[k][0] = left_part[i][0];
            data[k][1] = left_part[i][1];
            i++;
        } else {
            data[k][0] = right_part[j][0];
            data[k][1] = right_part[j][1];
            j++;
        }
        k++;
    }
    while (i < size1) {
        data[k][0] = left_part[i][0];
        data[k][1] = left_part[i][1];
        i++;
        k++;
    }
    while (j < size2) {
        data[k][0] = right_part[j][0];
        data[k][1] = right_part[j][1];
        j++;
        k++;
    }
 
}
 
void mergesort(string data[][2], int left, int right) {
    if (left < right) {
        int middle = (right + left) / 2;
        mergesort(data, left, middle);
        mergesort(data, middle + 1, right);
        merge(data, left, middle, right);
    }
}
 
int main() {
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    int n;
    cin >> n;
    string data[n][2];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            cin >> data[i][j];
    mergesort(data, 0, n - 1);
    cout << "=== " << data[0][0] << " ===" << "\n" << data[0][1] << "\n";
    for (int k = 1; k < n; k++) {
        if ((k > 0) && (data[k][0] != data[k - 1][0]))
            cout << "=== " << data[k][0] << " ===" << "\n";
        cout << data[k][1] << "\n";
    }
    return 0;
}
