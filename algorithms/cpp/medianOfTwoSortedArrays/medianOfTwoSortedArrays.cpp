/*
 * offical solution is more brief with some mathmatic trick
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int len1=nums1.size();
    int len2=nums2.size();
    int total = 0;
    int i=0,j=0;
    if(len1 == 0) {
        if(len2 % 2 == 0)
            return double(nums2[len2/2-1]+nums2[len2/2])/2;
        else
            return nums2[len2/2];
    } else if(len2 == 0){
        if(len1 % 2 == 0)
            return double(nums1[len1/2-1]+nums1[len1/2])/2;
        else
            return nums1[len1/2];
    }
    if((len1+len2)%2 == 0){
        while(total<(len1+len2)/2 - 1){
            if(nums1[i]<nums2[j])
                if(i<len1-1)
                    i++;
                else
                    //only nums2 remain
                    return (double)(nums2[(len1+len2)/2 -i-2]+nums2[(len1+len2)/2-i-1])/2;
            else
                if(j<len2-1)
                    j++;
                else
                    //only nums1 remain
                    return (double)(nums1[(len1+len2)/2 -j-2] + nums1[(len1+len2)/2-j-1])/2;
            total++;
        }
        int m1,m2;
        if(nums1[i]<nums2[j]){
            m1 = nums1[i];
            cout<<"get m1:"<<m1<<",i="<<i<<endl;
            if(i<len1-1)
                i++;
            else
                return (double)(m1+nums2[j])/2;
        }else{
            m1 = nums2[j];
            cout<<"get m1:"<<m1<<",j="<<j<<endl;
            if(j<len2-1)
                j++;
            else
                return (double)(m1+nums1[i])/2;
        }
        if(nums1[i]<nums2[j]){
            return (double)(m1+nums1[i])/2;
        }else{
            return (double)(m1+nums2[j])/2;
        }
        cout<<"m1:"<<m1<<" ,m2:"<<m2<<endl;
        return (double)(m1+m2)/2;
    } else {
            while(total<(len1+len2)/2){
            if(nums1[i]<nums2[j])
                if(i<len1-1)
                    i++;
                else
                    //only nums2
                    return nums2[(len1+len2)/2-i-1];
            else
                if(j<len2-1)
                    j++;
                else
                    //only nums1
                    return nums1[(len1+len2)/2-j-1];
            total++;
        }
        cout<<"i="<<i<<",j="<<j<<endl;
        cout<<"1="<<nums1[i]<<",2="<<nums2[j]<<endl;
        if(nums1[i]<nums2[j])
            return nums1[i];
        else
            return nums2[j];
    }
    }
};
