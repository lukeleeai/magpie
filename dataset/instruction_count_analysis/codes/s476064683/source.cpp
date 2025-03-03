#include "stdc++.h"

using namespace std;



#define for_(i,a,b) for(int i=a;i<b;++i)

#define ALL(a) a.begin(),a.end()

#define INIT(a,b) memset(a,b,sizeof(a))

using lint = long long int;



int main() {

    string T;

    cin >> T;

    int N = T.size();

    for_(i,0,N) if (T[i] == '?') T[i] = 'D';

    cout << T << endl;

}