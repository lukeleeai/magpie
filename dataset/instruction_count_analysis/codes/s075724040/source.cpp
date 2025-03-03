#include<cctype>

#include<cstdio>

#include<algorithm>

using i64=long long;

int fetc(){int c=getchar();while(c^'-'&&c^'+')c=getchar();return c;}

int read(){int x=0,c=getchar();while(isspace(c))c=getchar();while(isdigit(c))(x*=10)+=c&15,c=getchar();return x;}

int main()

{

    int n=read();i64 ans=read(),b=-1e18,c=-1e18;

    for(int x;n^1;--n) fetc()=='-'?(x=read(),c=b+x,ans=b=std::max(ans-x,c)):(x=read(),ans+=x,c+=x,b=std::max(b-x,c));

    printf("%lld",ans);

}
