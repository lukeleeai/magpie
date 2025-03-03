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

    long long ans=0;

    for (int i=1;i<=n;i++)

    {

        if (i%3==0)

        continue;

        else if (i%5==0)

        continue;

        else

        ans+=i;

    }

    cout<<ans<<endl;

    return 0;

}


