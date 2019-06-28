/**
 * 
 * @Title: Chess Knight Moves
 * 
 * @Author: Theocharis Dimitrios Siarras
 * 
 * @Inputs: - Starting point (in algebraic chess notation & uppercase)
 *          - Ending point (in algebraic chess notation & uppercase)
 *          - Maximum moves allowed (positive integer)
 * 
 * @Output: All the different paths that the knight could follow in order to reach the 
 *          ending point accompanied by the path tally. If no paths are found then it
 *          prints a corresponding message.
 * 
 * 
 * This program simulates the Knight Chess moves. Given a starting point and an ending point
 * (both in algebraic chess notation) and a maximum number of moves allowed, finds and prints
 * all the available paths that the knight could take so as to reach the ending point. It uses
 * recursion instead of a loop.
 * 
 * 
 * ******************************** Algorith ********************************
 * 
 * 
 * findPaths(source, dest, visited, activeList)
 * 
 *      u <- current node
 *      for every possible neighbor v of u
 * 
 *          if v is in the chessboard & not visited before
 *              if v is the dest
 *                  a path has been found 
 *                  return
 *              else if current moves < MAX 
 *                  clone activeList
 *                  clone visited
 * 
 *                  findPaths(v, dest, cloned visited, cloned activeList)
 * 
 * 
 * ******************************** Limitations & further improvements ********************************
 * 
 * 
 * One of the drawbacks of using recursion instead of a basic loop is the risk of Stack Overflow. The word
 * risk is not intentional, since the stack overflow depends on the system it is being run.
 *
 * If a very large number is given for max moves allowed, apart from the computation overload a stack overflow
 * might happen. In the scenarios tested (max < 15) a stack overflow has not been occured, however when
 * the number increases the probability of happening increases as well.
 * 
 * As a first improvement would be to break the recursion and implement it as a basic loop. This can be achieved
 * using the same data structure used in the recursive version, a stack, and every time we Pop from the stack the
 * current node and we do the same computations. The loop will continue until the Stack is not empty.
 * 
 * 
 * 
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0


/************ Global Variables ************/ 


//counter of paths
int numOfPaths = 0;

// maximum number of moves; provided from the user
int maxMoves = 0;

// 8 possible movements from any given point in chess board
const int move_row[8] = {2, 2, -2, -2, 1, 1, -1, -1};
const int move_col[8] = {-1, 1, 1, -1, 2, -2, 2, -2};


/************ Data Structures ************/ 


// the node of the graph
struct node
{
    int row;
    int column;
};

// the queue node contains a pointer to next item,the data and
// the number of the current element, i.e. the 1st element has
// itemCount = 1, the 3rd element itemCount = 3 and so on...

struct list
{
    struct list *next;
    struct node data;
    int itemCount;
};

// list to be used so as to implement a stack data structure
typedef struct list list;
typedef struct node graphNode;



/************ Auxilary Functions ************/ 



/*
 * 
 * Takes no arguments.
 * 
 * @returns a pointer to a list or NULL for error. 
 * 
 * Creates an empty list node, as the top of the stack, and returns a 
 * pointer to that element. In case of a malloc error it prints the 
 * corresponding message.
 * 
 */


void *initStack()
{
    list *root = (list *)malloc(sizeof(list));

    if (!root)
    {
        printf("root ERR\n");
        return NULL;
    }

    // end of the queue
    root->next = NULL; 
    root->itemCount = 1;

    return root;
}



/*
 * 
 * @param root. It is a pointer to a list; The head of the stack.
 * @param data. It is the data to be pushed into the stack.
 * 
 * @returns a pointer to a list. 
 * 
 * Creates a new list node, and it is placed in the beginning of the list as
 * the head of the stack. It returns the new root, which points to the new 
 * element. In case of a memory allocation error returns null and prints a
 * corresponding message.
 * 
 */


