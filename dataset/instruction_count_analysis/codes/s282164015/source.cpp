#include<stdio.h>

#include<string.h>





int main(){

	int a,b;

	

	scanf("%d %d", &a,&b);

	

	int tambah=a+b;

	int kurang=a-b;

	int kali=a*b;

	

	printf("%d\n", tambah>=kurang&&tambah>=kali?tambah:(kurang>=kali&&kurang>=tambah?kurang:kali));

	

	return 0;

}