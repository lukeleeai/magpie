#include<cstdio>

#include<vector>

#include<cstring>

using i64=long long;

int n,flg=1,t[300007];std::vector<int>p[3];

int read(){int x;scanf("%d",&x);return x;}

void add(int p){while(p)++t[p],p^=p&-p;}

int ask(int p){int r=0;while(p<=n)r+=t[p],p+=p&-p;return r;}

i64 tao(std::vector<int>p){i64 r=0;memset(t,0,sizeof t);for(int x:p)r+=ask(x),add(x);return r;}

int main()

{

    n=read();

    for(int i=1,x;i<=n;++i) p[2].push_back(x=read()),p[i&1].push_back(x),flg&=!((i^x)&1);

    puts(flg&(tao(p[2])==3*(tao(p[0])+tao(p[1])))? "Yes":"No");

}
