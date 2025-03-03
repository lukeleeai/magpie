#include "stdc++.h"



#define fr first

#define sc second

#define pb push_back

#define mk make_pair

#define mt make_tuple

#define int long long

#define OK puts("OK")

#define sz(s) (int)s.size()

#define all(s) s.begin(), s.end()



using namespace std;





int N, X[1009], Y[1009], H[1009];

vector< tuple < int , int , int > > v;



 main() {

	cin >> N;

	tuple < int , int , int > G = mt ( -1 , -1 , -1 ) ;

	for (int i = 1; i <= N; i++)

    {

		cin >> X[i] >> Y[i] >> H[i];

		if ( H[i] >= 1)

		G = mt (X[i], Y[i], H[i]);

	}

    for (int j = 0; j <= 100; j++)

	 {

	   for (int i = 0; i <= 100; i++) {

			int V = get<2> (G) + abs ( get<0> (G) - i) + abs(get<1>(G) - j);

            V = max(V, 0LL);

            bool flag = true;



			for (int k = 1; k <= N; k++)

            {

				int VV = V - abs( X[k] - i) - abs ( Y[k] - j );

                VV = max(VV, 0LL);

				if (H[k] != VV)

                    flag = false;

			}

			if (flag == true)

                v.push_back(make_tuple(i, j, V));

		}

	}

//	if (vec.size() == 1)

    		cout << get<0> ( v[0] ) << " " << get<1> ( v[0] ) << " " << get<2> (v[0]) << endl;



}


