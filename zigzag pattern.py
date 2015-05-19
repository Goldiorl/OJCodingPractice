class Solution:
    # @param {string} s
    # @param {integer} numRows
    # @return {string}
    def convert(self, s, numRows):
        if s == "":
            return ""
        if numRows == 1:
            return s
        n = numRows*2 - 2
        num_list = list(range(n))
        queue = []
        queue.append(num_list.pop(0))
        while len(num_list) != 1:
            queue.append(num_list.pop(0))
            num_list.pop(-1)
        queue.append(num_list[0])

        res = [] * n
        dict = {}
        for i, char in enumerate(s):
            dict.update({i:char})

        quotient = len(s)//n
        for remainder in queue:
            for i in range(0, quotient+1):
                if i*n + remainder < len(s):
                    res.append(dict[i * n + remainder ]) # keyword is lifted by one
                if remainder == 0 or remainder == num_list[0]:
                    continue
                if (i*n + (n-remainder)<len(s)):
                    res.append(dict[i * n + n-remainder ]) # keyword is lifted by one
        return "".join(res)



sol = Solution()
print(sol.convert("PAYPALISHIRING", 3))
