#define ALL(obj) (obj).begin(), (obj).end()

 

#include <iostream>

#include <iomanip>

#include <fstream>

#include <cstdio>

#include <cmath>

#include <vector>

#include <string>

#include <set>

#include <map>

#include <stack>

#include <queue>

#include <deque>

#include <bitset>

#include <algorithm>

#include <complex>

#include <array>

#include <functional>

 

using namespace std;

typedef long long ll;

const ll INF = 1e18;

 

int N;

int K;

 

int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    cin >> N >> K;

    vector<int> p(N);

 

    for (int i=0; i<N; i++) {

        cin >> p[i];

    }

    

    double answer = 0.0;

    for (int j=0; j<K; j++) {

        answer += (double)(1+p[j])/2;

    }

    

    double maxd = answer;

    for (int i=K; i<N; i++) {

        double left = (double) (1+p[i-K])/2;

        double right = (double)(1+p[i])/2;

        answer += right;

        answer -= left;

        maxd = max(maxd, answer);

    }

    

    cout << setprecision(12) << maxd << endl;

    

    return 0;

}
