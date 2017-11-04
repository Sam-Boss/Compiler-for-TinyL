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
#include <math.h>
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
        Instruction *ptr, *next;
        ptr = head;
        next = ptr->next;

        while(next != NULL){
              if(ptr->opcode == LOADI){
                    double val = ptr->field1;
                    int powerof2 = 0;
                    while(val > 1){
                    val = val / 2;
                    powerof2++;
                    }
                    if(val == 1){
                    switch(next->opcode){
                           case MUL:
                                    next->opcode = LSHIFTI;
                                    break;
                           case DIV:
                                    next->opcode = RSHIFTI;
                                    break;
                           default:
                                    ptr = ptr->next;
                                    next = ptr->next;
                                    continue;
                     }
                    next->field2 = powerof2;
                    ptr->prev->next = next;
                    next->prev = ptr->prev;
                    free(ptr);
                    ptr = next;
                    next = ptr->next;
                    continue;
                    }
                 }
               
              ptr = ptr->next;
              next = ptr->next;  
        }

	if (head) 
		PrintInstructionList(stdout, head);
                DestroyInstructionList(head);
	
	return EXIT_SUCCESS;
}

