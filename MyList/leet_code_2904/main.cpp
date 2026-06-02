#include <math.h>
#include <algorithm>
#include <iostream>
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x,TreeNode *left,TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
public:
	bool isBalanced(TreeNode* root) {
		auto n = TreeHeight(root);
		if (n == -1) return false;
		else true;
	}
	int TreeHeight(TreeNode* root) {
		if (root==nullptr) return 0;
		int leftH = TreeHeight(root->left);
		if (leftH == -1) return -1;
		int rightH = TreeHeight(root->right);
		if (rightH == -1) return -1;
		if (abs(leftH - rightH) > 1) return -1;
		return std::max(leftH, rightH)+1;
		//проверить отладчиком (построить дерево).
	}


};

int* createArr(size_t n) {
	int* arr=new int[n];
	for (size_t i = 0; i < n; i++)
	{
		arr[i] = i;
	}
	return arr;
}

void showArr(int* arr, size_t n) {
	for (size_t i = 0; i < n; i++)
	{
		std::cout << arr[i] << std::endl;
	}
}




int main() {

	TreeNode* myTree = new TreeNode(3,new TreeNode(9),new TreeNode(20, new TreeNode(15), new TreeNode(7,nullptr,new TreeNode(777))));

	Solution mysol;
	int max=mysol.TreeHeight(myTree);

	int* myArr = createArr(10);
	
	showArr(myArr, 10);

	delete[] myArr;


	return 0;
}