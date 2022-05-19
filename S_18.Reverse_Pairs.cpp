class Solution {
public:
    
    long long merge(vector<int> &arr , int left , int mid , int right , int temp[]){
        // here mid = mid + 1(we passed mid + 1 when we were calling merge function)
        int i = left , j = mid , k = left;
        long long inv = 0 ;
        
        // counting number of inversions alag se while doing merge
		//because we were not able to merge the elements in sorted 
		//oreder with the given condition arr[i] > 2*arr[j] unlike the counting inversion question
		//on geeks in which the conditon was arr[i] > arr[j]. and we were able to merge and count inversions simoultaniously(EK SATH)
        
        while(i < mid && j <=right ){
            if((long long)arr[i] > 2*(long long)arr[j]){
                inv += mid - i;
                j++;
            }
            else 
                i++;
        }
        
        i = left ; j = mid;
        
		// merging and storing in temp array
        while(i < mid && j <= right){
            if(arr[i] <= arr[j])
                temp[k++] = arr[i++];
            else
                temp[k++] = arr[j++];
        }
        
        while(i < mid)
            temp[k++] = arr[i++];
        
        while(j <= right)
            temp[k++] = arr[j++];
        
		//storing in the main array(NUMS array) 
        for(; left <= right ; left++)
            arr[left] = temp[left];
        
        return inv;
    }
    
   int solve(vector<int> &arr , int left , int right ,int temp[]){
        if(left == right)
            return 0;
        
       long long inv  = 0;
        int mid = left + (right - left)/2;
        
        inv+=solve(arr , left , mid , temp);        // left part inversion count 
        inv+=solve(arr , mid + 1 , right , temp);   // right part inversion count
        inv+=merge(arr , left , mid + 1 , right , temp);    
        
        return inv;
    }

long long reversePairs(vector<int>& nums)
{
    int n = nums.size();
   if(n == 0 )
        return 0;
    
    int temp[n];
   
    return solve(nums , 0 , n - 1 , temp);
    
    // if we print the nums array after calling the solve function then our nums array will be sorted as we are using merge sort to find the inversion count (in this case the condition is nums[i] > 2*nums[j])
    
    }
};
