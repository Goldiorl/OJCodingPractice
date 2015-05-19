import pdb
def partition(s):
    m = len(s)
    pal = [m*[0] for i in range(0, m)]
    for i in range(0, m):
        for j in range(0, i+1):
            if s[i] == s[j] and (i-j < 2 or pal[j+1][i-1] == 1):
                pal[j][i] = 1
    palindrom_till_i = [[] for i in range(0, m)]
    # defined as inclusive
    for i in range(0, m):
        for j in range(0, i+1):
            if pal[j][i] == 1:
                sub_palindrom = s[j:i+1]
                if j == 0:
                    palindrom_till_i[i].append([sub_palindrom])
                    #pdb.set_trace()
                else:
                    for palinList in palindrom_till_i[j-1]:
                        import copy
                        palinList_toAdd = copy.copy(palinList)
                        palinList_toAdd.append(sub_palindrom)
                        palindrom_till_i[i].append(palinList_toAdd)
                        #print('value')
                        #pdb.set_trace()

    return palindrom_till_i[m-1]
        



s = "aaa"
print(partition(s))

