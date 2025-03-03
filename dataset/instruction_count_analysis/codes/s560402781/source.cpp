//#include"stdc++.h"

//#include<tr1/unordered_map>

#include<iostream>

#include<string>

#include<algorithm>

#include<utility>

#include<functional>

#include<vector>



#pragma GCC optimize ("Ofast")

#define ll long long

#define pll pair<long long,long long>

#define pii pair<int,int>

#define mp make_pair

#define pb push_back

#define F first

#define S second

#define forn(i, n) for(int i=0; i<int(n); i++)

#define Forn(i, n) for(int i=1; i<=int(n); i++)



using namespace std;



/*#include <ext/pb_ds/tree_policy.hpp>

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> rbtree;*/



string s;



int main()

{

    cin.tie(0);ios_base::sync_with_stdio(false);

    cin >> s;

    sort(s.begin(), s.end());

    for(char c = 'a'; c<='z'; c++)

    {

        if(!binary_search(s.begin(), s.end(), c))

        {

            cout << c << endl;

            return 0;

        }

    }

    cout << "None" << endl;

}
