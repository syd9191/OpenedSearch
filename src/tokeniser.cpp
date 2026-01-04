# include <tokeniser.hpp>
#include <cctype> 

std::vector<std::string> tokenise(std::string const &inputString) { // const here is a promise not to modify the param
    std::string curr;
    std::vector<std::string> tokensVec;

    for (char c : inputString){
        unsigned char unsignedC=static_cast<unsigned char>(c);
        if (std::isalnum(unsignedC)){
            unsigned char lowerC=std::tolower(unsignedC);
            curr.push_back(lowerC);
        }
        else{
            if (!curr.empty()){
                tokensVec.push_back(curr);
                curr.clear();
            }
        }
    }
    
    if (!curr.empty()){
        tokensVec.push_back(curr);
    }

    return tokensVec;
};