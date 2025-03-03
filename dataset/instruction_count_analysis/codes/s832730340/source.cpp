#include"stdc++.h"

using namespace std;



int h,w,a,b;

string s1,s2;



int main() {

	cin >> h >> w >> a >> b;

	for (int i = 0; i < a; i++) s1 += '1', s2 += '0';

	for (int i = a; i < w; i++) s1 += '0', s2 += '1';

	for (int i = 0; i < b; i++) cout << s1 << "\n";

	for (int i = b; i < h; i++) cout << s2 << "\n";

}