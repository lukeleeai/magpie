#include <iostream>

#include<cstdio>

#include<algorithm> 

#include<cstring>

using namespace std;



//#pragma warning(disable:4996)



struct res

{

	char ch[21];

	int s = -1;

	int i = -1;

};



res r[101];



bool comp(res& r1, res& r2)

{

	int c = strcmp(r1.ch, r2.ch);

	if (c < 0)return true;

	if (c > 0)return false;

	return r1.s > r2.s;

}



int n;

int main()

{

	//cin >> n;

	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)

	{

		scanf("%s", r[i].ch);

		scanf("%d", &r[i].s);

		r[i].i = i;

	}

	sort(&r[1], &r[n]+1, comp);



	for (int i = 1; i <=n; ++i)

		printf("%d\n", r[i].i);



	return 0;

}


