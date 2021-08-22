#include <iostream>
#include <vector>
 
using namespace std;
 
struct str_label {
    string step;
    string label;
};
 
struct infor {
    unsigned short key;
    infor *next = nullptr;
};
 
class Quack {
private:
    infor *Tail;
    infor *Head;
public:
    Quack() {
        Tail = nullptr;
        Head = nullptr;
    }
 
    void put(unsigned short x) {
        infor *v;
        v = new infor;
        v->key = x;
        if (Head == nullptr) {
            Head = v;
            Tail = v;
        } else {
            Tail->next = v;
            Tail = Tail->next;
        }
    }
 
    int get() {
        unsigned short key;
        infor *del;
        if (Head == nullptr)
            return 0;
        else {
            del = Head;
            if (Head == Tail) {
                key = Head->key;
                Head = nullptr;
                Tail = nullptr;
                delete del;
                return key;
            } else {
                key = Head->key;
                Head = Head->next;
                delete del;
                return key;
            }
        }
    }
};
 
int main() {
    freopen("quack.in", "r", stdin);
    freopen("quack.out", "w", stdout);
    Quack value;
    unsigned short regis[26];
    for (int i = 0; i < 26; i++)
        regis[i] = 0;
    vector<str_label> x(0);
    string str;
    while (cin >> str) {
        str_label y;
        y.step = str;
        if (str[0] == ':') {
            y.label.resize(str.size() - 1);
            for (int i = 1; i < str.size(); i++)
                y.label[i - 1] = str[i];
        } else {
            y.label.resize(0);
            y.label = "";
        }
        x.push_back(y);
    }
    int current = 0;
    while (current < x.size()) {
        switch (x[current].step[0]) {
            case '+':
                value.put((value.get() + value.get()) % 65536);
                break;
            case '-':
                value.put((value.get() - value.get()) % 65536);
                break;
            case '*':
                value.put((value.get() * value.get()) % 65536);
                break;
            case '/': {
                int k = value.get();
                int s = value.get();
                if (s == 0) {
                    value.put(0);
                } else value.put(k / s);
            }
                break;
            case '%': {
                int k = value.get();
                int s = value.get();
                if (s == 0) {
                    value.put(0);
                } else value.put(k % s);
            }
                break;
            case '>':
                regis[x[current].step[1] - 'a'] = value.get();
                break;
            case '<':
                value.put(regis[x[current].step[1] - 'a']);
                break;
            case 'P':
                if (x[current].step == "P")
                    cout << value.get() << "\n";
                else cout << regis[x[current].step[1] - 'a'] << "\n";
                break;
            case 'C':
                if (x[current].step == "C") {
                    unsigned char c((value.get()) % 256);
                    cout << c;
                } else {
                    unsigned char c((regis[x[current].step[1] - 'a']) % 256);
                    cout << c;
                }
                break;
            case ':':
                break;
            case 'J': {
                string v;
                v.resize(x[current].step.size() - 1);
                for (int i = 1; i < x[current].step.size(); i++)
                    v[i - 1] = x[current].step[i];
                for (int i = 0; i < x.size(); i++)
                    if (x[i].label == v) {
                        current = i - 1;
                        break;
                    }
            }
                break;
            case 'Z':
                if (regis[x[current].step[1] - 'a'] == 0) {
                    string v;
                    v.resize(x[current].step.size() - 2);
                    for (int i = 2; i < x[current].step.size(); i++)
                        v[i - 2] = x[current].step[i];
                    for (int i = 0; i < x.size(); i++)
                        if (x[i].label == v) {
                            current = i - 1;
                        }
                }
                break;
            case 'E':
                if (regis[x[current].step[1] - 'a'] == regis[x[current].step[2] - 'a']) {
                    string v;
                    v.resize(x[current].step.size() - 3);
                    for (int i = 3; i < x[current].step.size(); i++)
                        v[i - 3] = x[current].step[i];
                    for (int i = 0; i < x.size(); i++) {
                        if (x[i].label == v)
                            current = i - 1;
                    }
                }
                break;
            case 'G':
                if (regis[x[current].step[1] - 'a'] > regis[x[current].step[2] - 'a']) {
                    string v;
                    v.resize(x[current].step.size() - 3);
                    for (int i = 3; i < x[current].step.size(); i++)
                        v[i - 3] = x[current].step[i];
                    for (int i = 0; i < x.size(); i++)
                        if (x[i].label == v)
                            current = i - 1;
                }
                break;
            case 'Q':
                return 0;
                break;
            default:
                value.put(stoi(x[current].step)%65536);
                break;
        }
        current++;
    }
    return 0;
}
