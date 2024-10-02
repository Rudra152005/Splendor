// Answer
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // If the array is empty, return an empty array
        if (arr.empty()) return {};

        // Create a sorted copy of arr and remove duplicates
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        sortedArr.erase(unique(sortedArr.begin(), sortedArr.end()), sortedArr.end());

        // Create a map to store the rank of each element
        unordered_map<int, int> rankMap;
        for (int i = 0; i < sortedArr.size(); ++i) {
            rankMap[sortedArr[i]] = i + 1;  // Rank starts from 1
        }

        // Replace each element in the original array with its rank
        vector<int> result;
        for (int num : arr) {
            result.push_back(rankMap[num]);
        }

        return result;
    }
};

int main() {
    Solution solution;
    
    // Example input
    vector<int> arr = {37, 12, 28, 9, 100, 56, 80, 5, 12};

    // Call the function
    vector<int> result = solution.arrayRankTransform(arr);

    // Output the result
    for (int rank : result) {
        cout << rank << " ";
    }
    cout << endl;

    return 0;
}
