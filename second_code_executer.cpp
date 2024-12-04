#include <iostream>
#include <cstdlib>

int main() {

    int cr = std::system("g++ code02.cpp -o code02");

    if (cr != 0) {
        std::cerr << "Compilation failed\n";
        return 1; 
    }
    int er = std::system(".\\code02 < input.txt > output2.txt");
    if (er != 0) {
        std::cerr << "Execution failed\n";
        return 1; 
    }

    return 0;
}
