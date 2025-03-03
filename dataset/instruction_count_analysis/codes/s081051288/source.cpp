#include"stdc++.h"

using namespace std;

int a[3],b[3][3],c[3][3];

int main(){

    for(int i=0;i<3;++i){

        for(int j=0;j<3;++j){

            cin>>c[i][j];

        }

    }

    for(a[0]=0;a[0]<=100;++a[0]){

        for(a[1]=0;a[1]<=100;++a[1]){

            for(a[2]=0;a[2]<=100;++a[2]){

                for(int i=0;i<3;++i){

                    for(int j=0;j<3;++j){

                        b[j][i]=c[i][j]-a[i];

                    }

                }

                bool ok=true;

                for(int i=0;i<3;++i){

                    for(int j=1;j<3;++j){

                        if(b[i][j]!=b[i][0]){

                            ok=false;

                        }

                    }

                }

                if(ok){

                    cout<<"Yes"<<endl;

                    return 0;

                }

            }

        }

    }

    cout<<"No"<<endl;

    return 0;

}