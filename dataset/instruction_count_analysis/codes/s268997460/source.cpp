#include<cstdio>

#include<cmath>

using namespace std;

int main()

{

    bool fi=true;

    long long n,x,mi,tr=0;

    scanf("%lld",&n);

    while(n--){

        scanf("%lld",&x);

        if(fi){

            mi=x;

            tr++;

            fi=false;

        }

        else{

            if(x<mi){

                mi=x;

                tr++;

            }

            else continue;

        }

    }

    printf("%lld",tr);

}
