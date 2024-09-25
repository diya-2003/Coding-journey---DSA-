###  Intuition
The task is to compute the sum of prefix scores for each word in an array, where the score of a prefix is defined as the number of words in the array that share that prefix. The problem hints at the need to efficiently count how many words share common prefixes, which naturally suggests using a **Trie** (prefix tree) to store the prefixes of words and track how many words share them.

###  Approach
1. **Trie Data Structure**: 
   A Trie is an optimal choice for problems involving prefixes because it allows us to efficiently store and retrieve information about common prefixes. We will use the Trie to:
   - Insert each word from the array, updating prefix counts as we go.
   - For each word, retrieve the total score by traversing the Trie and summing up the counts of all prefixes of the word.

2. **Insert Words into Trie**:
   As we insert each word character by character into the Trie, we increment a `count` at each node that corresponds to a character. This count keeps track of how many words pass through that node (i.e., how many words have that prefix).

3. **Calculate Prefix Scores**:
   After the Trie is constructed, for each word in the array, we traverse the Trie from the root for each character in the word and accumulate the counts stored in the nodes. This gives the total score for that word's prefixes.

4. **Result Array**:
   Store the sum of prefix scores for each word in an array and return it.

###  Complexity

- **Time complexity**:
  - Inserting a word into the Trie takes O(m), where `m` is the length of the word.
  - Querying the prefix scores for a word also takes O(m).
  - Since we are doing this for `n` words, where `n` is the number of words in the array, and each word has an average length of `m`, the overall time complexity is:
  - $$O(n * m)$$

- **Space complexity**:
  - The space required for the Trie is proportional to the number of characters in all the words, so it is O(n * m) for storing the Trie.
  - We also need space for the result array, which is O(n).
  - Thus, the total space complexity is:
  - $$O(n * m)$$

###  Code

```c
int* sumPrefixScores(char** words, int wordsSize, int* returnSize) {
    typedef struct TrieNode {
        struct TrieNode* children[26];
        int count;
    } TrieNode;
    TrieNode* createNode() {
        TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
        node->count = 0;
        for (int i = 0; i < 26; i++) {
            node->children[i] = NULL;
        }
        return node;
    }

    int getPrefixScore(TrieNode* root, const char* word) {
        TrieNode* current = root;
        int score = 0;
        while (*word) {
            int index = *word - 'a';
            current = current->children[index];
            score += current->count; 
            word++;
        }
        return score;
    }
    void insertWord(TrieNode* root, const char* word) {
        TrieNode* current = root;
        while (*word) {
            int index = *word - 'a';
            if (current->children[index] == NULL) {
                current->children[index] = createNode();
            }
            current = current->children[index];
            current->count++;
            word++;
        }
    }
    TrieNode* root = createNode();
    for (int i = 0; i < wordsSize; i++) {
        insertWord(root, words[i]);
    }
    int* result = (int*)malloc(wordsSize * sizeof(int));
    *returnSize = wordsSize;
    for (int i = 0; i < wordsSize; i++) {
        result[i] = getPrefixScore(root, words[i]);
    }

    return result;
/*	Author   : Pankaj Mondal
	Date     : Wednesday, September 25, 2024, 9:00 PM
	LinkedIn : https://www.linkedin.com/in/buroush
	GitHub   : https://github.com/Buroush
	LeetCode : https://leetcode.com/Buroush        		*/
    
}

```

---

This approach efficiently handles the problem using a Trie, ensuring both time and space complexity are optimal for the given constraints.
