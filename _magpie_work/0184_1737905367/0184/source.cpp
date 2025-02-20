#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

struct house {
    int x, y;
    house() {}
    house(int x, int y) : x(x), y(y) {}
};

struct comp_x {
    bool operator()(const house& a, const house& b) const {
        return (a.x != b.x) ? a.x < b.x : a.y < b.y;
    }
};

struct comp_y {
    bool operator()(const house& a, const house& b) const {
        return (a.y != b.y) ? a.y < b.y : a.x < b.x;
    }
};

int main() {
    srand(static_cast<unsigned int>(time(NULL)));
    int hh, w, n; 
    scanf("%d %d", &hh, &w); 
    scanf("%d", &n);

    vector<house> h(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &h[i].x, &h[i].y);
    }

    set<int> se1, se2;
    sort(h.begin(), h.end(), comp_x());
    se1.insert(h[(n - 2) / 2].x);
    se1.insert(h[n / 2].x);
    sort(h.begin(), h.end(), comp_y());
    se2.insert(h[(n - 2) / 2].y);
    se2.insert(h[n / 2].y);

    ll ret = 1e15; 
    int px = 2000000000, py = 2000000000;

    for (int x : se1) {
        for (int y : se2) {
            vector<ll> distances(n);
            for (int i = 0; i < n; i++) {
                distances[i] = abs(h[i].x - x) + abs(h[i].y - y);
            }
            ll val = 0, gen = 0;
            for (int i = 0; i < n; i++) {
                val += 2LL * distances[i];
                gen = max(gen, distances[i]);
            }
            if (ret > val - gen || (ret == val - gen && (px > x || (px == x && py > y)))) {
                ret = val - gen;
                px = x; 
                py = y;
            }
        }
    }
    printf("%lld\n%d %d\n", ret, px, py);
}
