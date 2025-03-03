#include"stdc++.h"



using namespace std;

const int maxn = 1e5+10;

int main()

{

	int n;

	cin >> n;

	string s[maxn];

	int a[3];

	memset(a,0,sizeof(a));

	int cnt = 0;

	for(int i = 0;i < n;i ++){

		cin >> s[i];

		int l =s[i].size();

		for(int j = 1;j < l;j ++){

			if(s[i][j - 1] =='A' && s[i][j] == 'B'){

				cnt ++;

			}

		}

		if(s[i][0] == 'B') a[0] ++;

		if(s[i][l-1] == 'A') a[1]++;

		if(s[i][l-1] == 'A' && s[i][0] =='B') a[2] ++;

	}

	if(a[0] < a[1])  cnt += a[0];

	else cnt += a[1];

	if(a[0] == a[1] && a[1] == a[2] && a[2] != 0) cnt --;

	cout << cnt << endl;

	return 0;

}