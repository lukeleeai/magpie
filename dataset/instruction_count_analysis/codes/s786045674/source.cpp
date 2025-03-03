#include <iostream>

#include <vector>

#include <string>

#include <algorithm>

#include <utility>

#include <numeric>

using namespace std;

//変数デバッグ

#define DEB(variable) cout << #variable << '=' << variable << endl



//for簡易表記(引数ミス防止)

#define FOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)

#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)





int main(){



    long long int n,a,b;

    cin>>n>>a>>b;

    if(n==0||(n==1&&a!=b)||a>b){

        cout << 0 << endl;

    }else{

        cout << 1 + ((n - 2) * (b - a)) << endl;

    }

    return 0;

}   