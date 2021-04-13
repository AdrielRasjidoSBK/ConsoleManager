#ifndef CONSOLEMANAGER_H_INCLUDED
#define CONSOLEMANAGER_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<string.h>
#include<windows.h>
#include<iostream>
#include<conio.h>
#include<time.h>

using namespace std;


/**
Version 1.X
Fundadores de la biblioteca "ConsoleManager" - Adriel Elian Rasjido - Alan Gabriel Vaca
Biblioteca Colaborativa - UTN FRGP.

Integrantes:
-Adriel Elian Rasjido
-Alan Gabriel Vaca
-José Enrique Menéndez Fernández

AVISO*****(esta es una biblioteca para soporte visual y/o funciones secundarias,
           idea para acortar el tiempo de diseño y asi los usuarios puedan
           enfocarse en la logica)

¿QUIEN PUEDE USARLO?
En primera instacia fue creada para los alumnos o cursantes de la UTN
Aunque la implementacion puede ser usada fuera de la misma
SIEMPRE Y CUANDO, NO ALTEREN EL PRODUCTO, TAMPOCO LA ELIMINACION DE LOS
ARCHIVOS ADJUNTOS AL DESCARGABLE

ADVERTENCIA:Contiene una licencia MIT, NO debe ser borrada ni alterada
            para no incumplir las leyes y condiciones de privacidad
            (SI PUBLICAS TU PROYECTO/PROGRAMA UTILIZANDO ESTA BIBLIOTECA
            PUEDES USARLA SIEMPRE Y CUANDO NO INCUMPLAS LO ANTES PROPUESTO,
            ESTO ADMITE EL PODER VENDERLO PERO SIN ALTERACIONES)

¿PUEDO FORMAR PARTE DEL PROYECTO?
SI, ingresa al siguiente LINK: https://discord.gg/a4ZJh8XDwf
DEBES JUSTIFICAR QUE SOS ALUMNO O CURSANTE DE LA UTN (Presentando LEGAJO, INSCRIPCION y MATERIA)
Y ser aprobado por los administradores en un cuestionario.
¿QUÉ PASA SI NO SOY ACEPTADO?
Puedes ser postulante de ideas que seran usadas para futuras actualizacion.
**/

///Titulo
void titulo(const char* nombrar){SetConsoleTitle(nombrar);}

///Gotoxy
void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos; dwPos.X = x; dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }

/**
Visualizadores:
*/
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//Al llamar esta funcion mostrar la ubicacion del cursor
void cursor(bool estado){
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = estado;
    SetConsoleCursorInfo(out, &cursorInfo);
}
//Al llamar esta funcion se podra crear recuadros
void recuadro(short x, short y, short ancho, short alto){
    int i, j;
    for(i=x; i<=x+ancho; i++){
        for(j=y; j<=y+alto; j++){gotoxy(i, j);
            if(i==x && j==y){cout << (char) 201;}                               ///ARRIBA  - IZQUIERDA
            else if(i==x+ancho && j==y){cout << (char) 187;}                    ///ARRIBA  - DERECHA
            else if(i==x && j==y+alto){cout << (char) 200;}                     ///ABAJO   - IZQUIERDA
            else if(i==x+ancho && j==y+alto){cout << (char) 188;}               ///ABAJO   - DERECHA
            else if(j==y || j==y+alto){cout << (char) 205;}                     ///ARRIBA  - ABAJO
            else if(i==x || i==x+ancho){cout << (char) 186;}                    ///DERECHA - IZQUIERDA
            else{cout << " ";}                                                  ///DENTRO DEL RECUADRO
        }
    }
}
//Se podra visualizar toda la gama completa de colores
void gamaColores(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for(int k = 1; k < 255; k++){SetConsoleTextAttribute(hConsole, k);
    cout << k << " Gracias por usar ConsoleManager :)" << endl;
  }
}
/**
Colores:
*/
//Al llamar esta funcion se solicitara el nombre del color en español
void color(const char* nombre){
if(strcmp(nombre,"negro")==0)           {SetConsoleTextAttribute(hConsole,0);}
else if(strcmp(nombre,"azul")==0)       {SetConsoleTextAttribute(hConsole,1);}
else if(strcmp(nombre,"verde")==0)      {SetConsoleTextAttribute(hConsole,2);}
else if(strcmp(nombre,"aguamarina")==0) {SetConsoleTextAttribute(hConsole,3);}
else if(strcmp(nombre,"rojo")==0)       {SetConsoleTextAttribute(hConsole,4);}
else if(strcmp(nombre,"purpura")==0)    {SetConsoleTextAttribute(hConsole,5);}
else if(strcmp(nombre,"amarillo")==0)   {SetConsoleTextAttribute(hConsole,6);}
else if(strcmp(nombre,"blanco")==0)     {SetConsoleTextAttribute(hConsole,7);}
else if(strcmp(nombre,"gris")==0)       {SetConsoleTextAttribute(hConsole,8);}
else if(strcmp(nombre,"celeste")==0)    {SetConsoleTextAttribute(hConsole,11);}
else if(strcmp(nombre,"default")==0)    {SetConsoleTextAttribute(hConsole,7);}
}

