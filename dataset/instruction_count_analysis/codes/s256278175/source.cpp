#include <iostream>

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <list>

#include <vector>

#include <unistd.h>

#include <algorithm>

#define ll long long

using namespace std;

ll N;

ll m[301][301]; 

int main(){

	cin >> N;

	memset(m, -1, sizeof(m));

	for ( ll i = 0 ; i < N ; i ++ ){

		for ( ll j = 0 ; j < N ; j ++ ){

			cin >> m[i][j];

		}

	}

	ll tot = 0;

	for ( ll i = 0 ; i < N ; i ++ ){

		for ( ll j = 0 ; j < N ; j ++ ){

			if ( i == j ) continue;

			bool flag = true;

			for ( ll k = 0 ; k < N ; k ++ ){

				if ( k == i || k == j ) continue;

				if ( m[i][k] + m[k][j] < m[i][j] )  {

					cout << -1 << endl;

					return 0;

				}

				if ( m[i][k] + m[k][j] == m[i][j] ) flag = false;

			}

			if ( flag ){

					tot += m[i][j];

			}                

		}

	}

	cout << tot / 2 << endl;

	return 0;

}