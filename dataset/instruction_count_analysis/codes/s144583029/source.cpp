#include "stdc++.h"

using namespace std;



#define MAX_N 8003



bool can(vector <int> v ,int x){

    bitset <MAX_N> bs; bs[0] = 1;

    int tot = 0;

    for(int&i : v)

        bs |= (bs<<i) ,tot += i;

    return !((tot+x)&1) && (tot >= x && bs[(tot-x)/2]);

}



int main()

{

    string s;

    int x ,y;

    cin >> s; s += 'T';

    cin >> x >> y; y = abs(y);



    vector <int> units[2];

    int axis = 0 ,mvs = 0;

    for(int i=0; i<s.size(); i++){

        if(s[i] == 'T'){

            units[axis].push_back(mvs);

            axis ^= 1 ,mvs = 0;

        }

        else

            mvs++;

    }



    x = abs(x-units[0][0]);

    units[0].erase(units[0].begin());

    cout << (can(units[0] ,x) && can(units[1] ,y) ? "Yes" : "No") << endl;

}
