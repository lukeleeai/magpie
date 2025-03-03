#include <iostream>

#include <vector>

#define N 100001

using namespace std;

typedef long long ll;

int func(int);

int n,q,e,k;

bool marked[N];

vector<int> edge[N];



int main(){

  char c;

  ll cnt;

  while(1){

    cin>>n>>q;

    if(!n&&!q) break;

    for(int i=0;i<n-1;i++) cin>>e,edge[i+2].push_back(e);

    for(int i=0;i<n-1;i++) marked[i+2]=false;

    marked[1]=true;

    cnt=0;

    while(q--){

      cin>>c>>k;

      if(c=='M') marked[k]=true;

      else cnt+=func(k);

    }

    cout<<cnt<<endl;

    for(int i=2;i<=n;i++) edge[i].clear();

  }

  return 0;

}



int func(int x){

  if(marked[x]) return x;

  return func(edge[x][0]);

}