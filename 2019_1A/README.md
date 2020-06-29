alienRhyme.cpp: No two words are the same. Thus after building the reverse trie, we know that for each word which runs from dummy to leaf, it can only form pair with another word at some node between dummy and leaf node. Moreover, each node in the reverse trie can be the merging point of two words for at most once. We greedily merge word pairs such that words are merged whenever possible, i.e., as early as possible as we move from the bottom of the trie to the top of the trie. We merge word pairs in a recursive fashion. 

golfGophers.py: An application of Chinese remainder theorem.
