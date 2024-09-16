int convertToMinutes(const char* timePoint) {
    int hours = (timePoint[0] - '0') * 10 + (timePoint[1] - '0');
    int minutes = (timePoint[3] - '0') * 10 + (timePoint[4] - '0');
    return hours * 60 + minutes;}
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);}
int findMinDifference(char** timePoints, int timePointsSize) {
    if (timePointsSize > 1440) {
        return 0;    }
    int* minutes = (int*)malloc(timePointsSize * sizeof(int));
    for (int i = 0; i < timePointsSize; i++) {
        minutes[i] = convertToMinutes(timePoints[i]);    }
    qsort(minutes, timePointsSize, sizeof(int), compare);
    int minDiff = 1440;
    for (int i = 1; i < timePointsSize; i++) {
        int diff = minutes[i] - minutes[i - 1];
        if (diff < minDiff) {
            minDiff = diff;        }    }
    int circularDiff = 1440 + minutes[0] - minutes[timePointsSize - 1];
    if (circularDiff < minDiff) {
        minDiff = circularDiff;    }
    free(minutes);
    return minDiff;}
