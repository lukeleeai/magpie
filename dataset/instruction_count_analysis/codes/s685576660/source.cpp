#include<cstdio>

#include<algorithm>

#define int long long

using namespace std;

struct arr

  {

   int aa,bb;

  }a[100010];

int n;

long long b[100010];

int cmp(arr x,arr y)

  {

   if (x.aa!=y.aa) return x.aa>y.aa;

   return x.bb<y.bb;

  }

signed main()

  {

   scanf("%lld",&n);

   for (int i=1;i<=n;i++)

     {

      scanf("%lld",&a[i].aa);

      a[i].bb=i;b[i]=0;

	 }

   sort(a+1,a+1+n,cmp);

   int maxa=1;int maxb=1;

   while (true)

     {

      while ((a[maxb].aa==a[maxa].aa) && (maxb<=n)) maxb=maxb+1;

      if (maxb>n) break;

      b[a[maxa].bb]+=(maxb-1)*(a[maxa].aa-a[maxb].aa);

      a[maxa].aa=a[maxb].aa;

	  if (a[maxa].bb>a[maxb].bb) maxa=maxb;

	 }

   b[a[maxa].bb]+=a[maxa].aa*n;

   for (int i=1;i<=n;i++) printf("%lld\n",b[i]);

   return 0;

  } 