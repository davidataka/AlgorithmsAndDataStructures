#include <iostream>
 
using namespace std;
 
struct tree {
    int height;
    int parent;
};
 
void height(tree data[], int current) {
    if(data[current].height!=-1)
        exit(0);
    else if (data[current].parent == -1)
        data[current].height = 1;
    else if (data[data[current].parent].height != -1)
        data[current].height = data[data[current].parent].height + 1;
    else height(data, data[current].parent);
}
 
int main() {
    freopen("height.in", "r", stdin);
    freopen("height.out", "w", stdout);
    int n;
    cin >> n;
    tree data[n];
    for (int i = 0; i < n; i++) {
        data[i].parent = -1;
        data[i].height = -1;
    }
    for (int i = 0; i < n; i++) {
        int key, left, right;
        cin >> key >> left >> right;
        if ((left) > 0)
            data[left - 1].parent = i;
        if (right > 0)
            data[right - 1].parent = i;
    }
    for (int i = 0; i < n; i++)
        height(data, i);
    int max=0;
    if (n == 0)
        cout << 0;
    else {
        for(int i=0;i<n;i++)
            if(data[i].height>max)
                max=data[i].height;
        cout<<max;
    }
    return 0;
}
