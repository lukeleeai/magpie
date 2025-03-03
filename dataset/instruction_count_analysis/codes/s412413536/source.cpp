#include "stdc++.h"



using namespace std;



int main(){

    int a,b;

    char c[105][105];

    set<int> x,y;

    cin>>a>>b;

    set<int>::iterator ax;

    set<int>::iterator by;

    for(int i=0;i<a;i++){

        scanf("%s",c[i]);

    }

    for(int i=0;i<a;i++){

        for(int j=0;j<b;j++){

            if(c[i][j]=='#')

            {

                x.insert(i);

                y.insert(j);

            }

        }

    }



    for(ax=x.begin();ax!=x.end();ax++)

    {

        for(by=y.begin();by!=y.end();by++)

        {

            cout<<c[*ax][*by];

        }

        cout<<endl;

    }

    return 0;

}
