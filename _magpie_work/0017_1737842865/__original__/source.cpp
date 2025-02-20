#include "stdc++.h"





using namespace std;

long long n;

long long k;

vector<long long> vec;



long long meme[100007];



long long solve(long long index){



    if(index==n-1){

        return 0;

    }

    

    if(meme[index]!=-1){

        return meme[index];

    }

    

    long long ret = 10000000000000000;

    long long sol = 10000000000000000;

    for(long long i = 1 ;i<=k ; i++){

        if(index+i<n){

            ret = abs (vec[index]- vec[index+i]) + solve(index+i); 

        }

        sol = min(sol,ret);

    }



    return meme[index] = sol;

}



int main(){

    cin>>n;

    cin>>k;

    memset(meme,-1,sizeof(meme));

    long long num;

    for(long long i = 0 ; i<n ; i++){

        cin>>num;

        vec.push_back(num);

    }

    cout<<solve(0)<<endl;

    return 0;

}