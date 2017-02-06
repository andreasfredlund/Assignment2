// linked list and database by Andreas Fredlund
// add, removes and printing min and max temperatur for given day

#include <stdio.h>
#include <stdlib.h>

typedef struct node{    //define a linked list node
    double min, max;
    struct node *next;
    int index; 
} node_t;



void printing(node_t *head){      // printing result
    node_t *temp = head;
    temp = temp -> next;
    printf("day\t");
    printf("min\t");
    printf("\tmax\n");
    while (temp)  {       // stops when node == NULL
     printf("%d", temp -> index);
     printf("\t%lf\t", temp -> min);
     printf("%lf\t", temp -> max);
     printf("\n");
     temp = temp -> next;     // one step forward
    }
    printf("\n");
}

void save(int index, double min, double max, node_t **head){ 
    node_t * temp_node; // saves index and min and max
    if(*head == NULL)   { 
    temp_node = malloc(sizeof(node_t));  
    temp_node -> max = max;
    temp_node -> min = min;
    temp_node -> index = index;
    temp_node -> next = NULL;
    *head = temp_node;
    return;
    }
    if (index == (*head) -> index){
     (*head) -> min = min;
     (*head) -> max = max;
    }
    if ( ((*head) -> index) < index){
    save(index, min, max, &(*head) -> next);   //calls the function itself.
    }
    if ( ((*head) -> index) > index) {   // if current index is less than the what the pointer is pointing at
    node_t * make_node;                  // we insert the node here.   
    make_node = malloc(sizeof(node_t));
    make_node -> index = index;
    make_node -> min = min;
    make_node -> max = max;
    make_node -> next = *head;
    *head = make_node;
   }
}

void removee(node_t **head, int index) {  // removes a node at certain index
    node_t *temporary;
    if(!(*head)){
     return;
    }
    if ( ((*head) -> index) < index){
     removee(&(*head) -> next, index); // calls function itself
    }
    if ( ((*head) -> index) == index) {
     if (((*head) -> next) == NULL){
       free(*head);       //free pace
       *head = NULL;
       return;
     }
     temporary = (*head) -> next;   //saves the pointer to the next node
     free(*head);                   
     *head = temporary;            //saves the pointer to the next node
     head = NULL;                  // removes node.
     return;
    }
}
     


int main (int args, char *argv[]) {
      node_t *head = head;
      head = malloc(sizeof(node_t));
      double max, min;
      int index;
      char command;
      int quit = 0;   // the Q-command changes "quit" to 1 and ends the while loop
    while (quit < 1) {
       printf("Enter command: ");    
       scanf(" %c", &command);
       switch(command) {         // checks what kind of command the user want and calls each function
          case 'A':              // saves data
             scanf("%d%lf%lf", &index, &min, &max);
             if (index < 1 || index > 31){
              printf("Error, use index between 1 and 31\n");
              break;
              }    
              save(index, min, max, &head);
              break;
          case 'P':            // printing data
             printing(head);
             break;
         case 'D':                         // deleting data
             scanf("%d", &index);
             removee(&head, index);
             break;
          case 'Q':                        // quits program
             quit=1;
             break;
         default: //input isnt correct. Message!
             printf("Change input!\n");
             break;         
        }
    }
  }


