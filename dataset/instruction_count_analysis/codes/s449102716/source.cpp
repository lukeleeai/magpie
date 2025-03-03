#include"stdc++.h"

using namespace std;

#define ll long long

#define ull unsigned long long

#define mp make_pair

typedef pair<int,int> pii;

char str[1000009];

int f[1000009];

int main()

{

    scanf("%s",str+1);

    int len=strlen(str+1);

    int answer=0;

    for(int i=1;i<=len;i++){

        f[i]=str[i]-'0';

    }

    for(int i=1;i<=len+10;i++)

    {

        if(f[i]>=10){

            f[i]-=10;

            f[i+1]++;

        }

        if(f[i]>=6){

            answer+=10-f[i];

            f[i+1]++;

        }

        else if(f[i]==5){

            answer+=5;

            if(f[i+1]>=5){

                f[i+1]++;

            }

        }

        else answer+=f[i];

    }

    cout<<answer<<endl;

    return 0;

}