var removeDuplicates = function(nums) {
    if(nums.length <= 1){
        return nums;
    }
    var left = 1;
    for(var i=0; i<nums.length; i++){
        if(i>0 && nums[i] != nums[i-1]){
            nums[left++] = nums[i];
        }
    }
    return left;
};