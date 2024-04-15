class Solution:
    def crackSafe(self, n: int, k: int) -> str:
        def dfs (res,vis,total):
            for i in range(k):
                prox = dfs (res + str(i),vis,total)
                if prox: return prox

        return dfs ( '0' * n, set(), k ** n)