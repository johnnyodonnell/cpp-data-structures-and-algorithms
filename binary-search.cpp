#include <iostream>
#include <vector>


using namespace std;

template <typename T>
int binary_search(const vector<T>& vec, const T& val) {
    int start = 0;
    int end = vec.size();

    while (start < end) {
        int mid = start + (end - start) / 2;

        if (vec[mid] == val) {
            return mid;
        } else if (vec[mid] < val) {
            start = mid;
        } else {
            end = mid;
        }
    }

    return -1;
}

int main() {
    vector<vector<int>> test_cases {
        {1, 2, 2, 3, 6, 7, 8, 8, 8, 10},
        {1, 2, 2, 3, 6, 7, 8, 8, 10},
    };

    for (auto& arr : test_cases) {
        cout << binary_search(arr, -20) << endl;
    }
    cout << endl;

    for (auto& arr : test_cases) {
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << ", ";
        }
        cout << endl;

        for (int i = 0; i < arr.size(); i++) {
            cout << arr[binary_search(arr, arr[i])] << ", ";
        }
        cout << endl;
        cout << endl;
    }
}

