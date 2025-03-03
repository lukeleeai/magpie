#include"stdc++.h"

#define LL long long



using namespace std;

const int N=2e5+10;

int rd()

{

    int x=0,w=1;char ch=0;

    while(ch<'0'||ch>'9'){if(ch=='-') w=-1;ch=getchar();}

    while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}

    return x*w;

}

int to[N<<1],nt[N<<1],hd[N],dg[N][2],tot=1;

void adde(int x,int y)

{

    ++tot,to[tot]=y,nt[tot]=hd[x],hd[x]=tot;

    ++tot,to[tot]=x,nt[tot]=hd[y],hd[y]=tot;

}

char cc[N];

int n,m,tt;

bool v[N];



int main()

{

////////////////

    n=rd(),m=rd();

    scanf("%s",cc+1);

    for(int i=1;i<=m;++i)

    {

	int x=rd(),y=rd();

	adde(x,y);

	++dg[x][cc[y]-'A'],++dg[y][cc[x]-'A'];

    }

    queue<int> q;

    for(int i=1;i<=n;++i)

	if(!dg[i][0]||!dg[i][1]) v[i]=1,q.push(i);

    while(!q.empty())

    {

	int x=q.front();

	q.pop();

	++tt;

	for(int i=hd[x];i;i=nt[i])

	{

	    int y=to[i];

	    --dg[y][cc[x]-'A'];

	    if(!v[y]&&!dg[y][cc[x]-'A']) v[y]=1,q.push(y);

	}

    }

    puts(tt==n?"No":"Yes");

    return 0;

}




