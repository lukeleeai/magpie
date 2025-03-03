#include"stdc++.h"

#define n 200005

using namespace std;

vector<long long >v(n,0);

vector<long long >prime;

long long i,j;

void sieve()

{

    for(i=3; i*i<=n; i+=2)

    {

        for(j=i*i; j<=n; j+=(i+i))

        {

            v[j-1]=1;

        }

    }

    prime.push_back(2);

    for(i=3; i<n; i+=2)

    {

        if(v[i-1]==0)

        {

            //cout<<i<<endl;

            prime.push_back(i);

        }

    }

}

int main()

{

    sieve();

    long long num,t;

    cin>>num;

    for(i=0;i<n;i++)

    {

        if(prime[i]>=num)

        {

            cout<<prime[i]<<endl;

            break;

        }

    }

    return 0;

}
