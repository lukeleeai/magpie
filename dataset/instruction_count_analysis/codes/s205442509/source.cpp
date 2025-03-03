#include <iostream>

#include <cmath>

#include <string>

#include <algorithm>

#include <vector>

using namespace std;



int main(void){

    string s, t;

    cin >> s; cin >> t;

    int count = 0;

    int check = 0;

    vector<string> ans(100000);

    if(s.length()>=t.length()){

    for(int i = 0; i <= s.length()-t.length(); i++){

        count = 0;

        for(int j = 0; j < t.length(); j++){

            if(s[i+j]==t[j]||s[i+j]=='?') count++;

        }

        if(count==t.length()){

            ans[check].insert(0, s, 0, i);

            ans[check]+=t;

            ans[check].insert(i+t.length(), s, i+t.length(), s.length()-t.length()-i);

            check++;

        }

    }}

    if(check==0)

        cout << "UNRESTORABLE" << endl;

    else{

        for(int i = 0; i < check; i++){

            for(int j = 0; j < ans[i].length(); j++){

                if(ans[i][j]=='?') 

                    ans[i][j]='a';

            }

        }

        sort(&ans[0], &ans[check]);

        cout << ans[0] << endl;

    }

    return 0;

}