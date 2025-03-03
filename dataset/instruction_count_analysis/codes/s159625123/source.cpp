//https://blog.csdn.net/hesorchen

// #include "stdc++.h"

#include <algorithm>

#include <iostream>

#include <cstring>

#include <map>

#include <cmath>

using namespace std;

#define ll long long

#define endl "\n"

#define mod 1000000007

#define MAX 200005

map<string, int> p;

string a[100005];

int ct;

int main()

{

    int n, m;

    cin >> n;

    string temp;

    while (n--)

    {

        cin >> temp;

        a[ct++] = temp;

        p[temp]++;

    }

    cin >> m;

    while (m--)

    {

        cin >> temp;

        a[ct++] = temp;

        p[temp]--;

    }

    int ans = 0;

    for (int i = 0; i < ct; i++)

        ans = max(ans, p[a[i]]);

    cout << ans << endl;



    return 0;

}
