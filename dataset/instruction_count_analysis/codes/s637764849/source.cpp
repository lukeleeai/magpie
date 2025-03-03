    #include<iostream>

    #include<string>

    #include<algorithm>

    using namespace std;

    int main(){

        string S;

        cin>>S;

        int res=S.size();

        int a=S.size();

        for(int i=1;i<S.size();i++){

            if(S[i]!=S[i-1])

                res=min(res,max(i,a-i));

        }

        cout<<res<<endl;

        return 0;

    }


