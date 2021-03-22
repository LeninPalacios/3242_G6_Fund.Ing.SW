#include <stdio.h>
#include <Windows.h>
#define precioh 25

int i,x1,x2,y1,y2,x,y,b1,b2;
struct Paciente{
    char nomp[15][20],sexo[15][9],medic[15][9],direc[15][50];
    long int cip[15],ci1;
    long long int telefp[15];
    int edad[15];
};
Paciente p1;
struct Cliente{
    char nomc[15][20],paren[15][9],fecha[15][20],hora[15][20];
    long int cic[15],ci2;
    long long telefc[15];
    int hora_ser[15];
};
Cliente c1;
struct Personal{
    char nomper[15][20],sexoper[15][10],experiencia[15][20],nivel[15][15],idiomas[15][30];
    int cod[15],califi[15];
    long long int telefper[15];
};
Personal per;

int j=0,k=5,precio[15],confir,j2=0,k2=5;

void gotoxy(int x,int y){
    HANDLE hCon;
    hCon=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X=x;
    dwPos.Y=y;
    SetConsoleCursorPosition(hCon,dwPos);
}
void cuadro(int x1,int y1,int x2,int y2){
    int i;
    for(i=x1;i<x2;i++){
        gotoxy(i,y1);printf("=");
        gotoxy(i,y2);printf("=");
    }
    for(i=y1;i<y2;i++){
        gotoxy(x1,i);printf("|");
        gotoxy(x2,i);printf("|");
    }
    gotoxy(x1,y1);printf("=");
    gotoxy(x1,y2);printf("=");
    gotoxy(x2,y1);printf("=");
    gotoxy(x2,y2);printf("=");
}

long int validarcedula(long int ci,int j){
    int z,A[10],mul,sumimp,sump,sum,c,dcsup,digitov,v;
    long int coc,ced;
    do{
        ced=ci;
        sumimp=0;
        sump=0;
        z=9;
        if(ci<999999999)
            A[0]=0;
        do{
            coc=ci/10;
            A[z]=ci%10;
            ci=coc;
            z--;
        }while(ci!=0);

        for(z=0;z<9;z+=2){
            mul=A[z]*2;
            if(mul>9)
                mul-=9;
            sump+=mul;
        }
        for(z=1;z<8;z+=2){
            sumimp+=A[z];
        }
        sum=sump+sumimp;
        c=sum/10;
        dcsup=c*10+10;
        digitov=dcsup-sum;
        if(digitov==10)
            digitov=0;
        if(digitov==A[9]){
            return(ced);
            v=1;
        }else{
                              //12345678901234567890123456789012
            gotoxy(2,22);printf("Error, ingrese cedula valida: ");
            gotoxy(32,22);scanf("%ld",&ci);
            v=0;
        }
    }while(v==0);
}

