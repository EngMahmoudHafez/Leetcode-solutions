
class Solution {

    function distributeCoins($root)
    {
        $ans = 0;
        $this->dfs($root, $ans);
        return $ans;
    }

    function dfs($node, &$ans)
    {
        if (is_null($node)) return 0;
        if (is_null($node->left) && is_null($node->right)) return $node->val - 1;
        
        $left = $this->dfs($node->left, $ans);
        $right = $this->dfs($node->right, $ans);
        
        $node->val += $left + $right;
        $ans += abs($left) + abs($right);
        
        return $node->val - 1;
    }
}