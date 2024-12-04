#include <cstdlib>
#include <iostream>
#include <string>

void run(std::string s){
    const char* cppFileName = s.data();

    std::string val;
    int i=0;
    while(s[i]!='.') val+=s[i],i++;
    std::string compileCommand = "g++ -o a " + std::string(cppFileName);
    int compileResult = system(compileCommand.c_str());

    if (compileResult == 0) {
        std::cout<<val<<" running"<<std::endl;
        const char* runCommand = "a";
        int runResult = system(runCommand);

        if (runResult == 0) {
            
        } else {
            std::cerr << "Execution failed." << std::endl;
        }
    } else {
        std::cerr << "Compilation failed." << std::endl;
    }
}


int main() {
    int n= 100;
    for(int i=0; i<n; i++){
    std::cout<<"Checking "<<" "<<i+1<<": "<<std::endl;
    run("Test_case_gen.cpp");
    run("first_code_executer.cpp");
    run("second_code_executer.cpp");
    run("checker.cpp");
    std::cout<<std::endl;
    }
}
