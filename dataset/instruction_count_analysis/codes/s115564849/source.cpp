#include <iostream>

#define Q 100005

using namespace std;

typedef long long ll;

int n,q,t[Q],p[Q];

bool marked[Q];

char c[Q];

ll ans;



int find(int x){

  if(marked[x]) return x;

  return p[x]=find(p[x]);

}



int main(){

  while(1){

    cin>>n>>q;

    if(!n&&!q) break;

    for(int i=1;i<=n;i++) marked[i]=false;

    for(int i=2;i<=n;i++) cin>>p[i];

    marked[1]=true;

    for(int i=0;i<q;i++){

      cin>>c[i]>>t[i];

      if(c[i]=='M'){

	if(marked[t[i]]) c[i]='E';

	marked[t[i]]=true;

      }

    }

    ans=0;

    for(int i=q-1;i>=0;i--){

      if(c[i]=='E') continue;

      if(c[i]=='M') marked[t[i]]=false;

      else ans+=find(t[i]);

    }

    cout<<ans<<endl;

  }

  return 0;

}