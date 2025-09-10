// Input From Online - Identification

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <unordered_set>

using namespace std;

// C++ keywords
unordered_set<string> keywords = {
    "int", "float", "double", "char", "void", "if", "else", "for", "while",
    "do", "switch", "case", "break", "continue", "return", "bool", "true", "false",
    "string", "class", "public", "private", "protected", "new", "delete"
};

// Check if a string is a keyword
bool isKeyword(const string &str) {
    return keywords.find(str) != keywords.end();
}

int main() {
    string code = R"(
        int main() {
            int x = 5;
            float totalSum = 20.5;
            char ch = 'A';
            if(x > 0) {
                totalSum = totalSum + x;
            }
            return 0;
        }
    )"; // এখানে কোড লিখতে পারো

    stringstream ss(code);
    char ch;
    string token;
    int identifierCount = 0;

    cout << "Identifiers found:\n";

    while (ss.get(ch)) {
        if (isspace(ch)) continue;

        if (isalpha(ch) || ch == '_') {
            token = "";
            while (isalnum(ch) || ch == '_') {
                token += ch;
                ss.get(ch);
            }
            ss.unget(); // শেষ character ফিরিয়ে দাও

            if (!isKeyword(token)) {
                cout << token << endl;
                identifierCount++;
            }
        }
    }

    cout << "\nTotal identifiers: " << identifierCount << endl;

    return 0;
}






Input from local file

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <unordered_set>

using namespace std;

// C++ keywords
unordered_set<string> keywords = {
    "int", "float", "double", "char", "void", "if", "else", "for", "while",
    "do", "switch", "case", "break", "continue", "return", "bool", "true", "false",
    "string", "class", "public", "private", "protected", "new", "delete"
};

// Check if a string is a keyword
bool isKeyword(const string &str) {
    return keywords.find(str) != keywords.end();
}

int main() {
    ifstream file("input.cpp"); // এখানে তোমার লোকাল ফাইলের নাম লিখবে
    if (!file) {
        cerr << "Cannot open file!" << endl;
        return 1;
    }

    char ch;
    string token;
    int identifierCount = 0;

    cout << "Identifiers found:\n";

    while (file.get(ch)) {
        if (isspace(ch)) continue;

        if (isalpha(ch) || ch == '_') {
            token = "";
            while (isalnum(ch) || ch == '_') {
                token += ch;
                file.get(ch);
            }
            file.unget(); // শেষ character ফিরিয়ে দাও

            if (!isKeyword(token)) {
                cout << token << endl;
                identifierCount++;
            }
        }
    }

    cout << "\nTotal identifiers: " << identifierCount << endl;

    file.close();
    return 0;
}