//Al llamar esta funcion se solicitara el nombre del color tanto del fondo como el del texto
void fondo(char* color){
if(strcmp(color,"default")==0){system("color 07");}
}
void fondo(char* color_fondo, char* color_texto){
string letra; string fondo;
if(strcmp(color_texto,"negro")==0)           {letra="0";}
else if(strcmp(color_texto,"azul")==0)       {letra="1";}
else if(strcmp(color_texto,"verde")==0)      {letra="2";}
else if(strcmp(color_texto,"aguamarina")==0) {letra="3";}
else if(strcmp(color_texto,"rojo")==0)       {letra="4";}
else if(strcmp(color_texto,"purpura")==0)    {letra="5";}
else if(strcmp(color_texto,"amarillo")==0)   {letra="6";}
else if(strcmp(color_texto,"blanco")==0)     {letra="7";}
else if(strcmp(color_texto,"gris")==0)       {letra="8";}
else if(strcmp(color_texto,"celeste")==0)    {letra="11";}

if(strcmp(color_fondo,"negro")==0)           {fondo="0";}
else if(strcmp(color_fondo,"azul")==0)       {fondo="1";}
else if(strcmp(color_fondo,"verde")==0)      {fondo="2";}
else if(strcmp(color_fondo,"aguamarina")==0) {fondo="3";}
else if(strcmp(color_fondo,"rojo")==0)       {fondo="4";}
else if(strcmp(color_fondo,"purpura")==0)    {fondo="5";}
else if(strcmp(color_fondo,"amarillo")==0)   {fondo="6";}
else if(strcmp(color_fondo,"blanco")==0)     {fondo="7";}
else if(strcmp(color_fondo,"gris")==0)       {fondo="8";}
else if(strcmp(color_fondo,"celeste")==0)    {fondo="11";}
std::string colores = "color " + fondo + letra;
system(colores.c_str());
}

