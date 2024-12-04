//Leetcode 1368
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dist[n][m];
        deque<pair<int, int>> dq;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};  // Add missing semicolon here
        
        // Initialize distance matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dist[i][j] = 1e9;  // Assign a large number initially
            }
        }
        dist[0][0] = 0;  // Start at the top-left corner
        dq.push_front({0, 0});  // Push the starting point to the deque
        
        // BFS with deque
        while (!dq.empty()) {
            auto curr = dq.front();
            dq.pop_front();
            int x = curr.first;
            int y = curr.second;
            int dir = grid[x][y];
            
            // Explore the 4 possible directions
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                // Skip if the new position is out of bounds
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                int edgewt = 1;  // Default weight is 1 (no alignment)
                if (i + 1 == dir) edgewt = 0;  // If the movement aligns with the direction, the weight is 0
                
                // Relax the edge
                if (dist[nx][ny] > dist[x][y] + edgewt) {
                    dist[nx][ny] = dist[x][y] + edgewt;
                    if (edgewt == 0) {
                        dq.push_front({nx, ny});  // No cost, so push to the front
                    } else {
                        dq.push_back({nx, ny});  // Push to the back if cost is 1
                    }
                }
            }
        }
        return dist[n-1][m-1];  // Return the minimum cost to reach the bottom-right corner
    }
};
