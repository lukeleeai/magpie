#include"stdc++.h"

#define ll long long

using namespace std;





map<ll,ll> nb;





ll f(ll x){



    if(x<=2) return 0;



    if(nb[x]!=0){

        return nb[x];

    }

    int aux;

    if(x%2==1){

        aux=f((x-1)/2);

    }

    else{

        aux=f((x-2)/2);

    }



    nb[x]=1+aux;



    return nb[x];





}





void cautare(ll stanga,ll dreapta,ll nb,ll &maxim){

    if(stanga>dreapta)

        return;

    ll m=(stanga+dreapta)/2;

    ll miscari=f(m);



    if(miscari==nb){

        maxim=m;

        cautare(m+1,dreapta,nb,maxim);

        return;

    }



    if(miscari>nb){

        cautare(stanga,m-1,nb,maxim);

    }

    else{

        cautare(m+1,dreapta,nb,maxim);

    }

}







int main()

{

    ll x;

    cin>>x;

    ll maxim;

    cautare(2,LONG_MAX,x,maxim);

    cout<<maxim<<"\n";

}