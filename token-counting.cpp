// Input from local file 
// Token Counting 

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <unordered_set>

using namespace std;

// Set of C++ keywords
unordered_set<string> keywords = {
    "int", "float", "double", "char", "void", "if", "else", "for", "while",
    "do", "switch", "case", "break", "continue", "return", "bool", "true", "false",
    "string", "class", "public", "private", "protected", "new", "delete"
};

// Function to check if a string is a keyword
bool isKeyword(const string &str) {
    return keywords.find(str) != keywords.end();
}

// Function to check if a character is an operator
bool isOperator(char ch) {
    string operators = "+-*/=%<>!&|^";
    return operators.find(ch) != string::npos;
}

// Function to check if a character is a delimiter
bool isDelimiter(char ch) {
    string delimiters = "();{},[]";
    return delimiters.find(ch) != string::npos;
}

int main() {
    ifstream file("input.cpp"); // Input file
    if (!file) {
        cerr << "Cannot open file.\n";
        return 1;
    }

    string token;
    char ch;

    int keywordCount = 0, identifierCount = 0, numberCount = 0, operatorCount = 0, delimiterCount = 0;

    while (file.get(ch)) {
        if (isspace(ch)) continue;

        if (isalpha(ch) || ch == '_') {
            // Parse identifiers or keywords
            token = "";
            while (isalnum(ch) || ch == '_') {
                token += ch;
                file.get(ch);
            }
            file.unget(); // Put back the last read character
            if (isKeyword(token)) keywordCount++;
            else identifierCount++;
        }
        else if (isdigit(ch)) {
            // Parse numbers
            token = "";
            while (isdigit(ch) || ch == '.') {
                token += ch;
                file.get(ch);
            }
            file.unget();
            numberCount++;
        }
        else if (isOperator(ch)) {
            operatorCount++;
        }
        else if (isDelimiter(ch)) {
            delimiterCount++;
        }
    }

    cout << "Keyword count: " << keywordCount << endl;
    cout << "Identifier count: " << identifierCount << endl;
    cout << "Number count: " << numberCount << endl;
    cout << "Operator count: " << operatorCount << endl;
    cout << "Delimiter count: " << delimiterCount << endl;

    file.close();
    return 0;
}







// Input from Online 

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

// Check if string is keyword
bool isKeyword(const string &str) {
    return keywords.find(str) != keywords.end();
}

// Check if character is operator
bool isOperator(char ch) {
    string ops = "+-*/=%<>!&|^";
    return ops.find(ch) != string::npos;
}

// Check if character is delimiter
bool isDelimiter(char ch) {
    string delims = "();{},[]";
    return delims.find(ch) != string::npos;
}

int main() {
    string code = R"( 
        int main() {
            int x = 5;
            float y = 3.14;
            if(x > 0) {
                x = x + 1;
            }
            return 0;
        }
    )"; // এখানে কোড লিখতে পারো

    stringstream ss(code);
    char ch;
    string token;

    int keywordCount = 0, identifierCount = 0, numberCount = 0, operatorCount = 0, delimiterCount = 0;

    while (ss.get(ch)) {
        if (isspace(ch)) continue;

        if (isalpha(ch) || ch == '_') {
            token = "";
            while (isalnum(ch) || ch == '_') {
                token += ch;
                ss.get(ch);
            }
            ss.unget();
            if (isKeyword(token)) keywordCount++;
            else identifierCount++;
        }
        else if (isdigit(ch)) {
            token = "";
            while (isdigit(ch) || ch == '.') {
                token += ch;
                ss.get(ch);
            }
            ss.unget();
            numberCount++;
        }
        else if (isOperator(ch)) {
            operatorCount++;
        }
        else if (isDelimiter(ch)) {
            delimiterCount++;
        }
    }

    cout << "Keyword count: " << keywordCount << endl;
    cout << "Identifier count: " << identifierCount << endl;
    cout << "Number count: " << numberCount << endl;
    cout << "Operator count: " << operatorCount << endl;
    cout << "Delimiter count: " << delimiterCount << endl;

    return 0;
}
