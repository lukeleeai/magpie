#include<cstdio>

#include<iostream>

#include<algorithm>

#include<cmath>

#include<cstring>

#include<string>

#include<map>

#include<set>

using namespace std;

int n,q,t,k,d,ans;

map <char,char> mp,mp2;

const int maxn=1e5+7;

int num[maxn];

bool vis[1000];

int main(){

    string a;

    string b;

    memset(num,-1,sizeof(num));

    cin>>a>>b;

    int len=a.size();

    for(int i=0;i<len;i++)

    {

        if(num[a[i]]==-1)

        {

            num[a[i]]=b[i];

        }

        else

        {

            if(num[a[i]]!=b[i])

            {

                cout<<"No"<<endl;

                return 0;

            }

        }

    }

    memset(num,-1,sizeof(num));

    for(int i=0;i<len;i++)

    {

        if(num[b[i]]==-1)

        {

            num[b[i]]=a[i];

        }

        else

        {

            if(num[b[i]]!=a[i])

            {

                cout<<"No"<<endl;

                return 0;

            }

        }

    }

    cout<<"Yes"<<endl;

    return 0;

	}