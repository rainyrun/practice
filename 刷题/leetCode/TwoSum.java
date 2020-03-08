/**
twoSum解题思路：
1. 先把数组排序
2. 把数组扩展成一个和的二维矩阵，和的集合可以看成是一个上三角矩阵，且每行逐渐增大，每列逐渐增大。从右上角开始找起。当和比target小时，行增加1；当和比target大时，列减小1。直到找到和target相等的和。
3. 时间复杂度：排序nlogn, 找数logn
*/
class TwoSum {
    public int[] twoSum(int[] nums, int target) {
        nums.sort();
        int result[2];
        int row = 0;
        int col = nums.length() - 1;
        while(row < col && row < nums.length() && col >= 0){
            if(target == nums[row] + nums[col]){
                break;
            }
            else if(target < nums[row] + nums[col])
                col--;
            else
                row++;
        }
        result[0] = row;
        result[1] = col;
        return result;
    }
}