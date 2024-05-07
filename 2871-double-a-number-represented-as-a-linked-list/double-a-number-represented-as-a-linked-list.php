/**
 * Definition for a singly-linked list.
 * class ListNode {
 *     public $val = 0;
 *     public $next = null;
 *     function __construct($val = 0, $next = null) {
 *         $this->val = $val;
 *         $this->next = $next;
 *     }
 * }
 */
class Solution {

    /**
     * @param ListNode $head
     * @return ListNode
     */
    function doubleIt($head) {
        $curNode = $head;

        if ($curNode->val > 4) {
            $head = new ListNode(1, $head);
        }

        while ($curNode->next) {
            $curNode->val = ($curNode->val * 2 + ($curNode->next->val > 4)) % 10;
            $curNode = $curNode->next;
        }

         $curNode->val = ($curNode->val * 2) % 10;

        return $head;
    }
}