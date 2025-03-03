#include"stdc++.h"



using namespace std;



int main()

{

    long long n,m,a,b,i,j=0;

    cin>>n>>m;

    vector < pair<int,int> > ab;

    for(i=0; i<n; i++)

    {

        cin>>a>>b;

        ab.push_back(make_pair(a,b));

    }

    priority_queue <long long> pq;

    sort(ab.begin(),ab.end());

    long long count=0;

    for(i=1; i<=m; i++)

    {

        for(; ab[j].first==i; j++)

        {

            pq.push(ab[j].second);

        }

        if(pq.size())

        {

            count+=pq.top();

            pq.pop();

        }

    }

    cout<<count;

}
