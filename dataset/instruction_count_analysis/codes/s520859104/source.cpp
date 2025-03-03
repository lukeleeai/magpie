#include"stdc++.h"

using namespace std;

#define ll long long



int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);



    int n;

    cin>>n;

    for(int i = 1;i<= 9; i++){

        for(int j = 1; j <= 9; j++){

            if(i*j == n){

                cout<<"Yes"<<endl;

                return 0;

            }

        }

    }

    cout<<"No"<<endl;



    return 0;

}