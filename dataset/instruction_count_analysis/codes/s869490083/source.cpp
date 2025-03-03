const char *WSPACE_SOURCE=R"(   

   

	

					   

	  	   	

   				   	  	      

		 

   

   	 

   	 

	

					

 	 	

   	 

			

 	 	  

   	

	    

 

		 

   	

				

 	   	 	 

	

  







   	

   	 

   

		 

   	 

 

    	

	      	 

 

		 		

	  		

   	 

 

		 	    	 

   	 

			   	

	   		 

 

 	 



   		

 





	



   	  

 

    	

			 

		  	

		 	 	

 





	



   	 	

   	

 

			 

	

)";



#include <cstdio>

#include <cstdint>

#include <cinttypes>

#include <cassert>



#include <iostream>

#include <map>

#include <stack>

#include <string>

#include <exception>



constexpr char SPACE=' ', TAB='\t', LINEFEED='\n';



struct CompileError: public std::exception {

  const std::string why;

  const size_t where;

  CompileError(const std::string &why, size_t where): why(why), where(where) {}

};



std::string tr(const std::string &src, char space, char tab, char linefeed) {

  std::string res="";

  for (char ch: src) {

    if (ch == space) {

      res += SPACE;

    } else if (ch == tab) {

      res += TAB;

    } else if (ch == linefeed) {

      res += LINEFEED;

    }

  }

  return res;

}



uint64_t parse_int(const std::string &src, size_t &i) {

  // XXX assume 64-bit integer, but specification requires arbitrary-

  //     precision integer



  char ch=src.at(i++);

  uint64_t n=0;

  if (ch == SPACE || ch == TAB) {

    while (src.at(i) != LINEFEED) {

      n = (n << 1) | (src.at(i++) == TAB);

    }

    if (ch == TAB) {

      n = -n;

    }

    ++i;

    return n;

  }

  throw CompileError("Invalid integer", i);

}



std::string int_to_bytes(uint64_t n) {

  std::string res(8, 0);

  for (size_t i=0; i<8; ++i) {

    res[i] = (unsigned char)(n & 255);

    n >>= 8;

  }

  return "q"+res;

}



uint64_t bytes_to_int(const std::string &b, size_t &i) {

  uint64_t n=0;

  if (b[i] == 'q') {

    int sh=0;

    while (sh < 64) {

      n |= uint64_t(b[++i] & 255) << sh;

      sh += 8;

    }

    ++i;

  }

  return n;

}



void stack_manipulation(std::string &res, const std::string &src, size_t &i) {

  char ch=src.at(i++);

  if (ch == SPACE) {

    // Push the number onto the stack

    res += "^" + int_to_bytes(parse_int(src, i));

    return;

  } else if (ch == LINEFEED) {

    ch = src.at(i++);

    if (ch == SPACE) {

      // Duplicate the top item on the stack

      res += "=";

      return;

    } else if (ch == TAB) {

      // Swap the top two items on the stack

      res += "~";

      return;

    } else if (ch == LINEFEED) {

      // Discard the top item on the stack

      res += "_";

      return;

    }

  }

  throw CompileError("Invalid stack manipulation", i);

}



void arithmetic(std::string &res, const std::string &src, size_t &i) {

  char ch=src.at(i++);

  if (ch == SPACE) {

    ch = src.at(i++);

    if (ch == SPACE) {

      res += "+";

      return;

    } else if (ch == TAB) {

      res += "-";

      return;

    } else if (ch == LINEFEED) {

      res += "*";

      return;

    }

  } else if (ch == TAB) {

    ch = src.at(i++);

    if (ch == SPACE) {

      res += "/";

      return;

    } else if (ch == TAB) {

      res += "%";

      return;

    }

  }

  throw CompileError("Invalid arithmetic", i);

}



void heap_access(std::string &res, const std::string &src, size_t &i) {

  char ch=src.at(i++);

  if (ch == SPACE) {

    // Store

    res += "!";

  } else if (ch == TAB) {

    // Retrieve

    res += "?";

  } else {

    throw CompileError("Invalid heap access", i);

  }

}



void flow_control(std::string &res, const std::string &src, size_t &i,

                  std::map<uint64_t, size_t> &label) {



  char ch=src.at(i++);

  if (ch == SPACE) {

    ch = src.at(i++);

    if (ch == SPACE) {

      // Mark a location in the program

      label[parse_int(src, i)] = res.size();

      return;

    } else if (ch == TAB) {

      // Call a subroutine

      res += "(" + int_to_bytes(parse_int(src, i));

      return;

    } else if (ch == LINEFEED) {

      // Jump unconditionally to a label

      res += "U" + int_to_bytes(parse_int(src, i));

      return;

    }

  } else if (ch == TAB) {

    ch = src.at(i++);

    if (ch == SPACE) {

      // Jump to a label if the top of the stack is zero

      res += "0" + int_to_bytes(parse_int(src, i));

      return;

    } else if (ch == TAB) {

      // Jump to a label if the top of the stack is negative

      res += "N" + int_to_bytes(parse_int(src, i));

      return;

    } else if (ch == LINEFEED) {

      // End a subroutine and transfer control back to the caller

      res += ")";

      return;

    }

  } else if (ch == LINEFEED && src.at(i++) == LINEFEED) {

    // End the program

    res += "$";

    return;

  }

  throw CompileError("Invalid flow control", i);

}



