#include <iostream>
#include <array>
using namespace std;

constexpr int SIZE = 10;
int compute(array<array<int, SIZE>, SIZE>& t, array<array<int, SIZE>, SIZE>& ans, array<array<int, SIZE>, SIZE>& u);
void dfs(int x, array<array<int, SIZE>, SIZE>& t, array<array<int, SIZE>, SIZE>& ans, array<array<int, SIZE>, SIZE>& u);

int main() {
    int n;
    cin >> n;
    while(n--) {
        array<array<int, SIZE>, SIZE> t, u, ans;
        for(int i = 0; i < SIZE; i++)
            for(int j = 0; j < SIZE; j++)
                cin >> t[i][j];
        dfs(0, t, ans, u);
    }
    return 0;
}

void dfs(int x, array<array<int, SIZE>, SIZE>& t, array<array<int, SIZE>, SIZE>& ans, array<array<int, SIZE>, SIZE>& u) {
    if(x == SIZE) {
        if(compute(t, ans, u)) {
            for(int i = 0; i < SIZE; i++) {
                for(int j = 0; j < SIZE; j++) {
                    if(j) cout << ' ';
                    cout << ans[i][j];
                }
                cout << endl;
            }
        }
        return;
    }
    ans[0][x] = 0;
    dfs(x + 1, t, ans, u);
    ans[0][x] = 1;
    dfs(x + 1, t, ans, u);
}

int compute(array<array<int, SIZE>, SIZE>& t, array<array<int, SIZE>, SIZE>& ans, array<array<int, SIZE>, SIZE>& u) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            u[i][j] = t[i][j];
            if(i) ans[i][j] = 0;
        }
    }
    for(int i = 0; i < SIZE; i++) {
        if(ans[0][i]) {
            u[0][i] ^= 1; // Using XOR for toggling
            if(0 > 0) u[0-1][i] ^= 1;
            if(i > 0) u[0][i-1] ^= 1;
            if(0 < 9) u[0+1][i] ^= 1;
            if(i < 9) u[0][i+1] ^= 1;
        }
    }
    for(int i = 1; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(u[i-1][j]) {
                ans[i][j] = 1;
                u[i][j] ^= 1;
                if(i > 0) u[i-1][j] ^= 1;
                if(j > 0) u[i][j-1] ^= 1;
                if(i < 9) u[i+1][j] ^= 1;
                if(j < 9) u[i][j+1] ^= 1;
            }
        }
    }
    for(int i = 0; i < SIZE; i++) {
        if(u[9][i]) return 0;
    }
    return 1;
}
