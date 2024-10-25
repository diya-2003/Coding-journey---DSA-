int compare(const void *a, const void *b){
    return strcmp(*(const char **)a, *(const char **)b);}
char** removeSubfolders(char** folder, int folderSize, int* returnSize) {
    qsort(folder, folderSize, sizeof(char*), compare);
    char** result = (char**)malloc(folderSize * sizeof(char*));
    int count = 0;
    result[count++] = folder[0];
    for (int i = 1; i < folderSize; i++) {
        int len = strlen(result[count - 1]);
        if (strncmp(folder[i], result[count - 1], len) != 0 || folder[i][len] != '/')
            result[count++] = folder[i];
    }
    *returnSize = count;
    return result;
}
