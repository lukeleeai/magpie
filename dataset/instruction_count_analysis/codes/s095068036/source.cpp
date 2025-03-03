#include <cstdio>

#include <iostream>

#include <algorithm>



using namespace std;





int an[105];

int ans,a,b,c;



int main()

{

	cin >> a >> b >> c;

	an[a]++;

	an[b]++;

	an[c]++;

	for(int i = 0; i < 105; i++){

		ans = max(ans,an[i]);

	}

	cout << (3-ans+1) << endl;

	return 0;

}