# Intuition
The problem is about simulating a scenario where friends arrive and leave a party at specific times. We need to assign them the smallest available chair at the moment they arrive and track which chair a specific target friend sits on. The core of the problem is efficiently managing the availability of chairs and processing events (arrival and departure) in the correct order.

# Approach
1. **Event-Based Simulation**: We treat each arrival and departure as an event. We need to process these events in order of time. If two events happen at the same time, the departure should be processed before the arrival to ensure the chair is freed up in time for the arriving friend.
   
2. **Min-Heap for Available Chairs**: We maintain a min-heap (priority queue) to efficiently get the smallest available chair when a friend arrives. When a friend leaves, their chair is added back to the heap.

3. **Sorting Events**: We create events for both arrival and departure, then sort them by time. If two events have the same time, departures are processed before arrivals to ensure the correct chair management.

4. **Process Each Event**: We iterate through the sorted events:
   - If it's an arrival, assign the smallest available chair from the heap.
   - If it's a departure, return the chair to the available heap.
   - If the arriving friend is the target friend, return the chair number immediately.

# Complexity
- **Time complexity**:  
  - Sorting the events takes $$O(n \log n)$$, where \(n\) is the number of friends.
  - Each insertion and removal from the heap takes $$O(\log n)$$, and we do this for each arrival and departure event, so the overall complexity is $$O(n \log n)$$.

- **Space complexity**:  
  We need additional space for storing the events, available chairs (min-heap), and a map to track each friend's chair, resulting in a space complexity of $$O(n)$$.

# Code
```c
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
```
> Talk to yourself at least once a day. Otherwise you will lose the chance to talk to one of the wisest people in the world. ~ Heroic monk Swami Vivekananda
