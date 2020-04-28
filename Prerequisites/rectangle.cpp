#include<bits/stdc++.h>
using namespace std;
int main(){
    int x1, y1, x2, y2, x3,  y3, x4, y4, area;
    cin>>x1>>y1>>x2>>y2;
    cin>>x3>>y3>>x4>>y4;
    
    int ar1 = (x2-x1)*(y2-y1);
    int ar2 = (x4-x3)*(y4-y3);
    
    int left_intersection = max(x1, x3);
    int right_intersection = min(x2, x4);
    
    int bottom_intersection = max(x1, x3);
    int top_intersection = min(x2, x4);
    
    int intersection_area = (right_intersection-left_intersection)*(top_intersection-bottom_intersection);
    if((right_intersection>left_intersection)||(top_intersection>bottom_intersection)){
     area = ar1 + ar2 -  intersection_area;  
    }
    else
    area = ar1 + ar2;
    
    cout<<area<<endl;
    
    return 0;
}
