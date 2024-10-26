#include<stdio.h>
#define true 1
#define false 0
#define bool int
bool  Perceptron(int*,int*,int,int);
/*
 * The improvement to the McCulloch-Pitts model is the Perception. 
 * It is a liner classifier that performs binary classification.
 * The major improvement over the McCulloch-Pitts model is the possibility to introduce weights {w1, w2, w3,...,wm,}.
 * The input {x1, x2, x3,..., xm} is given to a neuron, and it produces one output y.
 * The output is binary.
 * We need to calculate the ' I ' sum of all the dot product of input and weights inputs .
 * Put the input through the activation function y = f(I); in this case, its binary step function.
 */
bool  Perceptron(int* x, int* w, int m, int T){
	/* x is the input vector, n is the length of the input vector, T is the threshold */
	int i,I;	/* I is the net input. */
	for(I = 0, i = 0; i < m; i++)
		I += x[i] * w[i];   /* Net input is calculated by adding up all the dot product of input and weights. */
	return I >= T ? true : false;	/* returning 0 or 1 as per the threshold */	
}
/*      Author   : Pankaj Mondal
        Date     : Saturday, October 26, 2024, 5:06 PM
        LinkedIn : https://www.linkedin.com/in/buroush
        GitHub   : https://github.com/Buroush
        LeetCode : https://leetcode.com/Buroush                 */

int main(){
	int i,j,T=1,n=2,m=4, x[][4]={{0, 0}, {0, 1}, {1, 0}, {1, 1}}, w[]={1,1};
        printf("Implementation on Or Gate using Perceptron Network\n");
	printf("x1\tx2\ty= x1 or x2\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
			printf("%d\t",x[i][j]);
		printf("%d",Perceptron(x[i],w,n,T));
		printf("\n");
	}
	
return 0;
}
