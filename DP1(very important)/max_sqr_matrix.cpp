/*Given a n*m matrix which contains only 0s and 1s, find out the size of maximum square sub-matrix with all 0s. You need to return the size of square with all 0s.
Input format :

Line 1 : n and m (space separated positive integers)
Next n lines : m elements of each row (separated by space).

Output Format:

Line 1 : Size of maximum square sub-matrix

Sample Input :

3 3
1 1 0
1 1 1
1 1 1

Sample Output :

1

*/


#include<bits/stdc++.h>
using namespace std;

int findMaxSquareWithAllZeros(int** input, int m, int n){
    
    
    int** output = new int*[m];
    for(int i=0; i<m; i++){
        output[i] = new int[n];
    }
    
    for(int i=0; i<m; i++){
       if(input[i][0] == 0)
           output[i][0] = 1;
        else
            output[i][0] = 0;
    }
    for(int i=0; i<n; i++){
        if(input[0][i] == 0)
           output[0][i] = 1;
        else
            output[0][i] = 0;
    }
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(input[i][j] == 1)
                output[i][j] = 0;
            else
                output[i][j] = min(output[i-1][j-1], min(output[i-1][j], output[i][j-1]))+1;
        }
    }
    
    int max = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(output[i][j]>max)
                max = output[i][j];
        }
    }
    for(int i=0; i<m; i++){
        delete [] output[i];
    }
    delete [] output;
    return max;
}
    
