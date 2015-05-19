import pdb
def minCut(s):
    m = len(s)
    pal = [m*[0] for i in range(0, m)]
    cut = [(i-1) for i in range(0, m+1)]
    for i in range(0, m):
        for j in range(0, i+1):
            if s[i] == s[j] and (i-j < 2 or pal[j+1][i-1] == 1):
                pal[j][i] = 1
    # defined as inclusive
    for i in range(0, m):
        for j in range(0, i+1):
            if pal[j][i] == 1:
                cut[i+1] = min(cut[j]+1, cut[i+1])

    return cut[m]
        



s = "aab"
print(minCut(s))

