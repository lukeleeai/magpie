#include "stdc++.h"

using namespace std;



int main(int argc, char const *argv[])

{

	int nums;

	while(~scanf("%d",&nums)){

		int fr[nums],bk[nums],arr[nums];

		for (int i = 0; i < nums; ++i)

			scanf("%d",&arr[i]);

		fr[0]=arr[0];

		bk[nums-1]=arr[nums-1];

		for (int i = 1; i < nums; ++i)

			fr[i]=__gcd(arr[i],fr[i-1]);

		for (int i = nums-2; i >= 0; --i)

			bk[i]=__gcd(arr[i],bk[i+1]);



		// for (int i = 0; i < nums; ++i)

		// {

		// 	printf("fr[%d]==%d\n",i,fr[i] );

		// }



		// for (int i = 0; i < nums; ++i)

		// {

		// 	printf("bk[%d]==%d\n",i,bk[i] );

		// }



		int ans=0;

		for (int i = 0; i < nums; ++i)

		{

			if (i==0)

				ans=max(ans,bk[i+1]);

			else if (i==nums-1)

				ans=max(ans,fr[i-1]);

			else{

				ans=max(ans, __gcd( bk[i+1],fr[i-1]) );

			}



		}

		printf("%d\n",ans);

	}

	return 0;

}