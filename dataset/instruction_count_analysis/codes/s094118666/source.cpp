#include<cstdio>

#include<cstring>

using namespace std;

const int maxl=100010;

int l;

char str[maxl];

int main(){

	scanf("%s",&str);

	l=strlen(str);

	if(l%2!=0){

		printf("No\n");

		return 0;

	}

	for(int i=0;i<l/2;i++){

		if(str[i]=='b'&&str[l-i-1]!='d'){

			printf("No\n");

		    return 0;

		}

		if(str[i]=='d'&&str[l-i-1]!='b'){

		    printf("No\n");

		    return 0;

		}

		if(str[i]=='p'&&str[l-i-1]!='q'){

			printf("No\n");

		    return 0;

		}

		if(str[i]=='q'&&str[l-i-1]!='p'){

			printf("No\n");

		    return 0;

		}

	}

	printf("Yes\n");

	return 0;

}