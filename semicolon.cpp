// Input from online - Semicolon Check 


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
    bool allCorrect = true; // সব ঠিক আছে কিনা চেক করার জন্য

    while (getline(ss, line)) {
        lineNumber++;
        // লাইন শেষের white space মুছে দাও
        while(!line.empty() && isspace(line.back())) line.pop_back();

        // যদি লাইন খালি না হয় এবং শেষ character semicolon না হয়
        if (!line.empty() && line.back() != ';' && line.find('{') == string::npos && line.find('}') == string::npos) {
            cout << "Syntax error: Missing semicolon at line " << lineNumber << endl;
            allCorrect = false; // ভুল আছে
        }
    }

    if (allCorrect) {
        cout << "All statements are correct! No missing semicolons." << endl;
    }

    return 0;
}








// Input from local file 


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("input.cpp"); // input file
    if (!file) {
        cerr << "Cannot open file!" << endl;
        return 1;
    }

    string line;
    int lineNumber = 0;
    bool allCorrect = true;

    while (getline(file, line)) {
        lineNumber++;
        // লাইন শেষে white space মুছে দাও
        while(!line.empty() && isspace(line.back())) line.pop_back();

        // যদি লাইন খালি না হয় এবং semicolon না থাকে
        if (!line.empty() && line.back() != ';' && line.find('{') == string::npos && line.find('}') == string::npos) {
            cout << "Syntax error: Missing semicolon at line " << lineNumber << endl;
            allCorrect = false;
        }
    }

    if (allCorrect) {
        cout << "All statements are correct! No missing semicolons." << endl;
    }

    file.close();
    return 0;
}

