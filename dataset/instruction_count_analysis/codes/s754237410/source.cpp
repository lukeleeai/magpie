#include<iostream>

#include<algorithm>

#include<cmath>

#include<cstdlib>

#include<cstdio>

#include<cstring>

#include<iomanip>

#include<string>

#include<set>

#include<map>

#include<vector>

#include<queue>

#include<stack>

#include<utility>

#define PI acos(-1.0)

using namespace std;

int a[3][3];

int main() {

	int n;

	for(int i = 0; i < 3; i++) {

		for(int j = 0; j < 3; j++) {

			scanf("%d",&a[i][j]);

		}

	}

	cin >> n;

	int b;

	while(n--) {

		cin >> b;

		for(int i = 0; i < 3; i++) {

			for(int j = 0; j < 3; j++) {

				if(a[i][j] == b) {

					a[i][j] = 0;

					break;

				}

			}

		}

	}

	int flag = 0;

	int ans = 0;

	for(int i = 0; i < 3; i++) {

		ans = 0;

		for(int j = 0; j < 3; j++) {

			if(a[i][j] == 0) ans++;

			else break;

		}

		if(ans == 3) {

			flag = 1;

			break;

		}

	}

	if(flag) cout << "Yes" << endl;

	else {

		for(int i = 0; i < 3; i++) {

			ans = 0;

			for(int j = 0; j < 3; j++) {

				if(a[j][i] == 0) ans++;

				else break;

			}

			if(ans == 3) {

				flag = 1;

				break;

			}

		}

		if(flag) cout << "Yes" << endl;

		else{

			if((a[0][0] == 0 && a[1][1] == 0 && a[2][2] == 0)||(a[0][2] == 0 && a[1][1] == 0 && a[2][0] == 0)){

				flag = 1;

			}

			if(flag) cout << "Yes" << endl;

			else cout << "No" << endl;

		}

	}



	return 0;

}