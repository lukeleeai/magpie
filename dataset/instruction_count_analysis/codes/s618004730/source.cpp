#include <iostream>

#include <vector>

using namespace std;



//pair<int int> 

#define pir pair<int, int>

vector<pair<pir,pir>> ans;

int main(){

    int H, W;

    int tmp;

    int Num[500][500] = {0};



    cin >> H >> W;



    for (int i= 0; i < H; i++){

        for (int j=0; j < W; j++){

            if (i == H - 1 && j == W - 1) break;

            cin >> tmp;

            Num[i][j] += tmp;

            if (Num[i][j] % 2 != 0){

                if (j != W - 1){

                    ans.push_back({{i+1, j+1}, {i+1, j+2}});

                    Num[i][j+1]++;

                }else {

                    ans.push_back({{i+1, j+1}, {i+2, j+1}});

                    Num[i+1][j]++;

                }

            } 

        }

    }

    cout << ans.size() << endl;

    for (auto p:ans){

        cout << p.first.first << " " << p.first.second << " " << p.second.first << " " << p.second.second << endl;

    }

}