/**
Menues prediseñados:
*/
//Al llamar estas funcion se te solicitara las posiciones y las opciones
///Menues verticales
int menuVertical_2(int x, int y, int ancho, char *opc1, char *opc2){
cursor(false); int opc, pos=1;
while(true){
    switch(opc){
        case 80: //ABAJO
            pos++; if(pos>2){pos=1;}
        break;
        case 72: //ARRIBA
            pos--; if(pos<1){pos=2;}
        break;
        case 13: //ENTER
            color("default"); return pos;
        }
        switch(pos){
        case 1:
            color("amarillo");
            recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            color("blanco");
            recuadro(x,y+3,ancho,2);
            gotoxy(x+2,y+4); cout << opc2;
        break;
        case 2:
            color("blanco");
            recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            color("amarillo");
            recuadro(x,y+3,ancho,2);
            gotoxy(x+2,y+4); cout << opc2;
        break;
        }
        opc = getch();
    }
}
int menuVertical_3(int x, int y, int ancho, char *opc1, char *opc2, char *opc3){
cursor(false);
int opc, pos=1;
while(true){
    switch(opc){
        case 80: //ABAJO
            pos++; if(pos>3){pos=1;}
        break;
        case 72: //ARRIBA
            pos--; if(pos<1){pos=3;}
        break;
        case 13: //ENTER
            color("default"); return pos;
        }
        switch(pos){
        case 1:
            color("amarillo");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            color("blanco");recuadro(x,y+3,ancho,2);
            gotoxy(x+2,y+4); cout << opc2;
            recuadro(x,y+6,ancho,2);
            gotoxy(x+2,y+7); cout << opc3;
        break;
        case 2:
            color("blanco");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            color("amarillo");recuadro(x,y+3,ancho,2);
            gotoxy(x+2,y+4); cout << opc2;
            color("blanco");
            recuadro(x,y+6,ancho,2);
            gotoxy(x+2,y+7); cout << opc3;
        break;
        case 3:
            color("blanco");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            recuadro(x,y+3,ancho,2);
            gotoxy(x+2,y+4); cout << opc2;
            color("amarillo");recuadro(x,y+6,ancho,2);
            gotoxy(x+2,y+7); cout << opc3;
        break;
        }opc = getch();
    }
}
int menuVertical_4(int x, int y, int ancho, char *opc1, char *opc2, char *opc3, char *opc4){
cursor(false);
int opc, pos=1;
while(true){
    switch(opc){
        case 80: //ABAJO
            pos++;if(pos>4){pos=1;}
        break;
        case 72: //ARRIBA
            pos--;if(pos<1){pos=4;}
        break;
        case 13: //ENTER
            color("default");return pos;
        }
        switch(pos){
        case 1:
            color("amarillo");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            color("blanco");recuadro(x,y+3,ancho,2);
            gotoxy(x+2,y+4); cout << opc2;
            recuadro(x,y+6,ancho,2);
            gotoxy(x+2,y+7); cout << opc3;
            recuadro(x,y+9,ancho,2);
            gotoxy(x+2,y+10); cout << opc4;
        break;
        case 2:
            color("blanco");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            color("amarillo");recuadro(x,y+3,ancho,2);
            gotoxy(x+2,y+4); cout << opc2;
            color("blanco");
            recuadro(x,y+6,ancho,2);
            gotoxy(x+2,y+7); cout << opc3;
            recuadro(x,y+9,ancho,2);
            gotoxy(x+2,y+10); cout << opc4;
        break;
        case 3:
            color("blanco");
            recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            recuadro(x,y+3,ancho,2);
            gotoxy(x+2,y+4); cout << opc2;
            color("amarillo");recuadro(x,y+6,ancho,2);
            gotoxy(x+2,y+7); cout << opc3;
            color("blanco");recuadro(x,y+9,ancho,2);
            gotoxy(x+2,y+10); cout << opc4;
        break;
        case 4:
            color("blanco");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            recuadro(x,y+3,ancho,2);
            gotoxy(x+2,y+4); cout << opc2;
            recuadro(x,y+6,ancho,2);
            gotoxy(x+2,y+7); cout << opc3;
            color("amarillo");recuadro(x,y+9,ancho,2);
            gotoxy(x+2,y+10); cout << opc4;
        break;
        }opc = getch();
    }
}
int menuVertical_5(int x, int y, int ancho, char *opc1, char *opc2, char *opc3, char *opc4, char *opc5){
cursor(false);
int opc, pos=1;
while(true){
    switch(opc){
        case 80: //ABAJO
            pos++;if(pos>5){pos=1;}
        break;
        case 72: //ARRIBA
            pos--;if(pos<1){pos=5;}
        break;
        case 13: //ENTER
            color("default");return pos;
        }
        switch(pos){
        case 1:
            color("amarillo");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            color("blanco");recuadro(x,y+3,ancho,2);
            gotoxy(x+2,y+4); cout << opc2;
            recuadro(x,y+6,ancho,2);
            gotoxy(x+2,y+7); cout << opc3;
            recuadro(x,y+9,ancho,2);
            gotoxy(x+2,y+10); cout << opc4;
            recuadro(x,y+12,ancho,2);
            gotoxy(x+2,y+13); cout << opc5;
        break;
        case 2:
            color("blanco");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            color("amarillo");recuadro(x,y+3,ancho,2);
            gotoxy(x+2,y+4); cout << opc2;
            color("blanco");
            recuadro(x,y+6,ancho,2);
            gotoxy(x+2,y+7); cout << opc3;
            recuadro(x,y+9,ancho,2);
            gotoxy(x+2,y+10); cout << opc4;
            recuadro(x,y+12,ancho,2);
            gotoxy(x+2,y+13); cout << opc5;
        break;
        case 3:
            color("blanco");
            recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            recuadro(x,y+3,ancho,2);
            gotoxy(x+2,y+4); cout << opc2;
            color("amarillo");recuadro(x,y+6,ancho,2);
            gotoxy(x+2,y+7); cout << opc3;
            color("blanco");recuadro(x,y+9,ancho,2);
            gotoxy(x+2,y+10); cout << opc4;
            recuadro(x,y+12,ancho,2);
            gotoxy(x+2,y+13); cout << opc5;
        break;
        case 4:
            color("blanco");
            recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            recuadro(x,y+3,ancho,2);
            gotoxy(x+2,y+4); cout << opc2;
            recuadro(x,y+6,ancho,2);
            gotoxy(x+2,y+7); cout << opc3;
            color("amarillo");recuadro(x,y+9,ancho,2);
            gotoxy(x+2,y+10); cout << opc4;
            color("blanco");recuadro(x,y+12,ancho,2);
            gotoxy(x+2,y+13); cout << opc5;
        break;
        case 5:
            color("blanco");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            recuadro(x,y+3,ancho,2);
            gotoxy(x+2,y+4); cout << opc2;
            recuadro(x,y+6,ancho,2);
            gotoxy(x+2,y+7); cout << opc3;
            recuadro(x,y+9,ancho,2);
            gotoxy(x+2,y+10); cout << opc4;
            color("amarillo");recuadro(x,y+12,ancho,2);
            gotoxy(x+2,y+13); cout << opc5;
        break;
        }opc = getch();
    }
}

