#include "cstdio"

#include "cstring"

int max(int x,int y){

	return x>y?x:y;

}

int min(int x,int y){

	return x<y?x:y;

}

char s[100005];int ss=1e9;

int main(){

	scanf("%s",s);int x=strlen(s);

	for(int i=1;i<x;i++){

		if(s[i]!=s[i-1])ss=min(ss,max(i,x-i));

	}

	printf("%d\n",min(ss,x));

} 