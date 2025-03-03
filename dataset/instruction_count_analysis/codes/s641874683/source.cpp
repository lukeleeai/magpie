

#include "stdc++.h"

using namespace std;



#define ri reverse_iterator

#define pq priority_queue

#define pi 2.0*acos(0.0)

#define mp make_pair

#define ub upper_bound

#define er equal_range

#define nl '\n'

#define F first

#define lb lower_bound

#define mem(a, b) memset(a, b, sizeof(a))

#define Q queue

#define S second

#define pb push_back

#define inp freopen("in.txt", "r", stdin)

#define out freopen("out.txt", "w", stdout)



typedef long long ll;

typedef unsigned long long ull;

typedef pair <int, int> pii;

typedef pair <long long, long long> pll;

typedef pair <long long, int> pli;



int main()

{

    ios_base :: sync_with_stdio(false);

    int a, b;

    cin >> a >> b;



    if(a == b) cout << "Draw";

    else if (a == 1) cout << "Alice";

    else if(b == 1) cout << "Bob";

    else if(a > b) cout << "Alice";

    else cout << "Bob";



    return 0;

}
