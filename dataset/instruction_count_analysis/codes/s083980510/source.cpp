#include "stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef int64_t Int;

using namespace std;

 

int main(){

    string S; int Q;

    cin >> S >> Q;



    deque<char> DQ;

    rep(i, S.length()) DQ.push_back(S[i]);

 

    bool head = true;

    rep(q, Q){

        int T; cin >> T;

 

        if(T == 1) head = !head;

        if(T == 2){

            int F; char C; cin >> F >> C;

            if((F == 1 && head) || (F == 2 && !head)) DQ.push_front(C);

            if((F == 2 && head) || (F == 1 && !head)) DQ.push_back(C);  

        }

    }



    string ans;

    while(!DQ.empty()) {ans.push_back(DQ.front()); DQ.pop_front();}

 

    if(!head) reverse(ans.begin(), ans.end());

    cout << ans << endl;

}