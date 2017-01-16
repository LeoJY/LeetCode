//297. Serialize and Deserialize Binary Tree
//Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
//Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

//Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "#";
        return to_string(root -> val) + "," + serialize(root -> left) + "," + serialize(root -> right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    	if (data == "#") return NULL;
    	stringstream cinstr(data);
    	return makeTree(cinstr);
    }
private:
	TreeNode* makeTree(stringstream& cinstr){
		string temp;
		getline(cinstr, temp, ',');
		if (temp == "#") return NULL;
		TreeNode* root = new TreeNode(stoi(temp));
		root -> left = makeTree(cinstr);
		root -> right = makeTree(cinstr);
		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
