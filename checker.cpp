#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <windows.h>
#include <string>

using namespace std;

int main() {
    int il, ol,v;
    il = 2, ol = 1;
    ifstream expected_output("output2.txt"); // Replace with the actual expected output file
    ifstream your_output("output1.txt"); // Replace with the actual output file

    vector<string> expected, your;
    string line;

    while (getline(expected_output, line))
        expected.push_back(line);

    while (getline(your_output, line))
        your.push_back(line);

    if (expected.size() != your.size()) {
        cout << "Output mismatch: Different number of lines." << endl;
        return 0;
    }

    for (int i = 0; i < expected.size(); i++) {
        if (expected[i] != your[i]) {
            cout<<endl;
            cout << "Output mismatch at testcase " << (i + ol)/ol << ": " << endl;
            {
                freopen("input.txt","r",stdin);
                string sline;
                getline(cin,sline);
                v = (i+ol)/ol;
                for(int j=1; j<v; j++){
                    for(int l=0; l<il; l++) {getline(cin,sline);}
                }
                {   
                    cout<<"Input: "<<endl;
                    for(int l=0; l<il; l++){
                        getline(cin,sline);
                        cout<<sline<<endl;
                    }
                }
            }
            cout << "Expected: "<<endl;
            for(int j=0; j<ol; j++) cout<<expected[(v-1)*ol+j] << endl;
            cout << "Your output: "<<endl;
            for(int j=0; j<ol; j++) cout<<your[(v-1)*ol+j] << endl;
            GenerateConsoleCtrlEvent(CTRL_C_EVENT, 0);
            return 0;
        }
    }

    cout << "Output matches!" << endl;
    return 0;
}
