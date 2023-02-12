#include <iostream>
#include <unordered_map>
using namespace std;

string findWindow(string s, string p) {
    unordered_map<char, int> umap_p;
    for (char c : p) {
        umap_p[c]++;
    }

    // for (auto pr: umap_s) {
    //     cout << pr.first << " " << pr.second << endl;
    // }

    int counter = 0;
    int window_len = 0;
    int min_so_far = INT_MAX;
    int start = 0;
    int start_idx = -1;
    unordered_map<char, int> umap_s;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        umap_s[c]++;

        if ( (umap_p.find(c) != umap_p.end()) && (umap_p[c] >= umap_s[c]) ) {
            counter++;
        }

        if (counter == p.length()) {
            while ( (umap_p.find(s[start]) == umap_p.end()) || (umap_s[s[start]] > umap_p[s[start]]) ) {
                umap_s[s[start]]--;
                start++;
            }

            window_len = i - start + 1;

            if (min_so_far > window_len) {
                min_so_far = window_len;
                start_idx = start;
            }
        }
    }

    if (start_idx == -1) return "no window found";
    else return s.substr(start_idx, min_so_far);
}

int main(void) {
    string s, p;
    cin >> s >> p;

    cout << findWindow(s, p) << endl;

    return 0;
}
