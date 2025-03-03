#include<iostream>

#include<cstdio>

#include<iomanip>

#include<algorithm>

#include<cstring>

#include<cmath>

#include<vector>

#include<map>

using namespace std;

string s[10005];

int main() 

{

	int n;

    cin>>n;

    int flag=0;

    while (n!=0)

    {

        int m=n%10;

        if (m==7)

        {

            flag=1;

            break;

        }

        n=n/10;

    }

    if (flag)

    cout<<"Yes"<<endl;

    else

    cout<<"No"<<endl;

    return 0;

}


