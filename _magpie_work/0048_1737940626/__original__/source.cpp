#include <iostream>

#include <sstream>

#include <iomanip>

#include <algorithm>

#include <cmath>

#include <string>

#include <vector>

#include <list>

#include <queue>

#include <stack>

#include <set>

#include <map>

#include <bitset>

#include <numeric>

#include <climits>

#include <cfloat>

using namespace std;



int n;

vector<int> w, s;

vector<bool> used;

vector<int> bestIndex;

int bestG;



void solve(int k, vector<int>& index, int g, int sumW)

{

    if(k == n){

        if(g < bestG){

            bestG = g;

            bestIndex = index;

        }

        return;

    }



    for(int i=0; i<n; ++i){

        if(used[i])

            continue;

        used[i] = true;

        if(s[i] >= sumW){

            index[k] = i;

            solve(k+1, index, g+(n-k)*w[i], sumW+w[i]);

        }

        used[i] = false;

    }

}



int main()

{

    for(;;){

        cin >> n;

        if(n == 0)

            return 0;



        vector<string> name(n);

        w.resize(n);

        s.resize(n);

        for(int i=0; i<n; ++i)

            cin >> name[i] >> w[i] >> s[i];



        bestG = INT_MAX;

        used.assign(n, false);

        vector<int> index(n);

        solve(0, index, 0, 0);

        for(int i=n-1; i>=0; --i)

            cout << name[bestIndex[i]] << endl;

    }

}