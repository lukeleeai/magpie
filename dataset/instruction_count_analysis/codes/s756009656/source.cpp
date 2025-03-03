#include <stdio.h>

int main()

{

	int H,A;

	scanf("%d%d",&H,&A);

	H%A<=0?printf("%d",H/A):printf("%d",H/A +1);//kalo yang pertama kondisi contoh 10/5 jdi habis kalo kondisi kedua contoh 10/4 jdi sisa dan harus ditambah 1 kali atatck

	return 0;

}
