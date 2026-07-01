class Solution:
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        n = len(grid)

        if grid[0][0] == 1 or grid[n-1][n-1] == 1:
            return 0

        dist = [[float('inf')] * n for _ in range(n)]
        queue = deque()

        for r in range(n):
            for c in range(n):
                if grid[r][c] == 1:
                    dist[r][c] = 0

                    queue.append((r, c))

        direction = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        while queue:
            r, c = queue.popleft()
            for dr, dc in direction:
                nr, nc = r + dr, c + dc
                if 0 <= nr < n and 0 <= nc < n and dist[nr][nc] == float('inf'):
                    dist[nr][nc] = dist[r][c] + 1
                    queue.append((nr, nc))

        def isValidPath(mid : int) -> bool:
            if dist[0][0] < mid:
                return False

            bfs_q = deque([(0,0)])
            visited = [[False] * n for _ in range(n)]
            visited[0][0] = True

            while bfs_q:
                r, c = bfs_q.popleft()

                if r == n-1 and c == n-1:
                    return True

                for dr, dc in direction:
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < n and 0 <= nc < n and not visited[nr][nc]:
                        if dist[nr][nc] >= mid:
                            visited[nr][nc] = True
                            bfs_q.append((nr, nc))

            return False

        low, high = 0, 2*n
        ans = 0

        while low <= high:
            mid = (low+high)//2

            if isValidPath(mid):
                ans = mid
                low = mid + 1
            else:
                high = mid - 1

        return ans
