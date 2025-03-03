#include"stdc++.h"

using namespace std;



int x,y,gx,gy;



int main(){

    cin>>x>>y;

    if(x==2){

        gx=1;

    }else if((x==4)||(x==6)||(x==9)||(x==11)){

        gx=2;

    }else{

        gx=3;

    }



    if(y==2){

        gy=1;

    }else if((y==4)||(y==6)||(y==9)||(y==11)){

        gy=2;

    }else{

        gy=3;

    }



    if(gx==gy){

        cout<<"Yes"<<endl;

    }else{

        cout<<"No"<<endl;

    }

}