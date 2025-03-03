#include<cstdio>

#include<algorithm>

#define st first

#define nd second



using namespace std;

using pii = pair<int, int>;

const int N = 2e5 + 10;

int prefixArray[N];

pii mons[N];



int main(){

    int n, d, a;

    scanf("%d %d %d", &n, &d, &a);

    for(int i = 1; i <= n; i++){

        scanf("%d %d", &mons[i].st, &mons[i].nd);

    }

    sort(mons + 1, mons + n + 1);

    int ptr = 1;

    long long ans = 0LL;

    for(int i = 1; i <= n; i++){

        while(ptr <= n && mons[ptr].st <= mons[i].st + 2 * d)

            ptr++;

        prefixArray[i] += prefixArray[i - 1];

        if(prefixArray[i] >= mons[i].nd)

            continue;

        int bombTime = (mons[i].nd - prefixArray[i] + a - 1) / a;

        ans += 1LL * bombTime;

        prefixArray[i] += bombTime * a;

        prefixArray[ptr] -= bombTime * a;

    }

    printf("%lld", ans);





}
