#include "stdc++.h"



using namespace std;



long long int n,x=0,k=0,o=0,u=0,s=0,l=1e10,a[300000];

int main()

{

	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin >> n;

	

	for(int i=1; i<=n; i++)	

	{

		cin >> a[i];

		s+=a[i];

		k=max(k,a[i]);

		l=min(l,a[i]);

	}

	x=n*(n+1);

	x/=2;

	if(s%x!=0)

	{

		cout << "NO";

		return 0;

	}

	x=s/x;

	if(l<x || n*x<k)

	{

                cout << "NO";

                return 0;

        }

	s=0;

	//cout << "OK";

	for(int i=1; i<=n; i++)

        {

		if(i<n)

                	l=a[i+1]-a[i];

		else

			l=a[1]-a[n];

		k=x;

		if(l>=0)

		{

			k-=l;

			if(k%n!=0)

			{

				cout << "NO";

				return 0;

			}

			k/=n;

			s+=k;

		}

		else

		{

			l*=-1;

			o=l%(n-1);

			if(o>0)

				o=n-1-o;	

			l+=o;

			l/=(n-1);

			k-=o;

			k-=l;

			if(k%n!=0)

                        {

                                cout << "NO";

                                return 0;

                        }

			k/=n;

			k+=l;

			s+=k;

		}	

		//cout << i << ' ' << s << endl;

        }	

	//cout << s << " OK" << endl;

	if(s!=x)

	{

		cout << "NO";

		return 0;

	}

	cout << "YES";

	return 0;

}
