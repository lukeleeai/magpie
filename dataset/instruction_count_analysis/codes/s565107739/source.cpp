#include <cstdio>

#include <algorithm>

//#include <cstring>

//#include <cctype>

using namespace std;

typedef long long ll;

//////////LOCALS//////////

#ifdef OFFLINE

int unused_variable_name=(freopen("in.txt","r",stdin),1);

#endif

//////////LOCALS//////////

int arr[110];

int main(){

	int n,m,flag=0;

	scanf("%d%d%d",&n,&m,&arr[0]);

	if(m==1){

		if(n==1) printf("1\n1\n1\n");

		else printf("%d\n2\n%d 1\n",n,n-1);

		return 0;

	}

	flag=arr[0]%2;

	for(int i=1;i<m;i++){

		scanf("%d",&arr[i-(flag/2)]);

		if(arr[i-(flag/2)]%2){

			switch(flag++){

			case 0:

				arr[i]=arr[0]^arr[i];

				arr[0]=arr[0]^arr[i];

				arr[i]=arr[0]^arr[i];

				break;

			case 1:

				arr[m-1]=arr[i];

				break;

			case 2:

				printf("Impossible\n");

				return 0;

			}

		}

	}

	for(int i=0;i<m;i++){

		printf("%d%c",arr[i],i==m-1?'\n':' ');

	}

	if(arr[0]==1){

		printf("%d\n",m-1);

	} else {

		printf("%d\n%d ",m,arr[0]-1);

	}

	for(int i=1;i<m-1;i++){

		printf("%d ",arr[i]);

	}

	printf("%d\n",arr[m-1]+1);

	return 0;

} 