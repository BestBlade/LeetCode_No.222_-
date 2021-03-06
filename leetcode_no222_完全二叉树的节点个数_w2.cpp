﻿/* ------------------------------------------------------------------|
给出一个完全二叉树，求出该树的节点个数。

说明：

完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。

示例:

输入:
    1
   / \
  2   3
 / \  /
4  5 6

输出: 6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-complete-tree-nodes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	二分法
*
*	执行用时：40 ms, 在所有 C++ 提交中击败了98.92%的用户
*	内存消耗：30.8 MB, 在所有 C++ 提交中击败了28.90%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isexist(TreeNode* root,int index,int pre_dep) {
    TreeNode* node = root;
    while (pre_dep) {
        int mid = ((1 << pre_dep) >> 1);
        if (index > mid) {
            index -= mid;
            node = node->right;
        }
        else {
            node = node->left;
        }
        pre_dep--;
    }
    return node != nullptr;
}

int getDepth(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int dep = 1;
    while (root->left) {
        dep++;
        root = root->left;
    }
    return dep;
}

int countNodes(TreeNode* root) {
    if (!root) {
        return 0;
    }

    int dep = getDepth(root);
    int pre_dep = dep - 1;

    int start = 1;
    int end = (1 << pre_dep);

    while (start <= end) {
        int mid = start + ((end - start) >> 1);
        if (isexist(root, mid, pre_dep)) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    int res = (1 << pre_dep) - 1 + start - 1;
    return res;
}