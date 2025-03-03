#include<cmath>

#include<cstdio>

#include<cstdlib>

#include<map>

#include<cstring>

#include<algorithm>

#define ll long long

#define Max(x,y) ((x) > (y) ? (x) : (y))

#define Min(x,y) ((x) < (y) ? (x) : (y))

#define Abs(x) ((x) > 0 ? (x) : -(x))

#define mod 1000000007

#define N 300010

using namespace std;

inline ll read(){

	ll x = 0,f = 1;char ch = getchar();

	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}

	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0';ch = getchar();}

	return x*f;

}



int n;

int q[N],head1,head2;



int main(){

	int n = read();

	q[100010] = read();

	head1 = 100010;

	head2 = 100010;

	for(int i = 1;i < n;i++){

		if(i&1) q[++head1] = read();

		else q[--head2] = read();

	}

	if(!(n&1)){

		for(;head1 >= head2;head1--)

			printf("%d ",q[head1]);

	}

	else{

		for(;head2 <= head1;head2++)

			printf("%d ",q[head2]);

	}

	puts("");

	return 0;

}