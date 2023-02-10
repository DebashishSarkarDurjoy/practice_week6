#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void maxSubArray(vector<int> &numbers, int k) {
    deque<int> d(k);

    int i = 0;
    for (; i < 3; i++) {
        while ( (!d.empty()) && (numbers[d.back()] < numbers[i]) ) {
            d.pop_back();
        }
        d.push_back(i);
    }

    for (; i < numbers.size(); i++) {
        cout << d.front() << " ";
        while ( (!d.empty()) && (d.front() <= i-k) ) {
            d.pop_front();
        }
        while ( (!d.empty()) && (numbers[d.back()] < numbers[i]) ) {
            d.pop_back();
        }
        d.push_back(i);   
    }
}

int main(void) {
    vector<int> numbers = {1,2,3,1,4,5,2,3,5};
    maxSubArray(numbers, 3);

    return 0;
}