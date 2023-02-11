#include <iostream>
using namespace std;

void housing(int plot[], int n, int k) {
    int pointer1 = 0;
    int pointer2 = 1;

    int sum = plot[pointer1] + plot[pointer2];
    while (pointer1 <= pointer2) {
        if (sum == k) {
            cout << pointer1 << " " << pointer2 << endl;
            sum -= plot[pointer1];
            pointer1++;
        }
        else if (sum < k) {
            pointer2++;
            sum += plot[pointer2];
        }
        else {
            sum -= plot[pointer1];
            pointer1++;
        }
    }
}

int main(void) {
    int plot[] = {1,3,2,1,4,1,3,2,1,1};
    int n = sizeof(plot) / sizeof(int);
    int k = 8;

    housing(plot, n, k);

    return 0;
}