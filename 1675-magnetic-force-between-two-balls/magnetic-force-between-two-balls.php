class Solution {

    /**
     * @param Integer[] $position
     * @param Integer $m
     * @return Integer
     */
    function maxDistance(array $position, int $m): int
    {
        sort($position);
        $lo = 1;
        $hi = (end($position) - reset($position)) / ($m - 1); 
        $ans = 1;

        while ($lo <= $hi) {
            $mid = $lo + floor(($hi - $lo) / 2); 

            if ($this->canWePlace($position, $mid, $m)) {
                $ans = $mid;
                $lo = $mid + 1;
            } else {
                $hi = $mid - 1;
            }
        }

        return $ans;
    }

    function canWePlace(array $arr, int $dist, int $cows): bool
    {
        $cntCows = 1;
        $last = $arr[0];

        foreach ($arr as $i => $current) {
            if ($current - $last >= $dist) {
                $cntCows++;
                $last = $current;
            }
            if ($cntCows >= $cows) {
                return true;
            }
        }

        return false;
    }

}