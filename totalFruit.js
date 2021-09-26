/**
 * @param {number[]} fruits
 * @return {number}
 */
var totalFruit = function(fruits) {
    fruits = fruits.sort();
    var basket1 = -1;
    var basket2 = -1;
    var left = 0;
    var right = 0;
    var currFruit = fruits[0];
    var basket1Fruit = 0;
    var basket2Fruit = 0;
    while(right < fruits.length){
        if(fruits[right] != currFruit){
            if(right-left > basket1){
                basket1 = right-left;
                basket1Fruit = fruits[left];
            }
            left = right;
            currFruit = fruits[left];
        }
        right++;
    }
    left = 0;
    right = 0;
    currFruit = fruits[0];
    while(right < fruits.length){
        if(fruits[right] != currFruit && fruits[right] != basket1Fruit){
            if(right-left > basket2){
                basket2 = right-left;
                basket2Fruit = fruits[left];
            }
            left = right;
            currFruit = fruits[left];
        }
        right++;
    }
    return basket1 + basket2;
};
console.log(totalFruit([1,2,1]));