#include<cstdio>



using namespace std;



int a[100001],b[100001];

int main(){

	int n;

	scanf("%d",&n);

	for(int i=1;i<=n;i++)

		scanf("%d",&a[i]);

	long long s1=0,s2=0,s3=0;

	for(int i=1;i<=n;i++){

		scanf("%d",&b[i]);

		a[i]-=b[i];

		s1+=a[i];

		if(a[i]>0)s2+=a[i];

		if(a[i]<0)s3+=-(a[i]/2);

	}

	if(s2>s3||s2>-s1){

		printf("No\n");

		return 0;

	}

	printf("Yes\n");

}
