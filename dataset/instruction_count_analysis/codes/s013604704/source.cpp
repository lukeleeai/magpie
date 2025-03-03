#include <iostream>

#include <string>

using namespace std;



// 'P', 'Q', 'R' ツづー '1', '2', '3' ツづ可置ツつォツ環キツつヲツづゥ

void PQR_change(string& s ,char p , char q , char r ){

	for(int i=0 ; i < s.size() ; i++ ){

		if( s[i] == 'P' ) s[i] = p;

		if( s[i] == 'Q' ) s[i] = q;

		if( s[i] == 'R' ) s[i] = r;

	}

}



// "--"(ツ連ツ堕アツつキツづゥ2ツづつづ個マツイツナツス) ツづー "" ツづ可置ツつォツ環キツつヲツづゥ

void minus_erace(string& s){

	for(int i=1 ; i < s.size() ; i++ ){

		if( s[i] == '-' && s[i-1] == '-' ){

			s.erase( i-1 , 2 );

			i = 0;

		}

	}

}



// "-0", "-1", "-2" ツづー "2", "1", "0" ツづ可置ツつォツ環キツつヲツづゥ

void minus_calc(string& s){

	for(int i=1 ; i < s.size() ; i++ ){

		if( s[i-1] == '-' && ( s[i] == '0' || s[i] == '1' || s[i] == '2' ) ){

			if( s[i] == '0' ){

				s.replace( i-1 , 2 , "2" );

			}else if( s[i] == '1' ){

				s.replace( i-1 , 2 , "1" );

			}else if( s[i] == '2' ){

				s.replace( i-1 , 2 , "0" );

			}

			i = 0;

		}

	}

}



// "(0+0)", ... , "(2*2)" ツづー "0", ... , "2" ツづ可置ツつォツ環キツつヲツづゥ (18ツ津環づィ) 

void calc(string& s){

	string ex[18] = {

		"(0+0)", "(0+1)", "(0+2)",

		"(1+0)", "(1+1)", "(1+2)",

		"(2+0)", "(2+1)", "(2+2)",

		"(0*0)", "(0*1)", "(0*2)",

		"(1*0)", "(1*1)", "(1*2)",

		"(2*0)", "(2*1)", "(2*2)"

	};

	string result[18] = {

		"0", "1", "2",

		"1", "1", "2",

		"2", "2", "2",

		"0", "0", "0",

		"0", "1", "1",

		"0", "1", "2"

	};

	for(int i=0 ; i+4 < s.size() ; i++ ){

		for(int j=0 ; j < 18 ; j++ ){

			if( s.substr(i,5) == ex[j] ){

				s.replace( i , 5 , result[j] );

				i = -1;

				break;

			}

		}

	}

}



int main(){

	string s;

	while( cin >> s , s != "." ){

		int ans = 0;

		for(char p = '0' ; p <= '2' ; p++ ){

			for(char q = '0' ; q <= '2' ; q++ ){

				for(char r = '0' ; r <= '2' ; r++ ){

					string s_ = s;

					// 'P', 'Q', 'R' ツづー '1', '2', '3'ツづ可置ツつォツ環キツつヲツづゥ

					PQR_change( s_ , p , q , r );

					// "--"(ツ連ツ堕アツつキツづゥ2ツづつづ個マツイツナツス) ツづー ""ツづ可置ツつォツ環キツつヲツづゥ

					minus_erace( s_ );

					

					// "0", "1", "2" ツづ個値ツづ可づ按づゥツづ慊づ繰ツづィツ陛板つオツ嘉算ツづ湘ヲツ算ツづーツ計ツ算ツつキツづゥ

					while( s_.size() > 1 ){

						// "-0", "-1", "-2" ツづー "2", "1", "0" ツづ可置ツつォツ環キツつヲツづゥ

						minus_calc( s_ );

						// "(0+0)", ... , "(2*2)" ツづー "0", ... , "2" ツづ可置ツつォツ環キツつヲツづゥ (18ツ津環づィ) 

						calc( s_ );

						// cout << "debug : " << s_ << endl;

					}

					if( s_ == "2" ){

						ans++;

					}

				}

			}

		}

		cout << ans << endl;

	}	

}