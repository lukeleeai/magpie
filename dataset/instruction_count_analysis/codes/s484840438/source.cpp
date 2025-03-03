#include <cstdio>

bool A[200001],B[200001];

inline int read(){

  int ans=0,c=getchar_unlocked();

  while(c<'0'||c>'9')c=getchar_unlocked();

  while(c>='0'&&c<='9'){ans=ans*10+(c-'0'); c=getchar_unlocked();}

  return ans;

}

int main(){

  int n,m,a,b;n=read();m=read();

  while(m--){a=read();b=read();

    if(a==1)A[b]=true;

    if(b==n)B[a]=true;

  }

  for(int i=1;i<=n;i++)if(A[i]&&B[i])return puts("POSSIBLE"),0;

  puts("IMPOSSIBLE");

  return 0;

}