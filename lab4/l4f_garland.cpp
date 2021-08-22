#include <iostream>
#include <iomanip>
 
using namespace std;
 
//i-ый элемент(с 0) =i*a[1]-(i-1)*a[0]+i*(i-1)
//храним последний который потом выведем, а в check вычисляем a[1] через формулу для последнего
 
int garland_check(double value1, double value2, double count) {
    value2 = (value2 + (count - 2) * value1 - (count - 1) * (count - 2)) / (count - 1);
    for (int i = 0; i < count; i++)
        if ((i * value2 - (i - 1) * value1 + i * (i - 1) < 0))
            return 1;
    return 0;
}
 
double bin_search(double left, double right, double count, double value1) {
    if ((right - left) < 0.0000001) {
        return right;
    } else if (garland_check(value1, (right + left) / 2.0, count) == 1) {
        left = (right + left) / 2.0;
        return bin_search(left, right, count, value1);
    } else {
        right = (right + left) / 2;
        return bin_search(left, right, count, value1);
    }
}
 
int main() {
    freopen("garland.in", "r", stdin);
    freopen("garland.out", "w", stdout);
    int n;
    cin >> n;
    double A;
    cin >> A;
    //при a[1]=n каждый член больше 0, так как все члены линейно зависят от a[1], то есть  right<=A(i-1)-A(i-2)+(i-1)*(i-2)
    cout << fixed << setprecision(2) << bin_search(0, A + (n - 1) * (n - 2), n, A);;
    return 0;
}
