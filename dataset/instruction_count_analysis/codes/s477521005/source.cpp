#include"stdc++.h"

using namespace std;

int main()

{

    string s;

    cin>>s;

    int i,count=0;

    for(i=0;i<s.size();i++)

    {

        if(s[i]==s[i+1])

        count++;

    }

    if(count>=1)

        cout<<"Bad"<<endl;

    else

        cout<<"Good"<<endl;

    return 0;



}