void *push(list *root, graphNode data)
{
    list *new = (list *)malloc(sizeof(list));

    if (!new)
    {
        printf("push ERR\n");
        return NULL;
    }

    new->next = root;
    new->data = data;
    new->itemCount = root->itemCount + 1;
    root = new;

    return root;
}


/*
 * 
 * @param root. A pointer to a list. The head of the stack.
 * 
 * @returns a point to a list.
 * 
 * Given a stack, it pops the head of the stack and returns a
 * pointer of the new head.
 * 
 */


void *pop(list *root)
{
    list *newRoot = root->next;

    free(root);

    return newRoot;
}


/**
 * 
 * @param root. A pointer to a list. It is the head of the stack.
 * 
 * @returns nothing.
 * 
 * Deallocates the memory of the the whole list.
 * 
 */


void clearStack(list *root)
{

    for (list *curr = root; curr != NULL; curr = curr->next)
    {
        pop(curr);
    }
}


/**
 * 
 * @param root. A pointer to a list. It is the head of the root.
 * 
 * @returns a pointer to a list or NULL for error. It is a copy of 
 * the list provided.
 * 
 * Given a specific stack, the function allocates memory and copies
 * the data from the stack to a new one. Returns either a pointer to
 * the copied stack or NULL in case of an error.
 * 
 */


void *duplicateStack(list *root)
{
    list *newRoot, *new, *prev;

    for (list *curr = root; curr != NULL; curr = curr->next)
    {
        new = (list *)malloc(sizeof(list));

        if (!new)
        {
            printf("cpy queue ERR\n");
            return NULL;
        }

        if (curr == root)
        {
            newRoot = new;
        }
        else
        {
            prev->next = new;
        }

        // link with the new node
        prev = new;

        // copy the data
        new->data = curr->data;
        new->itemCount = curr->itemCount;
        new->next = NULL;
    }
    return newRoot;
}


/**
 * 
 * @param root. A pointer to a list. It is the head of a stack.
 * 
 * @returns nothing.
 * 
 * Prints the data contained in the stack in the following format
 * data.row / data.column / itemCount in the stack
 * 
 * 
 */


void printStack(list *root)
{

    for (list *curr = root; curr != NULL; curr = root)
    {
        root = root->next;
        printf("(%d,%d) and count=%d \n", curr->data.row, curr->data.column, curr->itemCount);
    }
}


/**
 * 
 * @param coordinates. A graphNode type. It is the coordinates
 * in the matrix.
 * 
 * @returns a string or NULL for error. The chess algebraic 
 * notation of the position in the chess board.
 * 
 * Maps the coordinates of an array to a chess notation.
 * 
 */


char *coordinatesToPos(graphNode coordinates)
{
    char *res;

    res = (char *)malloc(3 * sizeof(char));

    if (!res)
    {
        printf("Malloc error in coordinatesToPos");
        return NULL;
    }

    switch (coordinates.column)
    {
    case 0: 
        res[0] = 'A';
        break;
    case 1:
        res[0] = 'B';
        break;
    case 2: 
        res[0] = 'C';
        break;
    case 3: 
        res[0] = 'D';
        break;
    case 4: 
        res[0] = 'E';
        break;
    case 5: 
        res[0] = 'F';
        break;
    case 6: 
        res[0] = 'G';
        break;
    case 7: 
        res[0] = 'H';
        break;
    default:
        printf("Switch case error in coordinatesToPos");
        return NULL;
    }

    // convert integer to char and put end of string at the end
    res[1] = (char)8 - coordinates.row + '0';
    res[2] = '\0';

    return res;
}


/**
 * 
 * @param pos. A string with the chess position in chess algebraic notaion.
 * 
 * @returns a pointer to graphNode or NULL for error. The mapped coordination
 * in the array.
 * 
 * Given a chess position in chess algebraic notation, maps and returns the
 * array coordinates. Returns a pointer to the coordinates or NULL for error.
 * 
 */


