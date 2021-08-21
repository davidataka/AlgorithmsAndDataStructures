#include <iostream>
#include <vector>
 
using namespace std;
 
string is_heap(vector<int> &value) {
    for (int i = 0; i < (value.size() -1) / 2; i++) {
        if((value[2*i+1]<value[i])||(((2*i+2)<=value.size()-1)&&(value[2*i+2]<value[i])))
            return "NO";
    }
    return "YES";
}
 
int main() {
    freopen("isheap.in", "r", stdin);
    freopen("isheap.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> value(n);
    for (int i = 0; i < n; i++)
        cin >> value[i];
    cout<<is_heap(value);
    return 0;
}
