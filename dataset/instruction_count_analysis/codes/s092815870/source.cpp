#include<iostream>

#include<cstring>

using namespace std;

int main(){

	ios::sync_with_stdio(false);

	string sInput;

	int i,ans=0;

	cin >> sInput;

	for (i = 1; i < sInput.length(); ++i){

		if (sInput[i] != sInput[i - 1])

			++ans;

	}

	cout << ans << endl;

	return 0;

}