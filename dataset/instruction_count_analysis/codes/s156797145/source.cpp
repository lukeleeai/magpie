#include"stdc++.h"

using namespace std;

char s[10000],c;

int main(){

	scanf("%s",s);

	int len=strlen(s);

	for(int i=0;i<len;i++)

		for(int j=i+1;j<len;j++)

			if(s[i]==s[j]){

				printf("no");

				return 0;

			}

	printf("yes");

}