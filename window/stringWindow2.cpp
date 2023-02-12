#include <iostream>
#include <unordered_map>

using namespace std;

string find_window(string s, string p) {
    unordered_map<char, int> umap_s;
    unordered_map<char, int> umap_p;

    for (char c: p) {
        umap_p[c]++;
    }

    int min_window_len = INT_MAX;
    int window_len = 0;
    int start_idx = -1;
    int start = 0;
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        umap_s[c]++;

        if ( (umap_p.find(c) != umap_p.end()) && (umap_p[c] >= umap_s[c]) ) {
            count++;
        }

        if (count == p.size()) {
            while ( (umap_p.find(s[start]) == umap_p.end()) || (umap_p[s[start]] < umap_s[s[start]]) ) {
                umap_s[s[start]]--;
                start++;
            }

            window_len = i - start + 1;
            if (window_len < min_window_len) {
                min_window_len = window_len;
                start_idx = start;
            }
        }
    }

    if (start_idx == -1) return "No window found";
    else return s.substr(start_idx, min_window_len);
}

int main(void) {
    string s, p;
    s = "Hello_World";
    p = "lol";
    cout << find_window(s, p) << endl;

    return 0;
}