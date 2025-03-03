#include<iostream>

#include<cstring>

using namespace std;

int main()

{

    string n;

    int a,i;

    cin>>n;

    a=n.length();

    for(i=0;i<a;i++)

    {

        if(n[i]==',') cout<<" ";

        else cout<<n[i];

    }

    cout<<endl;

    return 0;

}