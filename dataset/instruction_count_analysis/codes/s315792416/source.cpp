#include<cstdio>

#include<cstring>

#include<iostream>

#include<algorithm>



#define nn 10010

using namespace std;



const int bs[2]={271,233};

const int mod[2]={998244353,1000000007};



char a[nn];

int n,pw[nn][2],N,as,h[nn][2];

struct Node{int h0,h1,p;}q[nn];



bool Cmp(Node a,Node b) {return(a.h0<b.h0||a.h0==b.h0&&a.h1<b.h1||a.h0==b.h0&&a.h1==b.h1&&a.p<b.p);}

inline bool Check(int md){

    N=0;

    for (int i=1;i+md-1<=n;i++){

        int nm[2];

        for (int j=0;j<2;j++) nm[j]=(h[i+md-1][j]-h[i-1][j]+mod[j])%mod[j];

        for (int j=0;j<2;j++) nm[j]=nm[j]*1ll*pw[n-(i+md-1)][j]%mod[j];

        q[++N]=(Node){nm[0],nm[1],i};

    }

    sort(q+1,q+1+N,Cmp);

    for (int j=1,i=1;i<=N;i=j){

        for (j=i;q[i].h0==q[j].h0&&q[i].h1==q[j].h1&&j<=N;j++);

        if (q[i].p+md<=q[j-1].p) return(1);

    }

    return(0);

}



int main()

{

    scanf("%d%s",&n,a+1);

    pw[0][0]=pw[0][1]=1;

    for (int i=1;i<=n;i++)

    for (int j=0;j<2;j++) pw[i][j]=pw[i-1][j]*1ll*bs[j]%mod[j];

    for (int i=1;i<=n;i++)

    for (int j=0;j<2;j++) h[i][j]=(h[i-1][j]+a[i]*1ll*pw[i][j]%mod[j])%mod[j];



    int l=1,r=n;

    while (l<=r){

        int md=(l+r)/2;

        if (Check(md)) as=md,l=md+1;

        else r=md-1;

    }

    printf("%d\n",as);

}