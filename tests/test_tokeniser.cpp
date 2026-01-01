#include "tokeniser.hpp"
#include <vector>
#include <cassert>
#include <iostream>
#include <string>

void run_tests(const std::string &input,
               const std::vector<std::string> &expected){
    std::cout<<"---TEST START---"<<"\n";

    std::cout<<"Input: " << input << "\n";

    std::vector<std::string> tokenisedInput=tokenise(input);

    std::cout<<"Output Tokens: ";

    for (std::string &outputToken:tokenisedInput){
        std::cout<<"["<<outputToken<<"] ";
    }

    std::cout<<"\n";

    assert(tokenisedInput.size() == expected.size());
    for (std::size_t i=0; i<tokenisedInput.size(); i++){
        assert(tokenisedInput[i]==expected[i]);
    }

    std::cout<<"---TEST PASSED---"<<"\n\n";
}

int main(){
    run_tests("Hello World 123", {"hello", "world", "123"});
    run_tests(" " , {});
    run_tests("123!:dfgdfg134#!:", {"123", "dfgdfg134"});

    return 0;
}