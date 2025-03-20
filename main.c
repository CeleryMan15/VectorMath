#include <stdio.h>
#include <stdlib.h>

int readNumInp() {
        int numInp; printf("\n$>> ");
        scanf("%d", &numInp);
        return numInp;
}

int askVectorCount() {
        int vectorCount;
        printf("Vector Amount: ");
        scanf("%d", &vectorCount);
        return vectorCount;
}

int calculateScalarProduct(int** vectors) {
	int resultX = vectors[0][0] * vectors[1][0];
	int resultY = vectors[0][1] * vectors[1][1];
	int resultZ = vectors[0][2] * vectors[1][2];
	return (resultX + resultY + resultZ);
}

int* askVectorParams() {
        static int vector[3];
        char coordinateStrings[3] = {'X', 'Y', 'Z'};

	for(int i = 0; i < 3; i++) {
                printf("Vector %c: ", coordinateStrings[i]);
		scanf("%d", &vector[i]);
        }
        return vector;
}

int** askVectors(int vectorCount) {
	int** vectors = (int**)malloc(vectorCount * sizeof(int*));

	for(int i = 0; i < vectorCount; i++) {
		printf("\n V%d\n", i+1);               
                vectors[i] = askVectorParams(); 
		printf("\n(%d, %d, %d)\n", vectors[i][0], vectors[i][1], vectors[i][2]);
	}

	printf("\n(%d, %d, %d)\n", vectors[0][0], vectors[0][1], vectors[0][2]);
        return vectors;
}

void handleScalarMenu() {
        system("clear");
//        int vectorCount = askVectorCount();
        int** vectors = askVectors(2);
	int result = calculateScalarProduct(vectors);
	printf("\nResult: %d\n", result);
}

void handleVectorMenu() {
        system("clear");
}

void handleMainMenu() { 
	int choice;
        system("clear");
        printf("3D Vector Algebra\n---------------\n(1) Scalar Product\n(2) Vector Product\n");

        choice = readNumInp();

        if(choice == 1) {
                handleScalarMenu();
        }
        else if(choice == 2) {
                handleVectorMenu();
        }
}

int main() {
        handleMainMenu();
        return 0;
}

