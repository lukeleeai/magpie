#include <iostream>

#include <algorithm>

#include <cstdio>

#include <cstring>

#include <cmath>

#include <set>

#include <queue>

#include <iomanip>

#include <vector>

#include <numeric>

//#include "stdc++.h"



using namespace std;

const int INF = 1 << 30 ;

queue<int> Q;





bool BFS()

{

    while(!Q.empty())

    {

        int x;

        x = Q.front();

        Q.pop();

        if(x==0)

        {

            return true;

        } 

        else 

        {

            if(x-4>=0)

                Q.push(x-4);

            if(x-7>=0)

                Q.push(x-7);

        }

    }

    return false;

}



int main()

{

    ios::sync_with_stdio(false);

    int n;

    cin>>n;

    Q.push(n);

    if(BFS())

        cout<<"Yes"<<endl;

    else 

        cout<<"No"<<endl;

    return 0;

}