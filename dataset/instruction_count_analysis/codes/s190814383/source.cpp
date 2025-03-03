#include <iostream>

#include <map>

#include <vector>

using namespace std;



int main(){

	int n,a,b;

	bool flag;

	string number;

	map<string,int> info;

	vector<string> seq;

	

	while(cin >> n && n){

		info.clear();

		seq.clear();

		while(n--){

			cin >> number >> a >> b;

			if(!info[number])seq.push_back(number);

			while(b-- && info[number]<1000000){

				info[number] += a;

			}

		}

		flag = true;

		for(int i=0;i<seq.size();i++){

			if(info[seq[i]]>=1000000){

				flag = false;

				cout << seq[i] << endl;

			}

		}

		if(flag)cout << "NA" << endl;

	}

}