///Menues horizontales
int menuHorizontal_2(int x,int y, int ancho, char *opc1, char *opc2){
cursor(false);
int opc, pos=1;
while(true){
    switch(opc){
        case 77: //DERECHA
            pos++;if(pos>2){pos=1;}
        break;
        case 75: //IZQUIERDA
            pos--;if(pos<1){pos=2;}
        break;
        case 13: //ENTER
            color("default");return pos;
        }
        switch(pos){
        case 1:
            color("amarillo");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            color("blanco");recuadro(x+ancho+2,y,ancho,2);
            gotoxy(x+ancho+4,y+1); cout << opc2;
        break;
        case 2:
            color("blanco");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            color("amarillo");recuadro(x+ancho+2,y,ancho,2);
            gotoxy(x+ancho+4,y+1); cout << opc2;
        break;
        }opc = getch();
    }
}
int menuHorizontal_3(int x,int y, int ancho, char *opc1, char *opc2, char *opc3){
cursor(false);
int opc, pos=1;
while(true){
    switch(opc){
        case 77: //DERECHA
            pos++;if(pos>3){pos=1;}
        break;
        case 75: //IZQUIERDA
            pos--;if(pos<1){pos=3;}
        break;
        case 13: //ENTER
            color("default");return pos;
        }
        switch(pos){
        case 1:
            color("amarillo");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            color("blanco");recuadro(x+ancho+2,y,ancho,2);
            gotoxy(x+ancho+4,y+1); cout << opc2;
            recuadro(x+ancho*2+4,y,ancho,2);
            gotoxy(x+ancho*2+6,y+1); cout << opc3;
        break;
        case 2:
            color("blanco");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            color("amarillo");
            recuadro(x+ancho+2,y,ancho,2);
            gotoxy(x+ancho+4,y+1); cout << opc2;
            color("blanco");recuadro(x+ancho*2+4,y,ancho,2);
            gotoxy(x+ancho*2+6,y+1); cout << opc3;
        break;
        case 3:
            color("blanco");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            recuadro(x+ancho+2,y,ancho,2);
            gotoxy(x+ancho+4,y+1); cout << opc2;
            color("amarillo");recuadro(x+ancho*2+4,y,ancho,2);
            gotoxy(x+ancho*2+6,y+1); cout << opc3;
        break;
        }opc = getch();
    }
}
int menuHorizontal_4(int x,int y, int ancho, char *opc1, char *opc2, char *opc3, char *opc4){
cursor(false);
int opc, pos=1;
while(true){
    switch(opc){
        case 77: //DERECHA
            pos++;if(pos>4){pos=1;}
        break;
        case 75: //IZQUIERDA
            pos--;if(pos<1){pos=4;}
        break;
        case 13: //ENTER
            color("default");return pos;
        }
        switch(pos){
        case 1:
            color("amarillo");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            color("blanco");recuadro(x+ancho+2,y,ancho,2);
            gotoxy(x+ancho+4,y+1); cout << opc2;
            recuadro(x+ancho*2+4,y,ancho,2);
            gotoxy(x+ancho*2+6,y+1); cout << opc3;
            recuadro(x+ancho*3+6,y,ancho,2);
            gotoxy(x+ancho*3+8,y+1); cout << opc4;
        break;
        case 2:
            color("blanco");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            color("amarillo");recuadro(x+ancho+2,y,ancho,2);
            gotoxy(x+ancho+4,y+1); cout << opc2;
            color("blanco");
            recuadro(x+ancho*2+4,y,ancho,2);
            gotoxy(x+ancho*2+6,y+1); cout << opc3;
            recuadro(x+ancho*3+6,y,ancho,2);
            gotoxy(x+ancho*3+8,y+1); cout << opc4;
        break;
        case 3:
            color("blanco");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            recuadro(x+ancho+2,y,ancho,2);
            gotoxy(x+ancho+4,y+1); cout << opc2;
            color("amarillo");recuadro(x+ancho*2+4,y,ancho,2);
            gotoxy(x+ancho*2+6,y+1); cout << opc3;
            color("blanco");
            recuadro(x+ancho*3+6,y,ancho,2);
            gotoxy(x+ancho*3+8,y+1); cout << opc4;
        break;
        case 4:
            color("blanco");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            recuadro(x+ancho+2,y,ancho,2);
            gotoxy(x+ancho+4,y+1); cout << opc2;
            recuadro(x+ancho*2+4,y,ancho,2);
            gotoxy(x+ancho*2+6,y+1); cout << opc3;
            color("amarillo");recuadro(x+ancho*3+6,y,ancho,2);
            gotoxy(x+ancho*3+8,y+1); cout << opc4;
        break;
        }opc = getch();
    }
}
int menuHorizontal_5(int x,int y, int ancho, char *opc1, char *opc2, char *opc3, char *opc4, char *opc5){
cursor(false);
int opc, pos=1;
while(true){
    switch(opc){
        case 77: //DERECHA
            pos++;if(pos>5){pos=1;}
        break;
        case 75: //IZQUIERDA
            pos--;if(pos<1){pos=5;}
        break;
        case 13: //ENTER
            color("default");return pos;
        }
        switch(pos){
        case 1:
            color("amarillo");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            color("blanco");recuadro(x+ancho+2,y,ancho,2);
            gotoxy(x+ancho+4,y+1); cout << opc2;
            recuadro(x+ancho*2+4,y,ancho,2);
            gotoxy(x+ancho*2+6,y+1); cout << opc3;
            recuadro(x+ancho*3+6,y,ancho,2);
            gotoxy(x+ancho*3+8,y+1); cout << opc4;
            recuadro(x+ancho*4+8,y,ancho,2);
            gotoxy(x+ancho*4+10,y+1); cout << opc5;
        break;
        case 2:
            color("blanco");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            color("amarillo");recuadro(x+ancho+2,y,ancho,2);
            gotoxy(x+ancho+4,y+1); cout << opc2;
            color("blanco");
            recuadro(x+ancho*2+4,y,ancho,2);
            gotoxy(x+ancho*2+6,y+1); cout << opc3;
            recuadro(x+ancho*3+6,y,ancho,2);
            gotoxy(x+ancho*3+8,y+1); cout << opc4;
            recuadro(x+ancho*4+8,y,ancho,2);
            gotoxy(x+ancho*4+10,y+1); cout << opc5;
        break;
        case 3:
            color("blanco");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            recuadro(x+ancho+2,y,ancho,2);
            gotoxy(x+ancho+4,y+1); cout << opc2;
            color("amarillo");recuadro(x+ancho*2+4,y,ancho,2);
            gotoxy(x+ancho*2+6,y+1); cout << opc3;
            color("blanco");
            recuadro(x+ancho*3+6,y,ancho,2);
            gotoxy(x+ancho*3+8,y+1); cout << opc4;
            recuadro(x+ancho*4+8,y,ancho,2);
            gotoxy(x+ancho*4+10,y+1); cout << opc5;
        break;
        case 4:
            color("blanco");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            recuadro(x+ancho+2,y,ancho,2);
            gotoxy(x+ancho+4,y+1); cout << opc2;
            recuadro(x+ancho*2+4,y,ancho,2);
            gotoxy(x+ancho*2+6,y+1); cout << opc3;
            color("amarillo");recuadro(x+ancho*3+6,y,ancho,2);
            gotoxy(x+ancho*3+8,y+1); cout << opc4;
            color("blanco");
            recuadro(x+ancho*4+8,y,ancho,2);
            gotoxy(x+ancho*4+10,y+1); cout << opc5;
        break;
        case 5:
            color("blanco");recuadro(x,y,ancho,2);
            gotoxy(x+2,y+1); cout << opc1;
            recuadro(x+ancho+2,y,ancho,2);
            gotoxy(x+ancho+4,y+1); cout << opc2;
            recuadro(x+ancho*2+4,y,ancho,2);
            gotoxy(x+ancho*2+6,y+1); cout << opc3;
            recuadro(x+ancho*3+6,y,ancho,2);
            gotoxy(x+ancho*3+8,y+1); cout << opc4;
            color("amarillo");recuadro(x+ancho*4+8,y,ancho,2);
            gotoxy(x+ancho*4+10,y+1); cout << opc5;
        break;
        }opc = getch();
    }
}

