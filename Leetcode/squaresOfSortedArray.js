/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortedSquares = function(nums) {
    if(nums.length < 0){
        return nums;
    }
    for(var i=0; i<nums.length; i++){
        nums[i] = Math.pow(nums[i], 2);
    }
    for(var i=0; i<nums.length; i++){
        for(var j=i+1; j<nums.length; j++){
            if(nums[j]<nums[i]){
                var temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;  
            }
        }
    }
    return nums;
};