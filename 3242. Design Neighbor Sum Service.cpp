class neighborSum {
private:
    vector<vector<int>> grid;
    int n;

    pair<int, int> reqdpos(int value) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == value) {
                    return {i, j};
                }
            }
        }
        return {0,0};
    }

    bool validitycheck(int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < n;
    }

public:
    neighborSum(const vector<vector<int>>& grid) : grid(grid), n(grid.size()) {}

    //for adjacent sum
    int adjacentSum(int value) {

        pair<int, int> pos = reqdpos(value);
        int ans = 0;
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}}; 

        for (auto d : dir) {
            int nr = pos.first + d.first;
            int nc = pos.second + d.second;
            if (validitycheck(nr, nc)) {
                ans += grid[nr][nc];
            }
        }
        return ans;
    }
    //for diagonal sum
    int diagonalSum(int value) {
        pair<int, int> pos = reqdpos(value);
        vector<pair<int, int>> dir = {{-1, 1}, {-1, -1}, {1, -1}, {1, 1}}; 
        int ans = 0;

        for (auto d : dir) {
            int nr = pos.first + d.first;
            int nc = pos.second + d.second;

            if (validitycheck(nr, nc)) {
                ans += grid[nr][nc];
            }
        }
        return ans;
    }
};
