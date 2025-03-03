#include"stdc++.h"

#define ll long long

using namespace std;

#define maxn 100010

#define mod 1000000007

struct cv{

    int x,y;

}a[maxn];

int b[maxn];

int cnt;

set<int>s[maxn];

int dp[maxn],du[maxn];

bool cmp(cv p,cv q){

    if(p.x!=q.x) return p.x<q.x;

    return p.y<q.y;

}

int main(){

    int n;

    scanf("%d",&n);

    for(int i=0;i<n;i++) scanf("%d",&a[i].x);

    for(int i=0;i<n;i++) scanf("%d",&a[i].y),b[i]=a[i].y;

    sort(a,a+n,cmp);

    sort(b,b+n);

    cnt=0;

    int flag=0;

    for(int i=0;i<n;i++){

        if(a[i].x>b[i]){

            printf("No\n");

            return 0;

        }

        if(i<n-1&&a[i+1].x<b[i]) flag=1;

        if(i!=0){

            if(b[i]==b[i-1]) flag=1;

        }

        if(i!=0&&a[i].x!=a[i-1].x){

            cnt++;

            s[cnt].insert(a[i].y);

        }

        else{

            s[cnt].insert(a[i].y);

            if(i!=0) flag=1;

        }

    }

    cnt=0;

    if(flag){

        printf("Yes\n");

        return 0;

    }

    for(int i=0;i<n;i++){

        dp[lower_bound(b,b+n,a[i].y)-b]=i;

    }

    cnt=0;

    for(int i=0;i<n;i++){

        if(du[i]) continue;

        cnt++;

        du[i]=1;

        int x=dp[i];

        while(du[x]==0){

            du[x]=1;

            x=dp[x];

        }

    }

    if(cnt>=2) printf("Yes\n");

    else printf("No\n");

    return 0;

}