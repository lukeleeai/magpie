#include<iostream>

#include<cstring>

#include<cstdio>

#include<algorithm>

#include<vector>

#define N 300010

#define gc getchar()

#define lb(x) (x&-x)

#define debug(x) cerr<<#x<<"="<<x

#define sp <<" "

#define ln <<endl

using namespace std;

inline int inn()

{

    int x,ch;while((ch=gc)<'0'||ch>'9');

    x=ch^'0';while((ch=gc)>='0'&&ch<='9')

        x=(x<<1)+(x<<3)+(ch^'0');return x;

}

int l[N],r[N],b[N],ans[N];vector<int> v[N];

inline int update(int x,int n,int v) { for(;x<=n;x+=lb(x)) b[x]+=v;return 0; }

inline int update(int x,int y,int n,int v) { return update(x,n,v),update(y+1,n,-v); }

inline int query(int x,int v=0) { for(;x;x-=lb(x)) v+=b[x];return v; }

int main()

{

    int n=inn(),m=inn();

    for(int i=1;i<=n;i++)

        l[i]=inn(),r[i]=inn(),v[r[i]-l[i]+1].push_back(i);

    for(int d=1;d<=m;d++)

    {

        for(int i=d;i<=m;i+=d) ans[d]+=query(i);

        for(int i=0,id;i<(int)v[d].size();i++)

            id=v[d][i],update(l[id],r[id],m,1);

    }

    for(int d=m,cnt=0;d;d--)

        cnt+=(int)v[d].size(),ans[d]+=cnt;

    for(int i=1;i<=m;i++) printf("%d\n",ans[i]);

    return 0;

}