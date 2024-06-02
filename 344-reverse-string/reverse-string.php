class Solution {

    /**
     * @param String[] $s
     * @return NULL
     */
    function reverseString(&$s) {
        $l=0;
        $r=count($s)-1;

        while($l<=$r){
            $temp=$s[$r];
            $s[$r]=$s[$l];
            $s[$l]=$temp;
            $l++;
            $r--;
        }
    }
}