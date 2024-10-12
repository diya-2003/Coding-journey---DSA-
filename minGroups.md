
### Intuition:
The core idea behind this problem is to group intervals such that no two intervals in the same group overlap. We need to figure out the maximum number of overlapping intervals at any point because that dictates the minimum number of groups required. If we can track when intervals start and end, the maximum number of intervals active at the same time will give us the number of groups needed.

### Approach:
1. **Event Representation**: 
   Treat the intervals as events. For each interval `[left, right]`, consider two events: 
   - A "start" event at `left` (i.e., an interval starting).
   - An "end" event at `right + 1` (i.e., the interval ending).

2. **Sorting the Events**:
   We sort the events by time. If two events have the same time, end events (`-1`) should come before start events (`+1`) to correctly handle intervals that touch at the boundary.

3. **Counting Overlaps**:
   After sorting, traverse the events and maintain a counter (`currentGroups`) to track the number of overlapping intervals. The maximum value of this counter at any point in time will be the number of groups required.

### Complexity:
- **Time Complexity**:  
  Sorting the events takes \(O(n \log n)\), where \(n\) is the number of intervals. Traversing the events to calculate overlaps takes \(O(n)\).  
  Thus, the overall time complexity is \(O(n \log n)\).

- **Space Complexity**:  
  We store an array of events, which requires \(O(n)\) space.

### Code:
```c
#include <stdio.h>
#include <stdlib.h>
```
```c
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

```
```c
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

```

> "A life without suffering is like a boat without a sailor; it has no discretion of its own, moving only in a light breeze." - Ishwar Chandra Vidyasagar
