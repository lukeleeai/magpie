#include"stdc++.h"

using namespace std;

const int N = 2e5 + 10;

int n , k;

string s , t;

int main(){

    cin >> n >> k;

    cin >> s;

    int i = 0 , j = 1 , ans = 1 , cost = 0;

    cost += (s[0] == '0');

    while(j < n){

        if(s[j] == '0' && s[j] != s[j - 1])

            cost++;

        while(cost > k){

            if(s[i] == '0'){

               cost--;

               while(s[i] == '0')i++;

               break;

            }

            i++;

        }

        ans = max(ans , j - i + 1);

        j++;

    }

    cout << ans << endl;

    return 0;

}