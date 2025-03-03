#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

#define MAXM 100

char s[MAXM+10]; 

bool a[MAXM+10],b[MAXM+10];   

int main()

{

    int n,m,ans;  

    int i,j;

    scanf("%d",&n); 

    scanf("%s",s);

    for(i=0;i<n;i++)

	{

        a[s[i]-'a']=1; 

        memset(b,false,sizeof(b));  

        

        for(j=i+1;j<n;j++)

		{   

            b[s[j]-'a']=1;  

        }

        m=0; 

        for(j=0;j<26;j++)

		{

            if(a[j] && b[j])

			{    

                m++; 

            } 

        } 

        ans=max(ans,m); 

    }

    printf("%d",ans); 

    return 0; 

} 