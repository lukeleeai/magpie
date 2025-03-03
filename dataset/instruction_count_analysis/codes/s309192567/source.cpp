#include "stdc++.h"

using namespace std;



int main(){

    string s, temp;

    int K;

    cin >> s >> K;

    vector<string> sub(10000);

    

    for(int i=0; i<s.size(); i++){

        for(int j=1; j<=K; j++){

            temp = s.substr(i,j);

            sub.push_back(temp);

        }

    }

    sort(sub.begin(), sub.end());

    sub.erase(unique(sub.begin(),sub.end()),sub.end());



    cout << sub.at(K) << endl;

}