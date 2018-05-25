#include<stdio.h>
#include<stdlib.h>

FILE* fp ;
FILE* ofp ;

struct node {
    int key;
    struct node *left, *right;
};

// A utility function to create a new BST node
struct node *newNode(int item) {
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key) {
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

/* Given a non-empty binary search tree, return the node with minimum
   key value found in that tree. Note that the entire tree does not
   need to be searched. */
struct node * minValueNode(struct node* node)
{
    struct node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

/* Given a binary search tree and a key, this function deletes the key
   and returns the new root */
struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL) return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);

        // If the key to be deleted is greater than the root's key,
        // then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

        // if key is same as root's key, then This is the node
        // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

/* Given a binary tree, print its nodes according to the
  "bottom-up" postorder traversal. */
void printPostorder(struct node* node) {
    if (node == NULL)
        return;

    // first recur on left subtree
    printPostorder(node->left);

    // then recur on right subtree
    printPostorder(node->right);

    // now deal with the node
    fprintf(ofp,"%d ", node->key);
}

/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct node* node) {
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    fprintf(ofp,"%d ", node->key);

    /* now recur on right child */
    printInorder(node->right);
}

/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct node* node) {
    if (node == NULL)
        return;

    /* first print data of node */
    fprintf(ofp,"%d ", node->key);

    /* then recur on left sutree */
    printPreorder(node->left);

    /* now recur on right subtree */
    printPreorder(node->right);
}

// A utility function to do inorder traversal of BST
void inorder(struct node *root) {
    if (root != NULL)
    {
        inorder(root->left);
        fprintf(ofp,"%d ", root->key);
        inorder(root->right);
    }
}

// Maximum stack size
#define MAX_SIZE 100

// Stack type
struct Stack
{
    int size;
    int top;
    struct node* *array;
};

// A utility function to create a stack of given size
struct Stack* createStack(int size)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (struct node**) malloc(stack->size * sizeof(struct node*));
    return stack;
}

// BASIC OPERATIONS OF STACK
int isFull(struct Stack* stack)
{  return stack->top - 1 == stack->size; }

int isEmpty(struct Stack* stack)
{  return stack->top == -1; }

void push(struct Stack* stack, struct node* inode)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = inode;
}

struct node* pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}

struct node* peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top];
}

// An iterative process to print preorder traversal of Binary tree
void inOrderIterative(struct node *root)
{
    // Base Case
    if (root == NULL)
        return;
    // Create an empty stack and push root to it
    struct Stack* stack = createStack(MAX_SIZE);
    struct node *current = root;
    int done = 0;
    while (!done)
    {
        /* Reach the left most tNode of the current tNode */
        if(current !=  NULL)
        {
            /* place pointer to a tree node on the stack before traversing
              the node's left subtree */
            push(stack, current);
            current = current->left;
        }
        else
        {
            if (!isEmpty(stack))
            {
                current = pop(stack);
                fprintf(ofp, "%d ", current->key);
                /* we have visited the node and its left subtree.
                  Now, it's right subtree's turn */
                current = current->right;
            }
            else
                done = 1;
        }
    } /* end of while */
}

// An iterative process to print preorder traversal of Binary tree
void preOrderIterative(struct node *root)
{
    // Base Case
    if (root == NULL)
        return;
    // Create an empty stack and push root to it
    struct Stack* stack = createStack(MAX_SIZE);
    push(stack, root);

    /* Pop all items one by one. Do following for every popped item
       a) print it
       b) push its right child
       c) push its left child
    Note that right child is pushed first so that left is processed first */
    while (!isEmpty(stack))
    {
        // Pop the top item from stack and print it
        struct node *node = pop(stack);
        fprintf (ofp,"%d ", node->key);

        // Push right and left children of the popped node to stack
        if (node->right)
            push(stack,node->right);
        if (node->left)
            push(stack,node->left);
    }
}

// An iterative function to do postorder traversal of a given binary tree
void postOrderIterative(struct node* root)
{
    // Check for empty tree
    if (root == NULL)
        return;
    struct Stack* stack = createStack(MAX_SIZE);
    do
    {
        // Move to leftmost node
        while (root)
        {
            // Push root's right child and then root to stack.
            if (root->right)
                push(stack, root->right);
            push(stack, root);
            // Set root as root's left child
            root = root->left;
        }

        // Pop an item from stack and set it as root
        root = pop(stack);

        // If the popped item has a right child and the right child is not
        // processed yet, then make sure right child is processed before root
        if (root->right && peek(stack) == root->right)
        {
            pop(stack);  // remove right child from stack
            push(stack, root);  // push root back to stack
            root = root->right; // change root so that the right
            // child is processed next
        }
        else  // Else print root's data and set root as NULL
        {
            fprintf(ofp,"%d ", root->key);
            root = NULL;
        }
    } while (!isEmpty(stack));
}


int main(){
    fp = fopen("binarytreein.doc", "r");
    ofp = fopen("assignment13out.doc", "w+");
    struct node * root = NULL;
    int deletenode;
    int input;
    if (NULL == fp) {
        perror("File not found!");
        exit(-1);
    }
    for (int i = 0; fscanf(fp, "%d%*c", &input) != EOF; i++) {
        if(i==0)
            root = insert(root,input);
        else
            insert(root,input);
    }

    fclose(fp);

    fprintf(ofp,"Inorder Traversal\n");
    printInorder(root);
    fprintf(ofp,"\n\n");
    fprintf(ofp,"iterative Inorder Traversal\n");
    inOrderIterative(root);
    fprintf(ofp,"\n\n");
    fprintf(ofp,"Preorder Traversal\n");
    printPreorder(root);
    fprintf(ofp,"\n\n");
    fprintf(ofp,"Iterative preorder Traversal\n");
    preOrderIterative(root);
    fprintf(ofp,"\n\n");
    fprintf(ofp,"Postorder Traversal\n");
    printPostorder(root);
    fprintf(ofp,"\n\n");
    fprintf(ofp,"Iterative Postorder Traversal\n");
    postOrderIterative(root);
    fprintf(ofp,"\n\n");

    fprintf(ofp,"Enter a number to be deleted from Binary Tree or -1 to Quit: \n");
    fflush(ofp);
    scanf("%d", &deletenode);
    while(deletenode != -1){
        fprintf(ofp,"Inorder Traversal Before delete of %d\n",deletenode);
        printInorder(root);
        fprintf(ofp,"\n\n");
        if (deleteNode(root, deletenode) == NULL){
            fprintf(ofp,"Empty Binary Tree... Exiting\n");
            fflush(ofp);
            exit(0);
        }
        else{
            fprintf(ofp,"Inorder Traversal After delete of %d\n",deletenode);
            printInorder(root);
            fprintf(ofp,"\n\n");
        }
        fprintf(ofp,"Enter a number to be deleted from Binary Tree or -1 to Quit: \n");
        fflush(ofp);
        scanf("%d", &deletenode);
    }
    fprintf(ofp,"Exiting...\n");
    fflush(ofp);
    fclose(ofp);
    return 0;
}