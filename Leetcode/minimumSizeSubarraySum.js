var minSubArrayLen = function(target, nums) {
    var minCounter = 1000000000;
    var currCounter = 0;
    var left = 0;
    while(left < nums.length){
        var sum = 0;
        for(var i=left; i<nums.length; i++){
            currCounter++;
            sum = sum + nums[i];
            if(sum >= target && currCounter < minCounter){
                minCounter = currCounter;
                break;
            }
        }
        currCounter = 0;
        left++;
    }
    return minCounter === 1000000000 ? 0 : minCounter;
};
/**
 * @param {number} target
 * @param {number[]} nums
 * @return {number}
 */
var minSubArrayLen = function(target, nums) {
    var minCounter = Number.MAX_SAFE_INTEGER;;
    var currCounter = 0;
    var left = 0;
    var right = 0;
    var sum = 0;

    while(right < nums.length){

        sum += nums[right];
        while(sum >= target){
            currCounter = right - left + 1;
            minCounter = Math.min(currCounter, minCounter);
            sum = sum - nums[left];
            left++;
        }
        currCounter = 0;
        right++;
    }
    return minCounter === Number.MAX_SAFE_INTEGER ? 0 : minCounter;
};
console.log(minSubArrayLen(11,[1,1,1,1,1,1,1,1]));