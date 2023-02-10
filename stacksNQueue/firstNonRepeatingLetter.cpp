#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    queue<char> q;
    int map[27] = {0};

    char ch;
    do {
        cin >> ch;
        map[ch - 'a']++;

        q.push(ch);
        while ( !q.empty() && (map[q.front() - 'a'] > 1) ) {
            q.pop();
        }

        if (q.empty()) cout << -1 << endl;
        else cout << q.front() << endl;

    } while (ch != '.');


    return 0;
}