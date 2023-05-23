#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define int long long
int id_smoreq_than(vector<int> &v, int x){// v has to be sorted 
    if (v.size() == 0) return 0;
    int l = 0, r = v.size()- 1;
    while(l < r){// find the first v[i] s.t. v[i] >= x
        int mm = l + (r - l)/2;
        if(v[mm] > x){
            r = mm;
        }else{
            l = mm+1;
        }
    }
    return l;
}
int total_smoreq_than(vector<int> &v1, vector<int> &v2, int x){
    return id_smoreq_than(v1, x) + id_smoreq_than(v2, x);
}
int get_id(vector<int> &base, vector<int> &comp, int target){
    int len = base.size();
    int l = 0, r = len - 1;
    while(l < r){
        int mm = (l + r)/2;
        if((mm + 1) + id_smoreq_than(comp, base[mm]) < target){
            l = mm+1;
        }else{
            r = mm;
        }// the first >=  target
    }
    return l;
}
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int target = (len1 + len2 + 1)/2;
        //00000011111 , 1 is the first index i in nums1 such that the (index <= num1[i]) + (#num2index < num1[i]) >= target 
        //(the number of indexes in nums 2 < i) >= target;
        int res1 = get_id(nums1, nums2, target);
        int res2 = get_id(nums2, nums1, target);
        if((len1 + len2)%2){
            if(total_smoreq_than(nums1, nums2, nums1[res1]) == target){
                return nums1[res1];
            }else{
                return nums2[res2];
            }
        }else{// identify the real index medium, then find is complementary part to add and mean 
            if(total_smoreq_than(nums1, nums2, nums1[res1]) == target){
                return (nums1[res1]+ min(nums1[res1 + 1], 
                        nums2[id_smoreq_than(nums2, res1) + 1]))/2;
            }else{
                return (nums2[res2] + min(nums2[res2 + 1], 
                        nums1[id_smoreq_than(nums1, nums2[res2]) + 1]))/2;
            }
        }
    }
};
signed main(){

}