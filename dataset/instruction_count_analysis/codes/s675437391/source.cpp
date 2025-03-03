#include<cstdio>

#include<cstring>

using namespace std;

int main()

{

	char a[1000],b[1000];

	scanf("%s %s",&a,&b);

	int la=strlen(a);

	int lb=strlen(b);

	if(la>lb) printf("GREATER\n");

	else if(la<lb) printf("LESS\n");

	else{

		for(int i=0;i<la;i++){

		        if(a[i]>b[i]){

		        	printf("GREATER\n");break;

				}

		        if(a[i]<b[i]){

		        	printf("LESS\n");break;

				}

		        if(a[i]==b[i]){

                   if(i==la-1 && a[i]==b[i])

		        	  printf("EQUAL\n");

		           else continue;

				}

		}

	}

}