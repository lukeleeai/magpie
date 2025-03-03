#include"stdc++.h"

using namespace std;

typedef long long ll;

int main()

{

    ll n,p;

    cin>>n>>p;

    if(n==1)

    {

        cout<<p<<endl;

        return 0;

    }

    int ma=1;

    for(int i=2;i<=p;i++)

    {

        if(i>1e6+5) break;  // 这个质因数是一个大素数

        int cnt=0;

        while(p%i==0)

        {

            p/=i;

            cnt++;

        }

        if(cnt>=n)

            ma*=pow(i,cnt/n);

    }

    cout<<ma;

}






