#include<iostream>

#include<cstdio>

#include<cstdlib>

#include<cstring>

#include<algorithm>

#define Max 100001

#define inf 1000000000000000

using namespace std;

struct title {

    int p,c,score;

}s[11];

int d,g,ans = 1000;

int vis[11];

void dfs(int sum,int k) {

    for(int i = 1;i <= d;i ++) {

        if(vis[i])continue;

        if(g - sum <= s[i].score) {

            int temp;

            if(g - sum < s[i].p * i) {

                temp = g - sum;

                temp = temp / i + (temp % i > 0);

            }

            else temp = s[i].p;

            ans = min(ans,k + temp);

            continue;

        }

        vis[i] = 1;

        dfs(sum + s[i].score,k + s[i].p);

        vis[i] = 0;

    }

}

int main() {

    scanf("%d%d",&d,&g);

    g /= 100;

    for(int i = 1;i <= d;i ++) {

        scanf("%d%d",&s[i].p,&s[i].c);

        s[i].c /= 100;

        s[i].score = s[i].p * i + s[i].c;

    }

    dfs(0,0);

    printf("%d",ans);

}
