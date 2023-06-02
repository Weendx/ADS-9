// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  <stdexcept>
#include  <string>
#include  "bst.h"


BST<std::string> makeTree(const char* filename) {
    std::ifstream file(filename);
    if (!file)
        throw std::runtime_error("Can't open file");
    BST<std::string> words;
    std::string word;
    while (!file.eof()) {
        int symbol = file.get();
        if (symbol >= 'A' && symbol <= 'Z') {
            symbol += 32;  // A -> a
            word += symbol;
        } else if (symbol >= 'a' && symbol <= 'z') {
            word += symbol;
        } else {
            words.add(word);
            word.clear();
        }
    }
    file.close();
    return words;
}