graphNode *posToCoordinates(char *pos)
{
    graphNode *res;

    res = (graphNode *)malloc(sizeof(graphNode));

    if (!res)
    {
        printf("Error while allocating memory through malloc");
        return NULL;
    }

    switch (pos[0])
    {
    case 'A':
        res->column = 0;
        break;
    case 'B':
        res->column = 1;
        break;
    case 'C':
        res->column = 2;
        break;
    case 'D':
        res->column = 3;
        break;
    case 'E':
        res->column = 4;
        break;
    case 'F':
        res->column = 5;
        break;
    case 'G':
        res->column = 6;
        break;
    case 'H':
        res->column = 7;
        break;

    default:
        printf("Switch case error in posToCoordinate");
        return NULL;
    }

    // type casting to int
    res->row = 8 - pos[1] + '0';

    return res;
}


/**
 * 
 * @param root. A pointer to a list. The head of a stack.
 * 
 * @returns nothing.
 * 
 * Takes as an argument a stack and prints it as a queue,
 * that is, backwards. For example, given the A->B->C->NULL stack
 * it prints C->B->A
 * 
 * 
 */


void printStackAsQueue(list *root)
{
    list *queueRoot, *new; // list with fifo order
    queueRoot = NULL;

    if (!root)
    {
        printf("cannot print an empty stack \n");
        return;
    }

    // make a temp queue for printing pursposes
    for (list *curr = root; curr != NULL; curr = curr->next)
    {
        new = (list *)malloc(sizeof(list));

        if (!new)
        {
            printf("printStackAsQueue malloc error \n");
            return;
        }

        // copy the data from stack
        new->data = curr->data;
        new->itemCount = curr->itemCount;

        // link new item with the rest of the queue
        new->next = queueRoot;

        // newest item is always first
        queueRoot = new;
    }

    // print the queue
    for (list *curr = queueRoot; curr != NULL; curr = curr->next)
    {
        char *boardPos;
        boardPos = coordinatesToPos(curr->data);

        printf("%s", boardPos);

        if (curr->next != NULL)
        {
            printf(" -> ");
        }
    }
    printf("\n");

    clearStack(queueRoot);
}


/**
 * 
 * @param v. The node to be checked.
 * 
 * @returns TRUE or FALSE if the node is in or out of the
 * chess board respectively.
 * 
 * Takes as an argument a node and checks whether that row and column
 * is in an 8x8 array. Returns TRUE or FALSE. 
 * 
 */


int isValid(graphNode v)
{
    if (v.row < 0 || v.column < 0 || v.column >= 8 || v.row >= 8)
    {
        return FALSE;
    }
    return TRUE;
}


/**
 * 
 * @param source. The starting point in the chess board.
 * @param des. The destination point in the chess board.
 * @param visited. A 2D array for keeping the visited positions.
 * @activeList. A list that holds the active path for every possible
 * search.
 * 
 * @returns nothing.
 * 
 * Takes as arguments the starting point (in array coordinates), the ending
 * point (in array coordinations), a 2D array that stores the positions that
 * have been visited so far, and the activeList that holds the path that has been
 * taken so far. It prints all the paths that have been found, otherwise does 
 * nothing. Finally, frees the activeList given as a parameter.
 * 
 */



