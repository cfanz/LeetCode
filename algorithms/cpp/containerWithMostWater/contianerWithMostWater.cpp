/*
 * Description:
 * Given n non-negative integers a1, a2, ..., an, where each
 * represents a point at coordinate (i, ai). n vertical lines 
 * are drawn such that the two endpoints of line i is at (i, ai) 
 * and (i, 0). Find two lines, which together with x-axis forms a container, 
 * such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int start = 0;
        int end   = len -1;
        int max_area = min(height[start],height[end])*(end - start);
        while(start < end-1){
            if(height[start] > height[end])
                end--;
            else
                start++;
            
            max_area = max(max_area,min(height[start],height[end])*(end-start)) ;
        }
        return max_area;
    }
};
/*
 * After hours thinking, I finally turn to 'the solution'.
 * When saw "two pointers at the begin and end", I thought maybe
 * I have known the answer that just move pointers from outside to
 * inside. If area(++start,end)>currentMax or area(start,--end)>max,
 * move the pointer. But this failed with the case '2,3,4,5,17,18,6',
 * because the pointer stop move further. Yes, it does know that the
 * optimal solution must exist in that range, but it can not figure out.
 * 
 * That's all. I did not find the right strategy for moving pointers, frustrating...
