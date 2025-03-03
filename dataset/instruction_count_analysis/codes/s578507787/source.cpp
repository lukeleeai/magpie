#include"stdc++.h"

using namespace std;



#define rep(i,n) for (int i = 0; i< (n); ++i)

#define vvec(m,n) vector<vector<int>> (int(m), vector<int>(n))

#define ALL(a) (a).begin(), (a).end()



using ll = long long;



int main(){

    int H, W, h, w;

    cin >> H >> W >> h >> w;

    cout << H*W - h*W - w*H + h*w << endl;

}