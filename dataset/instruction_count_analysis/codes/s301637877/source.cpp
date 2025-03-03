/// @author MUSTAFA MOGHAZY

#include"stdc++.h"

using namespace std;

#define ll long long

int a [32+4];

int main()

{

 string s; cin>>s;

 for(int i=0; i<s.size(); ++i){

    ++a[ s[i] - 96];

 }

 for(int i=1; i<=32; ++i){

    if(a[i]%2==1){

        cout<<"No\n";

        return 0;

    }

 }

 cout<<"Yes\n";

}
