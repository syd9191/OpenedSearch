#include <iostream>
#include "tokeniser.hpp"

int main(){
    std::string testString1= "Hello World 123";
    std::string testString2= " ";
    std::string testString3= "123!:dfgdfg134#!:";

    std::vector<std::string> tokensVec;

    tokensVec=tokenise(testString3);

    std::cout<<"Test Starts Here"<<"\n";

    for (const std::string&tokenString:tokensVec){
        std::cout<<tokenString<<"\n";
    }
    return 0;
}