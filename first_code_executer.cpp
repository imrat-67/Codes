#include <iostream>
#include <cstdlib>

int main() {

    int cr = std::system("g++ code01.cpp -o code01");

    if (cr != 0) {
        std::cerr << "Compilation failed\n";
        return 1; 
    }
    int er = std::system(".\\code01 < input.txt > output1.txt");
    if (er != 0) {
        std::cerr << "Execution failed\n";
        return 1; 
    }

    return 0;
}
