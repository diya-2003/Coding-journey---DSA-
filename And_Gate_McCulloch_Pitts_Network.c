#include<stdio.h>
#define true 1
#define false 0
#define bool int
bool  McCulloch_Pitts_Network(int*,int,int);
/*
 * The simplest network is the McCulloch-Pitts model.
 * The input {x1, x2, x3,..., xn} is given to a neuron, and it produces one output y.
 * The output is binary.
 * We need to calculate the net input sum of all inputs ( I ).
 * Put the input through the activation function y = f(I); in this case, its binary step function.
 */
bool McCulloch_Pitts_Network(int* x,int n,int T){
	/* x is the input vector, n is the length of the input vector, T is the threshold */
	int i,I;	/* I is the net input. */
	for(I = 0, i = 0; i < n; i++)
		I += x[i];	/* Net input is calculated by adding up all inputs. */
	return I >= T ? true : false;	/* returning 0 or 1 as per the threshold */	
}
/*      Author   : Pankaj Mondal
        Date     : Friday, October 25, 2024, 6:04 PM
        LinkedIn : https://www.linkedin.com/in/buroush
        GitHub   : https://github.com/Buroush
        LeetCode : https://leetcode.com/Buroush                 */

int main(){
	int i,j,T=2,n=2,m=4;
	int x[][4]={{0, 0}, {0, 1}, {1, 0}, {1, 1}};
        printf("Implementation on And Gate using McCulloch-Pitts Network\n");
	printf("x1\tx2\ty= x1 and x2\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
			printf("%d\t",x[i][j]);
		printf("\t%d",McCulloch_Pitts_Network(x[i],n,T));
		printf("\n");
	}
	
return 0;
}
