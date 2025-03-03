#include "stdc++.h"

using namespace std;

const int N=2e5+5;

char tmp[N];

pair<int,string> A[N];

map<string , int> idx;

map<string , int>mp;

map<int,vector<string> > rmp;

int main()

{

    int n,mx=-1;

    scanf("%d",&n);

    string s;

    for(int i=0;i<n;++i){

        scanf("%s",tmp);

        string s(tmp);

        mx = max(mx,++mp[s]);

        rmp[mp[s]].push_back(s);

    }

    sort(rmp[mx].begin(),rmp[mx].end());

    for(auto x:rmp[mx]){

        printf("%s\n",x.c_str());

    }



    return 0;

}
