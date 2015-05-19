import pdb
import copy
    # @param start, a string
    # @param end, a string
    # @param dict, a set of string
    # @return a list of lists of string


def lengthOfLongestSubstring(s):
    dict, cur_max, p1, p2 = {}, 0, 0, 0
    while p2 < len(s):
        prev_pos = dict.get(s[p2], None)
        if prev_pos != None:
            while p1 <= prev_pos:
                dict.pop(s[p1])
                p1 += 1
        else:
            dict[s[p2]] = p2
            cur_max = max(cur_max, p2-p1+1)
            p2 += 1
    return cur_max

s = "eee"
print(lengthOfLongestSubstring(s))