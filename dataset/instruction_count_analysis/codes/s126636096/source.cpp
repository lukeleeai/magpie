#include <iostream>

using namespace std;

int shu[100000];

long long co[100001];

int main (){

  int n,m;

  cin>>n>>m;

  for(int i=0;i<n-1;i++) cin>>shu[i];

  for(int i=0;i<=n;i++) co[i]=0;

  int ima=0;

  for(int i=0;i<m;i++){

    int s,e;

    int a;

    cin>>a;

    s=min(ima+a,ima);

    e=max(ima+a,ima);

    co[s]++;

    co[e]--;

    ima+=a;

  }

  for(int i=1;i<n;i++) co[i]+=co[i-1];

  long long sumco=0;

  for(int i=0;i<n-1;i++) sumco+=co[i]*shu[i],sumco%=100000;

  cout<<sumco<<endl;

  return 0;

}