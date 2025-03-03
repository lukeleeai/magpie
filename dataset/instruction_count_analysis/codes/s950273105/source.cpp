#include <cstdio>

#include <cstring>

#include <iostream>

#include <string>

#include <cmath>

#include <bitset>

#include <vector>

#include <map>

#include <set>

#include <queue>

#include <deque>

#include <algorithm>

#include <complex>

#include <unordered_map>

#include <unordered_set>

#include <random>

#include <cassert>

#include <fstream>

#define popcount __builtin_popcount

using namespace std;

typedef long long ll;

typedef pair<int, int> P;

const int MOD=1e9+7;

int main()

{

    string s; cin>>s;

    int c[100010];

    int n=s.size();

    c[0]=0;

    bool dame=1;

    for(int i=0; i<n; i++){

        if(s[i]=='a') c[i+1]=(c[i]+1)%3;

        else c[i+1]=(c[i]+2)%3;

        if(i<n-1 && s[i]==s[i+1]) dame=0;

    }

    if(dame){

        cout<<1<<endl; return 0;

    }

    int nx[100010];

    int p[3];

    for(int j=0; j<3; j++) p[j]=n+1;

    p[c[n]]=n;

    for(int i=n-1; i>=0; i--){

        p[c[i]]=i;

        if(s[i]=='a') nx[i]=p[(c[i]+2)%3];

        else nx[i]=p[(c[i]+1)%3];

    }

    int dp[100010]={};

    dp[0]=1;

    int ans=0;

    for(int i=0; i<n; i++){

        (dp[i+1]+=dp[i])%=MOD;

        (dp[nx[i]]+=dp[i])%=MOD;

        int x=(c[n]-c[i+1]+3)%3;

        if(x==0) (ans+=dp[i+1])%=MOD;

    }

    cout<<ans<<endl;

    return 0;

}