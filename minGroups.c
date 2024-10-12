#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int time,type; // +1 for start of interval, -1 for end of interval
} Event;

// Comparator for sorting events: sort by time first, then by type (-1 before +1)
int compare(const void* a, const void* b) {
    Event *eventA = (Event*)a,*eventB = (Event*)b;
    if (eventA->time == eventB->time)
        return eventA->type - eventB->type; // End (-1) before Start (+1) if time is the same

    return eventA->time - eventB->time; // Otherwise, sort by time
}

int minGroups(int** intervals, int intervalsSize, int* intervalsColSize) {
    int numEvents = intervalsSize * 2, i;
    Event* events = (Event*)malloc(numEvents * sizeof(Event));
    
    // Create events for each interval
    for (i = 0; i < intervalsSize; i++) {
        events[2 * i] = (Event){intervals[i][0], +1};   // Start of interval
        events[2 * i + 1] = (Event){intervals[i][1] + 1, -1}; // End of interval (+1 to avoid overlap)
    }
    
    // Sort events by time (and handle tie-breaking by type)
    qsort(events, numEvents, sizeof(Event), compare);
    
    // Sweep through events and calculate maximum overlap
    int maxGroups = 0, currentGroups = 0;
    
    for (i = 0; i < numEvents; i++) {
        currentGroups += events[i].type;
        if (currentGroups > maxGroups)
            maxGroups = currentGroups;
    }
    free(events);
    return maxGroups;
}

int main() {
    // Example 1
    int intervals1[][2] = {{5, 10}, {6, 8}, {1, 5}, {2, 3}, {1, 10}};
    int* intervals1Ptrs[5] = {intervals1[0], intervals1[1], intervals1[2], intervals1[3], intervals1[4]};
    int intervalsColSize1[5] = {2, 2, 2, 2, 2};
    printf("Minimum number of groups: %d\n", minGroups(intervals1Ptrs, 5, intervalsColSize1)); // Output: 3

    // Example 2
    int intervals2[][2] = {{1, 3}, {5, 6}, {8, 10}, {11, 13}};
    int* intervals2Ptrs[4] = {intervals2[0], intervals2[1], intervals2[2], intervals2[3]};
    int intervalsColSize2[4] = {2, 2, 2, 2};
    printf("Minimum number of groups: %d\n", minGroups(intervals2Ptrs, 4, intervalsColSize2)); // Output: 1
/*	Author   : Pankaj Mondal
	Date     : Saturday, October 12, 2024, 2:48 PM
	LinkedIn : https://www.linkedin.com/in/buroush
	GitHub   : https://github.com/Buroush
	LeetCode : https://leetcode.com/Buroush        		*/
    return 0;

}
