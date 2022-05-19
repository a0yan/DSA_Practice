class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
     for(int i=0;i<n;i++) {
         int val=abs(nums[i])-1;
         if(nums[val]<0){
             return val+1;
         }
         else{
             nums[val]=-nums[val];
         }
     }
        return 0;
    }
};
------------------Without Modifying Array------------------
------------------Cycle Detection Algorithm--------------------------
 int findDuplicate(vector < int > & nums) {
  int slow = nums[0];
  int fast = nums[0];
  do {
    slow = nums[slow];
    fast = nums[nums[fast]];
  } while (slow != fast);
  fast = nums[0];
  while (slow != fast) {
    slow = nums[slow];
    fast = nums[fast];
  }
  return slow;
}
