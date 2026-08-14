#include <iostream>
#include <queue>      // Used for Level-Order Traversal
#include <algorithm>  // Used for max()

using namespace std;


// ============================================================
// 1. NODE STRUCTURE
// ============================================================

// A node represents one element in our Binary Search Tree.
struct node
{
    int key;           // The value stored inside the node.

    node* left;        // Pointer to the left child.
    node* right;       // Pointer to the right child.
};


// ============================================================
// 2. CREATE A NEW NODE
// ============================================================

node* newNode(int item)
{
    // Allocate memory for a new node.
    node* temp = new node;

    // Store the given value inside the node.
    temp->key = item;

    // A new node does not have children yet.
    temp->left = nullptr;
    temp->right = nullptr;

    // Return the address of the newly created node.
    return temp;
}


// ============================================================
// 3. INORDER TRAVERSAL
// ============================================================
//
// Order:
// LEFT -> ROOT -> RIGHT
//
// For a Binary Search Tree, inorder traversal prints
// the values in SORTED ORDER.
//
// Example:
//
//        4
//       / \
//      2   6
//
// Inorder:
// 2 -> 4 -> 6
// ============================================================

void inorder(node* root)
{
    // If root is NULL, there is nothing to visit.
    if (root == nullptr)
    {
        return;
    }

    // First visit the left subtree.
    inorder(root->left);

    // Then visit the current node.
    cout << root->key << " -> ";

    // Finally visit the right subtree.
    inorder(root->right);
}


// ============================================================
// 4. PREORDER TRAVERSAL
// ============================================================
//
// Order:
// ROOT -> LEFT -> RIGHT
//
// Example:
//
//        4
//       / \
//      2   6
//
// Preorder:
// 4 -> 2 -> 6
// ============================================================

void preorder(node* root)
{
    // Stop when there is no node.
    if (root == nullptr)
    {
        return;
    }

    // Visit the root first.
    cout << root->key << " -> ";

    // Then visit the left subtree.
    preorder(root->left);

    // Finally visit the right subtree.
    preorder(root->right);
}


// ============================================================
// 5. POSTORDER TRAVERSAL
// ============================================================
//
// Order:
// LEFT -> RIGHT -> ROOT
//
// Example:
//
//        4
//       / \
//      2   6
//
// Postorder:
// 2 -> 6 -> 4
// ============================================================

void postorder(node* root)
{
    // Stop when there is no node.
    if (root == nullptr)
    {
        return;
    }

    // Visit the left subtree.
    postorder(root->left);

    // Visit the right subtree.
    postorder(root->right);

    // Visit the root last.
    cout << root->key << " -> ";
}


// ============================================================
// 6. LEVEL-ORDER TRAVERSAL
// ============================================================
//
// Level-order traversal visits nodes level by level.
//
// Example:
//
//        4
//       / \
//      2   6
//     / \ / \
//    1  3 5  7
//
// Output:
// 4 -> 2 -> 6 -> 1 -> 3 -> 5 -> 7
//
// We use a QUEUE because this is basically BFS.
// ============================================================

void levelOrder(node* root)
{
    // If the tree is empty, there is nothing to print.
    if (root == nullptr)
    {
        return;
    }

    // Create a queue that stores node pointers.
    queue<node*> q;

    // Put the root into the queue.
    q.push(root);

    // Continue while the queue is not empty.
    while (!q.empty())
    {
        // Get the node at the front of the queue.
        node* current = q.front();

        // Remove it from the queue.
        q.pop();

        // Print the current node.
        cout << current->key << " -> ";

        // If the node has a left child,
        // add it to the queue.
        if (current->left != nullptr)
        {
            q.push(current->left);
        }

        // If the node has a right child,
        // add it to the queue.
        if (current->right != nullptr)
        {
            q.push(current->right);
        }
    }
}


// ============================================================
// 7. COUNT ALL NODES
// ============================================================
//
// Example:
//
//        4
//       / \
//      2   6
//
// Number of nodes = 3
//
// Recursive idea:
//
// count = 1 + left subtree count + right subtree count
// ============================================================

int countNodes(node* root)
{
    // An empty tree contains 0 nodes.
    if (root == nullptr)
    {
        return 0;
    }

    // Count the current node: 1
    // Then recursively count the left subtree.
    // Then recursively count the right subtree.
    return 1 + countNodes(root->left) + countNodes(root->right);
}


// ============================================================
// 8. COUNT LEAF NODES
// ============================================================
//
// A leaf is a node that has NO children.
//
// Example:
//
//        4
//       / \
//      2   6
//     / \
//    1   3
//
// Leaves = 1, 3, 6
// Number of leaves = 3
// ============================================================

int countLeaves(node* root)
{
    // Empty tree has zero leaves.
    if (root == nullptr)
    {
        return 0;
    }

    // If both children are NULL,
    // this node is a leaf.
    if (root->left == nullptr && root->right == nullptr)
    {
        return 1;
    }

    // Otherwise, count leaves in both subtrees.
    return countLeaves(root->left) + countLeaves(root->right);
}


