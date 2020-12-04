#include <stdio.h>
#include <stdlib.h>

// ####################### Tree Node #######################

struct node {
   int data;   
   struct node *leftChild;
   struct node *rightChild;
};

struct node *root = NULL;

//####################### insert operation ####################### 

void insert(int data) {
   struct node *tempNode = (struct node*) malloc(sizeof(struct node));
   struct node *current;
   struct node *parent;

   tempNode->data = data;
   tempNode->leftChild = NULL;
   tempNode->rightChild = NULL;

   //if tree is empty, create root node
   if(root == NULL) {
      root = tempNode;
   } else {
      current = root;
      parent  = NULL;

      while(1) {                
         parent = current;

         //go to left of the tree
         if(data < parent->data) {
            current = current->leftChild;                
            
            //insert to the left
            if(current == NULL) {
               parent->leftChild = tempNode;
               break;
            }
         }
			
         //go to right of the tree
         else {
            current = current->rightChild;
            
            //insert to the right
            if(current == NULL) {
               parent->rightChild = tempNode;
               break;
            }
         }
      }            
   }
}

//  ####################### search operation  ####################### 

struct node* search(int data) {
   struct node *current = root;
   printf("Visiting elements: ");

   while(current->data != data) {
      if(current != NULL)
      printf("%d ",current->data); 
      
      //go to left tree

      if(current->data > data) {
         current = current->leftChild;
      }
      //else go to right tree
      else {                
         current = current->rightChild;
      }

      //not found
      if(current == NULL) {
         return NULL;
      }

      return current;
   }  
}

//  ####################### inorderorder traversal ####################### 

void inorder_traversal(struct node* root) {
   if(root != NULL) {
      inorder_traversal(root->leftChild);
      printf("%d ",root->data);          
      inorder_traversal(root->rightChild);
   }
}

//  ####################### pre-order traversal ####################### 

void pre_order_traversal(struct node* root) {
   if(root != NULL) {
      printf("%d ",root->data);
      pre_order_traversal(root->leftChild);
      pre_order_traversal(root->rightChild);
   }
}

//  ####################### post-order traversal ####################### 

void post_order_traversal(struct node* root) {
   if(root != NULL) {
      post_order_traversal(root->leftChild);
      post_order_traversal(root->rightChild);
      printf("%d ", root->data);
   }
}

//  ####################### main function  ####################### 

int main() {
   int i;
   int array[7] = { 27, 14, 35, 10, 19, 31, 42 };

   for(i = 0; i < 7; i++)
      insert(array[i]);

   i = 31;
   struct node * temp = search(i);

   if(temp != NULL) {
      printf("[%d] Element found.", temp->data);
      printf("\n");
   }else {
      printf("[ x ] Element not found (%d).\n", i);
   }

   i = 15;
   temp = search(i);

   if(temp != NULL) {
      printf("[%d] Element found.", temp->data);
      printf("\n");
   }else {
      printf("[ x ] Element not found (%d).\n", i);
   }            

   printf("\nInorder traversal: ");
   inorder_traversal(root);

   printf("\nPreorder traversal: ");
   pre_order_traversal(root);

   printf("\nPost order traversal: ");
   post_order_traversal(root);       

   return 0;
}