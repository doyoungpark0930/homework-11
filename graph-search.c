/*
 * Binary Search Tree #2
 * 작성자 :박도영
 * 작성일자: 2021/05/09
 * Data Structures
 *
 * Department of Computer Science
 * at Chungbuk National University
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int key;
	struct node* left;
	struct node* right;
} Node;


int main()
{
	char command;
	int key;
	Node* head = NULL;
	printf("Do young park/2018038077\n");
	do {
		printf("\n\n");
   

		printf("----------------------------------------------------------------\n");
		printf("                   Graph search #2                              \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize Graph       = z                                     \n");
		printf(" Insert Vertex          = v      Insert Edge            = e \n");
		printf(" Depth First Search     = d      Breath First Search    = b \n");
		printf(" Print Graph  = p      Quit               Quit          = q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch (command) {
		case 'z': case 'Z':
			initializeBST(&head);
			break;
		case 'q': case 'Q':
			freeBST(head);
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(head, key);
			break;

		case 'r': case 'R':
			recursiveInorder(head->left);
			break;
		case 't': case 'T':
			iterativeInorder(head->left);
			break;

		case 'l': case 'L':
			levelOrder(head->left);
			break;

		case 'p': case 'P':
			//printStack();
			break;

		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	} while (command != 'q' && command != 'Q');

	return 1;
}