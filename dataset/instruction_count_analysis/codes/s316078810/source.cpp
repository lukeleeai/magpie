#include <iostream>

#include <vector>

#include <algorithm>

#include <fstream>

#include <iomanip>

#include <valarray>

#include <iterator>

#include <stack>

#include <set>

#include <cstring>

#include <cstdlib>

#include <queue>

#include <list>

#include <map>

#include <strstream>

#include <streambuf>

#include <string>

#include <sstream>



#define def(type,vec) vector<type> vec

#define last(arr) arr.size()-a

#define loop(i,n) for(ll i=0 ; i<n ; ++i)

#define all(v) ((v).begin()),((v).end())

#define pb push_back

#define ll long long

#define iteloop(type,data,name,it) for(type<data>::iterator it=name.begin() ;it!=name.end() ; ++it)



using namespace std;

string int_to_string(int x){

        string str;

        ostringstream temp;

        temp<<x;

        str=temp.str();

        return str;

}



int main(){

    int n,k;

    cin>>n>>k;

    char chr;

    set<char> st;

    loop(i,k){

        cin>>chr;

        st.insert(chr);

    }

    for(int i=n ; i<=100000 ; i++){

        string str=int_to_string(i);

        bool x=true;

        loop(j,str.size()){

            if(binary_search(all(st),str[j])){

                x=false;

            }

        }

        if(x){

            cout<<i<<endl;

            break;

        }

    }

}


