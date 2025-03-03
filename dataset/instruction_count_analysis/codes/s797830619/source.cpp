#include <cstdio>

int h,w,d;

int main(){

	scanf("%d%d%d",&h,&w,&d);

	for (int i=1;i<=h;i++){

		for (int j=1;j<=w;j++){

			int x=(i+j)/d%2;

			int y=(1000+i-j)/d%2;

			char c="RGBY"[2*x+y];

			printf("%c",c);

		}

		printf("\n");

	}		

}