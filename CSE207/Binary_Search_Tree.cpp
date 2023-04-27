#include<bits/stdc++.h>
using namespace std;

///Tree node has a data item with left & righ child pointer.
struct node {
   int data;
   struct node *leftChild, *rightChild;
};

struct node *root = NULL; ///initialization

///If the tree is empty
struct node *newNode(int item){
   struct node *temp = (struct node *)malloc(sizeof(struct node));
   temp->data = item;
   temp->leftChild = temp->rightChild = NULL;
   return temp;
}

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

         ///go to left of the tree [left side has smallest element than root]
         if(data < parent->data) {
            current = current->leftChild;

            ///insert to the left
            if(current == NULL) {
               parent->leftChild = tempNode;
               return;
            }
         }///go to right of the tree [right side has largest element than root]
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
struct node* search(int data){
   struct node *current = root;

   printf("\n\nVisiting elements: ");

   while(current->data != data) {
      if(current != NULL) {
         printf("%d ",current->data);

         ///go to left tree
         if(current->data > data) {
            current = current->leftChild;
         }///else go to right tree
         else {
            current = current->rightChild;
         }

         ///not found
         if(current == NULL) {
            return NULL;
         }
      }
   }
   return current;
}

 ///All traverse method using recursion
///Preorder Traversal (root, left, right)
void preorder(struct node *root){
   if (root != NULL) {

      printf("%d -> ", root->data); ///root

      preorder(root->leftChild); ///left
      preorder(root->rightChild);/// right
   }
}

// Inorder Traversal (left, root, right)
void inorder(struct node *root){
   if (root != NULL) {

      inorder(root->leftChild); ///left

      printf("%d -> ", root->data); ///root

      inorder(root->rightChild); ///right
   }
}


/// Postorder Traversal (left, right, root)

void postorder(struct node *root){
   if (root != NULL) {

      postorder(root->leftChild); ///left

      postorder(root->rightChild); ///right

      printf("%d -> ", root->data);///root
   }
}
int main(){
   insert(55);
   insert(20);
   insert(90);
   insert(50);
   insert(35);
   insert(15);
   insert(65);
   printf("Insertion done\n");
   printf("\nPreorder Traversal: ");
   preorder(root);
   printf("\nInorder Traversal: ");
   inorder(root);
   printf("\nPostorder Traversal: ");
   postorder(root);
   struct node* k;
   k = search(35);
   if(k != NULL)
      printf("\nElement %d found", k->data);
   else
      printf("\nElement not found");
   return 0;
}


A Binary Search Tree (BST) is a tree in which all the nodes follow the below-mentioned properties −

The left sub-tree of a node has a key less than or equal to its parent node's key.

The right sub-tree of a node has a key greater than or equal to its parent node's key.
