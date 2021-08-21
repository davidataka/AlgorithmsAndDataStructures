#include <iostream>
 
using namespace std;
 
int main() {
    freopen("queue.in", "r", stdin);
    freopen("queue.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    cin >> m;
    int queue[m];
    int current_head = 0;
    int current_tail = -1;
    for (int i = 0; i < m; i++) {
        char k;
        cin >> k;
        if (k == '+') {
            current_tail++;
            cin >> queue[current_tail];
        }
        if (k == '-') {
            cout << queue[current_head] << "\n";
            current_head++;
        }
    }
    return 0;
}
