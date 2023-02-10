#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxSubArray(vector<int> &numbers, int k) {
    vector<int> result;

    deque<int> d(k);
    int i = 0;
    for (; i < 3; i++) {
        while ( (!d.empty()) && (numbers[d.back()] < numbers[i]) ) {
            d.pop_back();
        }
        d.push_back(i);
    }

    for (; i <= numbers.size(); i++) {
        result.push_back( numbers[d.front()] );
        while ( (!d.empty()) && (d.front() <= i-k) ) {
            d.pop_front();
        }
        while ( (!d.empty()) && (numbers[d.back()] < numbers[i]) ) {
            d.pop_back();
        }
        d.push_back(i);
    }

    return result;
}

int main(void) {
    vector<int> numbers = {1,3,-1,-3,5,3,6,7};
    
    
    for (int n: maxSubArray(numbers, 3)) {
        cout << n << endl;
    }

    return 0;
}