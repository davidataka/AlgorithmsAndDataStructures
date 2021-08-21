#include <iostream>

using namespace std;

long long int count_inversions = 0;

void merge_inversions(int value[], int left, int middle, int right) {
    int size1 = middle - left + 1;
    int size2 = right - middle;
    int left_part[size1];
    int right_part[size2];
    for (int i = 0; i < size1; i++)
        left_part[i] = value[i + left];
    for (int i = 0; i < size2; i++)
        right_part[i] = value[i + middle + 1];
    int i = 0;
    int j = 0;
    int k = left;
    while ((i < size1) && (j < size2)) {
        if (left_part[i] <= right_part[j]) {
            value[k] = left_part[i];
            i++;
        } else {
            value[k] = right_part[j];
            j++;
            count_inversions += middle - left + 1 - i;
        }
        k++;
    }
    while (i < size1) {
        value[k] = left_part[i];
        i++;
        k++;
    }
    while (j < size2) {
        value[k] = right_part[j];
        j++;
        k++;
    }

}

void mergesort(int value[], int left, int right) {
    if (left < right) {
        int middle = (right + left) / 2;
        mergesort(value, left, middle);
        mergesort(value, middle + 1, right);
        merge_inversions(value, left, middle, right);
    }
}

int main() {
    freopen("inversions.in", "r", stdin);
    freopen("inversions.out", "w", stdout);
    int n;
    cin >> n;
    int value[n];
    for (int i = 0; i < n; i++)
        cin >> value[i];
    mergesort(value, 0, n - 1);
    cout << count_inversions;
    return 0;
}
