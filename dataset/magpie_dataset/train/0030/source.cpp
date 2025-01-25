#include <iostream>

#include <string>

#include <cstring>

#include <vector>

#include <cstdlib>

#include <algorithm>

#include <utility>



#define YNUM(X) ( X < 0 ? X + 3 : X )



typedef std::pair<int, int> WH;

typedef std::vector<WH> whvec;



int main(){

	int h, w;



	while( std::cin >> h >> w, w + h != 0 ){

		bool map[502][502];

		std::string in;

		std::vector<std::vector<whvec> > data(3, std::vector<whvec>(502));

		int data_max = 0;

		int height_sum[502][502], width_sum[502][502];

		WH wh;



		memset( map, 0, sizeof(map) );

		memset( height_sum, 0, sizeof(height_sum) );

		memset( width_sum, 0, sizeof(width_sum) );



		for( int i = 1; i <= h; ++i ){

			std::cin >> in;

			for( int l = 1; l <= w; ++l ){

				map[i][l] = ( in[l - 1] == '.' );

			}

		}



		for( int i = 1; i <= h; ++i ){

			for( int l = 1; l <= w; ++l ){

				if(map[i][l]){

					width_sum[i][l] = width_sum[i][l - 1] + 1;

					height_sum[i][l] = height_sum[i - 1][l] + 1;

				}

			}

		}



		for( int i = 1, n = 1; n <= h; n++, i = n % 3 ){

			data[i] = std::vector<whvec>(502);

			for( int l = 1; l <= w; l++ ){

				if( map[n][l] ){

					if( map[n - 1][l] && map[n][l - 1] ){

						int x_cnt = width_sum[n][l], y_cnt = height_sum[n][l];

						for( int m = 0; m < data[YNUM(i - 1)][l].size(); ++m ){

							wh = WH( std::min(data[YNUM(i - 1)][l][m].first, x_cnt), data[YNUM(i - 1)][l][m].second + 1 );

							if( std::find( data[i][l].begin(), data[i][l].end(), wh ) == data[i][l].end() ){

								data[i][l].push_back( wh );

								data_max = std::max( data_max, wh.first * wh.second );

							}

						}

						for( int m = 0; m < data[i][l - 1].size(); ++m ){

							wh = WH( data[i][l - 1][m].first + 1, std::min(data[i][l - 1][m].second, y_cnt) );

							if( std::find( data[i][l].begin(), data[i][l].end(), wh ) == data[i][l].end() ){

								data[i][l].push_back( wh );

								data_max = std::max( data_max, wh.first * wh.second );

							}

						}

						

					}else if( map[n - 1][l] ){

						for( int m = 0; m < data[YNUM(i - 1)][l].size(); ++m ){

							data[i][l].push_back( wh = WH( 1, data[YNUM(i - 1)][l][m].second + 1 ) );

							data_max = std::max( data_max, wh.first * wh.second );

						}



					}else if( map[n][l - 1] ){

						for( int m = 0; m < data[i][l - 1].size(); ++m ){

							data[i][l].push_back( wh = WH( data[i][l - 1][m].first + 1, 1 ) );

							data_max = std::max( data_max, wh.first * wh.second );

						}



					}else data[i][l].push_back( wh = WH( 1, 1 ) ), data_max = std::max( data_max, wh.first * wh.second );

				}	

			}

		}



		std::cout << data_max << std::endl;

 	}

	return 0;

}