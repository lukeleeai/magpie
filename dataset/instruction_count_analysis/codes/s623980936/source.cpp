#include <cstdio>

#include <cstring>

#include <iostream>

#include <algorithm>

#include <cmath>



using namespace std;



int n;

int seq[300050];



bool chk(int mid)

{

	int val = seq[1];

	for(int i = 2;i <= n; i += 2)

	{

		if(val >= mid) val = max(val + seq[i + 1] - seq[i],seq[i + 1]);

		else val += seq[i + 1] - seq[i];

	}

	return val >= mid;

}



int main()

{

	scanf("%d",&n);

	int ji = 0,ou = 0;

	for(int i = 1;i <= n; ++ i)

	{

		scanf("%d",&seq[i]);

		if(i % 2) ji += seq[i];

		else ou += seq[i];

	}

	if(n % 2 == 0)

	{

		printf("%d %d\n",max(ji,ou),min(ji,ou));

	}

	else

	{

		int l = 0,r = 300000000,ans;

		while(l <= r)

		{

			int mid = (l + r) >> 1;

			if(chk(mid)) ans = mid,l = mid + 1;

			else r = mid - 1;

		}

		printf("%d %d\n",ou + ans,ji - ans);

	}

}