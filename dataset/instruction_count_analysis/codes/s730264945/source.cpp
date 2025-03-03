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

inline bool read(ll &x){

  x=0;int f=1;char c=gc();

  for (;!isdigit(c)&&~c;c=gc()) f^=c=='-';

  if (!~c) return 0;

  for (;isdigit(c);c=gc()) x=(x<<3)+(x<<1)+(c^'0');

  return x=f?x:-x,1;

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

string s;

int main(){

ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

cin>>s;

for (;!s.empty();){

  string tmp=s.substr(s.size()-5,5);

  if (tmp=="erase"||tmp=="dream"){

    s.erase(s.size()-5,5);

    continue;

    }

  tmp=s.substr(s.size()-6,6);

  if (tmp=="eraser"){

    s.erase(s.size()-6,6);

    continue;

    }

  tmp=s.substr(s.size()-7,7);

  if (tmp=="dreamer"){

    s.erase(s.size()-7,7);

    continue;

    }

  return puts("NO"),0;

  }

puts("YES");

}