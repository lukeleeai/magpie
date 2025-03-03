#include<iostream>

#include<cstdio>

#include<algorithm>

#include<cmath>

#include<string>

#include<cstring>

#include<vector>

#include<map>

#include<list>

#include<stack>

#include<queue>

#include<climits> //llong int_MIN/MAX





using namespace std;



#define FOR(i,s,e) for(llong int (i)=(s);(i)<(e);(i)++)

#define FORR(i,s,e) for(llong int (i)=(s);(i)>(e);(i)--)

#define MOD 1000000007

#define llong long long

#define debug(x) cout<<#x<<": "<<x<<endl

#define non -1

#define MAX 200010

llong n;



llong int color1[MAX];

llong int color2[MAX];

vector<llong int> G1[MAX];

vector<llong int> G2[MAX];

llong City[MAX];



void dfs1(llong int r, llong int c, llong int color[MAX], vector<llong int> G[MAX]) {//r

    stack<llong int>S;

    S.push(r);

    color[r] = c;

    while (!S.empty()) {

        llong int u = S.top();

        S.pop();



        FOR(i, 0, (llong int)G[u].size()) {

            llong int v = G[u][i];

            if (color[v] == non) {

                color[v] = c;

                S.push(v);

            }

        }

    }

}









void assigncolor1(llong int color[MAX], vector<llong int>G[MAX]) {

    llong int id = 1;

    FOR(i, 1, n + 1)

        color[i] = non;

    FOR(u, 1, n + 1) {

        if (color[u] == non)

            dfs1(u, id++, color, G);

    }

}











int main()

{

    cin.tie(0);

    ios_base::sync_with_stdio(false);



    llong int k, l;

    cin >> n >> k >> l;





    bool visit1[MAX];

    bool visit2[MAX];

    bool CityP[MAX];





    FOR(i, 1, n + 1) {

        visit1[i] = false;

        visit2[i] = false;

        City[i] = 1;

        CityP[i] = false;

    }





    FOR(i, 0, k) {

        llong int s, t;

        cin >> s >> t;

        G1[s].push_back(t);

        G1[t].push_back(s);



    }





    FOR(i, 0, l) {

        llong int s, t;

        cin >> s >> t;

        G2[s].push_back(t);

        G2[t].push_back(s);



    }



    assigncolor1(color1, G1);

    /*

      FOR(i, 1, n + 1) {

          cout << "color1 : v" << i << ": " << color1[i] << endl;

      }*/



    assigncolor1(color2, G2);



    /*FOR(i, 1, n + 1) {

        cout << "color2 : v" << i << ": " << color2[i] << endl;

    }

*/



//

//    FOR(v, 1, n + 1) {

//        if (visit1[v] == true)continue;

//        llong int count = 1;

//        queue<llong int >Q;

//       // queue<llong int >Q2;

//

//        Q.push(v);

//        //Q2.push(v);

//

//        while (!Q.empty()) {

//            llong int u = Q.front();

//            Q.pop();

//            visit1[u] = true;

//            FOR(i, 0, (llong int)G2[u].size()) {

//                llong int p = G2[u][i];

//                if (visit1[p] == false)

//                    if (color1[u] == color1[p] && color2[u] == color2[p]) {

//                        count++;

//                        /*  debug(count);

//                            debug(u);

//                            debug(p);

//        */

//                        Q.push(p);

//          //              Q2.push(p);

//                        visit1[p] = true;

//                    }

//            }

//        }

///*

//        count = Q2.size();

//        while (!Q2.empty()) {

//            llong int u = Q2.front();

//            Q2.pop();

//            City[u] = count;

//        }*/

//

//    }

//

//

    map<pair<int, int>, int>M;





    FOR(i, 1, n + 1) {

        M[make_pair(color1[i], color2[i])]++;

    }



    FOR(i, 1, n) {



        cout << M[make_pair(color1[i], color2[i])] << " ";



    }

    cout << M[make_pair(color1[n],color2[n])] << endl;





    return 0;

}
