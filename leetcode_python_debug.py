class Solution:
    # @param {string[]} words
    # @param {integer} maxWidth
    # @return {string[]}
    def fullJustify(self, words, maxWidth):
       lines = []
       while len(words) != 0: 
        length  = 0
        this_line = []
        while length < maxWidth:
            this_line.append(words[0])
            length += len(words[0]) + 1
            words.pop(0)
            