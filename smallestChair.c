typedef struct {
    int time, friendID;
    bool isArrival;
} Event;
int compareEvents(const void* a, const void* b) {
    Event* eventA = (Event*)a, *eventB = (Event*)b;
    if (eventA->time == eventB->time) 
        return eventA->isArrival ? 1 : -1;
    return eventA->time - eventB->time;
}
void pushHeap(int* heap, int* heapSize, int val) {
    heap[(*heapSize)++] = val;
    int i = *heapSize - 1, parent, temp;
    while (i > 0) {
        parent = (i - 1) / 2;
        if (heap[parent] > heap[i]) {
            temp = heap[parent];
            heap[parent] = heap[i];
            heap[i] = temp;
            i = parent;
        } else
            break;
    }
}
int popHeap(int* heap, int* heapSize) {
    int result = heap[0], i, left, right, minIndex;
    heap[0] = heap[--(*heapSize)];
    i = 0;
    while (i * 2 + 1 < *heapSize) {
        left = i * 2 + 1;
        right = i * 2 + 2;
        minIndex = left;
        if (right < *heapSize && heap[right] < heap[left]) 
            minIndex = right;
        if (heap[i] > heap[minIndex]) {
            int temp = heap[i];
            heap[i] = heap[minIndex];
            heap[minIndex] = temp;
            i = minIndex;
        } else 
            break;
    }
    return result;
}
int smallestChair(int** times, int timesSize, int* timesColSize, int targetFriend) {
    int numEvents = 2 * timesSize, i, *availableChairs, availableSize, *friendToChair, chair;
    Event* events = (Event*)malloc(numEvents * sizeof(Event));
    for (i = 0; i < timesSize; i++) {
        events[2 * i] = (Event){times[i][0], i, true};
        events[2 * i + 1] = (Event){times[i][1], i, false};
    }
    qsort(events, numEvents, sizeof(Event), compareEvents);
    availableChairs = (int*)malloc(timesSize * sizeof(int));
    availableSize = 0;
    for ( i = 0; i < timesSize; i++) {
        pushHeap(availableChairs, &availableSize, i);
    }
    friendToChair = (int*)malloc(timesSize * sizeof(int));
    for (i = 0; i < numEvents; i++) {
        Event event = events[i];
        if (event.isArrival) {
            chair = popHeap(availableChairs, &availableSize);
            friendToChair[event.friendID] = chair;
            if (event.friendID == targetFriend) {
                free(events);
                free(availableChairs);
                free(friendToChair);
                return chair;
            }
        } else {
            chair = friendToChair[event.friendID];
            pushHeap(availableChairs, &availableSize, chair);
        }
    }
    free(events);
    free(availableChairs);
    free(friendToChair);
    return -1;
/*	Author   : Pankaj Mondal
	Date     : Thursday, October 11, 2024, 2:48 PM
	LinkedIn : https://www.linkedin.com/in/buroush
	GitHub   : https://github.com/Buroush
	LeetCode : https://leetcode.com/Buroush        		*/    
}
