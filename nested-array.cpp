#include <iostream>
#include <vector>
#include <stack>


using namespace std;

class IntOrList {
    private:
        int i;
        vector<IntOrList> v_list;
        bool is_int = false;

        class Iterator {
            private:
                const IntOrList& val;
                bool done = false;

                stack<pair<IntOrList, int>> list_stack {};

            public:
                Iterator() :val(0) {
                    done = true;
                }

                Iterator(const IntOrList& c_val) :val{c_val} {
                    if (!val.is_int) {
                        list_stack.push({val, 0});
                    }
                }

                int operator*() {
                    if (val.is_int) {
                        return val.i;
                    } else {
                        auto& curr_list_pr = list_stack.top();
                        auto& curr_list = curr_list_pr.first;
                        auto& curr_list_i = curr_list_pr.second;

                        auto& int_or_list = curr_list.v_list.at(curr_list_i);

                        if (int_or_list.is_int) {
                            return int_or_list.i;
                        } else {
                            ++curr_list_i;
                            list_stack.push({int_or_list, 0});
                            return operator*();
                        }
                    }
                }

                int operator++() {
                    if (val.is_int) {
                        done = true;
                    } else if (list_stack.empty()) {
                        done = true;
                    } else {
                        auto& curr_list_pr = list_stack.top();
                        auto& curr_list = curr_list_pr.first;
                        auto& curr_list_i = curr_list_pr.second;

                        ++curr_list_i;

                        while (curr_list_i >= curr_list.v_list.size()) {
                            list_stack.pop();

                            if (list_stack.empty()) {
                                done = true;
                                break;
                            } else {
                                curr_list_pr = list_stack.top();
                                curr_list = curr_list_pr.first;
                                curr_list_i = curr_list_pr.second;
                            }
                        }
                    }
                }

                bool operator!=(const Iterator& o) {
                    return done != o.done;
                }
        };

    public:
        IntOrList(int c_i) :i{c_i} {
            is_int = true;
        }

        IntOrList(const initializer_list<IntOrList>& i_list) :v_list(i_list) {}

        Iterator begin() {
            return Iterator{*this};
        }

        Iterator end() {
            return Iterator{};
        }
};

int main() {
    vector<IntOrList> test_cases {
            1,
            {1, 2, 3},
            {1, 2, {3, 4}, 5, {6, {7, {8}}, 9}, 10}
    };

    for (auto& nested : test_cases) {
        for (auto i : nested) {
            cout << i << ", ";
        }
        cout << endl;
    }
}

