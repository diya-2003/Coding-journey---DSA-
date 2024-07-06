## Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
The problem requires us to simulate the passing of a pillow among `n` people over a given amount of time. The pillow is passed in a cyclic manner, where it starts at person 1 and is passed to the next person until it reaches the nth person, then it is passed back to person 1. This process continues for the given `time` units.

## Approach
<!-- Describe your approach to solving the problem. -->
1. Initialize the current person holding the pillow as 1 (starting position).
2. Determine the direction of passing (initially forward).
3. Iterate for each time unit:
   - If moving forward and reaching the nth person, change direction to backward.
   - If moving backward and reaching the 1st person, change direction to forward.
   - Adjust the current person based on the direction.
4. Continue until the given time is exhausted.
5. Return the person holding the pillow after the given time.

## Complexity
- Time complexity: \( O(\text{time}) \)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
  - We iterate through each time unit, so the time complexity is directly proportional to the time given.

- Space complexity: \( O(1) \)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
  - We only use a few additional variables for tracking the current position and direction, so the space complexity is constant.

## Code
```
int passThePillow(int n, int time) 
{
    if(n==time) 
    return n-1;
    else
    {
    int i=1;
    int j=0;
    while(time>0) 
    {
        if(i==n)
        j=1;
        if(j==0)
        {
            time--;
            i++;
        }
        else if(j==1 && i!=1)
        {
            time--;
            i--;
        }
        else
        {
            j=0;
        }
    }
    return i;
    }
}
```