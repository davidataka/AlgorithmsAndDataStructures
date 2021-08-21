#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    freopen("stack.in", "r", stdin);
    freopen("stack.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    cin >> m;
    int stack[m];
    int current_head = -1;
    for (int i = 0; i < m; i++) {
        char k;
        cin >> k;
        if (k == '+') {
            current_head++;
            cin >> stack[current_head];
        }
        if (k == '-') {
            cout << stack[current_head] << "\n";
            current_head--;
        }
    }
    return 0;
}
