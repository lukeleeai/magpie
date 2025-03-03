#include<cstdio>



int n,ne,cur;

int a[100005];



int main()

{

	scanf("%d",&n);

	for(int i = 1;i <= n; i++){

		scanf("%d",&cur);

		if(!a[cur]) {

			a[cur] = 1;

			ne ++;//多少不同的数字

		}

	}

	int ans;

	int pan = n - ne; //重复的数字

	if(pan % 2 == 0) ans = ne;

	else ans = ne - 1;

	printf("%d",ans);

}