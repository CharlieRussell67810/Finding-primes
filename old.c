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
void addItem (int arr[], long* sizeOfArray, long* arrPointer, int newNum){
	if ( *arrPointer >= *sizeOfArray){
		changeArrSize (arr,sizeOfArray);
	}
	arr[*arrPointer] = newNum;
	*arrPointer = *arrPointer + 1;


}

linkedNode* addNextNode (linkedNode* current, int num){
	linkedNode* nextNode = malloc(sizeof(linkedNode));
	nextNode->num = num;
	nextNode->next = NULL;
	(*current).next = nextNode; 
	return nextNode;
}

void printArray (int* arr, int size){

	for (int l = 0; l<size && arr[l] != 0; l++){
		printf("%d\n", arr[l]);
	}
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
	int* primes = malloc(sizeOfArr * sizeof(int));
	long nextFreePlace = 0;
	linkedNode* start = malloc(sizeof(linkedNode));
	linkedNode* currentNode = start;
	int input;
	scanf("%d",&input);
	for (int i = 2; i < input; i++){
		bool noRemainderFlag = false;

		
		for ( int j = 2; j < (div(i,2).quot + 1); j++){

			div_t output = div(i, j);
			if (output.rem == 0){
				noRemainderFlag = true;
				break;
			}
		}
		if (!noRemainderFlag){
			currentNode = addNextNode(currentNode, i); 
			sizeOfArr ++;
		}
	}
	printLinkedList ((*start).next, sizeOfArr);

	return 0;	
}
