#include <iostream>
#include <string>
#include <algorithm>

int check_line(std::string line) {
    size_t pos;
    int res = -1;
    char brackets[6] = {'(', ')', '{', '}', '[', ']'};

    for (size_t i = 0; i < line.size(); i++) {
        if (line[i] == ')' || line[i] == '}' || line[i] == ']')
            return i;
        
        for (int j = 0; j < 6; j += 2) {
            if (line[i] == brackets[j]) {
                pos = line.find_first_of(brackets[j + 1]);
                if (pos == std::string::npos)
                    return i;
                else {
                    res = check_line(line.substr(i + 1, pos - i - 1));
                    if (res != -1)
                        return (i + res);
                    i = pos;
                }
            }
        }
    }
    return -1;
}

int main()
{
    std::string newline;
    int res = -1;

    std::cout << "input string(s):\n";
    std::getline(std::cin, newline);
    res = check_line(newline.c_str());
    while (newline != "") {
        res = check_line(newline.c_str());
        if (res == -1)
            std::cout << "String is right\n";
        else
            std::cout << res + 1 << std::endl;
        std::getline(std::cin, newline);
    }
    return 0;
}