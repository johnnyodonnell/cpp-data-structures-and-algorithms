#include <iostream>
#include <vector>

/*
 * Heap operations:
 * https://stackoverflow.com/questions/9755721/how-can-building-a-heap-be-on-time-complexity
 * Building: O(n) -- surprising, but true
 * Extracting min: O(logn)
 *
 */

using namespace std;

template <typename T>
class MinHeap {
    private:
        vector<T> vec;
        size_t length;

        void sift_down(int i) {
            if (i >= length) {
                return;
            }

            auto& curr_val = vec[i];

            auto left_i = left_child_index(i);
            auto right_i = right_child_index(i);

            if (right_i < length) {
                auto& left_val = vec[left_i];
                auto& right_val = vec[right_i];

                if ((curr_val > left_val) || (curr_val > right_val)) {
                    if (left_val <= right_val) {
                        swap(curr_val, left_val);
                        sift_down(left_i);
                    } else {
                        swap(curr_val, right_val);
                        sift_down(right_i);
                    }
                }
            } else if (left_i < length) {
                auto& left_val = vec[left_i];

                if (curr_val > left_val) {
                    swap(curr_val, left_val);
                }
            }
        }

        int left_child_index(int i) {
            return ((2 * (i + 1)) - 1);
        }

        int right_child_index(int i) {
            return (2 * (i + 1));
        }

    public:
        MinHeap(const vector<T>& c_vec) :vec{c_vec}, length{vec.size()} {
            // Takes O(n) -- surprising, but true. See SO link above
            for (int i = length - 1; i >= 0; i--) {
                sift_down(i);
            }
        }

        T& front() {
            return vec.front();
        }

        // Runs O(logn)
        void pop() {
            swap(vec[0], vec[length - 1]);
            --length;
            sift_down(0);
        }

        bool empty() {
            return length == 0;
        }
};

int main() {
    vector<vector<int>> test_cases = {
        {6, 8, 3, 2, 4, 7, 6, 1},
        {10, 25, 7, 39, 45, 22},
        {},
        {1},
    };

    for (auto& arr : test_cases) {
        MinHeap<int> min_heap {arr};

        while (!min_heap.empty()) {
            cout << min_heap.front() << ", ";
            min_heap.pop();
        }
        cout << endl;
    }
}

