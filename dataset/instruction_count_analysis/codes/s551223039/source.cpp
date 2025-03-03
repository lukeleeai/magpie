#include<iostream>

#include<stdio.h>

#include<math.h>

using namespace std;

int main() {

	int h,w;

//	scanf("%d %d",&h,&w);

	cin>>h>>w;

	char str[1001][1001]= {'\0'};

	int i,j;

	fflush(stdin);

	for(i=1; i<=h; i++) {

		for(j=1; j<=w; j++) {

//			scanf("%c",str[i][j]);

			cin>>str[i][j];

		}



	}

//	for(i=1; i<=h; i++) {

//		gets(str[i]);

//	}

	for(i=1; i<=h; i++) {

		for(j=1; j<=w; j++) {

			printf("%c",str[i][j]);

		}

//		printf("%s",str[i]);

		printf("\n");

		for(j=1; j<=w; j++) {

			printf("%c",str[i][j]);

		}

//		printf("%s",str[i]);

		printf("\n");

	}

//	double temp;

//	for(i=1; i<=h; i++) {

//		gets(str[i]);

//	}

//	for(i=1; i<=h*2-1; i++) {

//		for(j=0; j<w; j++) {

//			temp=floor((i+1)/2);

//			int a=(int)temp;

//			printf("%c",str[a][j]);

//		}

//		printf("\n");

//	}

//	for(j=0; j<w; j++) {

//		temp=floor((i+1)/2);

//		int a=(int)temp;

//		printf("%c",str[a][j]);

//	}

}