#include<algorithm>

#include<iostream>

#include<vector>

#include<string>

#include<map>

#include<stack>

#include<queue>



typedef long long i64;



using namespace std;



int main(){

    int N,M;

    vector<int> vec(1001,0);   

    cin>>N>>M;



    int ans = 1e9;



    for(int i=0;i<=1000;i++) vec[i+1] = vec[i]+i;



    vector<int> a,b;



    for(int i=0;i<=1000;i++){

        if(vec[i] - N  > 0 ) {

            a.push_back(vec[i] - N);

        }



    }



    for(int i=0;i<=1000;i++){

        if(vec[i] - M  > 0 ) {

            b.push_back(vec[i] - M);

        }



    }



    for(int i=0;i<a.size();i++){

        for(int j=0;j<b.size();j++){

            if(a[i] == b[j]) ans = a[i];

        }

    }



    cout<<ans<<endl;

   



}