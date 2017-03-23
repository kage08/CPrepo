#include <iostream>
#include <string>
class CheckFunction{
   public:
    	int newFunction(std::string s){
        	int total=0;
            for(char c: s)
                total+=dashno(c);
            return total;
        }
    	
    	int dashno(char c){
            switch(c){
            	case '1': return 2;
            	case '7': return 3;
            	case '4': return 4;
            	case '2': case '3': case '5': return 5;
            	case '0': case '6': case '9': return 6;
            	case '8': return 7;
            	default: return 0;
	    } 

         }
};
