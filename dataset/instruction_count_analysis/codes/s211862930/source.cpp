//

//	Created by shamim_nik

//



#include "stdc++.h"

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

using namespace std;



typedef long long ll;

typedef tree<int,null_type,less<int>,rb_tree_tag,

		tree_order_statistics_node_update> indexed_set;



#define br printf("\n")



int main () {

	ios::sync_with_stdio(0);

	cin.tie(0);



//	freopen("input.txt", "r", stdin);

//	freopen("output.txt", "w", stdout);



	char ch;

	cin >> ch;

	if (ch >= 'A' && ch <= 'Z') {

		cout << "A\n";

	} else if (ch >= 'a' && ch <= 'z') {

		cout << "a\n";

	}

	return 0;

}