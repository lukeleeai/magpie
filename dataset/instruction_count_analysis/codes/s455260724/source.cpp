#include <iostream>

#include <iomanip>

#include <cstdio>

#include <cmath>

#include <string>

#include <vector>

#include <limits>

#include <algorithm>

#include <utility>

#include <sstream>

#include <numeric>

#include <iterator>



using namespace std;



#define repd(i,a,b) for (int i=(a);i<(b);i++)

#define rep(i,n) repd(i,0,n)

// #define ll long long

typedef long long ll;

typedef pair<int, int> P;



const int V = 100005;

vector<int> to[V*2];

bool visited[V*2];

vector<int> cnt;



void dfs(int v){

  if (visited[v]) return;

  visited[v] = true;

  cnt[v/V]++;

  for (int u : to[v]) dfs(u);

}



int main(int argc, const char * argv[]) {



    string s;

    cin >> s;

    

    char first = s[0];

    char second = '\0';



    rep(i,4){

      if(first != s[i]){

        second = s[i];

        break;

      }

    }

    // cout << second << endl;

    int sum1 = 0, sum2 = 0;

    rep(i,4){

      if (first == s[i]){

        sum1 += 1;

      }else if(second == s[i]){

        sum2 += 1;

      }

    }

    bool flag = false;



    if(sum1 == 2 && sum2 ==2) flag = true;



    if (flag){

      puts("Yes");

    }else{

      puts("No");

    }







    return 0;

}
