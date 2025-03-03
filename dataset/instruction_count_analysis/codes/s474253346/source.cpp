#include <iostream>

#include <string>

using namespace std;



void replace_all(string& s,string from,string to){

	string::size_type p = 0;

	while(p=s.find(from,p), p!=string::npos){

		s.replace(p,from.length(),to);

		p+=to.length();

	}

}



int main(void){

	int i,j,k,l,count;

	string s,ts,num[3]={"0","1","2"};

	string to0[6]={"(0*0)","(0*1)","(0*2)","(1*0)","(2*0)","(0+0)"};

	string to1[6]={"(1*1)","(1*2)","(2*1)","(0+1)","(1+0)","(1+1)"};

	string to2[6]={"(2*2)","(0+2)","(1+2)","(2+0)","(2+1)","(2+2)"};



	while(cin>>ts && ts!="."){

		count = 0;

		replace_all(ts,"--","");



		for(i=0;i<=2;i++){

			for(j=0;j<=2;j++){

				for(k=0;k<=2;k++){

					s = ts;

					replace_all(s,"P",num[i]);

					replace_all(s,"Q",num[j]);

					replace_all(s,"R",num[k]);



					while(s.length() != 1){

						replace_all(s,"-1","1");

						replace_all(s,"-2","0");

						replace_all(s,"-0","2");



						for(l=0;l<6;l++){

							replace_all(s,to0[l],"0");

							replace_all(s,to1[l],"1");

							replace_all(s,to2[l],"2");

						}

					}

					if(s=="2") count++;

				}

			}

		}



		cout<<count<<endl;

	}



	return 0;

}