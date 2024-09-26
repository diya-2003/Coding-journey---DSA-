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
