class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function countSegments($s) {
        $arr = array_filter(explode(" ", $s), 'strlen');
        return count($arr);
    }
}