import pdb
import copy
    # @param start, a string
    # @param end, a string
    # @param dict, a set of string
    # @return a list of lists of string


# def findMedianSortedArrays(nums1, nums2):
#     def rec_helper(nums1, nums2, k):
#         if(len(nums1) > len(nums2)):
#             return rec_helper(nums2, nums1, k)
#         if len(nums1) == 0:
#             return nums2[k-1]
#         half = int(k/2)
#         left = min(len(nums1), half)
#         right = int(k - left)
#         if nums1[left-1] == nums2[right-1]:
#             return nums1[left-1]

#         if k == 1:
#             return min(nums1[0], nums2[0])

#         if(nums1[left-1] < nums2[right-1]):
#             return rec_helper(nums1[left:], nums2, k-left)
#         else:
#             return rec_helper(nums1, nums2[right:], k-right)

#     total_len = len(nums1) + len(nums2)
#     if(total_len & 1):
#         return rec_helper(nums1, nums2, int((total_len+1)/2))
#     else:
#         return (rec_helper(nums1, nums2, int(total_len/2)) + rec_helper(nums1, nums2, int(total_len/2+1)))/2
class Solution:
    # @param {integer[]} nums1
    # @param {integer[]} nums2
    # @return {float}
    def findMedianSortedArrays(self, nums1, nums2):
        def rec_helper(nums1, nums2, k):
            if(len(nums1) > len(nums2)):
                return rec_helper(nums2, nums1, k)
            if len(nums1) == 0:
                return nums2[k-1]
            half = int(k/2)
            left = min(len(nums1), half)
            right = int(k - left)
            if nums1[left-1] == nums2[right-1]:
                return nums1[left-1]
    
            if k == 1:
                return min(nums1[0], nums2[0])
    
            if(nums1[left-1] < nums2[right-1]):
                return rec_helper(nums1[left:], nums2, k-left)
            else:
                return rec_helper(nums1, nums2[right:], k-right)
    
        total_len = len(nums1) + len(nums2)
        if(total_len & 1):
            return rec_helper(nums1, nums2, int((total_len+1)/2))
        else:
            return (rec_helper(nums1, nums2, int(total_len/2)) + rec_helper(nums1, nums2, int(total_len/2+1)))/2





a = []
b = [2, 3]
sol = Solution()
print(sol.findMedianSortedArrays(a,b))