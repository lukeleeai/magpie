#include<iostream>

#include<vector>

#include<algorithm>

using namespace std;

int main(){

    int a,b,c,n;

    while(cin>>a>>b>>c,a||b||c){

        cin>>n;

        int f[300];

        fill(f,f+300,2);

        int m=a+b+c;

        int x[1000],y[1000],z[1000];

        bool r[1000];

        for(int i=0;i<n;i++){

            cin>>x[i]>>y[i]>>z[i]>>r[i];

            x[i]--;y[i]--;z[i]--;

        }





        int cnt=0;

        while(cnt<100000){



            for(int i=0;i<n;i++){

                int a=x[i],b=y[i],c=z[i];

                bool Flag=r[i];

                if(Flag){



                    f[a]=f[b]=f[c]=1;

                }

                else{

                    if(f[b]==1&&f[c]==1){



                        f[a]=0;

                    }

                    if(f[a]==1&&f[c]==1){



                        f[b]=0;

                    }

                    if(f[a]==1&&f[b]==1){



                        f[c]=0;

                    }

                }

            }

            cnt++;

        }

        for(int i=0;i<m;i++)cout<<f[i]<<endl;

    }

}