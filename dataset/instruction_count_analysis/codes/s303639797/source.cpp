#include"stdc++.h"

using namespace std;

int n,t=0;

void dfs(int k,int end,string s)

{

    if(k>end)

        if(++t==n)

        {

            cout<<s;

            exit(0);

        }

        else return ;

    for(char ch=s[s.size()-1]-1;ch<=s[s.size()-1]+1;ch++)

        if(ch>='0'&&ch<='9')

            dfs(k+1,end,s+ch);

}

int main()

{

    ios::sync_with_stdio(false);

    cin>>n;

    for(int i=1;;i++)

		for(char c='1';c<='9';c++)

		{

			string s="";

			dfs(2,i,s+c);

		}

	return 0;

}