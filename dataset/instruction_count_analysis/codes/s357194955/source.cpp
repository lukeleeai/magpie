#include"stdc++.h"

using namespace std;



typedef long long ll;



const int N = 2500;

ll arr[N + 5];

ll sq[N + 5];



ll tipe[3];



int main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;

	cin>>n;

	for(int i = 0;i < n;i++) cin>>arr[i];

	sort(arr, arr + n);

	for(int i = 0;i < n;i++) sq[i] = arr[i] * arr[i];

	for(int i = 0;i < n;i++) {

		for(int j = i + 1;j < n;j++) {

			int lo = j + 1;

			int hi = n - 1;

			int ub = -1;

			while(lo <= hi) {

				int mid = (lo + hi) / 2;

				if(arr[i] + arr[j] > arr[mid]) {

					ub = mid;

					lo = mid + 1;

				} else hi = mid - 1;

			}

			

			if(ub != -1) {

				int lo = j + 1;

				int hi = ub;

				int resL = j;

				while(lo <= hi) {

					int mid = (lo + hi) / 2;

					if(sq[i] + sq[j] > sq[mid]) {

						resL = mid;

						lo = mid + 1;

					} else hi = mid - 1;

				}

				

				lo = j + 1;

				hi = ub;

				int resH = ub + 1;

				while(lo <= hi) {

					int mid = (lo + hi) / 2;

					if(sq[i] + sq[j] < sq[mid]) {

						resH = mid;

						hi = mid - 1;

					} else lo = mid + 1;

				}

				int total = ub - j;

				int t1 = resL - j;

				int t3 = ub + 1 - resH;

				int t2 = total - t1 - t3;

//				cout<<"RESL "<<resL<<" "<<resH<<endl;

//				cout<<"AT "<<i<<" "<<j<<" "<<t1<<" "<<t2<<" "<<t3<<endl;

				tipe[0] += t1, tipe[1] += t2, tipe[2] += t3;

			}			

		}

	}

	cout<<tipe[0] + tipe[1] + tipe[2]<<endl;

}