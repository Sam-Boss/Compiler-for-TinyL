/*
 *********************************************
 *  314 Principles of Programming Languages  *
 *  Fall 2017                                *
 *  Author: Uli                              *
 *  Student Version                          *
 *********************************************
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "InstrUtils.h"
#include "Utils.h"

int main()
{
	Instruction *head;

	head = ReadInstructionList(stdin);
	if (!head) {
		WARNING("No instructions\n");
		exit(EXIT_FAILURE);
	}

	/* YOUR CODE GOES HERE */
       
     Instruction *ptr, *next, *prev;
     ptr = head;
     next = ptr->next;
     prev = ptr->prev;
     while(next != NULL){
           if(prev != NULL && prev->opcode == LOADI){
              if(ptr != NULL && ptr->opcode == LOADI){ 
                 switch(next->opcode){
                        case ADD:
                             next->field1 = ptr->field1 + prev->field1;
                             break;    
                        case SUB:
                             next->field1 = ptr->field1 - prev->field1;
                             break;
                        case MUL:
                             next->field1 = ptr->field1 * prev->field1;
                             break;
                        default:
                             ptr = ptr->next;
                             next = ptr->next;
                             prev = ptr->prev;
                             continue;
                 }
                 next->opcode = LOADI;
                 next->field2 = next->field3;

                 if(prev->prev == NULL){
                   prev = next;
                   prev->prev = NULL;
                   free(ptr);
                   free(next);
                   ptr = prev->next;
                   next = ptr->next;
                   continue;  
                }else{
                   next->prev = prev->prev;
                   prev->prev->next = next;
                   free(ptr);
                   free(prev);
                   prev = next;
                   ptr = prev->next;
                   if(ptr->next != NULL){
                      next = ptr->next;
                   }else{
                      next = NULL;
                   }
                   continue; 
             }
            }
          }
          ptr = ptr->next;
          next = ptr->next;
          prev = ptr->prev;
     }
    
     if (head)    
         PrintInstructionList(stdout,head);
         DestroyInstructionList(head);
         
         return EXIT_SUCCESS;

}



