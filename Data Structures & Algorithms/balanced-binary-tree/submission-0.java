/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    private boolean isBalancedVar = true;
    public boolean isBalanced(TreeNode root) {
        height(root);
        return isBalancedVar;
    }

    public int height(TreeNode root) {
      if(root == null) return 0;

      int left = 1 + height(root.left);
      int right = 1 + height(root.right);

      if(Math.abs(left - right) > 1){
        isBalancedVar = false;
      }

      return Math.max(left, right);
    }
}
