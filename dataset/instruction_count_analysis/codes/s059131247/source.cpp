#include<iostream>

#include<string>

#include<algorithm>

using namespace std;

int main()

{

    string s;

    while(cin>>s)

    {



    int res=s.size();

    int a=s.size();

    for(int i=1; i<s.size(); i++)

    {

        if(s[i]!=s[i-1])

            res=min(res,max(i,a-i));

    }

    cout<<res<<endl;

    }

    return 0;

}
