#include<stdio.h>

#include<algorithm>

using namespace std;

#define fup(i,a,b) for(int i=a;i<=b;++i)



int x[200004],y[200004];

void Main()

{

    int n,nn;

    scanf("%d",&n);

    nn=n/2;

    fup(i,1,n)scanf("%d",&x[i]),y[i]=x[i];

    sort(y,y+1+n);

    int t=y[nn],tz=y[nn-1],ty=y[nn+1],sz=0,sy=0;

    {

        int i=nn,j=nn;

        while(y[--i]==t)++sz;

        while(y[++j]==t)++sy;

    }

    if(sz&&sy)fup(i,1,n)printf("%d\n",t);

    else if(!sz&&sy)fup(i,1,n)printf("%d\n",t);

    else if(sz&&!sy)fup(i,1,n)

    {

        if(x[i]<=t)printf("%d\n",ty);

        else printf("%d\n",t);

    }

    else fup(i,1,n)

    {

        if(x[i]<=t)printf("%d\n",ty);

        else printf("%d\n",t);

    }

}

int main()

{

Main();

return 0;

}