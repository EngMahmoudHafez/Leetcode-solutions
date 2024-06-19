class Solution {

    /**
     * @param Integer[] $bloomDay
     * @param Integer $m
     * @param Integer $k
     * @return Integer
     */
    function minDays($bloomDay, $m, $k) {
        $l = 1;
        $r = 1000000000;
        $ans = -1;
        while ($l <= $r) {
            $mid = $l + floor(($r - $l) / 2);
            $consecutiveLength = 0;
            $bouquets = 0;
            foreach ($bloomDay as $bloom) {
                if ($bloom <= $mid) {
                    $consecutiveLength++;
                    if ($consecutiveLength >= $k) {
                        $consecutiveLength = 0;
                        $bouquets++;
                    }
                } else {
                    $consecutiveLength = 0;
                }
            }
            if ($bouquets >= $m) {
                $ans = $mid;
                $r = $mid - 1;
            } else {
                $l = $mid + 1;
            }
        }
        return $ans;

    }
}