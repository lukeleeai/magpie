#include <iostream>

#include <cstdio>

#include <cstring>

#include <algorithm>

#include <cstdlib>

#include <cmath>

using namespace std;

#define MOD 1000000009

long long w,h,n;

struct Matrix{

    long long n,m[80][80];

    Matrix  operator * (const Matrix &b)const{

        Matrix c;

        memset(c.m,0,sizeof c.m);

        c.n=n;

        for (int i=0;i<n;i++)

        for (int j=0;j<n;j++)

        for (int k=0;k<n;k++){

            c.m[i][j]=(c.m[i][j]+(m[i][k]*b.m[k][j])%MOD)%MOD;

        }

        return c;

    }

};

Matrix ones;

Matrix Pow(const Matrix &a,unsigned long long n){

    Matrix t=ones,y=a;

    while (n){

        if (n & 1) t = (t * y) ;

        y = (y * y) ;

        n /= 2;

    }

    return t;

}

Matrix A;

long long x[80];

long long k,p,q;

struct node{

    long long a,b;

};

node Pos[80];

int cmp(node a,node b){

    return a.b<b.b;

}

void get_x(Matrix a){

    long long y[80];

    memset(y,0,sizeof y);

    for (int i=0;i<a.n;i++){

        for (int j=0;j<a.n;j++){

            y[i]=(y[i]+(x[j]*a.m[i][j])%MOD)%MOD;

        }

    }

    for (int i=0;i<a.n;i++)

        x[i]=y[i];

}

int main(){

    int i,j;

    int d=0;

    while (scanf("%lld%lld%lld",&w,&h,&n)!=EOF){

        memset(ones.m,0,sizeof ones.m);

        for (i=0;i<w;i++)

            ones.m[i][i]=1;

        ones.n=w;

        for (i=0;i<n;i++)

            scanf("%lld%lld",&Pos[i].a,&Pos[i].b);

        sort(Pos,Pos+n,cmp);

        if ((w==0)&&(h==0)&&(n==0)) return 0;

        memset(x,0,sizeof x);

        x[0]=1;

        memset(A.m,0,sizeof A.m);

        A.n=w;

        A.m[0][0]=1;

        A.m[0][1]=1;

        for (i=1;i<w;i++){

            A.m[i][i]=1;

            A.m[i][i-1]=1;

            A.m[i][i+1]=1;

        }

        k=0;

        j=0;

        while (j<n){

            p=Pos[j].b-1;

            if (p==k){

                x[Pos[j].a-1]=0;

            }

            else{

                get_x(Pow(A,p-k));

                k=p;

                x[Pos[j].a-1]=0;

            }

            j++;

        }

        if (k<h-1){

            get_x(Pow(A,h-1-k));

        }

        printf("Case %d: %lld\n",++d,x[w-1]);

    }

}