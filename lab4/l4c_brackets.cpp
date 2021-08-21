#include <iostream>
 
using namespace std;
 
int main() {
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char brkt_stack[1000];
    int head = -1;
    string str;
    while (cin >> str) {
        for (int i = 0; i < str.length(); i++) {
            if ((str[i] == '(') || (str[i] == '[')) {
                head++;
                brkt_stack[head] = str[i];
            } else if ((head != -1) &&
                       (((str[i] == ')') && (brkt_stack[head] == '(')) ||
                        ((str[i] == ']') && (brkt_stack[head] == '['))))
                head--;
            else{
                head++;
                break;
            }
        }
        if(head==-1)
            cout<<"YES"<<"\n";
        else {
            cout << "NO" << "\n";
            head=-1;
        }
    }
    return 0;
}
