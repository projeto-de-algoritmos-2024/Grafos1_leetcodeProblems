class Solution:
    def crackSafe(self, n: int, k: int) -> str:
        def dfs (res,vis,total):
            if res[-n:] in vis:return
            vis.add(res[-n:])
            if len(vis) == total:return res            
            for i in range(k):
                prox = dfs (res + str(i),vis,total)
                if prox: return prox
            vis.remove (res[-n:])
        return dfs ( '0' * n, set(), k ** n)