#include"stdc++.h"

using namespace std;

#define ll long long

int main()

{

    ll n,i,j,k,l,a,b,c,d;

    string s1;

    cin>>n;

    c=0;

    for(i=1;i<=n;i++)

    {

        stringstream ss;

        ss<<i;

        ss>>s1;

        k=s1.size();

        if(k%2!=0){c++;}

    }

    cout<<c<<endl;

    return 0;

}
