**Post: Building an AND Gate Using McCulloch-Pitts Neuron Model in C**

In my deep learning journey, I’ve implemented the classic *McCulloch-Pitts* neuron model—a foundational neural network structure that mimics how biological neurons fire based on inputs. Here’s how I used it to create an AND gate.

### Code Breakdown:

- **Input Vector**: We feed binary inputs \( x1 \) and \( x2 \) into the neuron.
- **Threshold (T)**: Set to 2. The neuron only fires (outputs 1) if the sum of inputs meets or exceeds this threshold.
- **Activation Function**: The model uses a *binary step function*—outputs 1 if the threshold is met, otherwise 0.

### Key Code Snippet:
In the `McCulloch_Pitts_Network` function, I calculate the sum of inputs and compare it to the threshold:
```c
bool McCulloch_Pitts_Network(int* x, int n, int T) {
    int I = 0;
    for (int i = 0; i < n; i++)
        I += x[i];
    return I >= T ? true : false;
}
/*      Author   : Pankaj Mondal
        Date     : Friday, October 25, 2024, 6:04 PM
        LinkedIn : https://www.linkedin.com/in/buroush
        GitHub   : https://github.com/Buroush
        LeetCode : https://leetcode.com/Buroush                 */

```

### Output:
The model accurately performs as an AND gate:
```
x1   x2   y = x1 AND x2
0    0       0
0    1       0
1    0       0
1    1       1
```

This simple model introduces how a neuron can “decide” based on inputs, setting the foundation for more complex networks.
