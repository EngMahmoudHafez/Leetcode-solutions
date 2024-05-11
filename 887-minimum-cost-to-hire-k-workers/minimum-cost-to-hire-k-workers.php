class Solution {

    /**
     * @param Integer[] $quality
     * @param Integer[] $wage
     * @param Integer $k
     * @return Float
     */
    function mincostToHireWorkers($quality, $wage, $k) {
        $n = count($quality);
        $workers = [];
        
        // Create an array of workers with their wage-to-quality ratio
        for ($i = 0; $i < $n; $i++) {
            $workers[] = [$wage[$i] / $quality[$i], $quality[$i]];
        }
        
        // Sort workers by their wage-to-quality ratio
        usort($workers, function($a, $b) {
            return $a[0] <=> $b[0];
        });
        
        $minCost = PHP_INT_MAX;
        $totalQuality = 0;
        $maxHeap = new SplMaxHeap();
        
        foreach ($workers as $worker) {
            $totalQuality += $worker[1];
            $maxHeap->insert($worker[1]);
            
            if ($maxHeap->count() > $k) {
                $totalQuality -= $maxHeap->extract();
            }
            
            if ($maxHeap->count() === $k) {
                $minCost = min($minCost, $worker[0] * $totalQuality);
            }
        }
        
        return $minCost;
    }
}