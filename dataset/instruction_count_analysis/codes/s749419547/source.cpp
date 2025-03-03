#include <algorithm>

#include <iostream>

#include <string>

#include <vector>

using namespace std;

int main()

{

    string s;

    int k;

    cin>>s>>k;

	vector<string> v;

	for (int i=0;i<s.size();i++)

    {

		for(int j=1;j<=5;j++)

        {

			v.push_back(s.substr(i,j));

		}

	}

	sort(v.begin(),v.end());

	v.erase(unique(v.begin(),v.end()),v.end());

	k--;

	cout<<v[k]<<endl;

	//system ("pause");

	return 0;

}