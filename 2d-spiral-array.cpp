#include <iostream>
#include <vector>


using namespace std;

vector<vector<int>> gen_2d_spiral_matrix(int n) {
    vector<vector<int>> result(n, vector<int>(n, 0));

    if (n == 0) {
        return {};
    }

    int row_min = 0;
    int row_max = n - 1;

    int col_min = 0;
    int col_max = n - 1;

    int direction = 0;

    int i = 1;
    int r = 0;
    int c = 0;

    do {
        result.at(r).at(c) = i++;

        switch (direction % 4) {
            case 0:
                ++c;
                break;
            case 1:
                ++r;
                break;
            case 2:
                --c;
                break;
            default:
                --r;
        }

        if (c > col_max) {
            --c;
            ++r;
            ++direction;
            ++row_min;
        } else if (r > row_max) {
            --r;
            --c;
            ++direction;
            --col_max;
        } else if (c < col_min) {
            ++c;
            --r;
            ++direction;
            --row_max;
        } else if (r < row_min) {
            ++r;
            ++c;
            ++direction;
            ++col_min;
        }
    } while ((r <= row_max) && (r >= row_min)
            && (c <= col_max) && (c >= col_min));

    return result;
}

void print_matrix(const vector<vector<int>>& matrix) {
    for (auto& row : matrix) {
        for (auto col : row) {
            cout << col << "\t";
        }
        cout << endl;
    }
}

int main() {
    for (int i = 0; i < 10; ++i) {
        cout << "i: " << i << endl;
        print_matrix(gen_2d_spiral_matrix(i));
        cout << endl;
    }
}

