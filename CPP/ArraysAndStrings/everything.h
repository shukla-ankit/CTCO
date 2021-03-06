#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <climits>
#include <ostream>
#include <algorithm>
#include <typeinfo>
#include <unordered_set>

using namespace std;

namespace Color {
    enum Code {
        FG_RED      = 31,
        FG_GREEN    = 32,
        FG_BLUE     = 34,
        FG_DEFAULT  = 39,
        BG_RED      = 41,
        BG_GREEN    = 42,
        BG_BLUE     = 44,
        BG_DEFAULT  = 49
    };
    class Modifier {
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&
        operator<<(std::ostream& os, const Modifier& mod) {
            return os << "\033[" << mod.code << "m";
        }
    };
}

Color::Modifier red(Color::FG_RED);
Color::Modifier green(Color::FG_GREEN);
Color::Modifier def(Color::FG_DEFAULT);

        template <typename T>
        string print_array(vector<T> array){
            if(array.size() == 0) return "[]";

            string ret = "[";
            for(auto n: array){
                    ret += to_string(n) + ",";                
            }            
            return ret.substr(0, ret.length()-1) + "]" ;
        }
        
        string print_array(vector<string> array){
            if(array.size() == 0) return "[]";
            
            string ret = "[" ;
            for(auto s: array){
                    ret += s + ",";
            }
            return ret.substr(0, ret.length()-1) + "]" ;
        }

        template <typename T>
        string print_array_of_arrays(vector<vector<T>> arrayOfArrays){
            string ret = "[" ;
            for(auto array : arrayOfArrays)
                ret += print_array(array) + ",";
            return ret.substr(0, ret.length()-1) + "]" ;
        }

        template <typename T>
        bool match_array(vector<T> array1, vector<T> array2){
            if (array1.size() != array2.size())
                return false;

            for(int i = 0; i< array1.size() ; i++){
                if(array1[i] != array2[i])
                    return false;
            }
            return true;
        }
        
        template <typename T>
        bool match_arrays_of_arrays(vector<vector<T>> arrayOfArrays1, vector<vector<T>> arrayOfArrays2){
            if (arrayOfArrays1.size() != arrayOfArrays2.size())
                return false;

            for(int i = 0; i< arrayOfArrays1.size() ; i++){
                if(match_array(arrayOfArrays1[i], arrayOfArrays2[i]))
                    return false;
            }
            return true;
        }
