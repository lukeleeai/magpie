#include"stdc++.h"

using namespace std;

const bool debug =0;



inline void read(int &x){

    char ch;

    bool flag=false;

    for (ch=getchar();!isdigit(ch);ch=getchar())if (ch=='-') flag=true;

    for (x=0;isdigit(ch);x=x*10+ch-'0',ch=getchar());

    x=flag?-x:x;

}



inline void write(int x){

    static const int maxlen=100;

    static char s[maxlen];

    if (x<0) {   putchar('-'); x=-x;}

    if(!x){ putchar('0'); return; }

    int len=0; for(;x;x/=10) s[len++]=x % 10+'0';

    for(int i=len-1;i>=0;--i) putchar(s[i]);

}





const int MAXN = 3e5+100;



vector<int> son[ MAXN ];

int n;

int MAX[ MAXN ],MAXX[ MAXN ];

int ans=0;



void dfs(int x,int fa){

MAX[x]=0;

MAXX[x]=0;

for(auto &y:son[x])

{

    if ( y==fa )    continue;

    dfs(y,x);

    MAXX[x] = max ( MAXX[x] , MAX[y]+1);

    if ( MAXX[x] > MAX[x] )

        swap( MAXX[x] ,  MAX[x] );

}

ans=max(ans,MAXX[x]+MAX[x]+1);

}



int main(){

    read(n);

    for (int i=1;i<n;i++)

    {

        int x,y;

        read(x);read(y);

        son[x].push_back(y);

        son[y].push_back(x);

    }

    dfs(1,0);

    if ( ans%3==2 )

        puts("Second");

    else

        puts("First");



    return 0;

}
