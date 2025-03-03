#include<algorithm>

#include<cstdio>

#include<cmath>

#include<iostream>

using namespace std;

long long K,N;

int main()

{

    long long sum=0;

    //freopen("in.txt","r",stdin);

    scanf("%lld%lld",&N,&K);

    if(K==0)

    {

        cout<<N*N<<endl;

        return 0;

    }

    for(int i=K+1;i<=N;++i)

    {

        for(int j=i;j<=N;j+=i)

        {

            sum+=i-K;

        }

        if(N%i>=K)

        {

            sum+=N%i-K+1;

        }

    }

    printf("%lld\n",sum);

}
