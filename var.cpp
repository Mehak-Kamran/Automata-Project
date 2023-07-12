#include <iostream>
#include <string>

bool isValidIdentifier(const std::string& str) {
    if (str.empty() || !isalpha(str[0]) && str[0] != '_')
        return false;

    for (size_t i = 1; i < str.length(); i++) {
        if (!isalnum(str[i]) && str[i] != '_')
            return false;
    }

    return true;
}

int main() {
    std::string input;

    // Prompt for input
    std::cout << "Enter a program statement: ";
    std::getline(std::cin, input);

    // Parsing
    size_t pos = 0;

    // Remove leading whitespaces
    while (pos < input.length() && isspace(input[pos]))
        pos++;

    // Check if it's a declaration
    if (input.substr(pos, 3) == "int" || input.substr(pos, 5) == "float" || input.substr(pos, 6) == "double" ||
        input.substr(pos, 4) == "char" || input.substr(pos, 4) == "bool") {

        std::string type;

        // Extract the type
        while (pos < input.length() && !isspace(input[pos])) {
            type += input[pos];
            pos++;
        }

        // Skip whitespaces after the type
        while (pos < input.length() && isspace(input[pos]))
            pos++;

        std::string identifier;

        // Extract the identifier
        while (pos < input.length() && (isalnum(input[pos]) || input[pos] == '_')) {
            identifier += input[pos];
            pos++;
        }

        // Check if the identifier is valid
        if (!isValidIdentifier(identifier)) {
            std::cout << "Invalid identifier!" << std::endl;
            return 0;
        }

        // Skip whitespaces after the identifier
        while (pos < input.length() && isspace(input[pos]))
            pos++;

        // Check for the semicolon at the end of the declaration
        if (input[pos] == ';') {
            std::cout << "Variable declaration: Type = " << type << ", Identifier = " << identifier << std::endl;
        } else {
            std::cout << "Missing semicolon!" << std::endl;
        }
    }
    // Check if it's an assignment
    else {
        std::string variable;
        std::string expression;

        // Extract the variable
        if (input[pos] == 'x' || input[pos] == 'y' || input[pos] == 'z') {
            variable += input[pos];
            pos++;
        } else {
            std::cout << "Invalid variable!" << std::endl;
            return 0;
        }

        // Skip whitespaces after the variable
        while (pos < input.length() && isspace(input[pos]))
            pos++;

        // Check for the equals sign
        if (input[pos] != '=') {
            std::cout << "Missing equals sign!" << std::endl;
            return 0;
        }

        pos++; // Skip the equals sign

        // Skip whitespaces after the equals sign
        while (pos < input.length() && isspace(input[pos]))
            pos++;

        // Extract the expression
        while (pos < input.length()) {
            expression += input[pos];
            pos++;
        }

        std::cout << "Variable assignment: Variable = " << variable << ", Expression = " << expression << std::endl;
    }

    return 0;
}
