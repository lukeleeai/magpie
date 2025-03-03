#include "stdc++.h"

using namespace std;

int main(void){

    

    int h;

    int w;

    int k;

    char s[999][999];

    int a[999][999]={};

    int tmp=0;

    // int zero=0;

    int count=999;

    

    cin >> h >> w >> k;

    

    for(int i=0; i<=h-1; i++){

        

        cin >> s[i];

        

        for(int j=0; j<=w-1; j++){

            

            if(s[i][j]=='#'){

                

                tmp += 1;

                a[i][j] = tmp;

                count = min(i, count);

                

            }

            

        }

        

    }

    

    tmp = 0;

    

    for(int i=0; i<=h-1; i++){

        

        tmp = 0;

        // zero = 0;

        

        for(int j=0; j<=w-1; j++){

            

            /*

            

            if(j==0&&a[i][j]==0){ // sento=0

                

                zero = 1;

                continue;

                

            }

            

            */

            

            if(a[i][j]==0){

                

                a[i][j] = tmp;

                

            } else {

                

                if(tmp==0){

                    

                    for(int p=0; p<=j-1; p++){

                        

                        a[i][p] = a[i][j];

                        

                    }

                    

                }

                

                tmp = a[i][j];

                

            }

            

        }

        

    }

    

    if(a[0][0]==0){

        

        for(int i=0; i<=count-1; i++){

            

            for(int j=0; j<=w-1; j++){

                

                a[i][j] = a[count][j];

                

            }

            

        }

        

    }

    

    for(int i=0; i<=h-1; i++){

        

        if(a[i][0]==0){

            

            for(int j=0; j<=w-1; j++){

                

                a[i][j] = a[i-1][j];

                

            }

            

        }

        

    }

    

    // cout << "debug : " << count << endl; // debug

    

    for(int i=0; i<=h-1; i++){

        

        for(int j=0; j<=w-1; j++){

            

            cout << a[i][j];

            

            if(j<=w-2){

                

                cout << " ";

                

            }

            

        }

        

        cout << endl;

        

    }



    return 0;

    

}