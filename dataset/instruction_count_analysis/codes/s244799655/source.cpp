#include<iostream>

#include<cstdio>

#include<cstring>

#include<algorithm>

#include<cmath>

#include<vector>





using namespace std;

int n,k;

long long num[55];

long long hand[55];

vector<long long> q;





bool cmp(long long a,long long b){

    return a>b;

}





long long solve(int l,int r){

    while(!q.empty())q.clear();

    long long ans=0;

    for(int i=1;i<=l;i++){

        ans+=num[i];

        q.push_back(num[i]);

    }

    for(int i=n;i>=n-r+1;i--){

        ans+=num[i];

        q.push_back(num[i]);

    }

    sort(q.begin(),q.end(),cmp);

    for(int i=0;i<k-r-l;i++){

        if(q.empty()) break;

        ans-=min(q[q.size()-1],(long long ) 0);

        q.pop_back();

    }

    return ans;

}





int main(){

    cin>>n>>k;

    for(int i=1;i<=n;i++){

        cin>>num[i];

    }

    long long maxn=0;

    for(int i=0;i<=k;i++){

        for(int j=0;j+i<=min(n,k);j++){

            maxn=max(solve(i,j),maxn);

        }

    }

    cout<<maxn;

}