#include<stdio.h>

#include<cstdio>

#include<iostream>

#include<algorithm>

#include<string>

#include<math.h>

#include<vector>

#include<queue>

#include<map>

#include<stack>

#include<fstream>

#include<stdlib.h>

#include<set>

#include<climits>

#include<cmath>

#include<memory.h> 

#include<sstream>

#include<time.h>

using namespace std;

const long long BIGER=1000000000000000;

const int BIG=1000000000;

long long a[101];

long long g=1;

string st;

long long s=0;

long long ypa(long long k)

{

	if(k==st.size())

	{

		for(long long i=1;i<=g;i++)

		{

			cerr<<a[i]<<" ";

			s+=a[i];

		}

		cerr<<endl;

	}

	else

	{

		a[g]=a[g]*10+st[k]-'0';

		ypa(k+1);

		a[g]=(a[g]-st[k]+'0')/10;

		g++;

		a[g]=a[g]*10+st[k]-'0';

		ypa(k+1);

		a[g]=(a[g]-st[k]+'0')/10;

		g--;

	}

	return 19260817;

}

int main()

{

	cin>>st;

	a[1]=st[0]-'0';

	ypa(1);

	cout<<s;

	return 0;

}