/**
Probabilidades:
*/
//Al llamar esta funcion se solicitara "1 de cada x intentos" tiene la probabilidad de crear una accion
bool probabilidad(int num){
srand(time(NULL)); int probable=rand()%(101-1);
if(num>=probable){return true;} return false;
}

/**
Margenes de texto:
*/
//Al llamar esta funcion se solicitara cadena de numeros(esta actuara como cadena de caracteres)
//posiciones x,y - el tamaño del vector, numero restrictor de caracteres
int margenTextoEscribir(int *texto, int x, int y, int tam, int restriccion){
for(int i=0;i<tam;i++){texto[i]=0;}
int tecla=1, px = 0, py = 0, t=0;
while(tecla!=13){
    px++;gotoxy(x-1+px,y+py);
    tecla = getch();t++;
    cout<<char(tecla);
    if(t%restriccion==0){py++;px=0;}
    if(tecla!=8){texto[t]=tecla;}
    else{px--;t-=2;cout<<" ";px--;}
}return *texto;
}

//Al llamar esta funcion se solicitara cadena de numeros(esta actuara como cadena de caracteres) anteriormente ingresado
//posiciones x,y - el tamaño del vector, numero restrictor de caracteres
void margenTextoMostrar(int *texto,int x, int y, int tam, int restriccion){
    int px = 0, py = 0;
    for(int i=1;i<tam;i++){px++;
    gotoxy(x-1+px,y+py);
    cout<<char(texto[i]);
    if(i%restriccion==0){
    py++;px=0;}
    }
}

