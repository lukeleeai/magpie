#include<cstring>

#include<cstdio>

using namespace std;

char s[666233];

int main(void){

	scanf("%s",s);

	for(int i=0;i<strlen(s);i+=2) putchar(s[i]);

	puts("");

	return 0;

}