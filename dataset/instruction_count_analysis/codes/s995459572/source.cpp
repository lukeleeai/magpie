#include<iostream>

#include<vector>

#include <algorithm>



using namespace std;

vector<int> n;



int main(void)

{

    int count,temp,ans=0,rant=0;



    cin>>count;

    for(int i=0;i<count;i++)

    {

        cin>>temp;

        rant=rant>temp?rant:temp;

        n.push_back(temp);

    }



  vector<bool> pri(++rant,0);



   for(int i=2;i*i<rant;i++)

  {

      if(!pri.at(i))

         {



             for(int j=i;j*i<rant;j++)

                {

                   pri[i*j]=true;

                }

         }

  }



    for(int i=0;i<count;i++)

    {

        if(!pri.at(n.at(i)))

            ans++;

    }



  cout<<ans<<endl;

return 0;

}