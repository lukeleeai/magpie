#include "stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef int64_t Int;

using namespace std;



int main(){

    string S; int Q;

    cin >> S >> Q;



    vector<int> T(200010), F(200010); vector<char> C(200010);

    

    bool rev = false;

    rep(q, Q){

        cin >> T[q];

        if(T[q] == 1) rev = !rev;

        if(T[q] == 2) cin >> F[q] >> C[q];

    }



    bool head = true; string left, right;

    rep(q, Q){

        if(!rev){

            if(T[q] == 1) head = !head;

            if(T[q] == 2){

                if((F[q] == 1 && head) || (F[q] == 2 && !head)) left = C[q] + left;

                if((F[q] == 2 && head) || (F[q] == 1 && !head)) right = right + C[q];  

            }

        } else {

            if(T[q] == 1) head = !head;

            if(T[q] == 2){

                if((F[q] == 1 && head) || (F[q] == 2 && !head)) left = left + C[q];

                if((F[q] == 2 && head) || (F[q] == 1 && !head)) right = C[q] + right;  

            }

        }

    }



    if(rev){

        reverse(S.begin(), S.end());

        cout << right+ S + left << endl; return 0;

    } else {

        cout << left + S + right << endl; return 0;

    }

}
