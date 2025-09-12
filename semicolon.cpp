//Semicolon Check 
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string code = R"(
        int x = 5
        float y = 3.14;
        x = x + 1;
        y = y + 2;
    )";

    stringstream ss(code);
    string line;
    int lineNumber = 0;
    bool allCorrect = true;

    while (getline(ss, line)) {
        lineNumber++;
        
        while(!line.empty() && isspace(line.back())) line.pop_back();

        if (!line.empty() && line.back() != ';' && line.find('{') == string::npos && line.find('}') == string::npos) {
            cout << "Syntax error: Missing semicolon at line " << lineNumber << endl;
            allCorrect = false;
        }
    }

    if (allCorrect) {
        cout << "All statements are correct! No missing semicolons." << endl;
    }

    return 0;
}

