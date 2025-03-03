#include "stdc++.h"



using namespace std;



#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)



int main(int argc, char const *argv[]){

	int foods, people, item_num, tmp, ans;

	while(cin >> people >> foods){

		ans = 0;

		bool foods_ch[foods + 5];

		bool foods_ch_tmp[foods + 5];

		for (int i = 1; i <= foods + 5; ++i){

			foods_ch[i] = true;

			foods_ch_tmp[i] = false;

		}



		for (int i = 0; i < people ; ++i){

			cin >> item_num;

			for (int j = 0; j < item_num; ++j){

				cin >> tmp;

				foods_ch_tmp[tmp] = true;

			}

			for (int j = 1; j <= foods; ++j){

				if (foods_ch_tmp[j] == false){

					foods_ch[j] = false;

					//cout << "j: " << j << endl;

				}

			}



			for (int j = 1; j <= foods + 5; ++j)

				foods_ch_tmp[j] = false;

		}



		for (int i = 1; i <= foods; ++i){

			if (foods_ch[i]){

				ans++;

				//cout << "---" << i << endl;

			}	

		}



		cout << ans << endl;

	}



	return 0;

}