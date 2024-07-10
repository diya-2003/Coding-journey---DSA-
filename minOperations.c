int minOperations(char** logs, int logsSize) {
    int counter = 0;
    for (int i = 0; i < logsSize; ++i) {
        if (logs[i][0] != '.') {
            counter++;
        } else if (counter != 0 && strlen(logs[i]) == 3) {
            counter--;
        }
    }
    return counter;
}
