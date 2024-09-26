# Intuition
The problem is asking to simulate a basic calendar where you can book time slots if they do not overlap with existing bookings. The first thought is to store each booking (as a pair of `start` and `end` times) and ensure that each new booking does not overlap with any existing bookings. If there is no overlap, the event can be added.

# Approach
1. Maintain a list of all previously booked events (storing each event's start and end times).
2. When a new event is requested, check if it overlaps with any of the existing events.
3. If no overlap is found, add the event to the list.
4. Use a simple dynamic array to store the events and ensure the array is resized as new events are added.

# Complexity
- **Time complexity**:  
  - For each new booking, we need to check all existing events to detect any overlap. Therefore, if there are `n` events already booked, the time complexity to book a new event is $$O(n)$$.
  - In the worst case, when we book all 1000 events, the total time complexity is $$O(n^2)$$.
  
- **Space complexity**:  
  - The space complexity is $$O(n)$$, where `n` is the total number of events, since we need to store all booked events in the array.

# Code
```c
typedef struct {
    int start;
    int end;
} Event;
typedef struct {
    Event* events;
    int size;
    int capacity;
} MyCalendar;
MyCalendar* myCalendarCreate() {
    MyCalendar* calendar = (MyCalendar*)malloc(sizeof(MyCalendar));
    calendar->size = 0;
    calendar->capacity = 10; 
    calendar->events = (Event*)malloc(calendar->capacity * sizeof(Event));
    return calendar;
}
bool myCalendarBook(MyCalendar* obj, int start, int end) {
    bool isOverlapping(int start1, int end1, int start2, int end2) {
        return !(end1 <= start2 || start1 >= end2);
    }
    void resizeIfNeeded(MyCalendar* obj) {
        if (obj->size >= obj->capacity) {
            obj->capacity *= 2;
            obj->events = (Event*)realloc(obj->events, obj->capacity * sizeof(Event));
        }
    }
    for (int i = 0; i < obj->size; ++i) {
        if (isOverlapping(start, end, obj->events[i].start, obj->events[i].end)) {
            return false;
        }
    }
    resizeIfNeeded(obj);
    obj->events[obj->size].start = start;
    obj->events[obj->size].end = end;
    obj->size++;
    return true;
}
void myCalendarFree(MyCalendar* obj) {
    free(obj->events);
    free(obj);
}
```
Test code
```c
int main() {
    MyCalendar* myCalendar = myCalendarCreate();

    printf("%d\n", myCalendarBook(myCalendar, 10, 20)); // returns 1 (true)
    printf("%d\n", myCalendarBook(myCalendar, 15, 25)); // returns 0 (false)
    printf("%d\n", myCalendarBook(myCalendar, 20, 30)); // returns 1 (true)

    myCalendarFree(myCalendar);
    return 0;
/*	Author   : Pankaj Mondal
	Date     : Thursday, September 26, 2024, 1:41 PM
	LinkedIn : https://www.linkedin.com/in/buroush
	GitHub   : https://github.com/Buroush
	LeetCode : https://leetcode.com/Buroush        		*/

}
```

### Explanation:
1. **Booking events**: The `myCalendarBook` function iterates through all previously booked events and checks for overlap using the `isOverlapping` helper function. If no overlap is found, it resizes the event list if necessary and adds the new event.
2. **Memory management**: The `myCalendarFree` function frees up the dynamically allocated memory for the events and the calendar when it's no longer needed.

This approach efficiently handles the problem within the constraints, using simple array management and dynamic memory allocation.
