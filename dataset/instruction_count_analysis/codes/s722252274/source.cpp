#pragma GCC optimize ("O3")

#pragma GCC target ("sse4")



#include "stdc++.h"

#include <ext/pb_ds/tree_policy.hpp>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/rope>



using namespace std;

using namespace __gnu_pbds;

using namespace __gnu_cxx;



template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

using namespace std;

/***********************************************/

/* Dear online judge:

 * I've read the problem, and tried to solve it.

 * Even if you don't accept my solution, you should respect my effort.

 * I hope my code compiles and gets accepted.

 *  ___  __     _______    _______      

 * |\  \|\  \  |\  ___ \  |\  ___ \     

 * \ \  \/  /|_\ \   __/| \ \   __/|    

 *  \ \   ___  \\ \  \_|/__\ \  \_|/__  

 *   \ \  \\ \  \\ \  \_|\ \\ \  \_|\ \ 

 *    \ \__\\ \__\\ \_______\\ \_______\

 *     \|__| \|__| \|_______| \|_______|

 */

const long double mod = 1000000007;



long long sum(long long X) {

	long long res = 0;

	while(X) res += X%10, X/=10;

	return res;

}



long long nxt(long long X) {

	long long mn = X;

	long long p = 1;

	long long other = 0;

	long long cur = X;

	while(cur) {

		other += p * 9;

		cur /= 10;

		p *= 10;

		if(mn * sum(cur * p + other) > (cur * p + other) * sum(mn)) mn = cur * p + other;

	}

	return mn;

}



int main(int argc, char** argv) {

	ios_base::sync_with_stdio(false);

	cin.tie(nullptr);



	int K;

	cin>>K;

	long long cur = 1;

	while(--K) {

		cout<<cur<<'\n';

		cur = nxt(cur+1);

	}

	cout<<cur<<'\n';

	return 0;

}
