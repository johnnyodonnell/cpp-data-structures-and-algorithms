#include <iostream>
#include <vector>

/*
 * O(n) solution to the longest palindrome substring problem
 *
 * https://en.wikipedia.org/wiki/Longest_palindromic_substring
 * https://leetcode.com/problems/longest-palindromic-substring
 *
 *
 */

using namespace std;

int max_index(const vector<int>& vec) {
    int index = 0;
    int max = vec.at(index);

    for (int i = 1; i < vec.size(); ++i) {
        if (vec.at(i) > max) {
            index = i;
            max = vec.at(index);
        }
    }

    return index;
}

string add_barriers(const string& str) {
    string result {'$'};

    for (int i = 0; i < str.size(); ++i) {
        result.push_back(str[i]);
        result.push_back('$');
    }

    return result;
}

string manachers(const string& str) {
    if (str.empty()) {
        return {str};
    }

    string str_p = add_barriers(str);
    vector<int> lengths(str_p.size(), 1);
    lengths[1] = 3;

    int center = 1;
    int left = 0;
    int right = 2;

    for (int i = 2; i < lengths.size(); ++i) {
        if (i <= right) {
            int mirror_i = (2 * center) - i;
            int mirror_length = lengths[mirror_i];

            if ((mirror_i - (mirror_length / 2)) > left) {
                lengths[i] = mirror_length;
                continue;
            } else {
                center = i;
                left = (2 * center) - right;
            }
        } else {
            center = i;
            left = center;
            right = center;
        }

        while (((left - 1) >= 0)
                && ((right + 1) < str_p.size())
                && (str_p[left - 1] == str_p[right + 1])) {
            --left;
            ++right;
        }

        lengths[i] = (right - left) + 1;
    }

    center = max_index(lengths);
    int length = lengths[center];

    center = (center / 2);
    length = (length / 2);

    return str.substr(center - (length / 2), length);
}

int main() {
    vector<string> test_cases {
        {"a"}, {"aa"}, {"aba"}, {"babad"}, {"bananas"}
    };

    for (auto& str : test_cases) {
        cout << "String: " << str << endl;
        cout << "String prime: " << add_barriers(str) << endl;
        cout << "Longest palindrome: " << manachers(str) << "\n" << endl;
    }
}

