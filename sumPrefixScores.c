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
}
