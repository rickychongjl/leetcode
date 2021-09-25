// https://leetcode.com/problems/palindrome-number/
/**
 * @param {number} x
 * @return {boolean}
 */
 var isPalindrome = function(x) {
    if(x < 0)
        return false;
    
    let str = x.toString();
    var left = 0;
    var right = str.length -1;
    while(left <= right){
        if(str[left] == str[right]){
            left++;
            right--;
        }else{
            return false;
        }
    }
    return true;
};