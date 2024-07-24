### Intuition
The problem is to determine whether a sequence of moves results in returning to the origin (0,0) on a 2D plane. The moves can be Up ('U'), Down ('D'), Left ('L'), and Right ('R'). To solve this, we need to track the net movement in both the x and y directions.

### Approach
1. Initialize counters for the x and y coordinates to zero.
2. Traverse the string of moves:
   - Increment the x-coordinate for 'R' (right) and decrement it for 'L' (left).
   - Increment the y-coordinate for 'U' (up) and decrement it for 'D' (down).
3. After processing all moves, check if both x and y coordinates are zero. If they are, the moves return to the origin; otherwise, they do not.

### Complexity
- **Time complexity:** \(O(n)\), where \(n\) is the length of the input string. Each character in the string is processed once.
- **Space complexity:** \(O(1)\). Only a fixed amount of additional space is used (for the x and y coordinates).

### Code
```
bool judgeCircle(char* moves) 
{
    int x = 0;
    int y = 0;
    for (int i = 0; moves[i] != '\0'; i++) 
    {
        char ch = moves[i];
        if (ch == 'U') 
        {
            x++;
        } 
        else if (ch == 'D') 
        {
            x--;
        } 
        else if (ch == 'L') 
        {
            y++;
        } 
        else if (ch == 'R') 
        {
            y--;
        }
    }
    if (x == 0 && y == 0) 
    {
        return true;
    } 
    else 
    {
        return false;
    }
}
```