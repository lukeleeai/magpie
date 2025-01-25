#include <iostream>   

#include <map>   

#include <sstream>   

#include <string.h>   

using namespace std;   

  

map<int, char> AlphabetTable;   

map<int, int> table;   

  

char decode(char a){   

       

    int z = a - 'a';   

       

    for(int i = 0; i < 26; i++){   

        if(table[i] == z) return AlphabetTable[i];   

    }   

}   

  

void makeTable(int a, int b){   

    for(int i = 0; i < 26; i++){   

        table[i] = (a*i+b) % 26;   

    }   

}   

  

void makeAlphabetTable(){   

  

    char c = 'a';   

  

    for(int i = 0; i < 26; i++){   

        AlphabetTable[i] = c;   

        c++;   

    }   

}   

  

int main(){   

  

    string code, tmp;   

    int n;   

       

    getline (cin, code);   

    stringstream ssn(code);   

    ssn >> n;   

    makeAlphabetTable();   

    for(int i = 0; i < n; i++){   

        getline(cin, code );   

        tmp = code;   

        for(int b = 0; b < 26; b++){   

            for(int a = 1; a < 26; a+=2){   

                if(a%13 != 0){   

                    makeTable(a, b);   

                    code = tmp;   

                    for(int j = 0; j < code.length(); j++){   

                        if('a' <= code[j] && code[j] <= 'z'){   

                            code[j] = decode(code[j]);   

                        }   

                    }   

                    if(code.find("this") != -1 || code.find("that")!= -1){   

                        cout << code << endl;   

                        break;   

                    }   

                }   

            }   

        }   

    }   

       

    return 0;   

}  