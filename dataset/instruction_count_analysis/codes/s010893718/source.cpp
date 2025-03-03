#include <iostream>

#include <algorithm>

#include <cstring>

#include <vector>

#include <unordered_set>

#define fs first

#define sc second

using namespace std;

const int maxn = 1e5+10;

using pii = pair<int,int>;

typedef long long ll;

int F[maxn];

vector<int> B[maxn];

int N,M,K;

int fa[maxn],cnt[maxn],ans[maxn];

void init(){

    for(int i = 1;i<=N;i++) fa[i] = i;

}

int find(int x){

    if(x != fa[x])

        fa[x] = find(fa[x]);

    return fa[x];

}

void join(int x,int y){

    int fx = find(x),fy = find(y);

    if(fx != fy){

        fa[fx] = fy;

    }

}

int main(){

    cin>>N>>M>>K;

    init();

    while(M--){

        int a,b;

        scanf("%d %d",&a,&b);

        F[a]++,F[b]++;

        join(a,b);

    }

    for(int i = 1;i<=N;i++) find(i);

    for(int i = 1;i<=N;i++) ++cnt[fa[i]];

    while(K--){

        int a,b;

        scanf("%d %d",&a,&b);

        B[a].push_back(b);

        B[b].push_back(a);

    }

    for(int i = 1;i<=N;i++){

        int total = cnt[fa[i]] - 1;

        total -= F[i];

        for(auto b:B[i]){

            if(find(i) == find(b))

                total -= 1;

        }

        printf("%d ",total);

    }



    return 0;

}