# include <iostream>

# include <deque>

using namespace std;



string S;

int K;

deque<int> d;

int counter=0;

long long ans=0;

bool allsame=true;



int main()

{

    cin>>S;

    cin>>K;



    char current=S[0];



    for (int i=0; i<S.size(); i++)

    {

        if (S[i]==current)

        {

            counter++;

        }



        else

        {

            d.push_back(counter);

            counter=1;

            current=S[i];

        }

    }



    d.push_back(counter);



    for (int i=0; i<d.size(); i++)

    {

        if (d[i]>1)

        {

            ans=ans+(d[i]/2);

        }

    }



    for (int i=0; i<S.size(); i++)

    {

        current=S[0];

        if (S[i]!=current)

        {

            allsame=false;

            break;

        }

    }



    if (allsame)

    {

        ans=1ll*K*S.size()/2;



    }



    else if (d.front()%2==1 && d.back()%2==1 && S[0]==S[S.size()-1])

    {

        ans=ans*K;

        ans=ans+K-1;

    }



    else

    {

        ans=ans*K;

    }



    cout<<ans<<endl;

}