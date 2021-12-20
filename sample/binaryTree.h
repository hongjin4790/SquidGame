#pragma once

typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode* search(TreeNode* node, int key);
TreeNode* new_node(int item);
TreeNode* insert_node(TreeNode* node, int key);
TreeNode* delete_node(TreeNode* root, int key);
TreeNode* min_value_node(TreeNode* node);