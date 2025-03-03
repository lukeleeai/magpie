///HELLO THERE~!

///CREATED BY MD SADMAN MEHEDI SIVAN(IUT CSE-SWE^19)



#include "stdc++.h"



#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define read freopen("blue.txt","r",stdin);

#define write freopen("red.txt","w",stdout);

#define pie 2*acos(0.0);



typedef long long ll;



using namespace std;





int main()



{



    fastio;



    int N,M;

    cin>>N>>M;



    int sivan[M+1];



    int sum=0;



    for(int i=0; i<M; i++)

    {

        cin>>sivan[i];

        sum=sum+sivan[i];

    }



    if(sum<=N)

        cout<<N-sum;

    else

        cout<<"-1";



    return 0;



}
