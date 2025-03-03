#include<cstdio>



using namespace std;



char c[1000001];

int a[1000001];

int main(){

	int n;

	scanf("%d",&n);

	scanf("%s",c+1);

	int ans=0;

	for(int i=1;i<=n;i++){

		int w=1;

		for(int j=0;j<20;j++)

			if(!(n-1>>j&1)&&((i-1>>j)&1))w=0;

		int z=w?c[i]-'1':0;

		a[i]=z;

		ans^=z;

	}

	int ok=0;

	for(int i=1;i<=n;i++)

		if(c[i]=='2')ok=1;

	if(!ok){

		printf("%d\n",ans&2);

	}

	else printf("%d\n",ans&1);

}