/**
Logos
*/
///Numeros
void numeros(char* _num,int _x, int _y){
int cant = 0;
while(_num[cant]!=NULL){cant++;}
for(int x=0;x<cant;x++){
    switch(_num[x]){
    case '1':
        gotoxy(_x+(x*15),_y);cout<<"    "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+1);cout<<"    "<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+2);cout<<"    "<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+3);cout<<"      "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+4);cout<<"      "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+5);cout<<"      "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+6);cout<<"      "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+7);cout<<"      "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+8);cout<<"    "<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+9);cout<<"    "<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+10);cout<<"    "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
    break;
    case '2':
        gotoxy(_x+(x*15),_y);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+1);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+2);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+3);cout<<"        "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+4);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+5);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+6);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+7);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+8);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+9);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+10);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
    break;
    case '3':
        gotoxy(_x+(x*15),_y);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+1);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+2);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+3);cout<<"        "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+4);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+5);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+6);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+7);cout<<"        "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+8);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+9);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+10);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
    break;
    case '4':
        gotoxy(_x+(x*15),_y);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+1);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+2);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+3);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+4);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+5);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+6);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+7);cout<<"        "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+8);cout<<"        "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+9);cout<<"        "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+10);cout<<"        "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
    break;
    case '5':
        gotoxy(_x+(x*15),_y);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+1);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+2);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+3);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+4);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+5);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+6);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+7);cout<<"        "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+8);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+9);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+10);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
    break;
    case '6':
        gotoxy(_x+(x*15),_y);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+1);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+2);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+3);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+4);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+5);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+6);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+7);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+8);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+9);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+10);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
    break;
    case '7':
        gotoxy(_x+(x*15),_y);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+1);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+2);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+3);cout<<"        "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+4);cout<<"        "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+5);cout<<"        "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+6);cout<<"        "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+7);cout<<"        "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+8);cout<<"        "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+9);cout<<"        "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+10);cout<<"        "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
    break;
    case '8':
        gotoxy(_x+(x*15),_y);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+1);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+2);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+3);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+4);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+5);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+6);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+7);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+8);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+9);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+10);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
    break;
    case '9':
        gotoxy(_x+(x*15),_y);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+1);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+2);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+3);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+4);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+5);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+6);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+7);cout<<"        "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+8);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+9);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+10);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
    break;
    case '0':
        gotoxy(_x+(x*15),_y);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+1);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+2);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+3);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+4);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+5);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+6);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+7);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+8);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+9);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+10);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
    break;
    }
}
}

