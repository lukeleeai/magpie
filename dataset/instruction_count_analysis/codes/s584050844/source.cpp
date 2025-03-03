#include"stdc++.h"

using namespace std;

 string S[200001];

int main()

{

    map <string,int> mp;



    int i, cnt = 0, n;

    cin >> n;

    for(i = 0; i < n; i++)

    {

        cin >> S[i];

        mp[S[i]]++;

    }

    for(i = 0; i < n; i++)

    {

        if(mp[S[i]] != 0)

        {

            cnt++;

            mp[S[i]] = 0;

        }

    }

    cout << cnt << endl;



}
