#include <iostream>
#include "ffe/src/StrPathFinder.h"

using namespace std;

int main() {
    string s ("abc");
    s.replace(0, 1, "r");
    const char* c = &s.at(2);

    cout << strcmp("n", c) << endl;
    return 0;
}
