//CODE FESTIVAL 2017 qual A - D

//https://code-festival-2017-quala.contest.atcoder.jp/tasks/code_festival_2017_quala_d

#include <cstdio>



const char c[]={'R','Y','G','B'};

int n,m,d,b;



int main(){

	scanf("%d%d%d",&n,&m,&d);b=10000*d;

	for(int i=0;i<n;++i,putchar(10))

	for(int j=0;j<m;++j)

		putchar(c[(((i+j)/d&1)<<1)|((i-j+b)/d&1)]);

	return 0;

}