void findPaths(graphNode source, graphNode dest, int **visited, list *activeList)
{
    if (activeList == NULL)
    {
        printf("ERROR no activeList given \n");
        return;
    }

    // get the current node u
    graphNode u = activeList->data;

    // for every neighbor v of u
    for (int i = 0; i < 8; i++)
    {

        // find the next neighbor v
        graphNode v;
        v.row = u.row + move_row[i];
        v.column = u.column + move_col[i];

        // if v is valid and not visited before
        if (isValid(v) && !visited[v.row][v.column])        
        { 
            if (v.row == dest.row && v.column == dest.column)
            {
                numOfPaths++;
                activeList = push(activeList, v);

                // print the results
                printStackAsQueue(activeList);

                // clear the stack
                clearStack(activeList);

                // free the visited array
                for (int i = 0; i < 8; i++)
                {
                    free(visited[i]);
                }

                return;
            }
            else if (activeList->itemCount < maxMoves)
            {
                // copy the activeList and push the new node
                list *newBranchList = duplicateStack(activeList);
                newBranchList = push(newBranchList, v);

                // copy the visited array for this path that is being created
                int **newVisited;

                // new visited
                newVisited = malloc(8 * sizeof(int *));
                for (int i = 0; i < 8; i++)
                {
                    newVisited[i] = malloc(8 * sizeof(int));
                }

                // copy old visited
                for (int i = 0; i < 8; i++)
                {
                    for (int j = 0; j < 8; j++)
                    {
                        newVisited[i][j] = visited[i][j];
                    }
                }

                // mark the current node as dirty
                newVisited[v.row][v.column] = TRUE;

                // recursive call
                findPaths(source, dest, newVisited, newBranchList);

            }
        }
    }

    // free unnecessary memory
    clearStack(activeList);

    for (int i = 0; i < 8; i++)
    {
        free(visited[i]);
    }
}



/************ Main Function of the program ************/ 



int main(int argc, char *argv[])
{
    graphNode source;
    graphNode dest;
    char *userInput;
    int **visited;
    int c;


    /* read all user input */

    userInput = (char *)malloc(3 * sizeof(char));

    // read starting point and flush stdin
    printf("Please type the STARTING point as an algebraic chess notation \n");
    fgets(userInput, 3, stdin);
    while ((c = fgetc(stdin)) != '\n' && c != EOF); 

    // validate input
    while (userInput[0] < 'A' || userInput[0] > 'H' || userInput[1] < '1' || userInput[1] > '8')
    {
        printf("Please enter a valid chess notation as a starting point\n");
        fgets(userInput, 3, stdin);
        while ((c = fgetc(stdin)) != '\n' && c != EOF); // Flush stdin
    }

    // map input data to appropriate matrix notation for computations
    source = *(posToCoordinates(userInput));

    // read ending point and flush stdin
    printf("Please type the ENDING point as an algebraic chess notation \n");
    fgets(userInput, 3, stdin);
    while ((c = fgetc(stdin)) != '\n' && c != EOF); // Flush stdin

    // validate input
    while (userInput[0] < 'A' || userInput[0] > 'H' || userInput[1] < '1' || userInput[1] > '8')
    {
        printf("Please enter a valid chess notation as an ending point\n");
        fgets(userInput, 3, stdin);
        while ((c = fgetc(stdin)) != '\n' && c != EOF); // Flush stdin
    }

    // map input data to appropriate matrix notation for computations
    // and free any dynamic unnecessary memory
    dest = *(posToCoordinates(userInput));
    free(userInput);

    // read max # of moves
    printf("Please enter the maximum moves allowed\n");
    scanf("%d", &maxMoves);

    // validate the number of moves
    while(maxMoves <= 0){
        printf("Please type a valid positive integer\n");
        scanf("%d", &maxMoves);
    }

    /* initialize all data needed for the algorithm */

    // init the statck that holds the active path
    list *activeList = initStack();
    activeList->data = source;

    /* create a 2D visited table, that holds information about
    which chess positions have been visited. It needs to be
    in the heap because we want to pass it to another function. So,
    mem space must be allocated dynamically.
    */
    visited = malloc(8 * sizeof(int *));

    for (int i = 0; i < 8; i++)
    {
        visited[i] = malloc(8 * sizeof(int));
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            visited[i][j] = FALSE;
        }
    }

    // mark the source as a visited node
    visited[source.row][source.column] = TRUE;

    printf("\nMoves: \n\n");

    /* CORE ALGORITHM */
    findPaths(source, dest, visited, activeList);

    if(!numOfPaths){
        printf("No moves found! Try another number of moves. \n");
    }
    else
    {
        printf("\n# of paths found: %d \n", numOfPaths);
    }

    return 0;
}