void ingresar_paciente(){
    int v;
    cuadro(0,20,115,28);//cuadro ingreso
    cuadro(1,18,22,20);//cuadro "datos de paciente"
    cuadro(0,0,115,28);//margen
    cuadro(50,1,64,3);//cuadro titulo
    gotoxy(52,2);printf("Hogar Feliz\n\n");
    //funcion ingresar paciente
    gotoxy(2,19);printf("Datos del paciente:");
                      //1234567890123456789012345678901234
    gotoxy(2,21);printf("Nombre y apellido del Paciente: ");
    gotoxy(2,22);printf("Cedula: ");
    gotoxy(2,23);printf("Edad del paciente: ");
    gotoxy(2,24);printf("Sexo: ");
    gotoxy(2,25);printf("Telefono: ");
    gotoxy(2,26);printf("¿Toma medicamentos?(Si/No): ");
    gotoxy(2,27);printf("Direccion: ");
    fflush(stdin);
    gotoxy(34,21);gets(p1.nomp[j]);
    gotoxy(10,22);scanf("%ld",&p1.ci1);
    p1.cip[j]=validarcedula(p1.ci1,j);
    gotoxy(21,23);scanf("%d",&p1.edad[j]);
    fflush(stdin);
    gotoxy(8,24);gets(p1.sexo[j]);
    gotoxy(12,25);scanf("%lld",&p1.telefp[j]);
    gotoxy(30,26);scanf("%s",&p1.medic[j]);
    gotoxy(13,27);scanf("%s",&p1.direc[j]);

}
void imprimir_paciente(){
    //funcion imprimir paciente
    k=5;
                     //1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
    gotoxy(2,4);printf("| Nombre del Paciente |CI del Paciente|Edad|   Sexo    |    Telefono  |Medicamentos|Direccion|");
    for(int i=0;i<=j;i++){
        gotoxy(3,k);puts(p1.nomp[i]);
        //if(ci<999999999){
            //gotoxy(27,k);printf("0%ld",p1.cip[i]);
        //}
        gotoxy(27,k);printf("%ld",p1.cip[i]);
        gotoxy(42,k);printf("%d",p1.edad[i]);
        gotoxy(46,k);puts(p1.sexo[i]);
        gotoxy(59,k);printf("%lld",p1.telefp[i]);
        gotoxy(73,k);printf("%s",p1.medic[i]);
        gotoxy(86,k);printf("%s",p1.direc[i]);
        k++;
    }
}

