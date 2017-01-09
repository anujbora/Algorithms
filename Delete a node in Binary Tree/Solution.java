/**
 * Time Complexity : O(height of the tree)
 */

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode deleteNode(TreeNode root, int key) {
        if (root == null) {
            return null;
        }
        
        if (root.val == key) {
            if (root.left == null) {
                return root.right;
            } else if (root.right == null){
                return root.left;
            } 
            
            int minValue = getMinimum(root.right);
            root.val = minValue;
            root.right = deleteNode(root.right, minValue);
            
        } else if (key > root.val) {
            root.right = deleteNode(root.right, key);
        } else {
            root.left = deleteNode(root.left, key);
        }
        
        return root;
        
    }
    
    private int getMinimum(TreeNode node) {
        while (node.left != null) {
            node = node.left;
        }
        
        return node.val;
    }
}