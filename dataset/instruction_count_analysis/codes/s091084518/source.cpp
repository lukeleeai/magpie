#include<iostream>

#include<algorithm>

#include "stdc++.h"

#include <map>

#define endl "\n"

using namespace std;





int main()

{

    map <string,int> poll;

    int i,n,maxi=0;

    string S;

    cin >> n;

    for (i=0;i<n;i++)

    {

        cin >> S;

        poll[S]++;

    }

    map <string,int>:: iterator itr;

    for (itr=poll.begin();itr != poll.end();itr++)

    {

        if (itr->second > maxi)

        {

            maxi = itr->second;

        }

    }

    for (itr=poll.begin();itr != poll.end();itr++)

    {

        if (itr->second == maxi)

        {

            cout << itr->first << endl;

        }

    }





}
