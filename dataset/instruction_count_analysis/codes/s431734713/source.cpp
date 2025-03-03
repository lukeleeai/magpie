

#include"stdc++.h"

#define ll long long

using namespace std;

#define N 1000000000

//ll primes[N];



//int seive()

//{

//	ll i,j,t=0,sq;

//	bool flag[N];

//	for(i=2;i<=N;i++) flag[i]=1;

//	sq=sqrt(N)+1;

//	for(i=2;i<sq;i++)

//		if(flag[i])

//			for(j=i;j*i<=N;j++)

//				flag[i*j]=0;

//	for(i=2;i<=N;i++)

//		if(flag[i])

//			primes[t++]=i;

//	return t;

//}



//     for(i=0;i<n;i++)

//     for(j=0;j<n;j++)



//int GCD(ll a, ll b)

//{

//    if(a==0)return b;

//    if(b==0)return a;

//    else return GCD(b,a%b);

//}









int main()

{

    ll i,j,k,m,n,q,t,a,b,c=0,r,x;

    cin>>a>>b;

    for(i=1;i<N;i++)

    {

        if(abs(a-i)==abs(b-i))

            {

                cout<<i<<endl;

                c++;

                break;

            }

    }

    if(c==0)

    cout<<"IMPOSSIBLE"<<endl;

}
