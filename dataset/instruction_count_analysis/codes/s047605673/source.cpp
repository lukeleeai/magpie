#include"stdc++.h"

using namespace std;

char a[1000010];

int main()

{

    cin>>a;

    int x=0,y=0;

    int ans=0;

    for(int i=0;i<sizeof(a);i++)

    {

        if(x==y){x++;if(a[i]=='p')ans--;}

        else {y++;if(a[i]=='g'){ans++;}}

    }

    cout<<ans;



}