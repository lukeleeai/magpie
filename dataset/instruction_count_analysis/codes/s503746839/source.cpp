#include<iostream>

#include<cstdio>

#include<cmath>

#define maxn 10005

using namespace std;

long long a[maxn],b[maxn],n,A,B;

int main()

{

 cin>>n;

 for(int i=1;i<=n;i++)

     cin>>a[i];

 for(int i=1;i<=n;i++)

    {

	 cin>>b[i];

     if(a[i]>b[i]) 

	    B+=(a[i]-b[i]);

   	 else if(a[i]<b[i]) 

		     A+=(b[i]-a[i])/2;

    }

 if(A>=B) 

    cout<<"Yes";

 else 

    cout<<"No";

 return 0;

} 