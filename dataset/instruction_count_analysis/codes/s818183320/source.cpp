#include<cstdio>

int main(){

	int n;

	while(~scanf("%d",&n))

	{

		int jin=0;

		int ti[100050]={0};

		int xi[100050]={0};

		int yi[100050]={0};

		int i;

		for(i=1;i<=n;i++)

		{

			scanf("%d%d%d",&ti[i],&xi[i],&yi[i]);

			int sum=xi[i]+yi[i]-xi[i-1]-yi[i-1];

			if(jin!=0)continue;

			if(sum<0){

				sum=-sum;

			}

			if(ti[i]>=sum){

				int l1=(ti[i]-ti[i-1])%2;

				int l2=sum%2;

				if(l1!=l2){

					jin=5;

				}

			}else {

				jin=5;

			}

		}

		if(jin){

			printf("No\n");

		}else {

			printf("Yes\n");

		}

		

	}

	return 0;

}