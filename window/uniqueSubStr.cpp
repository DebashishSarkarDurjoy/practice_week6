#include <iostream>
#include <unordered_map>
using namespace std;

string uniqueSubStr(string msg) {
    int i = 0;
    int j = 0;
    int window_len = 0;
    int max_window_len = INT_MIN;
    int start_idx = 0;

    unordered_map<char, int> map;
    while (i <= msg.size()) {
        char c = msg[j];

        if ( map.count(c) && (map[c] >= i) ) {
            i = map[c] + 1; 
        }

        window_len = j - i;
        if (window_len > max_window_len) {
            max_window_len = window_len;
            start_idx = i;
        }
        map[c] = j;
        j++;
    }

    return msg.substr(start_idx, max_window_len+1);
}

int main(void) {
    string msg = "Debashish";
    string msg1 = "aabcb";
    cout << uniqueSubStr(msg1) << endl;

    return 0;
}