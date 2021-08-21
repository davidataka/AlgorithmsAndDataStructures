#include <iostream>
 
using namespace std;
 
int main() {
    freopen("postfix.in", "r", stdin);
    freopen("postfix.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int value_stack[51];
    int head = -1;
    string str;
    while (cin >> str) {
        if (str == "+") {
            value_stack[head - 1] = value_stack[head - 1] + value_stack[head];
            head--;
        } else if (str == "-") {
            value_stack[head - 1] = value_stack[head - 1] - value_stack[head];
            head--;
        } else if (str == "*") {
            value_stack[head - 1] = value_stack[head - 1] * value_stack[head];
            head--;
        } else {
            head++;
            value_stack[head] = stoi(str);
        }
    }
    cout << value_stack[head];
    return 0;
}
