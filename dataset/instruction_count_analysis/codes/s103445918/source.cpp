#include"stdc++.h" //Ithea Myse Valgulious

namespace chtholly{

typedef long long ll;

#define re0 register int

#define rec register char

#define rel register ll

#define gc getchar

#define pc putchar

#define p32 pc(' ')

#define pl puts("")

/*By Citrus*/

inline int read(){

  int x=0,f=1;char c=gc();

  for (;!isdigit(c);c=gc()) f^=c=='-';

  for (;isdigit(c);c=gc()) x=(x<<3)+(x<<1)+(c^'0');

  return f?x:-x;

  }

inline void read(rel &x){

  x=0;int f=1;char c=gc();

  for (;!isdigit(c);c=gc()) f^=c=='-';

  for (;isdigit(c);c=gc()) x=(x<<3)+(x<<1)+(c^'0');

  x=f?x:-x;

  }

template <typename mitsuha>

inline int write(mitsuha x){

  if (!x) return pc(48);

  if (x<0) x=-x,pc('-');

  int bit[20],i,p=0;

  for (;x;x/=10) bit[++p]=x%10;

  for (i=p;i;--i) pc(bit[i]+48);

  }

inline char fuhao(){

  char c=gc();

  for (;isspace(c);c=gc());

  return c;

  }

}using namespace chtholly;

using namespace std;

const int yuzu=1e5;

char c[yuzu|10];

int cnt[999],sum;

vector<int> occur[999];



int main(){

scanf("%s",c+1);

int i,j,n=strlen(c+1);

if (n==2){

  if (c[1]==c[2]) printf("1 2");

  else puts("-1 -1");

  return 0;

  }

for (i=1;i<=n-2;++i){

  memset(cnt,0,sizeof cnt);

  for (j=i;j<=i+2;++j){

    if (++cnt[c[j]]>1) return printf("%d %d",i,i+2),0;

    }

  } 

puts("-1 -1");

}