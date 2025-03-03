#include "stdc++.h"

using namespace std;

typedef long long ll;

#define traverse(container,it)  for(auto it = container.begin();it != container.end(); it++)

int main()

{

    //freopen("in.txt","r",stdin);

    int n,m;

    ll sum = 0;

    multiset< int >  number;

    priority_queue< pair< int,int > > spare;



    cin >> n >> m;



    for(int i=0;i<n;i++){

        int x;

        cin >> x;

        number.insert(x);

    }



    for(int i=0;i<m;i++){

        int a,b;

        cin >> a >> b;

        spare.push(make_pair(b,a));

    }



    multiset< int >::iterator it = number.begin();



    while(!spare.empty() && it != number.end()){

        pair< int,int > curr = spare.top();



        while((curr.first> *it) && curr.second>0 && (it != number.end())){

            curr.second--;

            sum += curr.first;

            it++;

        }



        if(curr.first <= *it) break;



        spare.pop();

    }



    while(it != number.end()){

        sum += *it;

        it++;

    }



    cout << sum << endl;



    return 0;

}
