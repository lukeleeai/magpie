#include<iostream>

#include<stdio.h>

#include<cstring>

#include<cmath>

#include<algorithm>

#include<vector>

#include<map>

#include<set>

#include<queue>

#define ll long long

using namespace std;

int pos(int n)

{

    if(n<0)

        return 0;

    else

        return n;

}

int main()

{

    int a,b;

    cin>>a>>b;

    cout<<100<<" "<<100<<endl;

    int s[102][102]={0};//0为黑1为白.

    for(int i=51;i<=100;i++){

        for(int j=1;j<=100;j++){

            s[i][j]=1;

        }

    }

    a--,b--;

    for(int i=1;i<=50;i+=2){

        int j=1;

        for( ;j<=100;j+=2){

            if(a>0){

                s[i][j]=1;

                a--;

            }else{

                break;

            }

        }

    }

    for(int i=100;i>=51;i-=2){

        for(int j=1;j<=100;j+=2){

            if(b>0){

                s[i][j]=0;

                b--;

            }else{

                break;

            }

        }

    }

    for(int i=1;i<=100;i++){

        int j=1;

        for ( ;j<=100;j++){

            if(s[i][j]==1)

                cout<<".";

            else

                cout<<"#";

        }

        cout<<endl;

    }

}
