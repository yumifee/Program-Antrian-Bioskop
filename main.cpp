#include <stdio.h>
#include "matriks.h"

int main (){

	List First;
	First(First) = NULL;
	First(First) = createMatrix(10,10,0,0);
//	display(First);
//	printf("\n");

//	insertRow(&First,"Tri");
	insertColumn(&First,"APA");
	display(First);
	return 0;
}
