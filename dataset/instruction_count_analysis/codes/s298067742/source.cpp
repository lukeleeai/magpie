#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

int n,ans,x;

void read(int &x)

{

    int f=1;x=0;char s=getchar();

    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}

    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}

    x*=f;

}

int PD(int x)

{

	int count=0;

    while(x){

        if(x&1){

            return count; 

        }

        count++; 

        x>>=1; 

    }

    return count; 

}

int main()

{

	read(n);

	for(int i=1;i<=n;i++)

	{read(x);

		ans+=PD(x);

	}

	printf("%d",ans);

}
