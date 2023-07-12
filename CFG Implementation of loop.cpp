#include <iostream>
#include <string>
#include <cctype>

struct Assignment {
    std::string statement;
};

struct Expression {
    std::string identifier;
    int number;
};

bool parseAssignment(const std::string& str, Assignment& assignment) {
    assignment.statement = str;
    return true; // No validation is performed in this example
}

bool parseExpression(const std::string& str, Expression& expression) {
    std::string::const_iterator it = str.begin();
    std::string identifier;

    // Parse the identifier
    while (it != str.end() && std::isalpha(*it)) {
        identifier.push_back(*it);
        ++it;
    }
    if (identifier.empty()) {
        return false;
    }
    expression.identifier = identifier;

    // Check for the less than sign
    if (it == str.end() || *it != '<') {
        return false;
    }
    ++it;

    // Parse the number
    int number = 0;
    while (it != str.end() && std::isdigit(*it)) {
        number = number * 10 + (*it - '0');
        ++it;
    }
    if (it != str.end()) {
        return false;
    }
    expression.number = number;

    return true;
}




int main() {
    std::string input;

    // Prompt for input
    std::cout << "Enter a for loop statement: ";
    std::getline(std::cin, input);

    // Parsing
    std::string::size_type pos = input.find("for");
    if (pos == std::string::npos) {
        std::cout << "Invalid for loop statement!" << std::endl;
        return 0;
    }
    pos += 3; // Skip "for"

    // Skip whitespaces
    while (pos < input.length() && std::isspace(input[pos])) {
        ++pos;
    }

    // Check for the opening parenthesis
    if (pos == input.length() || input[pos] != '(') {
        std::cout << "Invalid for loop statement!" << std::endl;
        return 0;
    }
    ++pos;

    // Skip whitespaces
    while (pos < input.length() && std::isspace(input[pos])) {
        ++pos;
    }

    // Parse the assignment
    Assignment assignment;
    std::string assignmentStr;
    while (pos < input.length() && input[pos] != ';') {
        assignmentStr.push_back(input[pos]);
        ++pos;
    }
    if (!parseAssignment(assignmentStr, assignment)) {
        std::cout << "Invalid assignment!" << std::endl;
        return 0;
    }

    // Skip the semicolon
    ++pos;

    // Skip whitespaces
    while (pos < input.length() && std::isspace(input[pos])) {
        ++pos;
    }

    // Parse the expression
    Expression expression;
    std::string expressionStr;
    while (pos < input.length() && input[pos] != ';') {
        expressionStr.push_back(input[pos]);
        ++pos;
    }
    if (!parseExpression(expressionStr, expression)) {
        std::cout << "Invalid expression!" << std::endl;
        return 0;
    }

    // Skip the semicolon
    ++pos;

    // Skip whitespaces
    while (pos < input.length() && std::isspace(input[pos])) {
        ++pos;
    }

    // Parse the increment
    Assignment increment;
    std::string incrementStr;
    while (pos < input.length() && input[pos] != ')') {
        incrementStr.push_back(input[pos]);
        ++pos;
    }
    if (!parseAssignment(incrementStr, increment)) {
        std::cout << "Invalid increment!" << std::endl;
        return 0;
    }

    // Skip the closing parenthesis
    ++pos;

    // Skip whitespaces
    while (pos < input.length() && std::isspace(input[pos])) {
        ++pos;
    }

    // Check for theopening brace
if (pos == input.length() || input[pos] != '{') {
std::cout << "Invalid for loop statement!" << std::endl;
return 0;
}
++pos;
// Skip whitespaces
while (pos < input.length() && std::isspace(input[pos])) {
    ++pos;
}

// Parse the statement
std::string statementStr;
while (pos < input.length() && input[pos] != '}') {
    statementStr.push_back(input[pos]);
    ++pos;
}

// Check for the closing brace
if (pos == input.length() || input[pos] != '}') {
    std::cout << "Invalid for loop statement!" << std::endl;
    return 0;
}

// Output the parsed elements
std::cout << "Initialization: " << assignment.statement << std::endl;
std::cout << "Expression: " << expression.identifier << " < " << expression.number << std::endl;
std::cout << "Increment: " << increment.statement << std::endl;
std::cout << "Statement: " << statementStr << std::endl;

return 0;
}

