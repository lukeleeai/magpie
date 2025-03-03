#include"stdc++.h"

using namespace std;

int a,b,n;

int main()

{

    string s;

    cin>>a>>b;

    n=a+b;

    bool flag=false;

    cin>>s;

    if(s[a]!='-') flag=true;

    for(int i=0;i<=n;i++)

    {

        if(i==a) continue;

        if(!(s[i]>='0' && s[i]<='9')) flag=true;

    }

    if(!flag) cout<<"Yes"<<endl;

    else cout<<"No"<<endl;

    return 0;

}
