#include<cstdio>

using namespace std;

int a[100005];

int cnt[2][100005];

int main(){

	int n;

	scanf("%d",&n);

	for(int i=1;i<=n;i++){

		scanf("%d",&a[i]);

		cnt[0][a[i]]++;

		cnt[1][a[i]]++;

	}

	int ok=0,sum;

	int remain;

	sum=n-1;

	remain=n-1-a[1];

	cnt[0][a[1]]-=1;

	if(remain>=0&&cnt[0][a[1]]>=remain){

		sum-=remain;

		cnt[0][a[1]]-=remain;

		remain+=1;

		if(cnt[0][a[1]-1]+cnt[0][a[1]]==sum&&cnt[0][a[1]]<=remain&&cnt[0][a[1]]>0){

			ok=1;

			//printf("!\n");

		}

	}

	

	sum=n-1;

	remain=n-1-a[1];

	cnt[1][a[1]]-=1;

	if(remain>=0&&cnt[1][a[1]+1]>=remain){

		sum-=remain;

		cnt[1][a[1]+1]-=remain;

		if(cnt[1][a[1]+1]+cnt[1][a[1]]==sum&&cnt[1][a[1]+1]<=remain&&(cnt[1][a[1]+1]>0&&remain>0||cnt[1][a[1]+1]==0&&remain==0)){

			ok=1;

			//printf("?\n");

		}

	}

	

	if(ok)

		printf("Yes\n");

	else

		printf("No\n");

	

	

} 