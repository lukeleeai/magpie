#include <cstdio>

#include <queue>

#include <iostream>

#include "stdc++.h"

#define rep(i,n) for(int i=0;i<n;i++)

typedef long long int ll;



using namespace std;



int main() {

    cin.tie(0);

   	ios::sync_with_stdio(false);

    int i,j,k;

    long n,m,tmp;

    long l,r;

    int min=2018;

    string s[200000];



    cin >> l;

    cin >> r;

    if(abs(l-r)>2019){

        cout<< '0'<<endl;

        

    }else{

        l=l%2019;

        r=r%2019;

        for(int i=l;i<=r;i++){

            for(int j=i+1;j<=r;j++){

                if(i*j%2019<min){

                    min=i*j%2019;

                }

            }

        }

        cout<<min<<endl;

    }





    return 0;

}