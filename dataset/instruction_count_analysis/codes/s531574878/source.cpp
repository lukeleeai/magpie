#include<iostream>



using namespace std;

long long int gcd(int long long p,int long long q)

{

    int rem;

    while(q>0)

    {

        rem=p%q;

        p=q;

        q=rem;

    }

    return p;

}



int main()

{

    long long int n,a[100000],i,b=0;

    cin>>n;

    for(i=0;i<n;i++)

    {

        cin>>a[i];

        b=gcd(b,a[i]);

    }

    cout<<b<<endl;





    return 0;

}
