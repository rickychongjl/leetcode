// /**
//  * @param {string[]} strs
//  * @return {string}
//  */
//  var longestCommonPrefix = function(strs) {
//     if(strs.length <= 0)
//         return "";
    
//     var prefix = "";
//     for(var i=0; i<strs[0].length; i++){
//         for(var j=1; j<strs.length; j++){
//             if(strs[j][i] !== strs[0][i]){
//                 return strs[0].slice(0, i);
//             }
//         }
//     }
//     return strs[0];
// };
//Optimised mem usuage
// https://leetcode.com/problems/longest-common-prefix/submissions/
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    if(strs.length <= 0)
        return "";

    var prefix = strs[0];
    var xx = strs.reduce((previousValue, currentValue) => {
        var i = 0;
        while(i<previousValue.length && i<currentValue.length && previousValue[i] === currentValue[i]){
            i++;
        }
        return previousValue.slice(0, i);
    }, prefix);
    return xx;
};