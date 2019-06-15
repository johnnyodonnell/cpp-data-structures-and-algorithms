#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>


using namespace std;

unordered_map<string, int> cache {};

int hex_to_num(char c) {
    if ((c >= '0') && (c <= '9')) {
        return c - '0';
    } else {
        return 10 + (c - 'a');
    }
}

bool is_perfect_square(const string& s, int start, int end) {
    int num = 0;
    for (int i = start; i <= end; ++i) {
        num = (16 * num) + hex_to_num(s.at(i));
    }
    int root = sqrt(num);
    return ((root * root) == num);
}

int get_min(const string& s, int start, int end) {
    string key = to_string(start) + "," + to_string(end);

    if (cache.count(key) > 0) {
        return cache[key];
    }

    if (is_perfect_square(s, start, end)) {
        cache[key] = 1;
        return 1;
    }

    int result = -1;
    for (int i = 1; i <= (end - start); ++i) {
        int left = get_min(s, start, start + (i - 1));
        if (left < 0) {
            continue;
        }

        int right = get_min(s, start + i, end);
        if (right < 0) {
            continue;
        }

        if (result < 0) {
            result = left + right;
        } else if ((left + right) < result) {
            result = left + right;
        }
    }

    cache[key] = result;
    return result;
}

int get_min(string s) {
    cache = {};
    return get_min(s, 0, s.size() - 1);
}

int main() {
    vector<string> test_cases {
        "a919",
        "1a919",
        "00002",
        "0000000000002",
        "0000000000002",
        "2400",
        "124001",
    };

    for (auto& str : test_cases) {
        cout << str << endl;
        cout << get_min(str) << endl;
        cout << endl;
    }
}

