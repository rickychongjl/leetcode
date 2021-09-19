nums = [2, 7, 11, 15];
target = 9;
// https://leetcode.com/problems/two-sum/
sum = [];
var twoSum = function (nums, target) {
    for (var i = 0; i < nums.length; i++) {
        for(var j=i+1; j<nums.length; j++){
            if(nums[i]+nums[j] == target){
                sum.push(i);
                sum.push(j);
                return sum;
            }
        }
    }
};
twoSum(nums, target);