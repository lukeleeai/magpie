#include<cmath>

#include<cstdio>

#include<string>

#include<cstring>

#include<cstdlib>

#include<iostream>

#include<algorithm>

using namespace std;

int N,M,L;

struct node

{   double t,p;

}per[101][51];

long long c[51][51]={0};

void prepare()

{   c[0][0]=1;c[1][0]=1;

    for(int i=1;i<51;i++)

    for(int j=0;j<51;j++)

    {   if(j==0) c[i][j]=1;

        else c[i][j]=c[i-1][j]+c[i-1][j-1];

    }

}

int main()

{   int T;

    prepare();

    cin>>N>>M>>L;

    for(int i=0;i<N;i++)

    {   double p,t,v;

        cin>>p>>t>>v;p*=0.01;

        per[i][0].t=L/v;

        per[i][0].p=pow(1-p,M);

        for(int j=1;j<=M;j++)

        {   per[i][j].p=c[M][j]*pow(1-p,M-j)*pow(p,j);

            per[i][j].t=per[i][j-1].t+t;

        }

    }

//    for(int i=0;i<N;i++){

//    for(int j=0;j<=M;j++)

//    {   cout<<per[i][j].t<<'('<<per[i][j].p<<')'<<' ';

//

//    }puts("");}

    for(int i=0;i<N;i++)

    {   double s=0;

        for(int j=0;j<=M;j++)

        {   double tt=per[i][j].p;

            for(int k=0;k<N;k++)

            if(k!=i)

            {   double ts=0;

                for(int t=M;t>=0 && per[k][t].t>per[i][j].t;t--)

                {   ts+=per[k][t].p;

                }

                tt*=ts;

               // cout<<ts<<endl;

            }

            s+=tt;

        }

        printf("%.8lf\n",s);

    }

}