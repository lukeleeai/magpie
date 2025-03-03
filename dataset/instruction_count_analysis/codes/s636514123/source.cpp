#include"stdc++.h"

using namespace std;

typedef long long ll;

const int N=1e5+5;

string s[N];

char ans[N];

int n,a,b,c;

void dfs(int id,int a,int b,int c){

    if(a<0 || b<0 || c<0) return;

    if(id==n){

        puts("Yes");

        for(int i=0;i<n;i++) cout<<ans[i]<<endl;

        exit(0);

    }

    else{

        if(s[id]=="AB"){

            ans[id]='A';

            dfs(id+1,a+1,b-1,c);

            ans[id]='B';

            dfs(id+1,a-1,b+1,c);

        }

        else if(s[id]=="AC"){

            ans[id]='A';

            dfs(id+1,a+1,b,c-1);

            ans[id]='C';

            dfs(id+1,a-1,b,c+1);

        }

        else if(s[id]=="BC"){

            ans[id]='B';

            dfs(id+1,a,b+1,c-1);

            ans[id]='C';

            dfs(id+1,a,b-1,c+1);

        }

    }

}

main()

{

    cin>>n>>a>>b>>c;

    for(int i=0;i<n;i++) cin>>s[i];

    dfs(0,a,b,c);

    puts("No");

    return 0;

}
