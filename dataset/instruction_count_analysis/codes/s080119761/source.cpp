#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <algorithm>

#include <iostream>

using namespace std;

const int N = 1e5 + 5;

int ls[N], s[N], pos[N], num[N], n, a[N];

int sum[N * 4];

void add(int now, int l, int r, int pos) {

    sum[now]++;

    if(l == r) return;

    int mid = l + r >> 1;

    if(pos <= mid) add(now * 2, l, mid, pos);

    else add(now * 2 + 1, mid + 1, r, pos);

}

bool ask(int now, int l, int r, int L, int R) {

    if(l > R || L > r) return false;

    if(L <= l && r <= R) return (sum[now] != 0);

    int mid = l + r >> 1;

    return ask(now * 2, l, mid, L, R) | ask(now * 2 + 1, mid + 1, r, L, R);

}

bool ask(int pos) {

   return ask(1, 1, n, 1, pos);

}

void add(int pos) {

   add(1, 1, n, pos);

}

bool find(int x, int right) {

    int l = 1, r = n;

    for(int mid = l + r >> 1; l < r; mid = l + r >> 1) {

        if(ls[mid] < x) l = mid + 1;

        else r = mid;

    }

    while(ls[l] > x && l > 0) l--;

    if(l == 0) return false;

   // printf("ask = %d %d %d %d\n", l, ask(l), x, ls[l]);

    return ask(l);

}

bool check(int x) {

   // printf("test = %d\n", x);

    memset(sum, 0, sizeof(sum));

    for (int i = 1; i <= n; i++) {

        if(find(a[i] - x, i)) return true;

        add(num[i]);

        //printf("num = %d\n", num[i]);

        //rem[num[a[i]]] ++; 

    }    

    return false;

}

int main()

{

    int minn = 0, maxn = 0, m;

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {

        scanf("%d", &a[i]);

        ls[i] = a[i];

        maxn = max(maxn, a[i]);

    }

    sort(ls + 1, ls + n + 1);

    for (int i = 1; i <= n; i++) {  

        num[i] = lower_bound(ls + 1, ls + n + 1, a[i]) - ls;

        pos[num[i]] = i;

        //cerr << num[i] << " "; 

        //

    }

    //cerr << "\n"; 

    //

    int l = minn, r = maxn;

    for (int mid = (l + r) >> 1; l < r; mid = (l + r) >>  1) {

    //printf("%d %d\n", l, r);

        if(check(mid)) l = mid + 1;

        else r = mid;

    }

    if(!check(l)) l--;

    memset(sum, 0, sizeof(sum));

    //printf("%d\n", l);

    int ans = 0;

    for (int i = 1; i <= n; i++) {

        if(find(a[i] - l, i)) ans++;

        add(num[i]);

    }

    printf("%d\n", ans);

    return 0;

}