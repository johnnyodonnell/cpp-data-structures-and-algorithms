#include <iostream>
#include <vector>


using namespace std;

int find_lone_int(const vector<int>& vec) {
    int start = 0;
    int end = vec.size() - 1;

    while (start < end) {
        int mid = start + ((end - start) / 2);

        if (((mid == 0) && (vec.at(mid) != vec.at(mid + 1)))
                || ((mid == vec.size() - 1)
                    && (vec.at(mid) != vec.at(mid - 1)))
                || ((vec.at(mid) != vec.at(mid - 1))
                    && (vec.at(mid) != vec.at(mid + 1)))) {
            return vec.at(mid);
        } else if (vec.at(mid) == vec.at(mid + 1)) {
            if ((mid % 2) == 0) {
                start = mid + 2;
            } else {
                end = mid - 1;
            }
        } else {
            if (((mid - 1) % 2) == 0) {
                start = mid + 1;
            } else {
                end = mid - 2;
            }
        }
    }

    return vec.at(start);
}

int main() {
    vector<vector<int>> test_cases {
        {1},
        {1, 1, 2},
        {1, 1, 2, 2, 3},
        {4, 5, 5, 6, 6},
    };

    for (auto& test_case : test_cases) {
        cout << find_lone_int(test_case) << endl;
    }
}

