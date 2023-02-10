#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

string simplify(string path) {
    // filter path
    vector<string> tokens;
    istringstream iss(path);
    string token;
    while (getline(iss, token, '/')) {
        if ( (token == ".") || (token == "") ) {
            continue;
        }
        tokens.push_back(token);
    }

    // for (string token: tokens) cout << token << endl;

    vector<string> stack;
    if (path[0] == '/') stack.push_back("");

    for (string token: tokens) {
        if (token == "..") {
            if ( (stack.size() == 0) || (stack[stack.size()-1] == "..") ) {
                stack.push_back("..");
            }
            else if (stack[stack.size()-1] != "") {
                stack.pop_back();
            } 
        }
        else stack.push_back(token);
    }

    if (stack.size() < 2) return "/";

    ostringstream oss;
    int i = 0;
    for (string token: stack) {
        if (i != 0) oss << "/";
        i++;
        oss << token;
    }
    return oss.str();
}

int main(void) {
    string path = "/../x/y/../z/././w/a///../../c/./";
    cout << simplify(path) << endl;

    return 0;
}