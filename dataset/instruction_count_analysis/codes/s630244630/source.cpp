#include<cstdio>

#include<cstring>

#include<algorithm>

using std::scanf;

using std::printf;

using std::memset;

struct node

{

  long long data;

  int id;

  bool operator< (const node& o) const

  { return this->data < o.data;}

};



typedef long long llong;

const int maxn = 200010;



llong treeset[maxn];

llong end[maxn];

node rec[maxn];

llong n;

llong k;



inline int lowbit(int x)

{ return x&(-x);}



void add(int x, llong d)

{

  while(x <= n)

  {

    treeset[x] += d;

    x += lowbit(x);

  }

}



llong sum(int x)

{

  llong ans = 0;

  while(x)

  {

    ans += treeset[x];

    x -= lowbit(x);

  }

  return ans;

}



int main()

{

  llong tmp;

  llong ans = 0;

  scanf("%lld%lld", &n, &k);

  memset(rec, 0, sizeof(rec));

  for(int i = 1; i <= n; ++i)

  {

    scanf("%lld", &tmp);

    rec[i].data = rec[i-1].data +tmp-k;

    rec[i].id = i;

  }

  std::sort(rec+1, rec+1+n);

  end[rec[1].id] = 1;

  for(int i = 2; i <= n; ++i)

  {

    if(rec[i].data != rec[i-1].data)

    { end[rec[i].id] = i;}

    else

    { end[rec[i].id] = end[rec[i-1].id];}

  }

  for(int i = 1; i <= n; ++i)

  {

    add(end[i], 1);

    ans += sum(n) - sum(end[i]);

  }

  for(int i = 1; i <= n; ++i)

  {

    if(rec[i].data < 0)

    { ++ans;}

  }

  ans = n*(n+1)/2 - ans;

  printf("%lld\n", ans);

}
