#include"stdc++.h"

using namespace std;

int main()

{

    int sx,sy,tx,ty,i,j,k,n,m;

    cin>>sx>>sy>>tx>>ty;

    for(i=0;i<(tx-sx);i++)

    {

        cout<<"R";

    }

    for(i=0;i<(ty-sy);i++)

    {

        cout<<"U";

    }

    for(i=0;i<(tx-sx);i++)

    {

        cout<<"L";

    }

    for(i=0;i<(ty-sy);i++)

    {

        cout<<"D";

    }

    cout<<"D";

    for(i=0;i<(tx-sx+1);i++)

    {

        cout<<"R";

    }

    for(i=0;i<(ty-sy+1);i++)

    cout<<"U";

    cout<<"L";

    cout<<"U";

    for(i=0;i<(tx-sx+1);i++)

    {

        cout<<"L";

    }

    for(i=0;i<(ty-sy+1);i++)

    cout<<"D";

    cout<<"R";

    

    

    

}