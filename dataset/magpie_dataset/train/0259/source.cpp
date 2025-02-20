#include "stdc++.h"

 

#define loop(n, i) for(int i=0;i<n;i++)

#define all(v) v.begin(),v.end()



using namespace std;



string strip(string s)

{

    int i = 0;

    while (i < s.length() && s[i] == 0) i++;

    return i == s.length() ? "" : s.substr(i);

}



int less_than(string a, string b)

{

    int d = a.length() - b.length();

    if (d) return d < 0;

    return strip(a).compare(strip(b)) < 0;

}



int main()

{

    while (1) {

        int w, h; cin >> w >> h;

        if (!w) break;

        vector<string> rows(h+1);

        loop (h, i) cin >> rows[i];



        string len[80][80], amt[80][80];

        fill(len[0], len[79]+80, "");

        fill(amt[0], amt[79]+80, "");



        for (int i = h-1; i >= 0; i--) {

            for (int j = w-1; j >= 0; j--) {

                if (rows[i][j] >= 'A') continue;

                if (rows[i][j] == '0') {

                    auto ls = { len[i+1][j], len[i][j+1] };

                    len[i][j] = "0" + *max_element(all(ls), less_than);



                    auto as = { amt[i+1][j], amt[i][j+1] };

                    amt[i][j] = *max_element(all(as), less_than);

                } else {

                    auto ls = { len[i+1][j], len[i][j+1] };

                    amt[i][j] = len[i][j] = rows[i][j] + *max_element(all(ls), less_than);

                }

            }

        }



        string ans = "";

        loop (h, i) loop (w, j) {

            if (less_than(ans, amt[i][j])) ans = amt[i][j];

        }

        cout << ans << endl;

    }

    return 0;

}