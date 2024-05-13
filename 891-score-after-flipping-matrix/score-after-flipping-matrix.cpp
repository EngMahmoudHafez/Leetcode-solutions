class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        vector<int> col(grid[0].size(), 0);
        for (int i = 0; i < grid.size(); i++)
        {
            bool isF = false;
            if (grid[i][0] == 0)
            {
                isF = true;
            }
            
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (isF == true)
                {
                    if (grid[i][j] == 0)
                    {
                        grid[i][j] = 1;
                    }
                    else if (grid[i][j] == 1)
                    {
                        grid[i][j] = 0;
                    }
                }
                if (grid[i][j] == 0)
                {
                    col[j]++;
                }
            }
        }
        
        for (int j = grid[0].size() - 1; j >= 0; j--)
        {
            if (col[j] > grid.size() - col[j])
            {
                for (int i = 0; i < grid.size(); i++)
                {
                    if (grid[i][j] == 0)
                    {
                        grid[i][j] = 1;
                    }
                    else if (grid[i][j] == 1)
                    {
                        grid[i][j] = 0;
                    }
                }
            }
        }

        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            string curr = "";
            for (int j = 0; j < grid[0].size(); j++)
            {
                curr += (char)grid[i][j] + '0';
            }

            res += stoi(curr, 0, 2);
        }
        
        return res;
    }
};