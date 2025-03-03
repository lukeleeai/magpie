#include"stdc++.h"

using namespace std;



#define rep(i,n) for (int i = 0; i< (n); ++i)

#define vvec(m,n) vector<vector<int>> (int(m), vector<int>(n))

#define ALL(a) (a).begin(), (a).end()



using ll = long long;



int main(){

    int H, W, h, w;

    cin >> H >> W >> h >> w;

    vector<vector<int>> data(int(500), vector<int>(500));

    rep(i,H){

        rep(j,W){

            data.at(i).at(j) = 0;

        }

    }

    int count = 0;

    

    rep(i,H){

        rep(j,W){

            if(data.at(i).at(j) == 0) count++;

        }

    }

    if(h > H) h = H;

    if(w > W) w = W;

    cout << count - h*W - w*H + h*w << endl;

}