import numpy as np
class Solution:
    def minProductSum(self, nums1: List[int], nums2: List[int]) -> int:
        return np.dot(sorted(np.asarray(nums1)),sorted(np.asarray(nums2),reverse=True))