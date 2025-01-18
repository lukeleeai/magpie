#include <iostream>

#include <cmath>

#include <cstring>



using namespace std;



int pedras[100100];

long long dp[100100]; ///Guardo os valores da funcao frog;



int n,k;

const int inf = 1e9;



int frog2(int i,int j){



    if(dp[i] != -1){

        return dp[i];

    }



    int menor = inf;



    if(i>=j) return dp[i]=0;



    for(int x=1;x<=k;x++){ ///i=0; i=1;i=2;i=3;

        if(i+x <= j){      ///x=1, x=1;x=1;x=1;

            long long cost = (frog2(i+x,j)+ abs(pedras[i]-pedras[i+x]));



            if(cost < menor){

                menor = cost;

            }

        }

    }



    return dp[i] = menor;

}



int main(){



    memset(dp,-1,sizeof(dp));



    cin >>n>>k;



    for(int i=0;i<n;i++){

        cin >> pedras[i];

    }



    cout<<frog2(0,n-1)<<endl;

}
