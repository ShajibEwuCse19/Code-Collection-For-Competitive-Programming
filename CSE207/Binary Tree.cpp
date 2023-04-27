#include <iostream>
struct node {
   int data;
   struct node *leftChild;
   struct node *rightChild;
};

struct node *root = NULL;

void insert(int data){
   struct node *tempNode = (struct node*) malloc(sizeof(struct node));
   struct node *current;
   struct node *parent;

   tempNode->data = data;
   tempNode->leftChild = NULL;
   tempNode->rightChild = NULL;

   ///if tree is empty
   if(root == NULL) {

      root = tempNode;

   } else {

      current = root;
      parent = NULL;

      while(1) {
         parent = current;

         ///go to left of the tree
         if(data < parent->data) {

            current = current->leftChild;

            ///insert to the left
            if(current == NULL) {

               parent->leftChild = tempNode;
               return;
            }
         }///go to right of the tree
         else {

            current = current->rightChild;

            ///insert to the right
            if(current == NULL) {
               parent->rightChild = tempNode;
               return;
            }
         }
      }
   }
}

///root - left - right
void pre_order_traversal(struct node* root){

   if(root != NULL) {
      printf("%d ",root->data);
      pre_order_traversal(root->leftChild);
      pre_order_traversal(root->rightChild);

   }
}

///left - root - right
void inorder_traversal(struct node* root){

   if(root != NULL) {
      inorder_traversal(root->leftChild);
      printf("%d ",root->data);
      inorder_traversal(root->rightChild);

   }
}

///left - right - root
void post_order_traversal(struct node* root){

   if(root != NULL) {
      post_order_traversal(root->leftChild);
      post_order_traversal(root->rightChild);
      printf("%d ", root->data);

   }
}
int main(){
   int ara[7] = { 27, 14, 35, 10, 19, 31, 42 };

   for(int i = 0; i < 7; i++)insert(ara[i]);

   printf("\nPreorder traversal: ");
   pre_order_traversal(root);

   printf("\nInorder traversal: ");
   inorder_traversal(root);

   printf("\nPost order traversal: ");
   post_order_traversal(root);
   return 0;
}




Full Binary Tree : A full binary tree is a binary tree type where every node has either 0 or 2 child nodes.

Complete Binary Tree : A complete binary tree is a binary tree type where all the leaf nodes must be on the same level. 
                       However, root and internal nodes in a complete binary tree can either have 0, 1 or 2 child nodes.

Perfect Binary Tree : A perfect binary tree is a binary tree type where all the leaf nodes are on the same level and every node except leaf nodes have 2 children.
