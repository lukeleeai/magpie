#include <cstdio>

#include <algorithm>

#define max(a,b)a>b?a:b



int ans[100070];

int R(){

	int x=0;char ch;

	do{ch=getchar();}while(ch>57||ch<48);

	do{x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}while(ch>=48&&ch<=57);

	return x;

}

void W(int c){

	if(c>9)W(c/10);

	putchar('0'+c%10);

}



char ch[1000000];



signed main(){

	int n=R(),m=R(),p,i,now;

	scanf("%s",ch);

	now=n;

	i=n;

	p=m;

	while(i>m){

		

		while(ch[i-p]=='1'){

			p--;

			if(p==0)

				break;

		}

		if(p==0)

			break;

		ans[now--]=p;

		i-=p;

		p=m;

	}

	if(p==0){

		printf("-1");

	}

	else{

		printf("%d ",i);

		for(int i=now+1;i<=n;i++){

			printf("%d ",ans[i]);

		}

	}

}