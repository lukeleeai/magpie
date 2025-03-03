#include <iostream>

#include <sstream>

#include <string>

#include <list>

#include <stdio.h>

#include <ctype.h>

#include <string.h>



using namespace std;



void deleteX(list<int> &list, int x) {

    for(auto itr=list.begin(); itr!=list.end(); itr++ ) {

        if(*itr==x) {

            list.erase(itr);

            break;

        }

    }

}



bool tiny_match(const char* str, const char* ptn, int n, int* p_val) {

	*p_val = 0;

	if (strncmp(str, ptn, (size_t)n) != 0) {

		return false;

	}

	if (isalpha(str[n])) {

		return false;

	}

	*p_val = atoi(&(str[n]));

	return true;

};



#define MATCH(str, ptn, p)		(tiny_match((str), (ptn), sizeof(ptn) - (size_t)1, (p)))



int main(void) {

    list<int> list;

    int n;

    int x;

    

    string str;

    getline(cin,str);

    stringstream ss(str);



	ss >> n;



	while( n > 0 && getline(cin, str) ) {

		size_t head = str.find_first_not_of(" \t\v\r\n");

		if (head == std::string::npos) {

			printf("ERROR: Syntax error.\n");

			return -1;

		}

		n--;

        

        if( MATCH(&(str[head]), "insert", &x) ) {

			//printf("insert %d\n", x);

            list.push_front(x);

        }

        else if( MATCH(&(str[head]), "delete", &x) ) {

			//printf("delete %d\n", x);

            deleteX(list, x);

        }

        else if( MATCH(&(str[head]), "deleteFirst", &x) ) {

			//printf("deleteFirst %d\n", x);

            list.pop_front();

        }

        else if( MATCH(&(str[head]), "deleteLast", &x) ) {

			//printf("deleteLast %d\n", x);

            list.pop_back();

        }

		else {

			printf("ERROR: Unknown token.\n");

		}

    }



	//display list

    for(auto itr=list.begin(); itr!=list.end(); itr++ ) {

        if(itr==list.begin()) {

            cout << *itr;

        } else {

            cout << " " << *itr;

        }

    }

    cout << endl;



	return 0;

}