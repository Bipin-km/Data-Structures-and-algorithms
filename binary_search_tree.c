#include <stdio.h>
#include <stdlib.h>

struct BinaryTreeNode
{
    int data;
    struct BinaryTreeNode *left, *right;
};

// Function to create a newNode/root with a given value
struct BinaryTreeNode *newNode(int value)
{
    struct BinaryTreeNode *temp = (struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a node with specific value in the tree
struct BinaryTreeNode *insert(struct BinaryTreeNode *root, int a)
{
    if (root == NULL)
    {
        return newNode(a);
    }
    if (a < root->data)
    {
        root->left = insert(root->left, a);
    }
    if (a > root->data)
    {
        root->right = insert(root->right, a);
    }
    return root;
}

// function to find the minimum value
struct BinaryTreeNode *findMin(struct BinaryTreeNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->left != NULL)
    {
        return findMin(root->left);
    }
    return root;
}
// function to find the maximum value
struct BinaryTreeNode *findMax(struct BinaryTreeNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->right != NULL)
    {
        return findMax(root->right);
    }
    return root;
}

// function to delete node from the tree

struct BinaryTreeNode *delete(struct BinaryTreeNode *root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (x < root->data)
    {
        root->left = delete (root->left, x);
    }
    else if (x > root->data)
    {
        root->right = delete (root->right, x);
    }
    else
    {
        if (root->left == NULL)
        {
            struct BinaryTreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct BinaryTreeNode *temp = root->left;
            free(root);
            return temp;
        }

        struct BinaryTreeNode *temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete (root->right, temp->data);
    }
    return root;
}
// function to search for a node with specific key
struct BinaryTreeNode *search(struct BinaryTreeNode *root, int n)
{
    if (root == NULL || root->data == n)
    {
        return root;
    }
    if (n < (root->data))
    {
        return search(root->left, n);
    }
    return search(root->right, n);
}
// function to perform in-order traversal
void inOrder(struct BinaryTreeNode *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// function to perform pre-order traversal
void preOrder(struct BinaryTreeNode *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// function to perform postorder traversal
void postOrder(struct BinaryTreeNode *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}
void displayMenu()
{
    printf("1. Insert node\n");
    printf("2. Delete node\n");
    printf("3. Search\n");
    printf("4. Find minimum value\n");
    printf("5. Find maximum value\n");
    printf("6. Inorder Traversal\n");
    printf("7. Preorder Traversal\n");
    printf("8. Postorder Traversal\n");
    printf("9. Exit\n");
}

int main(void)
{
    struct BinaryTreeNode *root = NULL;
    int choice, value;

    while (1)
    {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 2:
            printf("Enter the value: ");
            scanf("%d", &value);
            root = delete (root, value);
            break;
        case 3:
            printf("Enter the value to search: ");
            scanf("%d", &value);
            if (search(root, value) != NULL)
            {
                printf("%d found.\n", value);
            }
            else
            {
                printf("%d not found.\n", value);
            }
            break;
        case 4:
            if (root != NULL)
            {
                struct BinaryTreeNode *minNode = findMin(root);
                printf("Min value: %d\n", minNode->data);
            }
            else
            {
                printf("BST is empty.\n");
            }
            break;
        case 5:
            if (root != NULL)
            {
                struct BinaryTreeNode *maxNode = findMax(root);
                printf("Max value: %d\n", maxNode->data);
            }
            else
            {
                printf("BST is empty.\n");
            }
            break;
        case 6:
            inOrder(root);
            printf("\n");
            break;
        case 7:
            preOrder(root);
            printf("\n");
            break;
        case 8:
            postOrder(root);
            printf("\n");
            break;
        case 9:
            printf("Exiting...\n");
            exit(0);
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    };
    return 0;
}