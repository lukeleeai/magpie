#include<cstdio>

#define sev en

using namespace std;

#define N 100010



int a[N],cnt[2],n;



int gcd(int a,int b){

	if(b == 0)

		return a;

	return gcd(b,a % b);

}



int dg(){

	for(int i = 1;i <= n;i++)

		if(a[i] & 1)

			a[i]--;

	cnt[0] = cnt[1] = 0;

	int w = a[1];

	for(int i = 2;i <= n;i++)

		w = gcd(w,a[i]);

	for(int i = 1;i <= n;i++)

		cnt[(a[i] /= w) & 1]++;

	if(cnt[0] & 1)

	return 1;

	else if(cnt[1] > 1)

	return 0;

	else{

		for(int i = 1;i <= n;i++)

		if(a[i] == 1)

		return cnt[0] & 1 ? 1 : 0;

		return dg() ^ 1;

	}

}



int main(){

	scanf("%d",&n);

	for(int i = 1;i <= n;i++){ 

		scanf("%d",&a[i]);

		cnt[a[i] & 1]++;

	}

	if(cnt[0] & 1)

	printf("First");

	else if(cnt[1] > 1)

	printf("Second");

	else{

		for(int i = 1;i <= n;i++)

		if(a[i] == 1){

			printf(cnt[0] & 1 ? "First" : "Second");

			return 0;

		}

		if(dg() ^ 1)

		printf("First");

		else

		printf("Second");

	}

	return 0;

}