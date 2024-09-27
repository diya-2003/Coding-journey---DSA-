#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Event;

typedef struct {
    Event* bookings;
    int bookings_size;
    int bookings_capacity;

    Event* overlaps;
    int overlaps_size;
    int overlaps_capacity;
} MyCalendarTwo;

// Helper function to check overlap between two intervals
int overlap(int start1, int end1, int start2, int end2) {
    return start1 < end2 && start2 < end1;
}

// Helper function to add an event to an event list
void add_event(Event** events, int* size, int* capacity, int start, int end) {
    if (*size == *capacity) {
        *capacity *= 2;
        *events = realloc(*events, (*capacity) * sizeof(Event));
    }
    (*events)[*size].start = start;
    (*events)[*size].end = end;
    (*size)++;
}

MyCalendarTwo* myCalendarTwoCreate() {
    MyCalendarTwo* obj = (MyCalendarTwo*)malloc(sizeof(MyCalendarTwo));

    obj->bookings_capacity = 10;
    obj->bookings_size = 0;
    obj->bookings = (Event*)malloc(obj->bookings_capacity * sizeof(Event));

    obj->overlaps_capacity = 10;
    obj->overlaps_size = 0;
    obj->overlaps = (Event*)malloc(obj->overlaps_capacity * sizeof(Event));

    return obj;
}

bool myCalendarTwoBook(MyCalendarTwo* obj, int start, int end) {
    // Check for triple booking in the overlaps
    for (int i = 0; i < obj->overlaps_size; i++) {
        if (overlap(start, end, obj->overlaps[i].start, obj->overlaps[i].end)) {
            return false; // Triple booking would happen
        }
    }

    // Check for overlaps with the existing bookings and record them in overlaps
    for (int i = 0; i < obj->bookings_size; i++) {
        if (overlap(start, end, obj->bookings[i].start, obj->bookings[i].end)) {
            int overlap_start = obj->bookings[i].start > start ? obj->bookings[i].start : start;
            int overlap_end = obj->bookings[i].end < end ? obj->bookings[i].end : end;
            add_event(&obj->overlaps, &obj->overlaps_size, &obj->overlaps_capacity, overlap_start, overlap_end);
        }
    }

    // Add the new event to bookings
    add_event(&obj->bookings, &obj->bookings_size, &obj->bookings_capacity, start, end);
    
    return true;
}

void myCalendarTwoFree(MyCalendarTwo* obj) {
    free(obj->bookings);
    free(obj->overlaps);
    free(obj);
}

int main() {
    MyCalendarTwo* myCalendarTwo = myCalendarTwoCreate();
    printf("%d\n", myCalendarTwoBook(myCalendarTwo, 10, 20)); // return True
    printf("%d\n", myCalendarTwoBook(myCalendarTwo, 50, 60)); // return True
    printf("%d\n", myCalendarTwoBook(myCalendarTwo, 10, 40)); // return True
    printf("%d\n", myCalendarTwoBook(myCalendarTwo, 5, 15));  // return False
    printf("%d\n", myCalendarTwoBook(myCalendarTwo, 5, 10));  // return True
    printf("%d\n", myCalendarTwoBook(myCalendarTwo, 25, 55)); // return True

    myCalendarTwoFree(myCalendarTwo);
    return 0;
}