// ============================================================
// 9. FIND MINIMUM VALUE NODE
// ============================================================
//
// In a BST:
//
// Smaller values are on the LEFT.
//
// Therefore, the minimum value is the
// LEFTMOST node.
//
// Example:
//
//        5
//       /
//      3
//     /
//    1
//
// Minimum = 1
// ============================================================

node* minValueNode(node* root)
{
    // Start from the given root.
    node* current = root;

    // Continue moving left while a left child exists.
    while (current != nullptr && current->left != nullptr)
    {
        current = current->left;
    }

    // Return the leftmost node.
    return current;
}


// ============================================================
// 10. FIND MAXIMUM VALUE NODE
// ============================================================
//
// In a BST:
//
// Larger values are on the RIGHT.
//
// Therefore, the maximum value is the
// RIGHTMOST node.
// ============================================================

node* maxValueNode(node* root)
{
    // Start from the given root.
    node* current = root;

    // Continue moving right while a right child exists.
    while (current != nullptr && current->right != nullptr)
    {
        current = current->right;
    }

    // Return the rightmost node.
    return current;
}


// ============================================================
// 11. INSERT A NODE
// ============================================================
//
// BST rule:
//
// If key < root->key
//     go LEFT
//
// If key > root->key
//     go RIGHT
//
// If the current position is empty,
// create a new node there.
// ============================================================

node* insert(node* root, int key)
{
    // If the tree/subtree is empty,
    // create a new node here.
    if (root == nullptr)
    {
        return newNode(key);
    }

    // If the new key is smaller,
    // insert it into the left subtree.
    if (key < root->key)
    {
        root->left = insert(root->left, key);
    }

    // If the new key is larger,
    // insert it into the right subtree.
    else if (key > root->key)
    {
        root->right = insert(root->right, key);
    }

    // If key == root->key,
    // we don't insert duplicates.
    else
    {
        cout << "Duplicate value " << key
             << " was not inserted.\n";
    }

    // Return the root of the tree/subtree.
    return root;
}


// ============================================================
// 12. SEARCH FOR A VALUE
// ============================================================
//
// BST search is efficient because at every step
// we can eliminate half of the possible direction.
//
// If:
//
// key < root->key -> search LEFT
//
// key > root->key -> search RIGHT
//
// key == root->key -> FOUND
// ============================================================

node* search(node* root, int key)
{
    // If the tree is empty,
    // the value cannot be found.
    if (root == nullptr)
    {
        return nullptr;
    }

    // If we found the value,
    // return this node.
    if (root->key == key)
    {
        return root;
    }

    // If key is smaller,
    // search in the left subtree.
    if (key < root->key)
    {
        return search(root->left, key);
    }

    // Otherwise, search in the right subtree.
    return search(root->right, key);
}


// ============================================================
// 13. DELETE A NODE
// ============================================================
//
// There are 3 cases:
//
// CASE 1:
// Node has NO children.
//
// CASE 2:
// Node has ONE child.
//
// CASE 3:
// Node has TWO children.
//
// For two children, we use the
// INORDER SUCCESSOR.
//
// The inorder successor is the smallest
// value in the right subtree.
// ============================================================

node* deleteNode(node* root, int key)
{
    // If the tree is empty,
    // there is nothing to delete.
    if (root == nullptr)
    {
        return nullptr;
    }

    // If the key is smaller than the root,
    // search in the left subtree.
    if (key < root->key)
    {
        root->left = deleteNode(root->left, key);
    }

    // If the key is larger than the root,
    // search in the right subtree.
    else if (key > root->key)
    {
        root->right = deleteNode(root->right, key);
    }

    // Otherwise, we found the node.
    else
    {
        // ----------------------------------------------------
        // CASE 1 & CASE 2:
        // Node has zero or one child.
        // ----------------------------------------------------

        // If there is no left child,
        // the right child replaces this node.
        if (root->left == nullptr)
        {
            node* temp = root->right;

            // Free the memory of the current node.
            delete root;

            // Return the right child.
            return temp;
        }

        // If there is no right child,
        // the left child replaces this node.
        else if (root->right == nullptr)
        {
            node* temp = root->left;

            // Free the memory of the current node.
            delete root;

            // Return the left child.
            return temp;
        }

        // ----------------------------------------------------
        // CASE 3:
        // Node has TWO children.
        // ----------------------------------------------------

        // Find the smallest node in the right subtree.
        node* temp = minValueNode(root->right);

        // Copy the successor's value into the current node.
        root->key = temp->key;

        // Delete the duplicate successor node
        // from the right subtree.
        root->right = deleteNode(root->right, temp->key);
    }

    // Return the root of the modified tree.
    return root;
}


// ============================================================
// 14. CALCULATE TREE HEIGHT
// ============================================================
//
// Height tells us how deep the tree is.
//
// Example:
//
//        4          Level 1
//       / \
//      2   6        Level 2
//     / \
//    1   3          Level 3
//
// If using "number of levels":
// Height = 3
//
// If using "number of edges":
// Height = 2
//
// Here we use NUMBER OF LEVELS.
// ============================================================

