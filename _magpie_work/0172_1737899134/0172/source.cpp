#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int direction[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

struct node {
    int w, h;
    int step;
};

int H, W, N;
string s[1005];

int cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    return a.first < b.first;
}

int DFS(int begin_h, int begin_w, int end_h, int end_w) {
    queue<node> Q;
    Q.push({ begin_w, begin_h, 0 });
    s[begin_h][begin_w] = '#'; // Mark the starting point as visited

    while (!Q.empty()) {
        node temp1 = Q.front();
        Q.pop();
        if (temp1.h == end_h && temp1.w == end_w) {
            return temp1.step;
        }
        for (int i = 0; i < 4; i++) {
            int new_h = temp1.h + direction[i][0];
            int new_w = temp1.w + direction[i][1];
            if (new_h >= 0 && new_h < H && new_w >= 0 && new_w < W &&
                s[new_h][new_w] == '.') {
                
                s[new_h][new_w] = '#'; // Mark as visited directly in the string
                Q.push({ new_w, new_h, temp1.step + 1 });
            }
        }
    }
    return -1; // Return -1 if not reachable
}

int main(void) {
    int all_step = 0;
    int s_h, s_w, e_h, e_w;

    scanf("%d%d%d", &H, &W, &N);
    vector<pair<int, pair<int, int>>> node1(20);

    for (int i = 0; i < H; i++) {
        char buffer[1005];
        scanf("%s", buffer);
        s[i] = buffer;
        for (int j = 0; j < s[i].length(); j++) {
            if (s[i][j] >= '0' && s[i][j] <= '9') {
                node1.push_back({ s[i][j] - '0', { i, j } });
                s[i][j] = '.';
            } else if (s[i][j] == 'S') {
                s_h = i;
                s_w = j;
                s[i][j] = '.';
            }
        }
    }

    sort(node1.begin() + 1, node1.begin() + N + 1, cmp);
    for (size_t i = 0; i < node1.size() - 1; i++) {
        e_h = node1[i + 1].second.first;
        e_w = node1[i + 1].second.second;
        s_h = node1[i].second.first;
        s_w = node1[i].second.second;
        all_step += DFS(s_h, s_w, e_h, e_w);
    }

    printf("%d\n", all_step);
    return 0;
}
