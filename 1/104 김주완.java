/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    
    private int maxDepth2(TreeNode root, int height) {
        if (root == null) {
            return height;
        } else {
            int h_right, h_left;
            h_right = maxDepth2(root.right, height + 1);
            h_left = maxDepth2(root.left, height + 1);
            return (h_right > h_left) ? h_right : h_left;
        }
    }
    public int maxDepth(TreeNode root) {
        return maxDepth2(root, 0);
    }
}
