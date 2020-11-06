/*
 Coder's Rating
Send Feedback
Some of the more elite (and not-so-elite) coders around take part in a certain unnamed programming contest. In said contest, there are multiple types of competitions. Here, we consider the Open and High School competition types. For each type, each competitor receives a rating, an integer between 1 and 100000, inclusive. A coder's rating is based upon his or her level of performance in matches and is calculated using a complicated formula which, thankfully, you will not be asked to implement.
Although the Open and High School ratings for a coder who has participated in both competition types lately are usually close, this is not always the case. In particular, High School matches are more about speed, since many coders are able to solve all the problems, whereas Open matches require more thinking and there is a steeper curve in terms of problem difficulty.
Problem Statement
You are given N coders (1 ≤ N ≤ 300000), conveniently numbered from 1 to N. Each of these coders participates in both High School and Open matches. For each coder, you are also given an Open rating Ai and a High School rating Hi. Coder i is said to be better than coder j if and only if both of coder i's ratings are greater than or equal to coder j's corresponding ratings, with at least one being greater. For each coder i, determine how many coders coder i is better than.
Input Format

On the first line of input is a single integer N, as described above. N lines then follow. Line i+1 contains two space-separated integers, Ai and Hi.

Output Format

 Line i should contain the number of coders that coder i is better than.

Sample Input

8
1798 1832
862 700
1075 1089
1568 1557
2575 1984
1033 950
1656 1649
1014 1473

Sample Output

6
0
2
4
7
1
5
1

*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
//#include <unordered_map>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

static int uget()
{
    int c;
    while(c = getchar(), isspace(c)) {}
    int n = c - '0';
    while(c = getchar(), isdigit(c)) { n = n * 10 + (c - '0'); }
    return n;
}
template<class T> static void uput(T n)
{
    char s[30];
    int x = 0;
    do { s[x ++]=(n % 10) + '0'; n /= 10; } while(n);
    for(int i = x - 1; i >= 0; i --) putchar(s[i]);
    putchar('\n');
}

const int me = 300025;

int n;
int ft[me], ans[me];
pair<pair<int, int>, int> a[me];
vector<int> values;

void add(int pos, int value){
    for( ; pos < me; pos += (pos & -pos))
        ft[pos] += value;
}
int get(int pos){
    int s = 0;
    for( ; pos > 0; pos -= (pos & -pos))
        s += ft[pos];
    return s;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    n = uget();
    for(int i = 0; i < n; i ++){
        a[i].first.first = uget();
        a[i].first.second = uget();
        a[i].second = i;
        values.push_back(a[i].first.second);
    }
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    for(int i = 0; i < n; i ++){
        a[i].first.second = (int)(lower_bound(values.begin(), values.end(), a[i].first.second) - values.begin()) + 1;
    }
    sort(a, a + n);
    for(int i = 0; i < n; ){
        ans[a[i].second] = get(a[i].first.second);
        add(a[i].first.second, 1);
        int j = i + 1;
        while(j < n && a[i].first == a[j].first){
            ans[a[j].second] = ans[a[i].second];
            add(a[j].first.second, 1);
            ++ j;
        }
        i = j;
    }
    for(int i = 0; i < n; i ++)
        uput(ans[i]);
    
    return 0;
}

