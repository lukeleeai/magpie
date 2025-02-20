#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_H = 1000, MAX_W = 1000;
int H, W; 
char s[MAX_H][MAX_W + 1]; // +1 for null terminator

int main() {
    scanf("%d %d", &H, &W); 
    for (int i = 0; i < H; i++) {
        scanf("%s", s[i]);
    }

    vector<pair<int, int>> v;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (s[i][j] == '.' || s[i][j] == '9') continue;
            int cnt = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 && l == 0) continue; // skip the center cell
                    int tx = j + l, ty = i + k;
                    if (0 <= tx && tx < W && 0 <= ty && ty < H && s[ty][tx] == '.') cnt++;
                }
            }
            if (cnt >= s[i][j] - '0') v.push_back(make_pair(j, i));
        }
    }

    int ret = 0;
    for (; !v.empty(); ret++) {
        for (pair<int, int> i : v) s[i.second][i.first] = '.';

        vector<pair<int, int>> w;
        for (pair<int, int> i : v) {
            int sx = i.first, sy = i.second;
            for (int j = -1; j <= 1; j++) {
                for (int k = -1; k <= 1; k++) {
                    if (j == 0 && k == 0) continue; // skip the center cell
                    int tx = sx + k, ty = sy + j;
                    if (!(0 <= tx && tx < W && 0 <= ty && ty < H)) continue;
                    if (s[ty][tx] == '.' || s[ty][tx] == '9') continue;

                    int cnt = 0;
                    for (int l = -1; l <= 1; l++) {
                        for (int m = -1; m <= 1; m++) {
                            if (l == 0 && m == 0) continue; // skip the center cell
                            int ux = tx + m, uy = ty + l;
                            if (0 <= ux && ux < W && 0 <= uy && uy < H && s[uy][ux] == '.') cnt++;
                        }
                    }
                    if (cnt >= s[ty][tx] - '0') w.push_back(make_pair(tx, ty));
                }
            }
        }
        sort(w.begin(), w.end());
        w.resize(unique(w.begin(), w.end()) - w.begin());
        v = w;
    }

    printf("%d\n", ret);
    return 0;
}
