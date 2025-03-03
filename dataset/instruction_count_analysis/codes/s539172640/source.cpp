	#include <iostream>

	#include <string>

	#include <stdio.h>

	#include <queue>

	#include <stack>

	#include <string.h>

	#include <algorithm>

	#include <math.h>

	//#include "stdc++.h"

	#define ll long long

	#define wtcl return

	using namespace std;

	

	inline int read()

	{

	    ll s = 0, f = 1;

	    char ch = getchar();

	    for(; ch < '0' || ch > '9'; ch = getchar()) if(ch == '-') f = - 1;

	    for(; ch >= '0' && ch <= '9'; ch = getchar()) s = ((s << 3ll) + (s << 1ll) + (ch ^ 48ll));

	    return s * f ;

	}

	

	int main()

	{

	    int n;

	    while(cin>>n)

	    {

	    	int num[200005];

	    	int a[200005];

	    	for(int i=0;i<n;i++)

	    	{

	    		num[i] = read();

	    		a[i] = num[i];

			}

			sort(a,a+n);

			for(int i=0;i<n;i++)

			{

				int pos = upper_bound(a,a+n,num[i])-a;

				//cout<<pos<<" ";

				if(pos<=(n/2))

					cout<<a[n/2]<<endl;

				else cout<<a[n/2-1]<<endl;

			}

	    		

		}

	    wtcl 0;

	}