#include"stdc++.h"

using namespace std;

int a,b;

int main() {

	ios::sync_with_stdio(false);

	cin >> a >> b;

	if(a <= 0 && b >= 0)

		cout << "Zero\n";

	else if(a > 0 || abs(b) - abs(a) & 1)

		cout << "Positive\n";

	else

		cout << "Negative\n";

	return 0;

}