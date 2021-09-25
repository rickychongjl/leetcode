
/**
 * @param {number} x
 * @return {number}
 */
 var reverse = function(x) {
    var str = Math.abs(x).toString().split('').reverse().join('');
    if(str > Math.pow(2, 31)){
        return 0;
    }
    return x < 0 ? '-' + str : str;
};
console.log(reverse(1563847412));