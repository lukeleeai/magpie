#include <map>

#include <cstdio>

#include <vector>

#include <sstream>

#include <iostream>

#include <algorithm>

#define LL long long

using namespace std;

const int MAXN = 2e3+55;

int vis[20];

int main()

{

    int n,k,v;

    cin>>n>>k;

    for(int i=1;i<=k;++i)

    {

        cin>>v;

        vis[v]++;

    }

    string s;

    for(int i = n;;++i)

    {

        stringstream in;

        in<<i;

        in>>s;

        bool flag = true;

        for(int i=0;i<s.size();++i)

        {

            int t = s[i] - '0';

            if(vis[t]){

                flag = false;

                break;

            }

        }

        if(flag) {cout<<i;return 0;}

    }

    return 0;

}
