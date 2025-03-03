#include <iostream>

#include <cstdio>

#include <cstring>

using namespace std;



const int maxn = 100010;



char str[maxn], cur[maxn];

int len;

int l[maxn];



void init()

{

	memset(l,0,sizeof(l));

	int cnt = 0;

	for (int i=0;i<=len;i++)

	{

		if (str[i] == '0' || i == len)

		{

			for (int j=i-cnt;j<=i-1;j++) l[j] = cnt;

			cnt = 0;

			continue;

		}

		cnt++;

	}

	//for (int i=0;i<len;i++) cout<<l[i]<<" ";

	//cout<<endl;

}



bool check(int k)

{

	for (int i=0;i<len;i++)

	{

		if (str[i] == '0') continue;

		if (i >= k || len-1-i>=k) continue;

		if (l[i] >= k) continue;

		return false;

	}

	return true;

}



int main()

{

	//freopen("D.in","r",stdin);

	scanf("%s",str);





	len = strlen(str);

	init();

	int lb = 1, ub = len + 1;

	while (ub > lb + 1)

	{

		int mid = (lb + ub)/2;

		if (check(mid)) lb = mid;

		else ub = mid;

	}



	for (int i=0;i<len;i++) str[i] = (str[i]=='1')?'0':'1';

	init();

	int lb2 = 1, ub2 = len + 1;

	while (ub2 > lb2 + 1)

	{

		int mid = (lb2 + ub2)/2;

		if (check(mid)) lb2 = mid;

		else ub2 = mid;

	}



	printf("%d\n",max(lb,lb2));

	return 0;

}
