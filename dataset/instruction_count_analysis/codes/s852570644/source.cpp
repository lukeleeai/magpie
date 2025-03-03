#include<stdio.h>

char s[10];

int c[10][10],f[10];

int h,w,k,ans=0;

int judge(int x,int y)

{

	int tot=0;

	//printf("\n");

	for(int i=0;i<h;i++)for(int j=0;j<w;j++)

	{

		if((f[i]&x)==0&&(f[j]&y)==0)tot+=c[i][j];

	//	printf("%d %d\n",(f[i]&x),(f[j]&y));

	}

	//printf("%d\n",tot);

	if(tot==k)return 1;

	return 0;

}

int main()

{

    f[0]=1;

    for(int i=1;i<=6;i++)f[i]=f[i-1]*2;

    scanf("%d%d%d",&h,&w,&k);

    for(int i=0;i<h;i++)

    {

    	scanf("%s",s);

    	for(int j=0;j<w;j++)if(s[j]=='#')

    		c[i][j]=1;

	}

	for(int i=0;i<f[h];i++)for(int j=0;j<f[w];j++)

		if(judge(i,j))ans++;

	printf("%d\n",ans);

    return 0;

}