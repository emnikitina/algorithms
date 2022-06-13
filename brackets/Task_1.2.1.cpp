#include <iostream>
#include <string>

int find_pair(char c, std::string line) {
    int pos = line.find_first_of(')');
    if (pos == std::string::npos)
        return i;
    int res = check_line(line.substr(i + 1, pos));
    if (res != -1)
        return i;
}

int check_line(std::string line) {
    int pos = -1;

    for (int i = 0; i < line.size(); i++) {
        if (line[i] == ')' || line[i] == '}' || line[i] == ']')
            return i;
        else if (line[i] == '(')
            pos = find_pair(')', line);
        else if (line[i] == '{')
            pos = find_pair('}', line);
        else if (line[i] == '[')
            pos = find_pair(']', line);
        if (pos != -1)
            return pos;
    }
    return -1;
}

int main()
{
    std::string newline;

    std::cout << "input string:\n";
    std::getline(std::cin, newline);
    while (newline != "") {
        check_line(newline);
    }
    return 0;
}