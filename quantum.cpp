#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
typedef long long ll;

using namespace std;

vector<vector<int>> product;

vector<vector<int>> tensor_product(vector<vector<int>>& a, vector<vector<int>>& b) {
    vector<vector<int>> result(a.size() * b.size(), vector<int>(a[0].size() * b[0].size()));

    for (int ra = 0; ra < a.size(); ra++) {
        for (int ca = 0; ca < a[0].size(); ca++) {

            for (int rb = 0; rb < b.size(); rb++) {
                for (int cb = 0; cb < b[0].size(); cb++) {
                    result[ra * b.size() + rb][ca * b[0].size() + cb] = a[ra][ca] * b[rb][cb];
                }
            }

        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // materix[row][clum]
    product.clear();
    for (int loop = 0; loop < N; loop++) {
        int r, c;
        cin >> r >> c;

        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        if (loop == 0) {
            product = matrix;
        } else {
            product = tensor_product(product, matrix);
        } 

    }

    int max = INT_MIN, min = INT_MAX;
    int max_row = INT_MIN, min_row = INT_MAX;
    int max_col = INT_MIN, min_col = INT_MAX;

    for (int i = 0; i < product.size(); i++) {
        int row_sum = 0;

        for (int j = 0; j < product[0].size(); j++) {
            int el = product[i][j];
            if (el > max) max = el;
            if (el < min) min = el;
            row_sum += el;
        }
        
        if (row_sum > max_row) max_row = row_sum;
        if (row_sum < min_row) min_row = row_sum;
    }

    for (int j = 0; j < product[0].size(); j++) {
        int col_sum = 0;

        for (int i = 0; i < product.size(); i++) {
            int el = product[i][j];
            if (el > max) max = el;
            if (el < min) min = el;
            col_sum += product[i][j];
        }
        
        if (col_sum < min_col) min_col = col_sum;
        if (col_sum > max_col) max_col = col_sum;

    }

    cout << max << "\n";
    cout << min << "\n";
    cout << max_row << "\n";
    cout << min_row << "\n";
    cout << max_col << "\n";
    cout << min_col << "\n";

}
