// RMQ (Range Minimum Query)

#include<cstdio>

#include<algorithm>

#include<climits>

using namespace std;

#define MAX ( 1 << 17 )

const int INF = INT_MAX;

int n, seg[MAX * 2 - 1];

void update( int i, int x){

  i += n - 1;

  seg[i] = x;

  while(i > 0){

    i = ( i - 1 ) / 2;

    seg[i] = min( seg[i * 2 + 1], seg[i * 2 + 2]);

  }

}

int query( int a, int b, int k, int l, int r){

  if( r <= a || b <= l ) return INF;

  if( a <= l && r <= b ) return seg[k];

  int vl = query( a, b, k * 2 + 1, l, (l + r) / 2);

  int vr = query( a, b, k * 2 + 2, (l + r) / 2, r);

  return min( vl, vr);

}

void init( int& size){

  n = 1;

  while( n < size ) n *= 2;

  fill_n( seg, n * 2 - 1, INF);

}

int main(){

  int size, q;

  scanf("%d %d", &size, &q);

  init(size);

  while(q--){

    int com, a, b;

    scanf("%d %d %d", &com, &a, &b);

    if( com == 0 ) update( a, b);

    else printf("%d\n", query( a, b + 1, 0, 0, n));

  }

}