int height(node* root)
{
    // Empty tree has height 0.
    if (root == nullptr)
    {
        return 0;
    }

    // Calculate height of left subtree.
    int leftHeight = height(root->left);

    // Calculate height of right subtree.
    int rightHeight = height(root->right);

    // The height is 1 for the current node
    // plus the larger subtree height.
    return 1 + max(leftHeight, rightHeight);
}


// ============================================================
// 15. CHECK IF A TREE IS A VALID BST
// ============================================================
//
// We use a range:
//
// Every node in the left subtree must be smaller
// than the current node.
//
// Every node in the right subtree must be larger
// than the current node.
// ============================================================

bool isBSTUtil(node* root, long long minValue, long long maxValue)
{
    // An empty tree is a valid BST.
    if (root == nullptr)
    {
        return true;
    }

    // Check whether the current value
    // is inside the allowed range.
    if (root->key <= minValue || root->key >= maxValue)
    {
        return false;
    }

    // Check the left subtree.
    // Its values must be smaller than root->key.
    bool leftValid =
        isBSTUtil(root->left, minValue, root->key);

    // Check the right subtree.
    // Its values must be larger than root->key.
    bool rightValid =
        isBSTUtil(root->right, root->key, maxValue);

    // The entire tree is valid only if
    // both subtrees are valid.
    return leftValid && rightValid;
}


// This is the function we call from main().
bool isBST(node* root)
{
    // Start with the largest possible range.
    return isBSTUtil(
        root,
        LLONG_MIN,
        LLONG_MAX
    );
}


// ============================================================
// 16. DELETE THE ENTIRE TREE
// ============================================================
//
// This function prevents memory leaks.
//
// We use POSTORDER:
//
// LEFT -> RIGHT -> ROOT
//
// Why?
//
// We should delete children before deleting
// their parent.
// ============================================================

void destroyTree(node* root)
{
    // If there is nothing to delete, stop.
    if (root == nullptr)
    {
        return;
    }

    // Delete left subtree.
    destroyTree(root->left);

    // Delete right subtree.
    destroyTree(root->right);

    // Delete the current node.
    delete root;
}


// ============================================================
// MAIN FUNCTION
// ============================================================

int main()
{
    // Start with an empty tree.
    node* root = nullptr;


    // ========================================================
    // INSERT VALUES
    // ========================================================

    // We intentionally use these values instead of
    // 1,2,3,4,5,6,7,8 because inserting sorted values
    // creates a badly unbalanced tree.
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 5);
    root = insert(root, 7);


    // Tree:
//
//          4
//        /   \
//       2     6
//      / \   / \
//     1   3 5   7


    // ========================================================
    // TRAVERSALS
    // ========================================================

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    cout << "Level-Order Traversal: ";
    levelOrder(root);
    cout << endl;


    // ========================================================
    // COUNT NODES
    // ========================================================

    cout << "\nNumber of nodes: "
         << countNodes(root)
         << endl;


    // ========================================================
    // COUNT LEAVES
    // ========================================================

    cout << "Number of leaves: "
         << countLeaves(root)
         << endl;


    // ========================================================
    // MINIMUM
    // ========================================================

    node* minNode = minValueNode(root);

    if (minNode != nullptr)
    {
        cout << "Minimum value: "
             << minNode->key
             << endl;
    }


    // ========================================================
    // MAXIMUM
    // ========================================================

    node* maxNode = maxValueNode(root);

    if (maxNode != nullptr)
    {
        cout << "Maximum value: "
             << maxNode->key
             << endl;
    }


    // ========================================================
    // SEARCH
    // ========================================================

    int searchKey = 5;

    node* result = search(root, searchKey);

    if (result != nullptr)
    {
        cout << "Search " << searchKey
             << ": FOUND"
             << endl;
    }
    else
    {
        cout << "Search " << searchKey
             << ": NOT FOUND"
             << endl;
    }


    // Try searching for a value that doesn't exist.
    searchKey = 10;

    result = search(root, searchKey);

    if (result != nullptr)
    {
        cout << "Search " << searchKey
             << ": FOUND"
             << endl;
    }
    else
    {
        cout << "Search " << searchKey
             << ": NOT FOUND"
             << endl;
    }


    // ========================================================
    // HEIGHT
    // ========================================================

    cout << "Tree height: "
         << height(root)
         << endl;


    // ========================================================
    // CHECK IF IT IS A BST
    // ========================================================

    if (isBST(root))
    {
        cout << "The tree is a valid BST."
             << endl;
    }
    else
    {
        cout << "The tree is NOT a valid BST."
             << endl;
    }


    // ========================================================
    // DELETE A NODE
    // ========================================================

    cout << "\nDeleting node 6...\n";

    root = deleteNode(root, 6);

    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;


    // ========================================================
    // DISPLAY TREE AFTER DELETION
    // ========================================================

    cout << "Level-order after deletion: ";
    levelOrder(root);
    cout << endl;


    // ========================================================
    // DESTROY ENTIRE TREE
    // ========================================================
    //
    // Free all dynamically allocated memory before
    // the program terminates.
    // ========================================================

    destroyTree(root);

    // Set root to nullptr because the tree no longer exists.
    root = nullptr;


    // Program finished successfully.
    return 0;
}