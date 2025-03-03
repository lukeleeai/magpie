#include <iostream>

using namespace std;



int ans(int* a, int* b , int n, int q)

{

	if(b[n] >= 0)

		return b[n] ;

	for(int i = 0 ; i < q ; i++)

	{

		if(a[i]>n)

        {

            b[n] = max(b[n] , 0);

			break;

        }

        b[n] = max(b[n] , ans(a,b,n-a[i],q)^1);

	}

	return b[n];

}

int main() 

{

	int q , n ;

	cin >> q >> n ;

	int a[q] ;

	for(int i = 0 ; i < n ; i++)

		cin >> a[i] ;

	int b[n+1] ;

    for(int i = 0 ; i <= n ; i++)

        b[i] = -1;

    b[0] = 0 ;

    int flag = ans(a,b,n,q);

    if(flag == 0)

        cout << "Second" << endl;

    else

        cout << "First" << endl;

	return 0;

}