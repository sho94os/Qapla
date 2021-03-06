#ifndef NODES_H
#define NODES_H

#include <stdlib.h> 
#include <stdio.h>
#include <stdbool.h>

//dtypes: 0:var, 1:int, 2:float, 3:str, 4:bool, 5:operator,
//        6:functions [decl], 7:parameters 8:instruction, 9:while

/* Operators
 *    - opEqual
 *    - opPlus
 *    - opMinus
 *    - opTimes
 *    - opDiv
 *    - opOR 
 *    - opAND
 *    - opNOT
 *    - opLT
 *    - opEVAL
 *    - opNEQ
 */

/* Instructions:
 *    - declareVar
 *    - print
 *    - createNewScope
 *    - funCall
 *    - parametersAssign
 *    - returnInstr
 *    - ifBlock
 *    - elseIfBlock
 *    - elseBlock
 *    - selectBlock
 *    - readStr
 *                                            - parameters [unused...]
 */


//default container for IDENTIFIERs, INTEGERs, REALs, 
//STRINGs, BOOLs, and FUNCTIONs 
struct DataNode {
   struct DataNode *parent;
   struct DataNode **children ;
   size_t size;
   size_t capacity;

   long ival, dtype; 
   double fval;
   char str[4096], name[256]; 
   bool bval;
};

//
typedef union { 
   struct DataNode *datanode;
} YYSTYPE;



//variables container
struct DataNode *varContainer;

//general nodes container
struct DataNode *programContainer;

struct DataNode *dummyNode;

//expects a capacity, returns the new node
struct DataNode* constructNode(size_t capacity);

struct DataNode* insertChild(struct DataNode *node, struct DataNode *element);

void freeNode(struct DataNode *node) ;


//copy a node - takes a node, returns a copy with its ival, fval, str and bval
//useful for variables and return values
//
struct DataNode *copyNode (struct DataNode *node);

#endif
