#include <iostream>

#include <tuple>

#include <set>

#include <vector>

#include <deque>

#include <algorithm>



typedef std::tuple<int, int, double> T;



std::vector<T> dis_city;

std::deque<double> dis;

std::vector<int> flag;

std::vector<int> num_basya;

int n, m, p, a, b;



double cost[2][2][2][2][2][2][2][2][30][30];

std::vector<std::tuple<int,int>> table;



/*double search(int ima)

{

	if ( num_basya.size() < dis.size() ) {

		return 0xffff;

	}

	if ( ima == b - 1 ) {

		double sum = 0;

		std::deque<double> d = dis;

		std::sort(d.begin(), d.end());

		int j = d.size() - 1;

		for ( int i = num_basya.size() - 1; i >= 0; --i ) {

			sum += d[j] / num_basya[i];

			//std::cout << "d:" << d[j] << " basya:" << num_basya[i] << " sum:" << sum << std::endl;

			j--;

			if ( j < 0 ) break;

		}

		return sum;

	}

	double ans = 0xffff;

	for ( int i = 0; i < dis_city.size(); ++i ) {

		if ( std::get<0>(dis_city[i]) == ima ) {

			if ( flag[std::get<1>(dis_city[i])] == false ) {

				flag[std::get<1>(dis_city[i])] = true;

				dis.push_back(std::get<2>(dis_city[i]));

				//std::cout << std::get<0>(dis_city[i]) << " -> " << std::get<1>(dis_city[i]) << std::endl;

				double tmp = search(std::get<1>(dis_city[i]));

				if ( ans > tmp ) ans = tmp;

				dis.pop_back();

				flag[std::get<1>(dis_city[i])] = false;

			}

		}

	}

	return ans;

}*/



long long unsigned PopCount(long long unsigned x) {

    x = (x & 0x5555555555555555ULL) + ((x & 0xAAAAAAAAAAAAAAAAULL) >> 1);

    x = (x & 0x3333333333333333ULL) + ((x & 0xCCCCCCCCCCCCCCCCULL) >> 2);

    x = (x & 0x0F0F0F0F0F0F0F0FULL) + ((x & 0xF0F0F0F0F0F0F0F0ULL) >> 4);



    x *= 0x0101010101010101ULL;



	return x;

  }



double& acost(int i, int j, int k) 

{

	return cost[i&1][(i&2)>>1][(i&4)>>2][(i&8)>>3][(i&16)>>4][(i&32)>>5][(i&64)>>6][(i&128)>>7][j][k];

}





double search()

{

	for ( int i = 0; i < (1<<n); ++i ) {

		for ( int j = 0; j < m; ++j ) {

			for ( int k = 0; k < m; ++k ) {

				if ( i == 0 && j == k ) {

					acost(i, j, k) = 0;

				} else {

					acost(i, j, k) = 0xffff;

				}

			}

		}

	}



	for ( int i = 0; i < (1<<n); ++i ) {

		int q = std::get<1>(table[i]);

		for ( int l = 0; l < n; l++) {

			if ( q & (1<<l) ) {

				for ( int j = 0; j < m; ++j ) {

					for ( int k = 0; k < m; ++k ) {

						for ( int o = 0; o < dis_city.size(); ++o ) {

							if ( std::get<0>(dis_city[o]) == k ) {

								double c = acost(q^(1<<l),j,std::get<1>(dis_city[o])) + std::get<2>(dis_city[o])/num_basya[l];

								acost(q, j, k) = (acost(q,j,k) < (c)) ? acost(q,j,k) : c;

							}

						}

					}

				}

			}

		}

	}



	double ans = 0xffff;

	for ( int i = 1; i < (1<<n); ++i ) {

		if ( ans > acost(i, a-1, b-1) ) {

			ans = acost(i, a-1, b-1);

		}

	}

	return ans;

}



int main(void)

{



	while(true) {

		dis_city.clear(); dis.clear(); flag.clear(); num_basya.clear();

		std::cin >> n >> m >> p >> a >> b;

		if ( n == 0 && m == 0 ) return 0;



		flag.resize(m);

		for ( int i = 0; i < m; ++i ) flag[i] = false;



		num_basya.resize(n);

		for ( auto &v: num_basya ) {

			std::cin >> v;

		}

		std::sort(num_basya.begin(), num_basya.end());





		for ( int i = 0; i < p; ++i ) {

			int x, y, z;

			std::cin >> x;

			std::cin >> y;

			std::cin >> z;

			x--; y--;



			T t1(x,y,z), t2(y,x,z);

			dis_city.push_back(t1);

			dis_city.push_back(t2);

		}



		flag[a - 1] = true;

		table.resize(1<<n);

		for ( int i = 0; i < (1<<n); ++i ) table[i] = std::make_tuple(PopCount(i), i);

		std::sort(table.begin(), table.end());



		double ans = search();

		if ( ans > 65530 ) {

			std::cout << "Impossible" << std::endl;

		} else {

			printf("%.4f\n", ans);

		}

	}



	return 0;

}