void io_access(std::string &res, const std::string &src, size_t &i) {

  char ch=src.at(i++);

  if (ch == SPACE) {

    ch = src.at(i++);

    if (ch == SPACE) {

      // Output the character at the top of the stack

      res += ".";

      return;

    } else if (ch == TAB) {

      // Output the number at the top of the stack

      res += "<";

      return;

    }

  } else if (ch == TAB) {

    ch = src.at(i++);

    if (ch == SPACE) {

      // Read a character and place it in the location given by the top

      // of the stack

      res += ",";

      return;

    } else if (ch == TAB) {

      // Read a number and place it in the location given by the top of

      // the stack

      res += ">";

      return;

    }

  }

  throw CompileError("Invalid I/O access", i);

}



std::string compile(const std::string &src,

                    std::map<uint64_t, size_t> &label) {



  std::string res="";

  size_t i=0;

  while (i < src.length()) {

    switch(src.at(i)) {

    case SPACE:

      stack_manipulation(res, src, ++i);

      break;



    case TAB:

      ++i;

      switch (src.at(i)) {

      case SPACE:

        arithmetic(res, src, ++i);

        break;



      case TAB:

        heap_access(res, src, ++i);

        break;



      case LINEFEED:

        io_access(res, src, ++i);

      }

      break;



    case LINEFEED:

      flow_control(res, src, ++i, label);

      if (res.back() == '$') break;

      break;



    default:

      (void)(0);  // maybe unreached, but not for sure

    }

  }

  return res;

}



void run(const std::string &code, const std::map<uint64_t, size_t> &label) {

  std::stack<uint64_t> stack;

  std::stack<size_t> callstack;

  std::map<size_t, uint64_t> heap;



  size_t i=0;

  char op;

  while (i < code.length()) {

    op = code.at(i++);

    switch (op) {

    case '^':

      stack.push(bytes_to_int(code, i));

      break;



    case '=':

      assert(!stack.empty());

      stack.push(uint64_t(stack.top()));

      break;



    case '~':

      assert(stack.size() >= 2);

      {

        uint64_t first=stack.top();

        stack.pop();

        uint64_t second=stack.top();

        stack.pop();

        stack.push(first);

        stack.push(second);

      }

      break;



    case '_':

      stack.pop();

      break;



    case '+':

    case '-':

    case '*':

    case '/':

    case '%':

      assert(stack.size() >= 2);

      {

        uint64_t first=stack.top();

        stack.pop();

        uint64_t second=stack.top();

        stack.pop();

        switch (op) {

        case '+': stack.push(first+second); break;

        case '-': stack.push(first-second); break;

        case '*': stack.push(first*second); break;

        case '/': stack.push(first/second); break;

        case '%': stack.push(first%second); break;

        }

      }

      break;



    case '!':

      assert(stack.size() >= 2);

      {

        uint64_t value=stack.top();

        stack.pop();

        size_t addr=stack.top();

        stack.pop();

        heap[addr] = value;

      }

      break;



    case '?':

      assert(!stack.empty());

      {

        size_t addr=stack.top();

        stack.pop();

        stack.push(heap[addr]);

      }

      break;



    case '(':

    case 'U':

    case '0':

    case 'N':

      {

        size_t lid=bytes_to_int(code, i);

        auto addrp=label.find(lid);

        assert(addrp != label.end());

        size_t addr=addrp->second;

        if (op == '(') {

          callstack.push(std::exchange(i, addr));

        } else if (op == 'U') {

          i = addr;

        } else {

          assert(!stack.empty());

          uint64_t top=stack.top();

          stack.pop();

          if ((op == '0' && top == 0) || (op == 'N' && (top >> 63))) {

            i = addr;

          }

        }

      }

      break;



    case ')':

      i = callstack.top();

      callstack.pop();

      break;



    case '$':

      return;



    case '.':

      putchar(stack.top());

      stack.pop();

      break;



    case '<':

      printf("%" PRId64, stack.top());

      stack.pop();

      break;



    case ',':

      assert(!stack.empty());

      heap[stack.top()] = getchar();

      stack.pop();

      break;



    case '>':

      assert(!stack.empty());

      scanf("%" SCNu64, &heap[stack.top()]);

      stack.pop();

      break;

    }

  }

}



int main(int argc, char *argv[]) {

  using namespace std::string_literals;

  std::string src;

  if (argc > 1) {

    FILE *fin;

    if (argv[1] != "-"s) {

      fin = fopen(argv[1], "r");

      if (!fin) return 1;

    } else {

      fin = stdin;

    }

    int ch;

    while ((ch = getc(fin)) != EOF)

      src += ch;



    fclose(fin);

  } else {

    src = WSPACE_SOURCE;

  }



  for (size_t i=0; i<src.length(); ++i) {

    if (src[i] > SPACE) {

      src = tr(src, 'S', 'T', 'L');

      break;

    }

  }



  std::map<uint64_t, size_t> label;

  std::string code;

  try {

    code = compile(src, label);

  } catch (CompileError &e) {

    printf("%zu: %s\n", e.where, e.why.c_str());

  }



  run(code, label);

}
