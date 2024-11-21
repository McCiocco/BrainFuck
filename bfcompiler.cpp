#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define cout out

int consecutive_equal_chars(string const &s, string::iterator p) {

    int ans = 1;
    while (*p == *++p) ans++;
    return ans;

}

int main(int argc, char* argv[]) {

    string instructions = "";
    string s = "";

    string pathIn, pathOut;

    pathIn = argv[1];
    ifstream in(pathIn);
    for (int i = 0; i < 3; i++) pathIn.pop_back();
    pathOut = pathIn + ".cpp";
    int repetitions = 0;

    ofstream out(pathOut);

    while (in) {

        in >> s;
        instructions.append(s);

    }

    auto ptr = instructions.begin();

    cout << "#include <iostream> \n using namespace std; \n int main() { \n const int MAXSIZE = 30000; \nint cells[MAXSIZE] = {0}; \nint *ptr = cells; \nchar inp; \n" ;

    while (ptr != instructions.end()) {
        
        switch(*ptr) {

            case '+': {

                repetitions = consecutive_equal_chars(instructions, ptr);
                cout << "*ptr += " << repetitions << ";\n"; 
                ptr = next(ptr, repetitions-1);
                break;
            
            }

            case '-': {

                repetitions = consecutive_equal_chars(instructions, ptr);
                cout << "*ptr -= " << repetitions << ";\n"; 
                ptr = next(ptr, repetitions-1);
                break;
            
            }

            case '>': {

                repetitions = consecutive_equal_chars(instructions, ptr);
                cout << "ptr += " << repetitions << ";\n"; 
                ptr = next(ptr, repetitions-1);
                break;
            
            }

            case '<': {

                repetitions = consecutive_equal_chars(instructions, ptr);
                cout << "ptr -= " << repetitions << ";\n"; 
                ptr = next(ptr, repetitions-1);
                break;
            
            }

            case '.': cout << "cout << (char) *ptr;\n"; break;

            case ',': cout << "cin >> inp;\n*ptr= (int) inp;\n"; break;

            case '[': cout << "while (*ptr != 0) {\n"; break;

            case ']': cout << "}\n"; break;

            default: break;

        }

        ptr++;

    }

    cout << "cout << endl;  \n }";

}

