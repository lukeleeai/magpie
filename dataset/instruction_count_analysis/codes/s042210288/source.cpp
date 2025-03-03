#include <iostream>

#include<cstdio>

#include <string>

#include <map>

#include <algorithm>

using namespace std;



long T;

int x = 0;

string a = "3";

string b = "5";

string c = "7";



void upnumber(long n)

{

	if (n <= T)

	{

		string N = to_string(n);

		if (N.find(a) != string::npos && N.find(b) != string::npos && N.find(c) != string::npos)

		{

			x++;

		}

		upnumber(n * 10 + 3);

		upnumber(n * 10 + 5);

		upnumber(n * 10 + 7);

	}

}



int main()

{

	cin >> T;

	upnumber(0);

	cout << x;



}