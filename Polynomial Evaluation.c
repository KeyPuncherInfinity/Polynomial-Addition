/*
Evaluate a polynomial using a Singly Linked List


*/

#include<stdio.h>
#include<stdlib.h>

typedef struct polyNode{

    int coefficient;
    int power;
    struct polyNode *next;
}NODE;
/*
Each node will contain the 
1. Coefficient value
2. Power of the 'x' term
*/

NODE* addPoly(NODE*, NODE*);

NODE* createNode(int pow){
    /*
    Creates a node and assigns a value to the coefficient
    The value of power is assigned to the newnode->power
    The address is set to NULL
    Returns address of the node
    */

    NODE *newnode;

    newnode = (NODE*)malloc(sizeof(NODE));

    newnode->next = NULL;
    newnode->power = pow;
    
    scanf("%d",&newnode->coefficient);

    return newnode;

}

NODE* createList(int degree){
    /*
    Creates a list of size degree using createNode(int) function
    Returns root address of the list
    */

    NODE *root,*travelNode,*newnode; //travelNode is used to traverse through the list when needed

    root = NULL;

    while(degree >= 0){
        newnode = createNode(degree);

        if(root == NULL)
            root = newnode; // Only executes if list hasn't been initialized
        else{
            travelNode = root;

            while(travelNode->next!=NULL){
                travelNode = travelNode->next;
            }

            travelNode->next = newnode;
        }

        degree--;
    }

    return root;

}

void display(NODE *root,int option){
    /*
    Call function with root of List to print
    Second argument can be zero or not-zero
    A call with '0' will also print address
    Useful for debugging
    */

    NODE *travelNode; //Used to travers the list 

    travelNode = root;

    if(option){
        //print with only data

        while(travelNode != NULL){
            
            printf("(%d(x^%d)) + ",travelNode->coefficient,travelNode->power);
            travelNode = travelNode->next;
        }

        printf("0\n");
        
    }


}


//begin main()

int main(){
    
    NODE *expression_1,*expression_2,*addedExpression;
    /*
    addedExpression contains the sum of the two polynomials ie;
    expression_1 + expression_2
    */

    int degree;


    printf("Enter the degree of the polynomial expressions\n");
    scanf("%d",&degree);


    printf("Enter the coefficients of the first polynomial expression along with the negative sign where required\n");
    expression_1 = createList(degree);

    printf("Enter the coefficients of the second polynomial expression along with the negative sign where required\n");
    expression_2 = createList(degree);

    addedExpression = addPoly(expression_1,expression_2);

    display(expression_1,1);
    display(expression_2,1);
    display(addedExpression,1);

    return 0;
}


NODE* addPoly(NODE *exp1, NODE *exp2){
    /*
    This function will add the nodes of the two expressions of the same degree
    The result is stored in the relevant nodes of a new list
    The root address of the new list is returned
    */

    NODE *root = NULL,*travelNode,*travelNode1,*travelNode2,*newnode;
    /*
    travelNode is used to traverse through the new list containing the sum of the two original lists
    travelNode1 is used to traverse through exp1
    travelNode2 is used to traverse through exp2
    */


    int degree = exp1->power;
    // Degree is going to be same in the reulting list/expression


    travelNode1 = exp1;
    travelNode2 = exp2;
    while(travelNode1 != NULL){
        //begin loop to traverse through the two original lists/expressions


        newnode = (NODE*)malloc(sizeof(NODE));

        newnode->power = degree;
        newnode->coefficient = travelNode1->coefficient + travelNode2->coefficient;
        newnode->next = NULL;

        if(root == NULL)
            root = newnode;

        else{
            // adds the node at the end of the new list

            travelNode = root;
            while(travelNode->next != NULL){
                travelNode = travelNode->next;
            }

            travelNode->next = newnode;
        }

        travelNode1 = travelNode1->next;
        travelNode2 = travelNode2->next;

        degree--;
    } // end loop

    return root;
}