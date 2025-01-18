#include"stdc++.h"

using namespace std;

#define MAX 100000

const int dx[8]={1,0,-1,0,1,-1,-1,1};

const int dy[8]={0,1,0,-1,1,1,-1,-1};



int main(){

    int s;

    cin>>s;

    int k[1000000]={};

    k[s]++;

    for(int i=2;;i++){

        if(s%2==0){

            s/=2;

        }else{

            s=3*s+1;

        }

        k[s]++;

        if(k[s]==2){

            cout<<i<<endl;

            break;

        }

    }



    return 0;

}
