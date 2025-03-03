#include<iostream>

#include<iomanip>

#include<cmath>

#include<cstdio>

#include<cstdlib>

#include<cstring>

#include<algorithm>

#include<set>

#include<map>

#include<queue>

#include<stack>

#include<vector>

#include<cctype>

#define szxb 13

#define F(a,b,c) for(register int (a)=(b);(a)<=(c);(a)++)

#define PDXD(a,b) (!(a-b))

#define PDBXD(a,b) (!(!(a-b)))

#define CON continue;

#define GO goto endreturn;

using namespace std;

int a[szxb][szxb];

int main()

{

	F(i,1,3){F(j,1,3){scanf("%d",&a[i][j]);}}

	int a1,a2,a3,b1,b2,b3,c1,c2,c3;

	F(i,0,100){a1=(a[1][1]-i);a2=(a[1][2]-i);a3=(a[1][3]-i);F(j,0,100){b1=(a[2][1]-j);b2=(a[2][2]-j);b3=(a[2][3]-j);if((PDBXD(a1,b1))||(PDBXD(a2,b2))||(PDBXD(a3,b3))){CON;}F(k,0,100){c1=(a[3][1]-k);c2=(a[3][2]-k);c3=(a[3][3]-k);if((PDXD(a1,c1))&&(PDXD(a2,c2))&&(PDXD(a3,c3))){printf("Yes");GO;}}}}

	printf("No");

	endreturn:return putchar(10),0;

}