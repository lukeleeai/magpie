#include<cstdio>

#define r register

int n;

char ch[305][305];

#define loop(x) (x>=n?(x-n):x)

int main(){

	scanf("%d",&n);r int ans=0;

	for(r int i=0;i<n;i++)scanf("%s",ch[i]);

	for(r int i=0,f=1;i<n;i++,f=1){

		for(r int j=0;j<n&&f;j++)

			for(r int k=j+1;k<n&&f;k++)

				f=(ch[j][loop(k+i)]==ch[k][loop(j+i)]);

		ans+=n*f;

	}

	printf("%d\n",ans);

}