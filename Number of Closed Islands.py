class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])

        def dfs(i, j):
            if i < 0 or j < 0 or i >= m or j >= n or grid[i][j] != 0:
                return
            
            grid[i][j] = 1
            for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                dfs(i + dx, j + dy)

        for i in range(0, m):
            for j in range(0, n):
                if i == 0 or j == 0 or i == m-1 or j == n-1:
                    dfs(i, j)

        count = 0
        for i in range(1, m-1):
            for j in range(1, n-1):
                if grid[i][j] == 0:
                    count += 1
                    dfs(i, j)
        return count
