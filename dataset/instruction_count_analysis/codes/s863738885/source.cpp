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

#include<set>

#include<tuple>

using namespace std;

#define INF 11000000000

#define MAX 100000

#define MOD 1000000007

typedef long long ll;

typedef pair<int,int> P;

typedef pair<pair<int,int>,int> p;

typedef pair< pair<int,int>, int> p; 

#define bit(n,k) ((n>>k)&1) /*nのk bit目*/

#define rad_to_deg(rad) (((rad)/2/M_PI)*360)



int ans[11000];





int main(){

    int N;

    cin>>N;

    vector<int> V[11000];

    ll c[11000];

    for(int i=0;i<N-1;i++){

        int a,b;

        cin>>a>>b; a--; b--;

        V[a].push_back(b);

        V[b].push_back(a);

    }

    for(int i=0;i<N;i++){

        cin>>c[i];

    }

    sort(c,c+N,greater<ll>());

    ll sum=0;

    for(int i=1;i<N;i++){

        sum+=c[i];

    }

    cout<<sum<<endl;

    queue<int> que;

    ans[0]=c[0];

    int count=0;

    que.push(0);

    while(!que.empty()){

        int now=que.front();

        que.pop();

        for(int i=0;i<(int)V[now].size();i++){

            int next=V[now][i];

            if(ans[next]==0){

                que.push(next);

                count++;

                ans[next]=c[count];

            }

        }

    }

    for(int i=0;i<N;i++){

        if(i) cout<<" ";

        cout<<ans[i];

    }

    cout<<endl;

}


