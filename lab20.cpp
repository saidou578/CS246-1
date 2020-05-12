#include <iostream>
#include <vector>
#include <map>

using namespace std;

int DuplicatesSum(vector<int>& data) {
    map<int, int> counts;
    for (int i = 0; i < data.size(); ++i) {
        if (counts.find(data[i]) == counts.end()) {
            counts[data[i]] = 0;
        }
        counts[data[i]]++;
    }
    int sum = 0;
    for (map<int, int>::iterator it = counts.begin(); it != counts.end(); it++) {
        if (it->second > 1) {
            sum += it->first;
        }
    }
    return sum;
}

int main() {
    vector<int> v = {1, 2, 2, 3, 2, 4, 1};
    cout << DuplicatesSum(v) << endl;
    return 0;
}