#include <iostream>
#include <vector>


using namespace std;


void quicksort(vector<int>& vec, int start, int end) {
    if (start >= end) {
        return;
    }

    auto& pivot = vec.at(end);

    auto start_i = start;
    auto end_i = end - 1;

    while (start_i <= end_i) {
        if ((vec[start_i] > pivot) && (vec[end_i] <= pivot)) {
            swap(vec[start_i], vec[end_i]);
            ++start_i;
            --end_i;
        } else if (vec[start_i] > pivot) {
            --end_i;
        } else if (vec[end_i] <= pivot) {
            ++start_i;
        } else {
            ++start_i;
            --end_i;
        }
    }

    swap(vec[start_i], pivot);
    quicksort(vec, start, start_i - 1);
    quicksort(vec, start_i + 1, end);
}

void quicksort(vector<int>& vec) {
    quicksort(vec, 0, vec.size() - 1);
}

int main() {
    vector<vector<int>> test_cases {
        {},
        {1},
        {1, 2, 3},
        {3, 2, 1},
        {1, 2, 3, 4},
        {4, 3, 2, 1},
        {6, 7, 2, 0, 10, 22},
    };

    for (auto& arr : test_cases) {
        quicksort(arr);

        for (auto elem : arr) {
            cout << elem << ", ";
        }
        cout << endl;
    }
}

