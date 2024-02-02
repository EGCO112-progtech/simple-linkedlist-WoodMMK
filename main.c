//
//  main.c
//  simple linkedlist
//
//  Created by Mingmanas Sivaraksa on 4/2/2566 BE.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(int argc, const char * argv[]) {
    int startvalue=5;
    struct node a,b,*head ;
    a.value = startvalue;
    a.next=&b;
    head=&a;
    b.value=head->value+3;

    printf("%d\n", head ->value ); //what value for 5
    printf("%d\n", head ->next->value ); //what value for 8
/*  Exercise I
    1. Add 1 more than at the end
    2. Add value(11)
    3. Make next become NULL
    4. Print โดยใช้ Head
 */
    struct node c;
    b.next = &c;
    head->next->next->value = 11; //equal c.value = 11;
    head->next->next->next = NULL;
    printf("%d\n", head ->next->next->value ); //what value for 8


    
/*  Exercise II
        1. Add 1 more than at the begining!!!!
        2. Add value (2)
    
*/
    struct node beforeA;
    beforeA.next = head;
    beforeA.value = 2;
    //move head pointer
    head = &beforeA;
    printf("before A node's value is: %d\n", head->value );


    typedef struct node* NodePtr;
    NodePtr tmp=head; 
    
    //add temp value to facilitate
        
    /*  Exercise III Use loop to print everything
    */
        int i,n=4;
        for(i=0;i<n;i++){
            printf("%3d", tmp->value);
            tmp = tmp->next;
          // What is missing???
        }
    
    //Exercise IV change to while loop!! (you can use NULL to help)
        tmp = head;
        while(tmp!=NULL){
            printf("%3d\n", tmp->value);
            tmp = tmp -> next;
        }
    
 /*  Exercise V Use malloc to create all nodes, instead of create a struct!!
        //use a loop to help
        
     */
    head = (struct node*)malloc(sizeof(struct node)); 
    tmp = head;
    for(int i = 0; i < 4; i++){
        if (i == 3) tmp-> next = NULL;
        else tmp->next = (struct node*)malloc(sizeof(struct node));
        tmp->value = i+1;
        printf("node %d value is %d\n", i+1, tmp->value);
        tmp = tmp -> next;
    }

    /*  Exercise VI Free all node !!
         //use a loop to help
    */
    while (head){
        tmp = head;
        head = tmp->next;
        printf("before: %d\n",tmp->value);
        free(tmp);
     }
    return 0;
}
