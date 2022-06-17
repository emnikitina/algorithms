#include <iostream>
#include <string>
#include <vector>


void find_next_min(const std::vector<int>& sequence, int *mins, size_t n) {    
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = i + 1; j < n; j++) {
            if (mins[i] == -1 || sequence[j] < mins[i])
                mins[i] = sequence[j];
        }
    }    
}

int main() {
    std::string newline;
    std::vector<int> sequence;
    size_t n;

    std::cout << "input sequense size:\n";
    std::getline(std::cin, newline);
    n = atoi(newline.c_str());
    std::cout << "input sequence:\n";
    std::getline(std::cin, newline);    
    char *token = std::strtok(const_cast<char*>(newline.c_str()), " ");
    while (token) {
        sequence.push_back(atoi(token));
        token = std::strtok(nullptr, " ");
    }
    if (n != sequence.size()) {
        std::cerr << "input size and size of sequence are different\n";
        exit(1);
    }

    int mins[n];
    for (size_t i = 0; i < n; i++)
        mins[i] = -1;
    find_next_min(sequence, mins, n);
    for (size_t i = 0; i < n; i++) {
        std::cout << mins[i];
        if (i != n - 1)
            std::cout << " ";
        else
            std::cout << "\n";
    }
    return 0;
}