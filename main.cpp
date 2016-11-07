#include <iostream>
#include <fstream>
#include <chrono>
#include "ffe/src/StrPathFinder.h"

using namespace std;
using namespace ffe;

void printPath(vector<string> path) {
    for(const string& s : path) {
        cout << s << endl;
    }
}

int main(int argc, char** argv) {
    if (argc != 3) {
        cerr << "Invalid number of arguments. Usage: `ffe_run START_AND_END_WORDS_PATH  DICTIONARY_PATH`\n" <<
                "Files must be in plain text with utf8 encoding, words separated by new line chars";
        return 1;
    }
    ifstream file(argv[1]);
    std::string from, to;
    std::getline(file, from);
    std::getline(file, to);

    StrPathFinder pathFinder(argv[2]);
    printPath(pathFinder.findPath(from, to));

    return 0;
}
