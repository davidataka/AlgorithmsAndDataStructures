#include <iostream>
#include <vector>
 
using namespace std;
 
void radix_sort(vector<string> &data, int length, int count_faze) {
    int counter[26];
    vector<string> data2(data.size());
    for (int current_position = (length - 1); current_position > (length - count_faze - 1); current_position--) {
        for (int i = 0; i < 26; i++)
            counter[i] = 0;
        for (int j = 0; j < data.size(); j++)
            counter[(int) data[j][current_position] - 97]++;
        for (int j = 1; j < 26; j++)
            counter[j] = counter[j] + counter[j - 1];
        for (int j = (data.size() - 1); j > (-1); j--) {
            data2[counter[(int) data[j][current_position] - 97] - 1] = data[j];
            counter[(int) data[j][current_position] - 97]--;
        }
        for (int i = 0; i < data.size(); i++)
            data[i] = data2[i];
    }
}
 
 
int main() {
    freopen("radixsort.in", "r", stdin);
    freopen("radixsort.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> data(n);
    for (int i = 0; i < n; i++)
        cin >> data[i];
    radix_sort(data, m, k);
    for (int i = 0; i < n; i++)
        cout << data[i] << "\n";
    return 0;
}
