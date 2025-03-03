#include"stdc++.h"

    using namespace std;

     

    int main()

    {

        int x,a,b;

        while(cin>>x>>a>>b){

            x-=a;

            x%=b;

            cout<<x<<endl;

        }

        return 0;

    }