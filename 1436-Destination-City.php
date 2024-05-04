class Solution {

    /**
     * @param String[][] $paths
     * @return String
     */
    function destCity($paths) {
        foreach ($paths as $item ){
            $start[]=$item[0];
            $end[]=$item[1];

            
        }
        // print_r($start );
        print_r(array_diff($end,$start) );
        $dif =array_diff($end,$start);
        return array_shift($dif);
    }
}