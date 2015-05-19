import math


# class Solution:
#     # @param {integer} n
#     # @return {integer}
#     def countPrimes(self, n):
#         sqrt_n = int(math.sqrt(n))
#         assert sqrt_n**2 <= n and (sqrt_n+1)**2 > n
#         potential_primes = [i for i in range(1, sqrt_n+1)]
#         potential_composite_number = [n//i for i in potential_primes]
#         if potential_composite_number[-1] == potential_primes[-1]:
#             potential_primes = potential_primes[:-1]
#         vector = potential_composite_number + potential_primes[::-1]
#         s = {n: (n-1) for n in vector}
#         for i in range(2, sqrt_n+1): # Bug 1: s是包括那个数为止，这里的话，需要包括sqrt_n
#             if s[i] != s[i-1]:
#                 p = i
#                 print(p, sqrt_n)
#                 cp = s[p-1] # 真正的少一个数才是前面已经筛掉的，现在遇到的这个p是新的
#                 p2 = i**2
#                 for v in vector:
#                     if v >= p2: # Bug 2: 对某个质数，它的作用于是等于或者大于它的平方
#                         s[v] -= s[v//p] - cp
#                     else:
#                         break
#         return s[n]


class Solution:
    # @param {integer} n
    # @return {integer}
    def countPrimes(self, n):
        if n < 2:
            return 0
        def count_inclusive(n):
            sqrt_n = int(math.sqrt(n))
            assert sqrt_n**2 <= n and (sqrt_n+1)**2 > n
            potential_primes = [i for i in range(1, sqrt_n+1)]
            potential_composite_number = [n//i for i in potential_primes]
            if potential_composite_number[-1] == potential_primes[-1]:
                potential_primes = potential_primes[:-1]
            vector = potential_composite_number + potential_primes[::-1]
            s = {n: (n-1) for n in vector}
            for i in range(2, sqrt_n+1): # Bug 1: s是包括那个数为止的质数，包含，这里的话，需要包括sqrt_n
                if s[i] != s[i-1]:
                    p = i
                    print(p, sqrt_n)
                    cp = s[p-1] # 真正的少一个数才是前面已经筛掉的，现在遇到的这个p是新的
                    p2 = i**2
                    for v in vector:
                        if v >= p2: # Bug 2: 对某个质数，它的作用于是等于或者大于它的平方
                            s[v] -= s[v//p] - cp
                        else:
                            break
            return s[n]
        return count_inclusive(n-1)
