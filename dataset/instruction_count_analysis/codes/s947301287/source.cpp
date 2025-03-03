#include "stdc++.h"

using namespace std;



int main()

{

    string s,a,e;

    int c,d,j;

    cin>>s>>a>>e;

    c = s.size();

    d = a.size();

    j = e.size();

    if(s[c-1]==a[0]&&a[d-1]==e[0])

        cout<<"YES"<<endl;

    else

        cout<<"NO"<<endl;

    return 0;



}
