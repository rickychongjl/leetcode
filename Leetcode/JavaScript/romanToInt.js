// //https://leetcode.com/problems/roman-to-integer/
// /**
//  * @param {string} s
//  * @return {number}
//  */
//  var dict = [];
//  var entry = {symbol: "I", value: 1};
//  var entry1 = {symbol: "V", value: 5};
//  var entry2 = {symbol: "X", value: 10};
//  var entry3 = {symbol: "L", value: 50};
//  var entry4 = {symbol: "C", value: 100};
//  var entry5 = {symbol: "D", value: 500};
//  var entry6 = {symbol: "M", value: 1000};
//  dict.push(entry);
//  dict.push(entry1);
//  dict.push(entry2);
//  dict.push(entry3);
//  dict.push(entry4);
//  dict.push(entry5);
//  dict.push(entry6);
 
// function accessDict(symbol){
//     for(var i=0; i<dict.length; i++){
//         if(dict[i].symbol === symbol){
//             return dict[i].value;
//         }
//     }
// }
// var romanToInt = function(s) {
//     //Read from back to front
//     var totalSum = 0;
//     for(var i=s.length-1 ; i>=0; i--){
//         if(i>0){
//             //Use substractions
//             if((s[i] == "X" || s[i] == "V") && s[i-1] == "I"){
//                 totalSum = totalSum + accessDict(s[i]) - accessDict(s[i-1]) 
//                 i--;
//                 continue;
//             }
//             if((s[i] == "C" || s[i] == "L") && s[i-1] == "X"){
//                 totalSum = totalSum + accessDict(s[i]) - accessDict(s[i-1]) 
//                 i--;
//                 continue;
//             }
//             if((s[i] == "D" || s[i] == "M") && s[i-1] == "C"){
//                 totalSum = totalSum + accessDict(s[i]) - accessDict(s[i-1]) 
//                 i--;
//                 continue;
//             }
//         }
//         totalSum = totalSum + accessDict(s[i]);
//     }
//     return totalSum;
// };
//After optimisation
//https://leetcode.com/problems/roman-to-integer/
var romanToInt = function(s) {
    let dict = {
        I: 1,
        V: 5,
        X: 10,
        L: 50,
        C: 100,
        D: 500,
        M: 1000
    };

    //Read from back to front
    var totalSum = 0;
    for(var i=0 ; i<s.length; i++){
        if(dict[s[i]] < dict[s[i+1]]){
            totalSum = totalSum + dict[s[i+1]] - dict[s[i]];
            i++;
        }else{
            totalSum = totalSum + dict[s[i]];
        }
    }
    console.log(totalSum);
    return totalSum;
};
romanToInt("IV");