int salir(int a){
                        //7890123456789012345678901234567890123456789
    gotoxy(47,23);printf("Ingrese 1 para terminar el programa: ");
    gotoxy(84,23);scanf("%d",&a);
    return(a);
}
void borrar2(){
    gotoxy(b1,b2);printf("             ");
}
void borrar(){
    gotoxy(47,24);system("pause");
    system("cls");
}
void precio_cliente(){
    precio[j]=c1.hora_ser[j]*precioh;
}
void ingresar_cliente(){
    //datos de la persona a cargo
    cuadro(0,20,115,28);//cuadro ingreso
    cuadro(1,18,31,20);//cuadro "datos de paciente"
    cuadro(0,0,115,28);//margen
    cuadro(50,1,64,3);//cuadro titulo
    gotoxy(52,2);printf("Hogar Feliz\n\n");
    //funcion ingresar paciente
    gotoxy(2,19);printf("Datos del cliente:");
                      //1234567890123456789012345678901234567890123456
    gotoxy(2,21);printf("Nombre y apellido: ");
    gotoxy(2,22);printf("Cedula: ");
    gotoxy(2,23);printf("Parentesco: ");
    gotoxy(2,24);printf("Telefono: ");
    gotoxy(2,25);printf("Numero de horas que desea el servicio: ");
    gotoxy(2,26);printf("Fecha: ");
    gotoxy(2,27);printf("Hora: ");
    fflush(stdin);
    gotoxy(21,21);gets(c1.nomc[j]);
    gotoxy(10,22);scanf("%ld",&c1.ci2);
    c1.cic[j]=validarcedula(c1.ci2,j);
    gotoxy(14,23);scanf("%s",&c1.paren[j]);
    gotoxy(12,24);scanf("%lld",&c1.telefc[j]);
    gotoxy(41,25);scanf("%d",&c1.hora_ser[j]);
    fflush(stdin);
    gotoxy(9,26);scanf("%[^\n]",c1.fecha[j]);
    fflush(stdin);
    gotoxy(8,27);scanf("%[^\n]",c1.hora[j]);
}
void imprimir_cliente(){
    //funcion imprimir paciente
    k=5;
                     //1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
    gotoxy(2,4);printf("| Nombre del Cliente |CI del Cliente|Parentesco|  Telefono  |Hrs. Servicio| Fecha  | Hora | Precio");
    for(int i=0;i<=j;i++){
        gotoxy(3,k);puts(c1.nomc[i]);
        gotoxy(25,k);printf("%ld",c1.cic[i]);
        gotoxy(39,k);printf("%s",c1.paren[i]);
        gotoxy(50,k);printf("%lld",c1.telefc[i]);
        gotoxy(67,k);printf("%d",c1.hora_ser[i]);
        gotoxy(77,k);printf("%s",c1.fecha[i]);
        gotoxy(86,k);printf("%s",c1.hora[i]);
        gotoxy(94,k);printf("%d",precio[i]);
        k++;
    }
}
void imprimir_personal(){
    gotoxy(3,k2);printf("%d",per.cod[j2]);
    gotoxy(12,k2);puts(per.nomper[j2]);
    gotoxy(34,k2);printf("%lld",per.telefper[j2]);
    gotoxy(47,k2);printf("%s",per.sexoper[j2]);
    gotoxy(57,k2);puts(per.experiencia[j2]);
    gotoxy(69,k2);printf("%s",per.nivel[j2]);
    gotoxy(87,k2);puts(per.idiomas[j2]);
    //gotoxy(94,k2);printf("%d",per.califi[j2]);
    k2++;
}
void ingresar_personal(){
    int postul;
                     //1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
    gotoxy(2,4);printf("| Codigo | Nombre del Personal |  Telefono  |   Sexo  |Experiencia| Nivel academico | Idiomas ");
    do{
        //postulacion de personal
        cuadro(0,20,115,28);//cuadro ingreso
        cuadro(1,18,22,20);//cuadro "datos del personal"
        cuadro(0,0,115,28);//margen
        cuadro(50,1,64,3);//cuadro titulo
        gotoxy(52,2);printf("Hogar Feliz\n\n");
        gotoxy(2,19);printf("Datos del personal:");
                          //1234567890123456789012345678901234567890123456
        gotoxy(2,21);printf("Codigo: ");
        gotoxy(2,22);printf("Nombre: ");
        gotoxy(2,23);printf("Telefono: ");
        gotoxy(2,24);printf("Sexo: ");
        gotoxy(2,25);printf("Tiempo de experiencia: ");
        gotoxy(2,26);printf("Nivel academico (Tercer/Cuarto): ");
        gotoxy(2,27);printf("Idiomas que domina: ");
        gotoxy(10,21);scanf("%d",&per.cod[j2]);
        fflush(stdin);
        gotoxy(10,22);gets(per.nomper[j2]);
        gotoxy(12,23);scanf("%lld",&per.telefper[j2]);
        gotoxy(8,24);scanf("%s",&per.sexoper[j2]);
        fflush(stdin);
        gotoxy(25,25);gets(per.experiencia[j2]);
        gotoxy(35,26);scanf("%s",&per.nivel[j2]);
        fflush(stdin);
        gotoxy(22,27);gets(per.idiomas[j2]);
        gotoxy(23,24);printf("Ingrese 1 para terminar la postulacion: ");
        gotoxy(63,24);scanf("%d",&postul);
        imprimir_personal();
        b1=10;b2=21;
        borrar2();
        b1=10;b2=22;
        borrar2();
        b1=12;b2=23;
        borrar2();
        b1=8;b2=24;
        borrar2();
        b1=25;b2=25;
        borrar2();
        b1=35;b2=26;
        borrar2();
        b1=22;b2=27;
        borrar2();
        b1=63;b2=24;
        borrar2();
    }while(postul!=1);
}
int main(){
    int a;
    do{
        do{
            //borrar_paciente();
            ingresar_paciente();
            imprimir_paciente();
            borrar();
            ingresar_cliente();
            precio_cliente();
            gotoxy(20,27);printf("El costo es %d presione 1 para confirmar pago: ",precio[j]);
            gotoxy(70,27);scanf("%d",&confir);
            if(confir==1){
                imprimir_cliente();
                borrar();
                ingresar_personal();
            }
            borrar();
        }while(confir!=1);
        a=salir(a);
        j++;
        k++;
    }while(a!=1&&k<15);
    borrar();
    return 0;
}
