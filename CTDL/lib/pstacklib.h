#include "plistlib.h"
typedef List Stack;

void MakeNull_Stack(Stack *S){
	MakeNull_List(S);
}
int Empty_Stack(Stack S){ 
	return Empty_List(S);
}

void Push(ElementType X, Stack *S){
		Insert_List (X, First (*S), S);
}

void Pop (Stack *S){	
	Delete_List (First (*S), S);
}
ElementType Top (Stack S){	
	Retrieve(First (S), S);
}
void Print_Stack(Stack S){
	Position top = First(S);
	while (top->Next!=NULL){
		cout << top->Next->Element << "  ";
		top=top->Next;
	}
	cout<< endl;	
}
