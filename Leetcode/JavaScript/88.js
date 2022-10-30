/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
    
    //base cases
    if (m === 0){
        for(var k=0; k<nums2.length; k++){
            nums1[k] = nums2[k]; 
        }
    }else{
        if (n > 0){
            for(var i=0; i<n; i++){//nms2
                for(var j=0; j<m; j++){//nums1
                    if (nums2[i] > nums1[j]){
                        continue;
                    }else{
                        let temp = nums1[j];
                        nums1[j] = nums2[i];
                        nums2[i] = temp;
                    }
                }
            }
            let point=0;
            nums2 = nums2.sort((a, b) => a-b);
            for(var k = m; k<m+n; k++){
                nums1[k] = nums2[point];
                point++;
            }
        }
    }
    console.log(nums1);
};

merge([-10,-10,-9,-9,-9,-8,-8,-7,-7,-7,-6,-6,-6,-6,-6,-6,-6,-5,-5,-5,-4,-4,-4,-3,-3,-2,-2,-1,-1,0,1,1,1,2,2,2,3,3,3,4,5,5,6,6,6,6,7,7,7,7,8,9,9,9,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
    ,55
    ,[-10,-10,-9,-9,-9,-9,-8,-8,-8,-8,-8,-7,-7,-7,-7,-7,-7,-7,-7,-6,-6,-6,-6,-5,-5,-5,-5,-5,-4,-4,-4,-4,-4,-3,-3,-3,-2,-2,-2,-2,-2,-2,-2,-1,-1,-1,0,0,0,0,0,1,1,1,2,2,2,2,2,2,2,2,3,3,3,3,4,4,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,7,7,7,7,7,7,7,8,8,8,8,9,9,9,9]
    ,99)