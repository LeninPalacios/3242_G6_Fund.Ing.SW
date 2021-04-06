#include <stdio.h>
#include <cstring>
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
    char nomeleg[15][20];
    int cod[15],califi[15],codele[15];
    float ganancia[15],empresa[15],calificacion[15][2],notas[15][4];
    long long int telefper[15],telefele[15];
    float total_personal=0,total_ingreso=0;
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
    int z,A[10],mul,sumimp,sump,sum,c,dcsup,digitov,v=0;
    long int coc,ced;
    do{
        for(i=0;i<10;i++)
            A[i]=-1;
        ced=ci;
        sumimp=0;
        sump=0;
        z=9;
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
            gotoxy(2,22);printf("Error, ingrese cedula valida:           ");
            gotoxy(32,22);scanf("%ld",&ci);
            v=0;
        }
    }while(v==0);
}
void borrar(){
    gotoxy(47,24);system("pause");
    system("cls");
}
void ingresar_paciente(){
    system("cls");
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
    gotoxy(2,24);printf("Sexo (M/F): ");
    gotoxy(2,25);printf("Telefono: ");
    gotoxy(2,26);printf("Toma medicamentos?(Si/No): ");
    gotoxy(2,27);printf("Direccion: ");
    fflush(stdin);
    gotoxy(34,21);gets(p1.nomp[j]);
    gotoxy(10,22);scanf("%ld",&p1.ci1);
    p1.cip[j]=validarcedula(p1.ci1,j);
    gotoxy(21,23);scanf("%d",&p1.edad[j]);
    while(p1.edad[j]<60||p1.edad[j]>110){
        gotoxy(2,23);printf("Edad del paciente:        ");
        gotoxy(21,23);scanf("%d",&p1.edad[j]);
    }
    fflush(stdin);
    gotoxy(14,24);gets(p1.sexo[j]);
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
    gotoxy(29,24);printf("Ingrese 1 para continuar el programa 2 para salir: ");
    scanf("%d",&a);
    while(a!=1&&a!=2){
        gotoxy(29,24);printf("Error, Ingrese 1 para continuar el programa 2 para salir:      ");
        gotoxy(87,24);scanf("%d",&a);
    }
    return(a);
}
void borrar2(){
    gotoxy(b1,b2);printf("             ");
}

