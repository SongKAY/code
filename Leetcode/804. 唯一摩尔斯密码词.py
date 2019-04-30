class Solution(object):
    def uniqueMorseRepresentations(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        dic = {}
        result = {}
        code  = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        l = list(range(ord('a'),ord('z')+1))
        for idx, i in enumerate(l):
            if chr(i) not in dic.keys():
                dic[chr(i)] = code[idx]
        for each in words:
            s = ""
            for char in each:
                s += dic[char]
            s = s.strip()
            if s not in result.keys():
                result[s] = 1
        return len(result.keys())
