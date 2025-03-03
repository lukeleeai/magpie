//include

//------------------------------------------

#include <vector>

#include <list>

#include <map>

#include <climits>

#include <set>

#include <deque>

#include <stack>

#include <bitset>

#include <algorithm>

#include <functional>

#include <numeric>

#include <utility>

#include <sstream>

#include <iostream>

#include <iomanip>

#include <cstdio>

#include <cmath>

#include <cstdlib>

#include <cctype>

#include <string>

#include <cstring>

#include <ctime>

#include <queue>

#include <random>

#include <cctype>

#include <complex>

#include <regex>



using namespace std;



#define C_MAX(a, b) ((a)>(b)?(a):(b))

#define SHOW_VECTOR(v) {std::cerr << #v << "\t:";for(const auto& xxx : v){std::cerr << xxx << " ";}std::cerr << "\n";}

#define SHOW_MAP(v){std::cerr << #v << endl; for(const auto& xxx: v){std::cerr << xxx.first << " " << xxx.second << "\n";}}



int main() {



    int A, B;

    cin >> A >> B;



    vector<string> M(100, string(100, '.'));

    for (int i = 0; i < 100; i++) for (int j = 50; j < 100; j++) M[i][j] = '#';



    A--, B--;



    for (int i = 0; i < A; i++) {

        int x = (i % 24) * 2;

        int y = (i / 24) * 2;

        M[y][x + 51] = '.';

    }



    for (int i = 0; i < B; i++) {

        int x = (i % 24) * 2;

        int y = (i / 24) * 2;

        M[y][x + 1] = '#';

    }



    cout << 100 << " " << 100 << endl;

    for (int i = 0; i < M.size(); i++) cout << M[i] << endl;



    return 0;

}












































































