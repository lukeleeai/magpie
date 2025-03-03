#include <cmath>

#include <cstdio>

#include <cstring>

#include <iostream>

#include <algorithm>



using namespace std;



int n , c;



const int N = 505;



int l[N];



double f[N][2 << 7] , ans , t;



int main(){

	cin >> n >> c;

	for(int i = 0; i < n; i++)

		cin >> l[i];

	sort(l , l + n);

	do{

		memset(f, 0, sizeof(f));

        f[l[n - 1] * n][0] = 1;

        for(int i = 0; i <= n * c; i++)

            for(int j = i; j <= n * c; j++)

                for(int S = 0; S < (1 << n - 1); S++)

                    if(i % n && !((S >> (i % n - 1)) & 1))

                        f[min(n * c, max(j, i + l[i % n - 1] * n))][S | (1 << (i % n - 1))] += f[j][S];

        ans += f[n * c][(1 << n - 1) - 1];

        ++t;

	}while(next_permutation(l , l + n - 1));

	printf("%.15lf" , (double)ans / t / pow(c , n - 1));

	return 0;

}