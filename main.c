#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
struct linkedNode {
	int num;
	struct linkedNode* next;
};

typedef struct linkedNode linkedNode;
void changeArrSize ( int arr[], long* sizeOfArray) {
	arr = (int*) malloc(*sizeOfArray * 2 * sizeof(int));
	*sizeOfArray = *sizeOfArray * 2;
}

linkedNode* addNextNode (linkedNode* current, int num){
	linkedNode* nextNode = malloc(sizeof(linkedNode));
	nextNode->num = num;
	nextNode->next = NULL;
	(*current).next = nextNode; 
	return nextNode;
}

void printLinkedList (linkedNode* start, int sizeOfList){
	printf("%d\n", (*start).num);
	if ( sizeOfList > 1 && start->next != NULL ){
		printLinkedList ((*start).next, sizeOfList - 1);
	}
}

bool isMultipleOfPrime (linkedNode* start, int num){
	div_t output = div(num,(*start).num);
	if ( output.rem == 0) {
		return true;
	}
	if ((*start).next == NULL){
		return false;
	}
	return isMultipleOfPrime ((*start).next, num);
}
int main () {
	long sizeOfArr = 1;
	linkedNode* start = malloc(sizeof(linkedNode));
	linkedNode* currentNode = start;
	(*start).num = 2;
	int input;
	scanf("%d",&input);
	for (int i = 3; i < input; i++){
		if (!(isMultipleOfPrime(start,i))){
			currentNode = addNextNode(currentNode, i);
			sizeOfArr ++;
		}
	}
	printLinkedList (start, sizeOfArr);

	return 0;	
}
