// stack.cpp

#include "stack.h"                                           
#include <iostream>
#include <assert.h>

using namespace std;

void StackNew(stack *s, int allocLen)
{
	s->logicalLen = 0;
	s->elems = (int*)malloc(allocLen*sizeof(int));
	s->allocLen = allocLen;
	assert(s->elems != NULL);
}

void StackDispose(stack *s)
{
	free(s->elems);
}

void StackPush(stack *s, int elem)
{
	if (s->logicalLen == s->allocLen){
		s->allocLen *= 2;
		s->elems = (int*)realloc(s->elems, s->allocLen*sizeof(int));
	}
	s->elems[s->logicalLen++] = elem;
}

int StackPop(stack *s)
{
	if (s->logicalLen == 0){
		throw "The stack is empty";
	}
	return s->elems[--s->logicalLen];
}

void StackPrint(stack *s)
{
	cout << endl << "The elements: ";
	for(int i=0; i<s->logicalLen; i++)
	{
		cout << i << ":" << s->elems[i] << ", ";
	}
	cout << endl;
}

int main(int argc, char* argv[])                              
{       
	if (argc < 3){
		cout << "usage : stack cmd element" << endl;
		return -1;
	}                                                      
        stack s;
	StackNew(&s, 4);                            
        StackPrint(&s);
	try{
        	if (strcmp(argv[1], "push") == 0){                        
	               for (int i=2;i<argc;i++){
			 StackPush(&s, atoi(argv[i]));
			}                  
        	}                                                     
	        else if (strcmp(argv[1], "pop") == 0){                    
        	        int elem = StackPop(&s);                       
	        }                                                     
        	else{                                                 
	                cout << "Invalid cmd : " << argv[1] << endl;                
                	return -1;                                    
       		}
	}
	catch(const char* error){
		cout << "Exception: " << error  << endl;
		return -1;
	}                                                     
        StackPrint(&s);
        return 0; 
}
