#include <cstdio>

char s[100005];

inline int getstring(char *_s){

	int l=0;

	for(char ch=getchar();ch!='\n';ch=getchar(),l++)

		_s[l]=ch;

	return l;

}

int main(){

	int l=getstring(s);

	printf("%s",(s[0]==s[l-1])^(l%2)?"First":"Second");

	return 0;

}