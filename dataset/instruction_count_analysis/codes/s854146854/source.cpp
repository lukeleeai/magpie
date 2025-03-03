#include <iostream>

#include <vector>

#include <deque>

#include <math.h>

#include <set>

#include <iomanip>

#include <time.h>

#include <list>

#include <stdio.h>

#include <queue>

#include <map>

#include <algorithm>

#include <assert.h>

#include <memory.h>



#define mk make_pair

#define sc second

#define fr first

#define pb emplace_back

#define all(s) s.begin(), s.end()

#define sz(s) ( (int)s.size() )



using namespace std;



string z = "AKIHABARA", o = "A";



bool check(string s)

{

    if (sz(s) == 9)

        return s == z;



    string em, suf = s;



    for (int i = 0; i <= sz(s); i++)

    {

        for (int j = 0; j < sz(o); j++)

        {

            if (check( em + o[j] + suf ) )

                return true;

        }

        if (i < sz(s))

            em += s[i],

            suf.erase(0, 1);

    }

    return false;

}



string s;



main ()

{

    cin >> s;

    if (sz(s) > 9 )

        puts("NO");

    else if (check(s))

        puts("YES");

    else

        puts("NO");

}
