#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> current_combination;

void backtrack(int start) {
    if (current_combination.size() == m) {
        for (int i = 0; i < m; i++) {
            cout << current_combination[i] << (i == m - 1 ? "" : " ");
        }
        cout << "\n";
        return;
    }

    for (int i = start; i <= n; i++) {
        current_combination.push_back(i);
        backtrack(i + 1);
        
        current_combination.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    backtrack(1);

    return 0;
}