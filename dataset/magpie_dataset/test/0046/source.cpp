#include "stdc++.h"



using namespace std;



int main(){

    int N, len;

    cin>>N;

    string s;

    cin>>s;

    len = s.size();

    if (len > N){

        for (int i = len; i > N; i--){

            s.pop_back();

        }

        for (int j = 0; j < 3; j++){

            s.push_back('.');

        }

        cout<<s;

    }

    else {

        cout<<s;

    }



    return 0;

}
