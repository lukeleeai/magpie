/*Bismillahir Rahmanir Rahim*/

#include"stdc++.h"

using namespace std;

int main()

{

    long long int a[100007],i,j,N,K,l;

    cin>>N>>K;

    for(i=0; i<N; i++)

        cin>>a[i];

    sort(a,a+N);

    l=a[K-1]-a[0];

    for(i=0; i<N-K+1; i++)

    {

        j=a[i+K-1]-a[i];

        if(j<l)

            l=j;

    }

    cout<<l<<endl;

    return 0;

}
