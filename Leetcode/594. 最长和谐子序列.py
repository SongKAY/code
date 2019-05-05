class Solution(object):
    def findLHS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        d = collections.Counter(nums)
        result = 0
        for i in nums:
            if i+1 in d:
                result = max(result,d[i]+d[i+1])
        return result
