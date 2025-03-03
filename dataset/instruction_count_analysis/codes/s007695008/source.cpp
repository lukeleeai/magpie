#include <algorithm>

#include <cstdio>

using namespace std;

const int N = 100010;

int n, x, y, len;

long long ans;

int a[N][2];

int idx[N], idy[N];

bool fx[N * 4], fy[N * 4];

int d[N];

bool bz[N];

int dis(int x, int y, int xx, int yy) {

    return max(abs(xx - x) , abs(yy - y));

}

void build(int l, int r, int s) {

    fx[s] = fy[s] = 1;

    if (l == r) return;

    build(l, (l + r)/ 2, s + s);

    build((l + r) / 2 + 1, r, s + s + 1);

}

void work1(int l, int r, int s) {

    if (!fy[s]) return;

    fy[s] = 0;

    if (l == r) {

        if (!bz[idy[l]])

            bz[d[++d[0]] = idy[l]] = 1;

        return;

    }

    work1(l, (l + r) / 2, s + s);

    work1((l + r) / 2 + 1, r, s + s + 1);

}



void work2(int l, int r, int s) {

    if (!fx[s]) return;

    fx[s] = 0;

    if (l == r) {

        if (!bz[idx[l]])

            bz[d[++d[0]] = idx[l]] = 1;

        return;

    }

    work2(l, (l + r) / 2, s + s);

    work2((l + r) / 2 + 1, r, s + s + 1);

}

void search1(int l, int r, int s, int ll, int rr, int lll) {

    if (a[idy[r]][1] < lll || a[idy[l]][1] > lll) return;

    if (a[idy[l]][1] == a[idy[r]][1] && (a[idy[l]][0] > rr ||a[idy[r]][0] < ll)) return;

    if (a[idy[l]][1] == a[idy[r]][1] && (a[idy[l]][0] >= ll &&a[idy[r]][0] <= rr)) {

        ans += r-l  +1;

        work1(l, r, s);

        return;

    }

    search1(l, (l + r ) / 2, s + s, ll, rr, lll);

    search1((l + r ) / 2 + 1, r, s + s + 1, ll, rr, lll);

    fy[s] = fy[s + s] | fy[s+s+1];

}



void search2(int l, int r, int s, int ll, int rr, int lll) {

    if (a[idx[r]][0] < lll || a[idx[l]][0] > lll) return;

    if (a[idx[l]][0] == a[idx[r]][0] && (a[idx[l]][1] > rr ||a[idx[r]][1] < ll)) return;

    if (a[idx[l]][0] == a[idx[r]][0] && (a[idx[l]][1] >= ll &&a[idx[r]][1] <= rr)) {

        ans += r-l  +1;

        work2(l, r, s);

        return;

    }

    search2(l, (l + r ) / 2, s + s, ll, rr, lll);

    search2((l + r ) / 2 + 1, r, s + s + 1, ll, rr, lll);

    fx[s] = fx[s + s] | fx[s+s+1];

}

int main() {

    scanf("%d %d %d", &n, &x, &y);

    for (int i =1; i <= n ; i ++) {

        int x ,y;

        scanf("%d %d", &x, &y);

        a[i][0] = x - y;

        a[i][1] = x + y;

        idx[i] = idy[i] = i;

    }

    len = dis(a[x][0], a[x][1], a[y][0], a[y][1]);

    sort(idx + 1, idx + n + 1, [](const int & x, const int & y) {

        return a[x][0] < a[y][0] || (a[x][0] == a[y][0] && a[x][1] < a[y][1]);

    });

    sort(idy + 1, idy + n + 1, [](const int & x, const int & y) {

        return a[x][1] < a[y][1] || (a[x][1] == a[y][1] && a[x][0] < a[y][0]);

    });

    build(1, n, 1);

    d[0] = 2;

    d[1] = x;

    d[2] = y;

    bz[x] = bz[y] = 1;

    for (int i = 1; i <= d[0]; i ++)

    {

        int x  = d[i];

        search1(1, n, 1, a[x][0] - len, a[x][0] + len, a[x][1] - len);

        search1(1, n, 1, a[x][0] - len, a[x][0] + len, a[x][1] + len);

        search2(1, n, 1, a[x][1] - len + 1, a[x][1] + len - 1, a[x][0] - len);

        search2(1, n, 1, a[x][1] - len + 1, a[x][1] + len - 1, a[x][0] + len);

    }

    printf("%lld\n", ans / 2);

    return 0;

}