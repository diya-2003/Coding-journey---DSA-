**Post: Implementing an OR Gate with Perceptron Model in C**

Continuing my exploration of neural network fundamentals, I built an OR gate using the *Perceptron Model*. Unlike the McCulloch-Pitts model, the perceptron introduces *weights*, adding flexibility and the ability to solve more complex problems.

### Code Overview:

- **Input and Weight Vectors**: Each binary input \( x1 \) and \( x2 \) is paired with a weight (\( w1 \) and \( w2 \)), both set to 1 in this case.
- **Threshold (T)**: Set to 1, allowing the output neuron to fire (return 1) if at least one input is active.
- **Activation**: A binary step function outputs 1 if the weighted sum of inputs meets or exceeds the threshold.

### Key Code Snippet:
In the `Perceptron` function, we calculate the dot product of inputs and weights:
```c
bool Perceptron(int* x, int* w, int m, int T) {
    int I = 0;
    for (int i = 0; i < m; i++)
        I += x[i] * w[i];
    return I >= T ? true : false;
}
```

### Output:
The model performs as an OR gate, validating the perceptron's ability to classify linearly separable data:
```
x1   x2   y = x1 OR x2
0    0       0
0    1       1
1    0       1
1    1       1
```

This is a key step in understanding how neural networks can be built up from individual perceptrons to solve more complex problems.
