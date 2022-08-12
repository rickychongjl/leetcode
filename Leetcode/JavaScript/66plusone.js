/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    if (digits[digits.length - 1] < 9) {
        digits[digits.length - 1] += 1;
        return digits;
    }
    let carry = 0;
    let reachStart = false;
    for (var i = digits.length-1; i >=0 ; i--) {
        let toAdd = carry > 0 ? carry : 1;
        if (digits[i] + toAdd > 9){
            digits[i] = 0;
            carry = 1;
            if (i==0)reachStart = true;
        }else{
            digits[i] += carry;
            break;
        }
    }
    let ret = digits;
    if (reachStart) {
        ret = digits.slice();
        ret.unshift(1);
    }
    return ret;
};

// plusOne([1,2,3]);
// plusOne([4, 3, 2, 1]);
// plusOne([9]);
plusOne([6, 1, 4, 5, 3, 9, 0, 1, 9, 5, 1, 8, 6, 7, 0, 5, 5, 4, 3]);
plusOne([5, 2, 2, 6, 5, 7, 1, 9, 0, 3, 8, 6, 8, 6, 5, 2, 1, 8, 7, 9, 8, 3, 8, 4, 7, 2, 5, 8, 9]);
plusOne([9]);