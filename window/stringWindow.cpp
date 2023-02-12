#include <iostream>
#include <unordered_map>

using namespace std;

string find_window(string s, string p) {
    unordered_map<char, int> FS;
    unordered_map<char, int> FP;

    for (char c: p) {
        FP[c]++;
    }

    // cout << "FP\n" << endl;
    // for (auto temp: FP) {
    //     cout << temp.first << " " << temp.second << endl;
    // }
    
    int start_idx = -1;
    int min_window_len = INT_MAX;
    int start = 0;
    int window_len = 0;
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        FS[c]++;

        if ( (FP.find(c) != FP.end()) && (FP[c] > FS[c]) ) {
            count++;
        }

        if (count == p.size()) {
            while ( (FP.find(s[start]) == FP.end()) || (FP[s[start]] < FS[s[start]]) ) {
                FS[s[start]]--;
                start++;
                cout << start << "__" << endl;
            }
        }

        window_len = i - start + 1;
        if (window_len < min_window_len) {
            min_window_len = window_len;
            start_idx = start;
            // cout << start_idx << "__" << endl;
        }
    }

    cout << start_idx << " " << min_window_len << endl;
    return s.substr(start_idx, min_window_len);
    // return "";
}

int main(void) {
    string s, p;
    

    cout << find_window("Hello_world", "lol") << endl;

    return 0;
}