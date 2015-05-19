import pdb
    # @param beginWord, a string
    # @param endWord, a string
    # @param wordDict, a set<string>
    # @return an integer
def ladderLength(beginWord, endWord, wordDict):
    visited = set([beginWord])
    queue = [beginWord, "#"]
    level, found = 1, False
    while len(queue) != 0 and (not found):
        word = queue.pop(0)
        if word == "#":
            level += 1
            if len(queue) > 0: #BUG1: endless loop for single #
                queue.append("#")
            continue
        word_length = len(word)
        for i in range(0, 27):
            char = chr(ord('a') + i)
            for j in range(0, word_length):
                newword = word[:j] + char + word[j+1:]
                if newword == endWord:
                    found = True
                    break
                if newword not in visited and newword in wordDict:
                    visited.add(newword)
                    queue.append(newword)
            if found: break
    if found: return level+1
    return 0



word_dict = ["hot","dog"]
start = "hot"
end = "dog"

# word_dict = ["hot","dot","dog","lot","log"]
# start = "hit"
# end = "cog"
print(ladderLength(start, end, word_dict))
