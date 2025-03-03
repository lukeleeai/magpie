#include <iostream>

#include <vector>

using namespace std;



int n={},k={};

string integer[11]={};

vector<string>num={};

int chousen[11]={};

string complete_integer[10000]={};

string answer={};

int integer_count=0;





void operation(){

    for(int i=1;i<=n;i++){

        if (chousen[i]==0){

            

            chousen[i]=1;

            num.push_back(integer[i]);

        

            if(num.size()==k){

                for(int i=1;i<=k;i++){

                    answer+=num[i-1];

                }

                for(int i=1;i<=integer_count;i++){

                    if(answer==complete_integer[i]){

                        goto none;

                    }

                }

                integer_count+=1;

                complete_integer[integer_count]=answer;



                none:;

                answer={};

            }else{

                operation();

            }

            num.pop_back();

            chousen[i]=0;

        }

        

    }



}















int main(){

    

    while(true){



    cin >> n >> k;

    if (n==0&&k==0){

        break;

    }

    for(int i=1;i<=n;i++){

        cin >> integer[i];

    }



    operation();



    cout << integer_count << endl;

        

    n={};

    k={};

    for(int i=0;i<=10;i++){

        integer[i]={};

        chousen[i]={};

    }

    num={};

    for(int i=0;i<=9999;i++){

        complete_integer[i]={};

    }

    answer={};

    integer_count=0;

        

    }

    return 0;

}