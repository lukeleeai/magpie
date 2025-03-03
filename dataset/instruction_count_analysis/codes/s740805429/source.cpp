#include <iostream>

#include <cstdio>

#include <cstring>

#include <algorithm>

using namespace std;



struct number

{

	int a;

	int b;

};



bool compare(number a, number b)

{

	return a.a < b.a;

}



int N[201000], dp[201000];

number num[201000];



int main ()

{

	int n;

	cin >> n;

	

	if(n == 1)

	{

		cout << "0" << endl;

		return 0;

	}

	

	for(int i = 0; i < 201000; i++)

	{

		N[i] = 0;

		dp[i] = 1;

		num[i].a = 0;

		num[i].b = 0;

	}

	

	int x;

	for(int i = 0; i < n; i++)

	{

		scanf("%d", &x);

		N[i] = x;

		num[i].a = x;

		num[i].b = i;

	}

	

	sort(num, num + n, compare);

	

//	for(int i = 0; i < n; i++)

//		cout << num[i].a << " " << num[i].b << endl;

	

	int max = 0;

	for(int i = 1; i < n; i++)

	{

		if(num[i].b > num[i - 1].b)

			dp[i] = dp[i - 1] + 1;

		

		if(dp[i] > max)

			max = dp[i];

	}

	

	cout << n - max << endl;

	

	return 0;

}