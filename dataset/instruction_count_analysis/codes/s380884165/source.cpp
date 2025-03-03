#include "stdc++.h"



using namespace std;



const int N = 2e5 + 5;

int memo[N][2];

string s;



int solve (int i , bool b) {

    if (i == s.size())

        return 0;



    int &ret = memo[i][b];

    if (~ret)

        return ret;



    ret = 0;



    if (s[i] == 'P' || s[i] == '?')

        ret = solve(i + 1 , 0);



    if (s[i] == 'D' || s[i] == '?')

        ret = max(ret , solve(i + 1 , 1) + 1 + !b);



    return ret;

}



void print(int i , bool b) {

    if (i == s.size())

        return;



    if ((s[i] == 'P' || s[i] == '?') && solve(i + 1 , 0) == solve(i , b)) {

        cout << 'P';

        return print(i + 1 , 0);

    }



    cout << 'D';

    print(i + 1 , 1);

}



int main() {

    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);



    cin >> s;



    memset(memo , -1 , sizeof memo);

    print(0 , 1);

}
