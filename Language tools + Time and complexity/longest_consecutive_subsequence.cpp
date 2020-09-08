/*
You are given an array of unique integers that contain numbers in random order. Write a program to find the longest possible sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains consecutive elements. Order of elements in the output is not important.
Best solution takes O(n) time.
If two sequences are of equal length then return the sequence starting with the number whose occurrence is earlier in the array.
Input Format :

Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)

Constraints :

0 <= n <= 10^8

Sample Input 1 :

13
2 12 9 16 10 5 3 20 25 11 1 8 6 

Sample Output 1 :

8 
9 
10 
11 
12

Sample Input 2 :

7
3 7 2 1 9 8 41

Sample Output 2 :

7
8
9
Explanation: Sequence should be of consecutive numbers. Here we have 2 sequences with same length i.e. [1, 2, 3] and [7, 8, 9], but output should be [7, 8, 9] because the starting point of [7, 8, 9] comes first in input array.

Sample Input 3 :

7
15 24 23 12 19 11 16

Sample Output 3 :

15 
16


*/
------------------------------------------------------------------------------------------------------------------------------

	
#include<bits/stdc++.h>
/*using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){
	//Your Code goes here
    unordered_map<int, bool>mp;
    vector<int>ans;
    
    for(int i=0; i<n; i++){        //INSERTING ALL ELEMENTS IN A MAP
        mp.insert({arr[i], false});
    }
    int index[n];
    for(int i=0; i<n; i++){
       index[i] = i; 
    }
    
  unordered_map<int, bool>::iterator it;
    
        int max_size=0;           //WILL KEEP SIZE OF LONGEST CONSECUTIVE SEQUENCE
        int prev_starting_point=0; //WILL KEEP STARTING POINT OF LONGEST CONSECUTIVE SEQUENCE
        int starting_point;    //ON EACH ITERATION, IT WILL KEEP THE NEW STARTING POINT EACH TIME
        int size;              //WILL KEEP SIZE OF NEW CONSECUTIVE SEQUENCE EACH TIME
        
    for(it=mp.begin(); it!=mp.end(); it++){  //ITERATING THROUGH ALL ELEMENTS
        
          
        int num = it->first;
        
        if(it->second == false){ //IF THE ELEMENT IS NOT VISITED
             size=1;
             it->second=true;  //MARK IT AS TRUE AND KEEP SIZE OF THIS NEW SEQUENCE AS 1(AS FOR NOW)
             starting_point = it->first;//AND THIS WILL BE THE STARTING ELEMENT RIGHT NOW
            for(int i=0; i<n; i++){ //SEARCH FOR ELEMENT LESSER THAN THE ORIGINAL ELEMENT
                num = num-1;
                if(mp.find(num)!=mp.end()){ //IF PREDECESSOR IS PRESENT, MARK IT AS TRUE, SET IT AS STARTING POINT AND INCRESE SIZE OF THIS SEQUENCE BY 1
                   mp.find(num)->second=true;
                    starting_point = num;
                    size++;
                }
                else //AND IF NOT PRESENT THEN THE ORIGINAL ELEMENT WILL BE THE STARTING POINT AND BREAK THE LOOP
                    break;
            }
            int num = it->first;  
            for(int i=0; i<n; i++){ //NOW SEARCH FOR SUCESSORS OF ORIGINAL ELEMENT AND IF FOUND, MARK THEM AS TRUE AND INCREASE THE SIZE
                
                int num = num+1;
                if(mp.find(num)!=mp.end()){
                    mp.find(num)->second =true;
                    size++;
                }
                else{
                    if(max_size<size){ //update max_size and prev_starting point
                        max_size=size;
                        prev_starting_point = starting_point;
                        break;
                        
                    }
                    
                }
            }
        }
    }
    for(int i=0; i<max_size; i++){ //insert the maximum subseq in vector
        ans.push_back(prev_starting_point);
        prev_starting_point++;
    }
return ans;
}*/


	
-----------------------------------------------------------------------------------------------------------------------------
	
	
#include<bits/stdc++.h>
using namespace std;



vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){

	unordered_map<int, bool> m;
	unordered_map<int, int> index;
	for(int i=0;i<n;i++){
	    m[arr[i]] = 1;
	    index[arr[i]]=0;
	    
	}
	

	for (int i = 1; i<=n; i++) {
	
		if(index[arr[i-1]]==0){
            index[arr[i-1]] = i;
            
        }
	}

	int maxLen = INT_MIN, minStart = INT_MAX;

	for (int i = 0; i < n; i++) {
        
		if (m[arr[i]]) {
            
			m[arr[i]] = 0;
            
			int len = 1, startC = arr[i], num = arr[i] + 1;
			while (m[num]) {
				m[num] = 0;
				num++;
				len++;
			}
			int lastInd = arr[i];
			num = arr[i] - 1;
            while (m[num]) {
				m[num] = 0;
				lastInd = num;
				num--;
				len++;
			}

			if (lastInd < startC) {
				startC = lastInd;
			}

			if (len > maxLen) {
				maxLen = len;
				minStart = startC;
			}
			else if (len == maxLen) {
				if (index[startC] < index[minStart]) {
				    
                    minStart = startC;
                }
			}
            }
            
	}

    // cout << minStart << " " << maxLen << "\n";
    
	vector<int> ans(maxLen, 0);
	for (int i = 0; i < maxLen; i++) {
		ans[i] = minStart + i;
	}

    return ans;
}



------------------------------------------------------------------------------------------------------------------------------
	
	If 
