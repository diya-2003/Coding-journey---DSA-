### Intuition
The problem involves determining if a robot, starting at the origin (0,0) facing north, will return to its starting point or end up in a loop after following a sequence of instructions. The robot can move in four directions (north, east, south, west) based on the 'G' (move forward), 'L' (turn left), and 'R' (turn right) commands.

### Approach
1. **Tracking Position and Direction**: 
   - Use a variable to track the robot's current direction.
   - Use coordinate variables to track the robot's position.

2. **Process Instructions**:
   - For each instruction:
     - **'G'**: Move forward in the current direction.
     - **'L'**: Turn left (change direction).
     - **'R'**: Turn right (change direction).

3. **Check for Loop**:
   - After processing the instructions, check if the robot returns to the starting point or if it’s facing a different direction than initially. If it's facing a different direction, it might still be in a loop even if it’s not at the starting point.

### Complexity
- **Time Complexity**: $$O(n)$$ where \( n \) is the number of instructions.
- **Space Complexity**: $$O(1)$$ since we’re only using a constant amount of space for position, direction, and loop control variables.

###Code:

```bool isRobotBounded(char* instructions) 
{
    int pos=1;
    float score=0;
    for(int j=0;j<4;j++){
    for(int i=0;instructions[i]!='\0';i++)
    {
        if(instructions[i] == 'G'){
            switch(pos){
                case 1: 
                    score += 1;
                    break;
                case 2: 
                    score += 0.5;
                    break;
                case 3: 
                    score -= 1;
                    break;
                case 4: 
                    score -= 0.5;
                    break;
                }
            }
            if(instructions[i] == 'L'){
                pos++;
                if(pos== 5){
                    pos= 1;
                }
            }
            if(instructions[i] == 'R'){
                pos--;
                if(pos== 0){
                pos= 4;
                }
            }
        }
        if(score == 0){
            return true;
        }
    }
    if(score == 0){
        return true;
    }
    return false;
}
```