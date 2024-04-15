class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        x = set()
        y= defaultdict(list)

        for a,b in connections:
            y[a].append(b)
            y[b].append(a)
            x.add ((a , b,))
        n = deque ([0])
        vis = set([0])
        r = 0