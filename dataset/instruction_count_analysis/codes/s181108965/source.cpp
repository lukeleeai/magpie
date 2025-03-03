#include"stdc++.h"

using namespace std;



#define scanf cin

#define printf cout



int main()

{

	std::ios::sync_with_stdio(false);

    string ori;

    scanf>>ori;

    string b=ori;

    reverse(ori.begin(),ori.end());

    for(int i=0;i<ori.size();++i)

    {

        if(ori[i]=='b') ori[i]='d';

        else if(ori[i]=='d') ori[i]='b';

        else if(ori[i]=='p') ori[i]='q';

        else if(ori[i]=='q') ori[i]='p';

    }

    if(ori==b) printf<<"Yes"<<endl;

    else printf<<"No"<<endl;

}