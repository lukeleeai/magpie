#include<cstdio>

#include<cstdlib>

#include<algorithm>

#include<iostream>

#include<queue>

#include<vector>

#include <bitset>

#include <cmath>

#include <limits>

#include <iostream>

using namespace std;

#define INF 100000

#define MAX 100000

#define MOD 1000000007

typedef long long ll;

typedef pair<int,int> P;

typedef pair< pair<int,int>, int> p; 

#define bit(n,k) ((n>>k)&1) /*nのk bit目*/



//http://drken1215.hatenablog.com/entry/2019/03/17/130800

vector<int> places[210000];

ll dp[210000];

void add(ll &a,ll b){

    a+=b;

    if(a>=MOD) a-=MOD;

}



int main(){

    int N;

    cin>>N;

    vector<int> c(N);

    for(int i=0;i<N;i++) cin>>c[i];



    for(int i=0;i<210000;i++) places[i].clear();

    for(int i=0;i<N;i++) places[c[i]].push_back(i);



    dp[0]=1;

    for(int i=1;i<=N;i++){

        add(dp[i],dp[i-1]);



        int color=c[i-1];

        int it=lower_bound(places[color].begin(),places[color].end(),i-1)-places[color].begin();

        if(it>0){

            int j=places[color][it-1];

            if((i-1)-j>1) add(dp[i],dp[j+1]);

        }

    }

    cout<<dp[N]<<endl;

}


