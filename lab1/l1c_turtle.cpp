#include <iostream>

using namespace std;

int main() {
    freopen("turtle.in", "r", stdin);
    freopen("turtle.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h, w;
    cin >> h >> w;
    int reward[h][w];
    //массив вознаграждений за посещение ячеек
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> reward[i][j];
    int maxsum[h][w];
    //массив максимального суммарного вознаграждения при пути в соответсвующую ячейку
    maxsum[h - 1][0] = reward[h - 1][0];
    for (int i = (h - 1); i > -1; i--)
        for (int j = 0; j < w; j++) {
            if (i < (h - 1) && (j > 0))
                maxsum[i][j] = max(maxsum[i + 1][j], maxsum[i][j - 1]) + reward[i][j];
            else if ((i == (h - 1)) && (j > 0))
                maxsum[i][j] = maxsum[i][j - 1] + reward[i][j];
            else if ((i < (h - 1)) && (j == 0))
                maxsum[i][j] = maxsum[i + 1][j] + reward[i][j];

        }
    cout << maxsum[0][w - 1];
    return 0;
}