///Letras
void letras(string texto,int _x, int _y){
char const *cadena = texto.c_str();
int cant = texto.length();
for(int x=0;x<cant;x++){
    switch(cadena[x]){
    case 'a':
        gotoxy(_x+(x*15),_y);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+1);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+2);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+3);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+4);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+5);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+6);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+7);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+8);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+9);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+10);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
    break;
    case 'b':
        gotoxy(_x+(x*15),_y);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+1);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+2);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+3);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<" "<<char(219)<<char(219)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+4);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+5);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+6);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+7);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"   "<<char(219)<<char(219)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+8);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+9);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+10);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
    break;
    case 'c':
        gotoxy(_x+(x*15),_y);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+1);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+2);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+3);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+4);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+5);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+6);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+7);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+8);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+9);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+10);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
    break;
    case 'd':
        gotoxy(_x+(x*15),_y);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+1);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+2);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+3);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+4);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+5);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+6);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+7);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+8);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+9);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+10);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
    break;
    case 'e':
        gotoxy(_x+(x*15),_y);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+1);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+2);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+3);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+4);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+5);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+6);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+7);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+8);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+9);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+10);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
    break;
    case 'f':
        gotoxy(_x+(x*15),_y);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+1);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+2);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+3);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+4);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+5);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+6);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+7);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+8);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+9);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+10);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
    break;
    case 'g':
        gotoxy(_x+(x*15),_y);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+1);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+2);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+3);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+4);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+5);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+6);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+7);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+8);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+9);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+10);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
    break;
    case 'h':
        gotoxy(_x+(x*15),_y);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+1);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+2);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+3);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+4);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+5);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+6);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+7);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+8);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+9);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+10);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
    break;
    case 'i':
        gotoxy(_x+(x*15),_y);cout<<"  "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+1);cout<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+2);cout<<"  "<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+3);cout<<"    "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+4);cout<<"    "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+5);cout<<"    "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+6);cout<<"    "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+7);cout<<"    "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+8);cout<<"  "<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+9);cout<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+10);cout<<"  "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
    break;
    case 'j':
        gotoxy(_x+(x*15),_y);cout<<"        "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+1);cout<<"        "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+2);cout<<"        "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+3);cout<<"        "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+4);cout<<"        "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+5);cout<<"        "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+6);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+7);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+8);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+9);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+10);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
    break;
    case 'k':
        gotoxy(_x+(x*15),_y);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+1);cout<<char(219)<<char(219)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+2);cout<<char(219)<<char(219)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+3);cout<<char(219)<<char(219)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+4);cout<<char(219)<<char(219)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+5);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+6);cout<<char(219)<<char(219)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+7);cout<<char(219)<<char(219)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+8);cout<<char(219)<<char(219)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+9);cout<<char(219)<<char(219)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+10);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
    break;
    case 'l':
        gotoxy(_x+(x*15),_y);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+1);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+2);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+3);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+4);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+5);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+6);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+7);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+8);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+9);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+10);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
    break;
    case 'm':
        gotoxy(_x+(x*15),_y);cout<<char(219)<<char(219)<<char(219)<<char(219)<<"     "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+1);cout<<char(219)<<char(219)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+2);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+3);cout<<char(219)<<char(219)<<char(177)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+4);cout<<char(219)<<char(219)<<char(177)<<char(219)<<" "<<char(219)<<char(177)<<char(177)<<char(219)<<" "<<char(219)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+5);cout<<char(219)<<char(219)<<char(177)<<char(219)<<" "<<char(219)<<char(177)<<char(177)<<char(219)<<" "<<char(219)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+6);cout<<char(219)<<char(219)<<char(177)<<char(219)<<" "<<char(219)<<char(219)<<char(219)<<char(219)<<" "<<char(219)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+7);cout<<char(219)<<char(219)<<char(177)<<char(219)<<"      "<<char(219)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+8);cout<<char(219)<<char(219)<<char(177)<<char(219)<<"      "<<char(219)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+9);cout<<char(219)<<char(219)<<char(177)<<char(219)<<"      "<<char(219)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+10);cout<<char(219)<<char(219)<<char(219)<<char(219)<<"      "<<char(219)<<char(219)<<char(219)<<char(219);
    break;
    case 'n':
        gotoxy(_x+(x*15),_y);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+1);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+2);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+3);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+4);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+5);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+6);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+7);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+8);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+9);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+10);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
    break;
    case 'o':
        gotoxy(_x+(x*15),_y);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+1);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+2);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+3);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+4);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+5);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+6);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+7);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+8);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+9);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+10);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
    break;
    case 'p':
        gotoxy(_x+(x*15),_y);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+1);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+2);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+3);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+4);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+5);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+6);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+7);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+8);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+9);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+10);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
    break;
    case 'q':
        gotoxy(_x+(x*15),_y);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+1);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219);
        gotoxy(_x+(x*15),_y+2);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219);
        gotoxy(_x+(x*15),_y+3);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(177)<<char(177)<<char(219);
        gotoxy(_x+(x*15),_y+4);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(177)<<char(177)<<char(219);
        gotoxy(_x+(x*15),_y+5);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(177)<<char(177)<<char(219);
        gotoxy(_x+(x*15),_y+6);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(177)<<char(177)<<char(219);
        gotoxy(_x+(x*15),_y+7);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(177)<<char(177)<<char(219);
        gotoxy(_x+(x*15),_y+8);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+9);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+10);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
    break;
    case 'r':
        gotoxy(_x+(x*15),_y);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+1);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+2);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+3);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+4);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+5);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+6);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+7);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+8);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+9);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+10);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
    break;
    case 's':
        gotoxy(_x+(x*15),_y);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+1);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+2);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+3);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+4);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+5);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+6);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+7);cout<<"        "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+8);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+9);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+10);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
    break;
    case 't':
        gotoxy(_x+(x*15),_y);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+1);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+2);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+3);cout<<"    "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+4);cout<<"    "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+5);cout<<"    "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+6);cout<<"    "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+7);cout<<"    "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+8);cout<<"    "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+9);cout<<"    "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+10);cout<<"    "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
    break;
    case 'u':
        gotoxy(_x+(x*15),_y);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+1);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+2);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+3);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+4);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+5);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+6);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+7);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+8);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+9);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+10);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
    break;
    case 'v':
        gotoxy(_x+(x*15),_y);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+1);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+2);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+3);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+4);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+5);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+6);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+7);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+8);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+9);cout<<"  "<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+10);cout<<"    "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
    break;
    case 'w':
        gotoxy(_x+(x*15),_y);cout<<char(219)<<char(219)<<char(219)<<char(219)<<"      "<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+1);cout<<char(219)<<char(219)<<char(177)<<char(219)<<"      "<<char(219)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+2);cout<<char(219)<<char(219)<<char(177)<<char(219)<<"      "<<char(219)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+3);cout<<char(219)<<char(219)<<char(177)<<char(219)<<"      "<<char(219)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+4);cout<<char(219)<<char(219)<<char(177)<<char(219)<<" "<<char(219)<<char(219)<<char(219)<<char(219)<<" "<<char(219)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+5);cout<<char(219)<<char(219)<<char(177)<<char(219)<<" "<<char(219)<<char(177)<<char(177)<<char(219)<<" "<<char(219)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+6);cout<<char(219)<<char(219)<<char(177)<<char(219)<<" "<<char(219)<<char(177)<<char(177)<<char(219)<<" "<<char(219)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+7);cout<<char(219)<<char(219)<<char(177)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+8);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+9);cout<<char(219)<<char(219)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+10);cout<<char(219)<<char(219)<<char(219)<<char(219)<<"     "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
    break;
    case 'x':
        gotoxy(_x+(x*15),_y);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+1);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(219)<<"  "<<char(219)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+2);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(219)<<"  "<<char(219)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+3);cout<<" "<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+4);cout<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+5);cout<<"   "<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+6);cout<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+7);cout<<" "<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+8);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(219)<<"  "<<char(219)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+9);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(219)<<"  "<<char(219)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+10);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
    break;
    case 'y':
        gotoxy(_x+(x*15),_y);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+1);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+2);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219)<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+3);cout<<" "<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+4);cout<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+5);cout<<"   "<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+6);cout<<"    "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+7);cout<<"    "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+8);cout<<"    "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+9);cout<<"    "<<char(219)<<char(219)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+10);cout<<"    "<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
    break;
    case 'z':
        gotoxy(_x+(x*15),_y);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+1);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+2);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+3);cout<<"      "<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+4);cout<<"     "<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+5);cout<<"   "<<char(219)<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+6);cout<<"  "<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+7);cout<<" "<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+8);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+9);cout<<char(219)<<char(219)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(177)<<char(219)<<char(219);
        gotoxy(_x+(x*15),_y+10);cout<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219)<<char(219);
    break;
    }
}
}

///Tonos de Beeps
void notas(string nota,int octava,int duracion){
if (nota=="do"){Beep(261*octava,100*duracion);}
if (nota=="re"){Beep(293*octava,100*duracion);}
if (nota=="mi"){Beep(329*octava,100*duracion);}
if (nota=="fa"){Beep(349*octava,100*duracion);}
if (nota=="sol"){Beep(392*octava,100*duracion);}
if (nota=="la"){Beep(440*octava,100*duracion);}
if (nota=="si"){Beep(493*octava,100*duracion);}
}


#endif // CONSOLEMANAGER_H_INCLUDED
