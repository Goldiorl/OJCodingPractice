import pdb
import copy
class Solution:
   # @return a string
   def longestPalindrome(self, s):
       if not s:
           return
       max, start = 1, 0
       for i in range(len(s)):
           if i - max - 1 >=0 and s[i-max-1:i+1]==s[i-max-1:i+1][::-1]:
               start = i-max-1
               max = max+2
               continue
           if i- max>=0 and s[i-max:i+1]==s[i-max:i+1][::-1]:
               start = i - max
               max = max + 1
       return s[start:start+max]

a = []
b = [2, 3]
sol = Solution()
print(sol.findMedianSortedArrays(a,b))
