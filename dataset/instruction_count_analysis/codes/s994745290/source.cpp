#include<cstdio>

#include<cstring>

char c[100005];

int s;

int main(){

	scanf("%s",c);

	for(int i=0;i<strlen(c);++i){

		if(c[i]=='g'&&i%2)++s;

		if(c[i]=='p'&&i%2==0)--s;

	}

	printf("%d\n",s);

    return 0;

}
