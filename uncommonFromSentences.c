typedef struct {
    char *word;
    int count;
} WordCount;

int compare(const void *a, const void *b) {
    return strcmp(((WordCount*)a)->word, ((WordCount*)b)->word);
}

char** uncommonFromSentences(char* s1, char* s2, int* returnSize) {
    // Allocate memory to store words and their counts
    WordCount wordCounts[400]; // A large array to store the words and counts
    int wordIndex = 0;
    
    // A helper function to tokenize and count words
    void countWords(char *sentence) {
        char *token = strtok(sentence, " ");
        while (token != NULL) {
            int found = 0;
            for (int i = 0; i < wordIndex; i++) {
                if (strcmp(wordCounts[i].word, token) == 0) {
                    wordCounts[i].count++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                wordCounts[wordIndex].word = strdup(token);  // Use strdup to make a copy of the word
                wordCounts[wordIndex].count = 1;
                wordIndex++;
            }
            token = strtok(NULL, " ");
        }
    }
    
    // Split and count the words in both sentences
    char s1Copy[201], s2Copy[201];
    strcpy(s1Copy, s1);
    strcpy(s2Copy, s2);
    countWords(s1Copy);
    countWords(s2Copy);
    
    // Allocate memory for the result
    char **result = (char **)malloc(400 * sizeof(char *));
    int resultIndex = 0;
    
    // Collect the uncommon words (those that appear exactly once)
    for (int i = 0; i < wordIndex; i++) {
        if (wordCounts[i].count == 1) {
            result[resultIndex] = strdup(wordCounts[i].word);  // Duplicate the word for the result
            resultIndex++;
        }
    }
    
    // Set the return size
    *returnSize = resultIndex;
    
    // Free the memory allocated by strdup for the word counts
    for (int i = 0; i < wordIndex; i++) {
        free(wordCounts[i].word);
    }

    return result;
}
