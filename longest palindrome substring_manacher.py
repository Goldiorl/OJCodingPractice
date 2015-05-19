class Solution:
    # @param {string} s
    # @return {string}
    def longestPalindrome(self, s):
        string_list = ['^', '#']
        for char in s:
            string_list.extend([char, '#'])
        string_list.append('$')
        r, i, center = 0, 0, 0
        max_p_value, start_center = 0, 0

        length = len(string_list)
        p = [0 for i in range(0, length)]

        for i in range(1, length-1):
            i_mirror = 2*center - i
            mirror_half_length = p[i_mirror]
            if r-i > 0:
                cached_info_from_mirror = min(mirror_half_length, r-i)
                p[i] = cached_info_from_mirror
            else:
                p[i] = 0

            while string_list[i+p[i]+1] == string_list[i-p[i]-1]: # Bug 1: 因为这句话的越界，所以要加^和#，而且range也变成了1和length-1
                p[i] += 1

            if p[i] > max_p_value:
                max_p_value, start_center = p[i], i

            if i + p[i] > r:
                center = i
                r = i + p[i]

        substr = string_list[start_center-p[start_center]:start_center-p[start_center] + max_p_value*2+1]
        # for i,s in enumerate(string_list):
        #     print(s, p[i])
        return_str = "".join(substr).replace('#','')
        return return_str


sol = Solution()
print(sol.longestPalindrome("aceeebb"))



# R: 当前扫到的palindrome(就是center所在的palindrome, 也是i被包含的最大的palindrome【如果不是center所在的话，i即为center】) 的最右端
# center: 最大的palindrome,如果i更大的话，那i就是center
# 1. i 扫到的palindrom如果超过了r，就要改center了
# 2. 此时r的界也被更新成了i扫到的右边
# 3. 至于i是怎么扫的：因为其实不断地在根据滑动的index，建立p[i]， 所以扫的过程其实是借助了已经建立的p[i]，来减少重复的检查，就是被center这个东西罩着，罩着它的那个center会告诉自己信息
#  具体的方法是 min那一步算法，可以看图
# 4. R一旦等于i了， p[i] 就等于0了，因为i所在的最大的palindrom就在自己地方
# ~ p其实一直根据移动的i在逐渐建立
# 5. 如果一个i被多个回数罩，为什么会按照算法那样被R最右边的给罩住呢？是因为R最远的潜在地能罩最多，如果是被p[i]所限制，那么大家都一样，不然的R越远能提供潜在的越远的信息
#      R'   L|   i'       center       i   |R
# 也可能是
#           L| R' i'      center       i   |R
#     永远是小的那一个，因为跟被罩的作用域有关系

#      |           center     center（i）'     |R    R(new)         这一步的话需要更新center, R了， 等于的时候更不更新都无所谓
#     然后第三幅图就不画了，大概就是i和R重叠的时候，p(0) = 0, 而且 下一步i的话就比r大了， r就更新了， i一定成为center