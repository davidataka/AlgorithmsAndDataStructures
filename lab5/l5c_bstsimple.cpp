#include <iostream>
 
using namespace std;
 
struct info {
    int key;
    info *left = nullptr;
    info *right = nullptr;
    info *parent = nullptr;
};
 
class tree {
private:
    info *root;
public:
    tree() { root = nullptr; }
 
    void insert(long int x) {
        info *v;
        v = new info;
        info *cur = root;
        v->key = x;
        if (root == nullptr) {
            root = v;
        } else {
            while (true) {
                if (cur->key > x) {
                    if (cur->left != nullptr)
                        cur = cur->left;
                    else {
                        cur->left = v;
                        v->parent = cur;
                        break;
                    }
                } else if (cur->key < x) {
                    if (cur->right != nullptr)
                        cur = cur->right;
                    else {
                        cur->right = v;
                        v->parent = cur;
                        break;
                    }
                } else break;
            }
        }
    }
 
    info *exists(long int x) {
        info *cur = root;
        if (root == nullptr)
            return nullptr;
        while (cur->key != x) {
            if (cur->key > x) {
                if (cur->left != nullptr)
                    cur = cur->left;
                else return nullptr;
            } else if (cur->key < x) {
                if (cur->right != nullptr)
                    cur = cur->right;
                else return nullptr;
            }
        }
        return cur;
    }
 
    void del(long int x) {
        info *cur = exists(x);
        if (cur != nullptr) {
            if ((cur->right == nullptr) && (cur->left == nullptr)) {
                if (cur == root)
                    root = nullptr;
                else if (cur == cur->parent->right)
                    cur->parent->right = nullptr;
                else cur->parent->left = nullptr;
                delete cur;
            } else if (cur->left == nullptr) {
                if (root == cur) {
                    root = cur->right;
                } else if (cur->parent->right == cur) {
                    cur->parent->right = cur->right;
                } else {
                    cur->parent->left = cur->right;
                }
                cur->right->parent = cur->parent;
                delete cur;
            } else if (cur->right == nullptr) {
                if (root == cur) {
                    root = cur->left;
                } else if (cur->parent->right == cur) {
                    cur->parent->right = cur->left;
                } else {
                    cur->parent->left = cur->left;
                }
                cur->left->parent = cur->parent;
                delete cur;
            } else {
                info *cur2;
                cur2 = cur->right;
                while (cur2->left != nullptr)
                    cur2 = cur2->left;
                if (cur2->parent->left == cur2)
                    cur2->parent->left = cur2->right;
                else cur2->parent->right = cur2->right;
                if (cur2->right != nullptr)
                    cur2->right->parent = cur2->parent;
                cur->key = cur2->key;
                delete cur2;
            }
 
        }
 
    }
 
    void prev(long int x) {
        info *cur = root;
        long int max = x;
        if (root != nullptr)
            while (true) {
                if ((cur->key < x) && ((cur->key > max) || (max == x)))
                    max = cur->key;
                if ((cur->key >= x)) {
                    if (cur->left != nullptr)
                        cur = cur->left;
                    else break;
                } else {
                    if (cur->right != nullptr)
                        cur = cur->right;
                    else break;
                }
            }
        if (max != x)
            cout << max << "\n";
        else cout << "none" << "\n";
    }
 
    void next(long int x) {
        info *cur = root;
        long int min = x;
        if (root != nullptr)
            while (true) {
                if ((cur->key > x) && ((cur->key < min) || (min == x)))
                    min = cur->key;
                if ((cur->key <= x)) {
                    if (cur->right != nullptr)
                        cur = cur->right;
                    else break;
                } else {
                    if (cur->left != nullptr)
                        cur = cur->left;
                    else break;
                }
            }
        if (min != x)
            cout << min << "\n";
        else cout << "none" << "\n";
    }
 
 
};
 
 
int main() {
    freopen("bstsimple.in", "r", stdin);
    freopen("bstsimple.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    tree value;
    string str;
    long int x;
    while (cin >> str) {
        cin >> x;
        if (str == "insert")
            value.insert(x);
        else if (str == "exists") {
            if (value.exists(x) == nullptr)
                cout << "false" << "\n";
            else cout << "true" << "\n";
        } else if (str == "delete")
            value.del(x);
        else if (str == "prev") {
            value.prev(x);
        } else if (str == "next") {
            value.next(x);
        }
    }
    return 0;
}
