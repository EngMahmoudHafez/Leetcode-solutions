class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        vector<vector<int>> safeness = calculateSafenessFactors(grid);
        int maxSafeness = findMaxSafeness(safeness);
        return findMaxSafenessFactor(grid, safeness, maxSafeness);
    }

private:
    vector<vector<int>> calculateSafenessFactors(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> safeness(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    safeness[i][j] = 0;
                }
            }
        }

        vector<int> dirX = {-1, 1, 0, 0};
        vector<int> dirY = {0, 0, -1, 1};

        while (!q.empty()) {
            auto cell = q.front(); q.pop();
            int x = cell.first;
            int y = cell.second;

            for (int i = 0; i < 4; i++) {
                int newX = x + dirX[i];
                int newY = y + dirY[i];

                if (newX >= 0 && newX < n && newY >= 0 && newY < n && safeness[newX][newY] > safeness[x][y] + 1) {
                    safeness[newX][newY] = safeness[x][y] + 1;
                    q.push({newX, newY});
                }
            }
        }

        return safeness;
    }

    int findMaxSafeness(vector<vector<int>>& safeness) {
        int maxSafeness = 0;
        for (auto& row : safeness) {
            for (auto val : row) {
                maxSafeness = max(maxSafeness, val);
            }
        }
        return maxSafeness;
    }

    int findMaxSafenessFactor(vector<vector<int>>& grid, vector<vector<int>>& safeness, int maxSafeness) {
        int left = 0, right = maxSafeness, result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canAchieveSafeness(grid, safeness, mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }

    bool canAchieveSafeness(vector<vector<int>>& grid, vector<vector<int>>& safeness, int threshold) {
        int n = grid.size();
        if (safeness[0][0] < threshold) return false; 

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        q.push({0, 0});
        visited[0][0] = true;

        vector<int> dirX = {-1, 1, 0, 0};
        vector<int> dirY = {0, 0, -1, 1};

        while (!q.empty()) {
            auto cell = q.front(); q.pop();
            int x = cell.first;
            int y = cell.second;

            if (x == n - 1 && y == n - 1) return true;

            for (int i = 0; i < 4; i++) {
                int newX = x + dirX[i];
                int newY = y + dirY[i];

                if (newX >= 0 && newX < n && newY >= 0 && newY < n && !visited[newX][newY] && safeness[newX][newY] >= threshold) {
                    q.push({newX, newY});
                    visited[newX][newY] = true;
                }
            }
        }

        return false;
    }
};