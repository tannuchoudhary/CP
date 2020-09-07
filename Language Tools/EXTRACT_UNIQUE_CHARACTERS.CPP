/*Given a string, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same.
Input format :

String S

Output format :

Output String

Constraints :

0 <= Length of S <= 10^8

Sample Input 1 :

ababacd

Sample Output 1 :

abcd

Sample Input 2 :

abcde

Sample Output 2 :

abcde
*/


/*#include<bits/stdc++.h>
#include<string.h>

char* uniqueChar(char *str){
    int index=0;
    int len = strlen(str);
    char output[len];
      int len2=1;
    for(int i=0; i<len; i++){
      
        int suc=0;
        for(int j=0; j<len2; j++){
            if (str[i] == output[j]){
                suc=0;
                break;
            }
            else 
                suc=1;
                
        }
        if(suc==1){
            output[index] = str[i];
        index++;
            len2++;
        }
    }
    return output;
}*/





#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

char* uniqueChar(char *str){
    int len = strlen(str);
    if(len == 0){
        char *ans = new char[1];
        ans[0] = '\0';
        return ans;
    }
    
    char *ans = new char[len+1];
    unordered_map<char, bool> hm;
    int i=0;
    for(int currIndex = 0; currIndex<len; currIndex++){
        char currChar = str[currIndex];
        if(hm.count(currChar) == 0){
            hm[currChar] = true;
            ans[i++] = currChar;
        }
    }
    ans[i] = '\0';
    return ans;
}

