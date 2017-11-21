#include <iostream>
#include<ctime>
#define COLUMNS 10
#define ROWS 10

using namespace std;
void fillMatrix(long[10][10]);
void initializeMatrix(long[10][10]);
void printMatrix(long[10][10]);
void printSpecificRow(long[10][10],int);
void printSpecificColumn(long[10][10],int);
void printMainDiagonal(long[10][10]);
void printSecondaryDiagonal(long[10][10]);
int printMainMenu();
int main() {
    long matrix[COLUMNS][ROWS];
    initializeMatrix(matrix);
    while (true){
        int choice = printMainMenu();
        switch (choice){
            case 1:
                fillMatrix(matrix);
                break;
            case 2:
                int row;
                cout<<"¿Cuál renglón desea imprimir?";
                cin>>row;
                printSpecificRow(matrix,row - 1);
                break;
            case 3:
                int column;
                cout<<"¿Cuál columna desea imprimir?";
                cin>>column;
                printSpecificColumn(matrix,column - 1);
                break;
            case 4:
                printMainDiagonal(matrix);
                break;
            case 5:
                printSecondaryDiagonal(matrix);
                break;
            case 6:
                printMatrix(matrix);
                break;
            case 7:
                return EXIT_SUCCESS;
            default:
                cout<<"Opción inválida";
        }
    }
    return EXIT_SUCCESS;
}

int printMainMenu(){

    system("clear");
    int choice;
    cout<<endl<<"Qué desea hacer?"<<endl;
    cout<<"1) Llenar la matriz con numeros aleatorios"<<endl;
    cout<<"2) Mostrar un renglón?"<<endl;
    cout<<"3) Mostrar una columna?"<<endl;
    cout<<"4) Mostrar diagonal principal?"<<endl;
    cout<<"5) Mostrar diagonal secundaria?"<<endl;
    cout<<"6) Mostrar matriz completa?"<<endl;
    cout<<"7) Finalizar programa?"<<endl;
    cout<<"Selecione opción"<<endl;
    cin>>choice;
    return choice;
}

void initializeMatrix(long matrix[10][10]){
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            matrix[i][j] = 0;
        }
    }
}

void fillMatrix(long matrix[COLUMNS][ROWS]){
    srand(time(NULL));
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            matrix[i][j] = 1 + random() % (11 - 1);
        }
    }
}

void printSpecificRow(long matrix[10][10],int row){
    for (int i = 0; i < COLUMNS; ++i) {
        cout<< matrix[row][i]<<" ";
    }
}

void printSpecificColumn(long matrix[10][10],int column){
    for (int i = 0; i < ROWS; ++i) {
        cout<< matrix[i][column]<<" ";
    }
}

void printMainDiagonal(long matrix[10][10]){
    for (int i = 0; i < ROWS; ++i) {
        cout<< matrix[i][i]<<" ";
    }
}
void printSecondaryDiagonal(long matrix[10][10]){
    int column = COLUMNS-1;
    for (int i = 0; i < ROWS; ++i) {
        cout<<matrix[i][column]<<" ";
        column--;
    }
}


void printMatrix(long matrix[COLUMNS][ROWS]){
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

