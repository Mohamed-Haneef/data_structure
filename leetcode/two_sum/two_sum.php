class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        for($i=0; $i<sizeof($nums); $i++){
            for($j=$i+1; $j<sizeof($nums); $j++){
                if($nums[$i] + $nums[$j] == $target){
                    $result[0] = $i;
                    $result[1] = $j;
                    return $result;
                }
            }
        }
    }
}
