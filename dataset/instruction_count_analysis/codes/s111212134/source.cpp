#include<cstdio>

#include<iostream>

#include<string>

#include<algorithm>

using namespace std;





int main()

{

	int a[5], len = 0;

	string st;



	for (int i = 1; i <= 3; i++)

	{

		cin >> a[i];

	}

	

	if (a[3] - a[2] == a[2] - a[1])

		cout << "YES" << endl;

	else

		cout << "NO" << endl;



	return 0; 

}