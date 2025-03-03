#include<cstdio>

#include<cstring>

#include<cmath>

#include<string>

#include<iostream>

using namespace std;



int main()

{

    long long int a, b, c, d, e;



    while (cin >> a >> b)

    {

        c = a + b;

        d = a - b;

        e = a * b;



        a = max(c, d);

        a = max(a, e);



        cout << a << endl;

    }



	return 0;

}
