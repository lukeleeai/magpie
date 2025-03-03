#include <iostream>

#include <stdio.h>

#include <iomanip>

#include <climits>

#include <vector>

#include <string>

#define REP(a,b) for(int a=0; a<b; a++)

using namespace std;



vector <int> colors;

int canvas[105][105];



int main() {

  ios_base::sync_with_stdio(false);

  int H, W, N, c;

  cin >> H >> W >> N;

  colors.push_back(0);

  REP(i, N){

    int temp;

    cin >> temp;

    colors.push_back(temp);

  }

  c = 1;

  REP(i, H){

    if(i % 2 == 0){

      REP(j, W){

        canvas[i][j] = c;

        colors[c]--;

        if(colors[c] == 0) c++;

      }

    }else{

      for(int j = W-1; j >= 0; j--){

        canvas[i][j] = c;

        colors[c]--;

        if(colors[c] == 0) c++;

      } 

    }

  }

  REP(i, H){

    REP(j, W){

      cout << canvas[i][j] << " ";

    }

    cout << endl;

  }

}