#include <iostream>
#include <vector>

/*
 * This currently uses O(nlog(n)) space, when we could instead use
 * O(n) space
 *
 */

using namespace std;

void mergesort(vector<int>& vec, int start, int end) {
    if (start >= end) {
        return;
    }

    int mid = start + ((end - start) / 2);

    vector<int> left {};
    for (int i = start; i <= mid; ++i) {
        left.push_back(vec[i]);
    }

    mergesort(left, 0, left.size() - 1);
    mergesort(vec, mid + 1, end);

    int i = start;
    int left_i = 0;
    int right_i = mid + 1;
    while (i <= end) {
        if ((left_i < left.size()) && (right_i <= end)) {
            auto& left_val = left[left_i];
            auto& right_val = vec[right_i];

            if (left_val < right_val) {
                vec[i] = left[left_i];
                ++left_i;
            } else {
                vec[i] = vec[right_i];
                ++right_i;
            }
        } else if (left_i < left.size()) {
            vec[i] = left[left_i];
            ++left_i;
        } else {
            vec[i] = vec[right_i];
            ++right_i;
        }

        ++i;
    }
}

void mergesort(vector<int>& vec) {
    mergesort(vec, 0, vec.size() - 1);
}

int main() {
    vector<vector<int>> test_cases {
        {},
        {1},
        {1, 2},
        {1, 2, 3},
        {3, 2, 1},
        {1, 2, 3, 4},
        {4, 3, 2, 1},
        {6, 7, 2, 0, 10, 22},
    };

    for (auto& arr : test_cases) {
        mergesort(arr);

        for (auto elem : arr) {
            cout << elem << ", ";
        }
        cout << endl;
    }
}