void precio_cliente(){
    precio[j]=c1.hora_ser[j]*precioh;
    per.ganancia[j]=precio[j]-c1.hora_ser[j]*10;
    per.empresa[j]=c1.hora_ser[j]*10;
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
    gotoxy(2,26);printf("Fecha (dd/mm/aa): ");
    gotoxy(2,27);printf("Hora (h:m): ");
    fflush(stdin);
    gotoxy(21,21);gets(c1.nomc[j]);
    gotoxy(10,22);scanf("%ld",&c1.ci2);
    c1.cic[j]=validarcedula(c1.ci2,j);
    gotoxy(14,23);scanf("%s",&c1.paren[j]);
    gotoxy(12,24);scanf("%lld",&c1.telefc[j]);
    gotoxy(41,25);scanf("%d",&c1.hora_ser[j]);
    while(c1.hora_ser[j]<0){
        gotoxy(2,25);printf("Error, Ingrese numero de horas positivo:    ");
        gotoxy(43,25);scanf("%d",&c1.hora_ser[j]);
    }
    fflush(stdin);
    gotoxy(20,26);scanf("%[^\n]",c1.fecha[j]);
    fflush(stdin);
    gotoxy(14,27);scanf("%[^\n]",c1.hora[j]);
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
void inicializar(){
    for(i=0;i<15;i++){
        per.calificacion[i][1]=20;
    }
}
void promedio(int i2){
    for(i=0;i<4;i++)
        per.calificacion[i2][1]+=per.notas[j-1][i];
    per.calificacion[i2][1]=per.calificacion[i2][1]/2;
}
void imprimir_personal(){
    int i2;
    gotoxy(3,k2);printf("%d",per.cod[j2]);
    gotoxy(12,k2);puts(per.nomper[j2]);
    gotoxy(34,k2);printf("%lld",per.telefper[j2]);
    gotoxy(47,k2);printf("%s",per.sexoper[j2]);
    gotoxy(57,k2);puts(per.experiencia[j2]);
    gotoxy(69,k2);printf("%s",per.nivel[j2]);
    gotoxy(87,k2);puts(per.idiomas[j2]);
    i2=0;
    while(i2<15){
        if(per.cod[j2]==per.calificacion[i2][0]){
            promedio(i2);
                            //234567890123456789012345678901234567890
            gotoxy(98,k2);printf("%.2f",per.calificacion[i2][1]);
        }
        i2++;
    }
    k2++;
}
void encuesta(){
    system("cls");
    i=0;
    cuadro(0,0,115,28);//margen
    cuadro(42,1,65,3);//cuadro titulo
    gotoxy(45,2);printf("Hogar Feliz Encuesta\n\n");
    cuadro(16,4,90,27);
                     //67890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
    gotoxy(31,5);printf("Por favor, conteste la siguiente encuesta");
    gotoxy(31,6);printf("Del 1 al 5, siendo 1 la minima puntuacion y 5 la maxima");
                    //21 1234567890123456789012345678901234567890123456789012345678901234567890
    gotoxy(21,8);printf("1. Cuan satisfecho se encuentra en general?: ");
    gotoxy(21,10);printf("2. Cuan probable es que recmiende el servicio?: ");
    gotoxy(21,12);printf("3. Como calificaria la calidad del servicio?: ");
    gotoxy(21,14);printf("4. Cuan probable es que vuelva a contratar nuestro servicio?: ");
    gotoxy(67,8);scanf("%f",&per.notas[j][i]);
    while(per.notas[j][i]<1||per.notas[j][i]>5){
        gotoxy(21,9);printf("Ingrese un valor del 1 al 5:   ");
        gotoxy(49,9);scanf("%f",&per.notas[j][i]);
    }
    gotoxy(70,10);scanf("%f",&per.notas[j][i+1]);
    while(per.notas[j][i+1]<1||per.notas[j][i+1]>5){
        gotoxy(21,11);printf("Ingrese un valor del 1 al 5:   ");
        gotoxy(49,11);scanf("%f",&per.notas[j][i+1]);
    }
    gotoxy(69,12);scanf("%f",&per.notas[j][i+2]);
    while(per.notas[j][i+2]<1||per.notas[j][i+2]>5){
        gotoxy(21,13);printf("Ingrese un valor del 1 al 5:   ");
        gotoxy(49,13);scanf("%f",&per.notas[j][i+2]);
    }
    gotoxy(84,14);scanf("%f",&per.notas[j][i+3]);
    while(per.notas[j][i+3]<1||per.notas[j][i+3]>5){
        gotoxy(21,15);printf("Ingrese un valor del 1 al 5:   ");
        gotoxy(49,15);scanf("%f",&per.notas[j][i+3]);
    }
}

void ingresar_personal(){
    int postul,i2,eleccion,salida,c=0;
    k2=5;j2=0;
                     //1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
    gotoxy(2,4);printf("| Codigo | Nombre del Personal |  Telefono  |   Sexo  |Experiencia| Nivel academico | Idiomas | Calificacion");
    do{
        //postulacion de personal
        cuadro(0,20,115,28);//cuadro ingreso
        cuadro(1,18,22,20);//cuadro "datos del personal"
        cuadro(0,0,115,28);//margen
        cuadro(50,1,64,3);//cuadro titulo
        gotoxy(52,2);printf("Hogar Feliz\n\n");
        gotoxy(2,19);printf("Datos del personal:");
                          //1234567890123456789012345678901234567890123456
        b1=2;b2=21;
        borrar2();
        b1=16;b2=21;
        borrar2();
        b1=29;b2=21;
        borrar2();
        c=0;
        gotoxy(2,21);printf("                                ");
        gotoxy(2,21);printf("Codigo:                                ");
        gotoxy(2,22);printf("Nombre:                 ");
        gotoxy(2,23);printf("Telefono:             ");
        gotoxy(2,24);printf("Sexo (M/F):           ");
        gotoxy(2,25);printf("Tiempo de experiencia:           ");
        gotoxy(2,26);printf("Nivel academico (Tercer/Cuarto):           ");
        gotoxy(2,27);printf("Idiomas que domina:           ");
        gotoxy(10,21);scanf("%d",&per.cod[j2]);
        i2=j2;
        while(i2>0){
            i2--;
            if(per.cod[i2]==per.cod[j2]){
                                   //234567890123456789012345678901234567890
                gotoxy(2,21);printf("Error, ingrese codigo diferente:      ");
                gotoxy(35,21);scanf("%d",&per.cod[j2]);
                i2=j2;
            }
        }
        i2=j2;
        while(i2>=0){
            if(per.codele[i2]==per.cod[j2]){
                c=1;
            }
            i2--;
        }
        if(c!=1){
            fflush(stdin);
            gotoxy(10,22);gets(per.nomper[j2]);
            gotoxy(12,23);scanf("%lld",&per.telefper[j2]);
            gotoxy(14,24);scanf("%s",&per.sexoper[j2]);
            fflush(stdin);
            gotoxy(25,25);gets(per.experiencia[j2]);
            gotoxy(35,26);scanf("%s",&per.nivel[j2]);
            fflush(stdin);
            gotoxy(22,27);gets(per.idiomas[j2]);
        }
        imprimir_personal();
                        //33 3345678901234567890123456789012345678901234567890123456789012345678901234567890
        gotoxy(33,22);printf("Ingrese 1 para terminar la postulacion 2 para ingresar nueva postulacion:   ");
        gotoxy(106,22);scanf("%d",&postul);
        while(postul!=1&&postul!=2){
            gotoxy(33,22);printf("Ingrese 1 para terminar la postulacion 2 para ingresar nueva postulacion:   ");
            gotoxy(106,22);scanf("%d",&postul);
        }
        b1=73;b2=22;
        borrar2();
        if(postul!=1)
            j2++;
    }while(postul!=1);
    gotoxy(33,23);printf("Ingrese el codigo del personal elegido:     ");
    gotoxy(73,23);scanf("%d",&eleccion);
    i2=j2;
    do{
        if(eleccion==per.cod[i2]){
            strcpy(per.nomeleg[j],per.nomper[i2]);
            per.codele[j]=per.cod[i2];
            per.telefele[j]=per.telefper[i2];
            per.calificacion[i2][0]=per.codele[j];
            salida=1;
        }else{
            i2--;
            salida=0;
        }
        if(i2<0){
            gotoxy(33,23);printf("Error, Ingrese un codigo valido:                  ");
            gotoxy(66,23);scanf("%d",&eleccion);
            i2=j2;
            salida=0;
        }
    }while(salida==0);
}
void recibo(){
    system("cls");
    cuadro(0,0,115,28);//margen
    cuadro(50,1,71,3);//cuadro titulo
    gotoxy(52,2);printf("Hogar Feliz Recibo\n\n");
    cuadro(33,4,82,27);
                     //67890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
    gotoxy(38,5);printf("Nombre del Cliente:        ");puts(c1.nomc[j]);
    gotoxy(38,7);printf("Cedula del Cliente:        %ld",c1.cic[j]);
    gotoxy(38,9);printf("Nombre del Paciente:       ");puts(p1.nomp[j]);
    gotoxy(38,11);printf("Cedula del Paciente:       %ld",p1.cip[j]);
    gotoxy(38,13);printf("Direccion del Paciente:    %s",p1.direc[j]);
    gotoxy(38,15);printf("Horas del servicio:        %d",c1.hora_ser[j]);
    gotoxy(38,17);printf("Costo total del Servicio:  $%d",precio[j]);
    gotoxy(38,19);printf("Servicio brindado por:     ");puts(per.nomeleg[j]);
    gotoxy(38,21);printf("Telefono:                  %lld",per.telefele[j]);
    gotoxy(38,24);system("pause");
    system("cls");
    cuadro(0,0,115,28);//margen
    cuadro(43,1,73,3);//cuadro titulo
    gotoxy(45,2);printf("Hogar Feliz Recibo Personal\n\n");
    cuadro(36,4,79,27);
                     //67890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
    gotoxy(38,5);printf("Nombre del Personal:    ");puts(per.nomeleg[j]);
    gotoxy(38,7);printf("Codigo del personal:    %ld",per.codele[j]);
    gotoxy(38,9);printf("Ingreso del personal:   $%.2f",per.ganancia[j]);
    gotoxy(38,11);printf("Telefono:               %lld",per.telefele[j]);
    gotoxy(38,24);system("pause");
}
void reporte(){
    system("cls");
    for(i=0;i<j;i++){
        per.total_personal+=per.ganancia[i];
        per.total_ingreso+=per.empresa[i];
    }
    cuadro(0,0,115,28);//margen
    cuadro(43,1,73,3);//cuadro titulo
    gotoxy(45,2);printf("Hogar Feliz Reporte Final\n\n");
    cuadro(36,4,79,27);
                     //67890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
    gotoxy(38,5);printf("Cantidad de pacientes atendidos:  %d",j);
    gotoxy(38,7);printf("Pago total del Personal:          $%.2f",per.total_personal);
    gotoxy(38,9);printf("Ingreso de la Empresa:            $%.2f",per.total_ingreso);
    gotoxy(38,24);system("pause");
}
int main(){
    int a;
    inicializar();
    do{
        do{
            //borrar_paciente();
            ingresar_paciente();
            imprimir_paciente();
            borrar();
            ingresar_cliente();
            precio_cliente();
            gotoxy(46,26);printf("El costo es %d ",precio[j]);
            gotoxy(46,27);printf("Presione 1 para confirmar pago 2 para repetir: ");
            scanf("%d",&confir);
            while(confir!=1&&confir!=2){
                gotoxy(46,27);printf("Error, presione 1 para confirmar pago, 2 para repetir:      ");
                gotoxy(101,27);scanf("%d",&confir);
            }
            if(confir==1){
                imprimir_cliente();
                borrar();
                ingresar_personal();
                recibo();
                encuesta();
            }
            gotoxy(38,24);system("pause");
        }while(confir==2);
        a=salir(a);
        j++;
        k++;
    }while(a==1&&k<15);
    reporte();
    return 0;
}
