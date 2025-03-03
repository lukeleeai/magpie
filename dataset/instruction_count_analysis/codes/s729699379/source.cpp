#include "stdc++.h"



using namespace std;



string a = "abc";

int cnt[150];

main ()

{

    string s;

    cin >> s;

    int n = s.size();

    s = ' ' + s;

    string ans = s;

    for( int i = 1; i <= n; i++ )

    {

        cnt[s[i]]++;

    }

    if( abs(cnt['a'] - cnt['b'] ) > 1 || abs( cnt['c'] - cnt['b'] ) > 1 || abs( cnt['a'] - cnt['c']) > 1 )

    {

        puts("NO");

        return 0;

    }

    puts("YES");

}
