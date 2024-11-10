#include <algorithm>
#include <iostream>
#include <sstream> 
#include <fstream>
#include <string>
#include <cctype>
#include <map>


int main() {
    std::string file_name;
    std::cin >> file_name;

    std::ifstream file(file_name);

    if (!file.is_open()) {
        std::cout << "Fatal error: unable to open the file" << std::endl;
        exit(1);
    }
    
    std::map<std::string, int> word_bunker;
    std::string line;

    while (std::getline(file, line)) {
        // Replace hyphens with spaces to split compound words
        std::replace(line.begin(), line.end(), '-', ' ');

        std::istringstream stream(line);
        std::string word;

        while (stream >> word) {
            // Remove punctuation from each word
            word.erase(std::remove_if(word.begin(), word.end(),
                [](unsigned char ch) { return std::ispunct(ch); }),
                word.end());

            // Transform to lowercase
            std::transform(word.begin(), word.end(), word.begin(),
                [](unsigned char ch) { return std::tolower(ch); });

            // Increment the count of the word
                word_bunker[word]++;
        }
    }

    file.close();

    for (const auto& it : word_bunker) {
        std::cout << it.first << " " << it.second << std::endl;
    }

    return 0;
}