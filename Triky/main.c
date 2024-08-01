#include <stdio.h>
#include <stdlib.h>

char tablero[3][3]= {"","","","","","","","",""};
char simbolo='V';

char Jugadas();
int verificarGanador();
void CrearTablero();
void Guardar(char Jugada);

int main(void) {
    for(int i=0; i<9; i++) {
        CrearTablero();
        if(i%2==1) simbolo='X';
        else simbolo='O';
        Guardar(Jugadas());
        if(verificarGanador()==1)printf("ganaste \n");
        system("cls");
    }
    return 0;
}

void CrearTablero() {
    int x=0,y=0;
    for(int i=0; i<6; i++) {
        for(int j=0; j<3; j++) {
            if(i%2==1 && i<5) printf("___");
            else {
                if(i<5) {
                    printf(" %c ",tablero[x][y]);
                    y++;
                } else {
                    printf("   ");
                }
            }
            if(j<2) printf("|");
        }
        printf("\n");
    }
}

char Jugadas() {
    int contador =0;
    char opc[9]="abcdefghi";
    printf("\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%c [ %d , %d ]",opc[contador], i, j);
            contador++;
            if(strcmp(&tablero[i][j],&"")!=0) {
                printf("ocupado");
            }
            printf("\n");
        }
    }
    char opcion[1];
    printf("\nOpcion: ");
    scanf("%s",&opcion);
    return opcion[0];
}
void Guardar(char Jugada) {
    switch(Jugada) {
        case 'a':
            tablero[0][0]=simbolo;
            break;
        case 'b':
            tablero[0][1]=simbolo;
            break;
        case 'c':
            tablero[0][2]=simbolo;
            break;
        case 'd':
            tablero[1][0]=simbolo;
            break;
        case 'e':
            tablero[1][1]=simbolo;
            break;
        case 'f':
            tablero[1][2]=simbolo;
            break;
        case 'g':
            tablero[2][0]=simbolo;
            break;
        case 'h':
            tablero[2][1]=simbolo;
            break;
        case 'i':
            tablero[2][2]=simbolo;
            break;
    }
}

int verificarGanador() {
    if(tablero[0][0]==tablero[0][1] && tablero[0][1]==tablero[0][2] && tablero[0][2]!=NULL) return 1;
    if(tablero[1][0]==tablero[1][1] && tablero[1][1]==tablero[1][2] && tablero[1][2]!=NULL) return 1;
    if(tablero[2][0]==tablero[2][1] && tablero[2][1]==tablero[2][2] && tablero[2][2]!=NULL) return 1;
    if(tablero[0][0]==tablero[1][0] && tablero[1][0]==tablero[2][0] && tablero[2][0]!=NULL) return 1;
    if(tablero[0][1]==tablero[1][1] && tablero[1][1]==tablero[1][1] && tablero[1][1]!=NULL) return 1;
    if(tablero[0][2]==tablero[1][2] && tablero[1][2]==tablero[2][2] && tablero[2][2]!=NULL) return 1;
    if(tablero[0][0]==tablero[1][1] && tablero[1][1]==tablero[2][2] && tablero[2][2]!=NULL) return 1;
    if(tablero[0][2]==tablero[1][1] && tablero[1][1]==tablero[2][0] && tablero[2][0]!=NULL) return 1;
    return 0;
}
