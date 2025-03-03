#include<cstdio>

#include<vector>

#include<map>

#include<climits>

#include<algorithm>

using namespace std;

typedef pair<int,int> Pt;

#define MAX 1000001

#define fr first

#define sc second

int n,dat[MAX * 2 - 1];

void update(int i,int x){

  i += n - 1;

  dat[i] = x;

  while(i > 0){

    i = (i - 1)/2;

    dat[i] = min(dat[i*2+1],dat[i*2+2]);

  }

}

int query(int a,int b,int k,int l,int r){

  if( r<=a || b <= l ) return INT_MAX;

  if( a<=l && r <= b ) return dat[k];

  return min(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));

}

int main(){

  int q,a,b,c,N;

  for(int i=0;i<MAX*2-1;i++) dat[i] = INT_MAX;

  scanf("%d %d",&N,&q);

  n=1;

  while(n < N) n *= 2;

  while(q--){

    scanf("%d %d %d",&a,&b,&c);

    if(!a) update(b,c);

    else printf("%d\n",query(b,c+1,0,0,n));

  }

}