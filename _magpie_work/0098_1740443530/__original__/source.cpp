#include <iostream>

#include <string>

#include <vector>

#include <cstring>

#include <climits>

#include <algorithm>

#include <map>

using namespace std;



int N, p[30], min_times;



map<int,int> rot[4] = {

    { {1, 28}, {2, 29}, {3, 30}, {15, 16}, {19, 21}, },

    { {3, 22}, {6, 25}, {9, 28}, {12, 19}, {13, 15} },

    { {7, 22}, {8, 23}, {9, 24}, {13, 18}, {10, 12} },

    { {1, 24}, {4, 27}, {7, 30}, {10, 21}, {16, 18} }

};



vector<int> group_id = {

    0, 0, 0, 0, 0, 0, 0, 0, 0,

    9, 9, 9,

    12, 12, 12,

    15, 15, 15,

    18, 18, 18,

    21, 21, 21, 21, 21, 21, 21, 21, 21

};



void rotate(int i) {

    for (auto it=rot[i].begin(); it!=rot[i].end(); ++it) {

        swap(p[it->first - 1], p[it->second - 1]);

    }

}



bool isOK() {

    for (int i=0; i<(int)group_id.size(); ++i) {

        if (p[i] != p[group_id[i]]) return false;

    }

    return true;

}



int solve(int times, int &min_times) {

    if (8 <= times || min_times <= times || isOK()) {

        min_times = min(min_times, times);

        return times;

    }

    int ret = INT_MAX;

    for (int i=0; i<4; ++i) {

        rotate(i);

        ret = min(ret, solve(times + 1, min_times));

        rotate(i);

    }

    return ret;

}



int main() {

    cin >> N;

    for (int i=0; i<N; ++i) {

        for (int j=0; j<30; ++j) {

            cin >> p[j];

        }

        min_times = INT_MAX;

        cout << solve(0, min_times) << endl;

    }

    return 0;

}