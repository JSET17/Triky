#include <stdio.h>
#include <stdlib.h>

char tablero[3][3]= {"","","","","","","","",""};
char simbolo='V';
int opc;
char jugador1[15];
char jugador2[15];
char maquina[10] = "Maquina";
char input[10];

char Jugadas();
int verificarGanador();
void CrearTablero();
void Guardar(char Jugada);
void iniciarJuego(void);
void inicio();
void jugadorVsJugador();
void jugadorVsMaquina();

int main() {
    inicio();
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

char Jugadas(int turno) {
    int contador = 0;
    char opc[9]="abcdefghi";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%c [ %d , %d ]",opc[contador], i, j);
            contador++;
            if(strcmp(&tablero[i][j],&"")!=0){
                printf("ocupado");
            }
            printf("\n");
        }
    }

    if (turno == 0) {
        printf("\nTurno de %s: ", jugador1);
        simbolo = 'X';
    } else {
        printf("\nTurno de %s: ", jugador2);
        simbolo = 'O';
    }

    char opcion[1];
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

void iniciarJuego(void) {
    system("cls");
    int turno = 0;
    for(int i=0; i<9; i++) {
        CrearTablero();
        Guardar(Jugadas(turno));
        turno = (turno + 1) % 2;
        if(verificarGanador()==1) {
            printf("¡%s ha ganado!\n", turno == 0 ? jugador1 : jugador2);
            break;
        }
        system("cls");
    }
}

void inicio() {
    do {
        system("cls");
        printf("-----Triky-----\n\n");
        printf("1. Jugador vs Jugador.\n");
        printf("2. Salir.\n\n");

        printf("Opcion: ");
        scanf("%d", &opc);

        switch(opc) {
            case 1:
                jugadorVsJugador();
                break;
            case 2:
                system("cls");
                printf("\nHasta pronto...\n\n");
                system("pause");
                break;
            default:
                system("cls");
                printf("\nError: Opcion incorrecta.\n\n");
                system("pause");
                break;
        }
    } while(opc != 2);
}

void jugadorVsJugador(){
    system("cls");

    printf("\nNombre de jugador 1: ");
    fgets(jugador1, 15, stdin);
    jugador1[strcspn(jugador1, "\n")] = '\0';

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Nombre de jugador 2: ");
    fgets(jugador2, 15, stdin);
    jugador2[strcspn(jugador2, "\n")] = '\0';

    iniciarJuego();
}
