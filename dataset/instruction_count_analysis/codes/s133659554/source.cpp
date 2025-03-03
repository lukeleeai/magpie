#include"stdc++.h"

using namespace std;

const int N = 1e5 + 10;

int n , cs[N] , k;

string s;

int freq[N];

int main(){

    cin >> n >> k ;

    cin >> s;

    memset(freq , -1 , sizeof freq);

    cs[0] = (s[0] == '0');

    freq[0] += (s[0] == '1');

    int ans = 1;

    for(int i = 1 ; i < s.size() ; i++){

        if(s[i] == s[i - 1] || s[i] == '1')

            cs[i] = cs[i - 1];

        else

            cs[i] = cs[i - 1] + 1;

        if(cs[i] <= k){

            ans = i + 1;

        }else{

        if(freq[cs[i] - k] != -1)

        ans = max(ans , i - freq[cs[i] - k] + 1);}

        if(s[i] == '1' && freq[cs[i]] == -1) freq[cs[i]] = i;  

    }

    cout << ans << endl;

    return 0;

}