#include<iostream>
#include<cstdlib>

#include"ConsoleManager.h"

using namespace std;

void menuInicial();
void MenuInrformacion();
void MenuFunciones();
void MenuCreditos();
void MenuEnlaces();

int main(){
titulo("CONSOLE MANAGER");pantallaCompleta();system("cls");
recuadro(20,5,193,40);
gotoxy(105,8);cout<<"B I E N V E N I D O S  A : ";
dado(37,10,1);dado(188,10,1);
dado(37,15,2);dado(188,15,2);
dado(37,20,3);dado(188,20,3);
dado(37,25,4);dado(188,25,4);
dado(37,30,5);dado(188,30,5);
dado(37,35,6);dado(188,35,6);
color(3);letras("console",65,11);
letras("manager",65,23);color(7);
gotoxy(98,36);cout<<"T U  B I B L I O T E C A  V I S U A L";
cursor(false);color(3);
gotoxy(106,40);cout<<"V E R S I O N  2 . X";
gotoxy(66,41);cout<<"Adriel Elian Rasjido - Alan Gabriel Vaca - Jose Enrique Menendez - Yesica Regina Laurentino Goncalves.";
tonos(8);color(4);
gotoxy(99,38);cout<<char(123)<<"Presiona una tecla para continuar"<<char(125);
system("pause>NULL");menuInicial();
return 0;
}
void menuInicial(){
color(7);recuadro(20,5,193,40);
recuadro(58,7,117,10);color(3);
letras("cm",25,7);numeros("2",180,7);letras("x",195,7);
gotoxy(74,10); cout<<"S E L E C C I O N A   L A   O P C I O N   Q U E   Q U I E R A S   V I S U A L I Z A R";color(7);
gotoxy(66,11); cout<<"(Usa las flechas del teclado '<-- . -->' Para desplazarte y luego utiliza el 'ENTER' para seleccionar)";
int opc = 0;MenuInrformacion();
while(true){
	opc = menuHorizontal_5(65,13,19,"INFORMACION","FUNCIONES","CREDITOS","ENLACES","SALIR");
	if(opc==1){MenuInrformacion();}
	else if(opc==2){MenuFunciones();}
	else if(opc==3){MenuCreditos();}
	else if(opc==4){MenuEnlaces();}
	else if(opc==5){mensajeEmergente("GRACIAS POR USAR CONSOLE MANAGER","QUE TENGAS UN LINDO DIA");exit(0);}
}
}
void MenuInrformacion(){
cursor(false);
color(7);
recuadro(25,19,183,24);
color(3);
gotoxy(28,21); cout<<char(168)<<"QUE ES CONSOLE MANAGER?";color(7);
gotoxy(28,22); cout<<"Esta es una biblioteca para soporte visual y/o funciones secundarias, ideal para acortar el tiempo de dise"
<<char(164)<<"o y asi los usuarios puedan enfocarse en la logica";
color(3);
gotoxy(28,24); cout<<char(168)<<"QUIEN PUEDE USARLO?";color(7);
gotoxy(28,25); cout<<"En primera instacia fue creada para los alumnos o cursantes de la UTN";
gotoxy(28,26); cout<<"Aunque la implementacion puede ser usada fuera de la misma";
gotoxy(28,27); subrayar("rojo","SIEMPRE Y CUANDO, NO ALTEREN EL PRODUCTO, TAMPOCO LA ELIMINACION DE LOS ARCHIVOS ADJUNTOS AL DESCARGABLE");
color(3);
gotoxy(28,30); cout<<char(168)<<"PUEDO FORMAR PARTE DEL PROYECTO?";color(7);
gotoxy(28,31); cout<<"SI, ingresa al siguiente LINK: ";color(3);cout<<"https://discord.gg/a4ZJh8XDwf ";color(7);
gotoxy(28,32); cout<<"DEBES JUSTIFICAR QUE ERES ALUMNO O CURSANTE DE LA UTN (Presentando LEGAJO, INSCRIPCION y MATERIA) Y ser aprobado por los administradores en un cuestionario.";
color(3);
gotoxy(28,34); cout<<char(168)<<"QUE PASA SI NO SOY ACEPTADO?";color(7);
gotoxy(28,35); cout<<"Puedes ser postulante de ideas que seran usadas para futuras actualizacion.";
gotoxy(28,38); subrayar("rojo","ADVERTENCIA!!!:");color(7);
gotoxy(44,38); cout<<"Contiene una licencia MIT, NO debe ser borrada ni alterada para no incumplir las leyes y condiciones de privacidad";
gotoxy(44,39); cout<<"(SI PUBLICAS TU PROYECTO/PROGRAMA UTILIZANDO ESTA BIBLIOTECA PUEDES USARLA SIEMPRE Y CUANDO NO INCUMPLAS LO ANTES PROPUESTO,";
gotoxy(44,40); cout<<"ESTO ADMITE EL PODER VENDERLO PERO SIN ALTERACIONES AL ORIGINAL)";
return;
}
void MenuFunciones(){
cursor(false);
color(7);
recuadro(25,19,183,24);
color(3);gotoxy(28,21); cout<<"TITULO()";color(7);
gotoxy(50,21);cout<<"CREA UN TITULO A LA VENTANA";
color(3);gotoxy(28,22); cout<<"GOTOXY()";color(7);
gotoxy(50,22);cout<<"UBICA EL CURSOR";
color(3);gotoxy(28,23); cout<<"CURSOR()";color(7);
gotoxy(50,23);cout<<"QUITA EL CURSOR";
color(3);gotoxy(28,24); cout<<"RECUADRO()";color(7);
gotoxy(50,24);cout<<"CREAR UN RECUADRO";
color(3);gotoxy(28,25); cout<<"GAMACOLORES()";color(7);
gotoxy(50,25);cout<<"MUESTRA TODOS LOS COLORES";
color(3);gotoxy(28,26); cout<<"COLOR()";color(7);
gotoxy(50,26);cout<<"CAMBIA DE COLOR AL TEXTO POR NOMBRE";
color(3);gotoxy(28,27); cout<<"FONDO()";color(7);
gotoxy(50,27);cout<<"CAMBIA EL COLOR DE FONDO Y TEXTO";
color(3);gotoxy(28,28); cout<<"MENUVERTICAL()";color(7);
gotoxy(50,28);cout<<"CREA MENUES VERTICALES ";
color(3);gotoxy(28,29); cout<<"MENUHORIZONTAL()";color(7);
gotoxy(50,29);cout<<"CREA MENUES HORIZONTALES ";
color(3);gotoxy(28,30); cout<<"PROBABILIDAD()";color(7);
gotoxy(50,30);cout<<"CREA UN BOOLEANO DE PROBABILIDAD";
color(3);gotoxy(28,31); cout<<"MARGENTEXTOESCRIBIR()";color(7);
gotoxy(50,31);cout<<"CREA UN MARGEN CON SALTO DE LINEA";
color(3);gotoxy(28,32); cout<<"MARGENTEXTOMOSTRAR()";color(7);
gotoxy(50,32);cout<<"MUESTRA ESE SALTO DE LINEA";
color(3);gotoxy(28,33); cout<<"NUMEROS()";color(7);
gotoxy(50,33);cout<<"CREA NUMEROS GRANDES ";
color(3);gotoxy(28,34); cout<<"LETRAS()";color(7);
gotoxy(50,34);cout<<"CREA LETRAS GRANDES ";
color(3);gotoxy(28,35); cout<<"NOTAS()";color(7);
gotoxy(50,35);cout<<"SONARAN LAS NOTAS MUSICALES ";
color(3);gotoxy(28,36); cout<<"CONSOLEMANAGER()";color(7);
gotoxy(50,36);cout<<"ACCESO A LA PRESENTACION Y LINKS";
color(3);gotoxy(28,37); cout<<"PANTALLA()";color(7);
gotoxy(50,37);cout<<"AJUSTA EL TAMAÑO DE LA PANTALLA";
color(3);gotoxy(28,38); cout<<"TONOS()";color(7);
gotoxy(50,38);cout<<"CREA TONOS MUSICALES PREDISEÑADOS";
color(3);gotoxy(28,39); cout<<"COLORNUMERICO()";color(7);
gotoxy(50,39);cout<<"CAMBIA EL COLOR AL TEXTO POR NUMERO";
color(3);gotoxy(28,40); cout<<"COMBOBOX()";color(7);
gotoxy(50,40);cout<<"CREA COMBOBOX PREDISEÑADOS";
color(3);gotoxy(28,41); cout<<"DADO()";color(7);
gotoxy(50,41);cout<<"MUESTRA UN DADO DIBUJADO ";
color(3);gotoxy(95,21); cout<<"SUBRAYAR()";color(7);
gotoxy(120,21);cout<<"SUBRAYA EL CONTENIDO QUE LE PASES";
color(3);gotoxy(95,22); cout<<"PANTALLACOMPLETA()";color(7);
gotoxy(120,22);cout<<"AJUSTA LA PANTALLA A PANTALLA COMPLETA";
color(3);gotoxy(95,23); cout<<"MENSAJEEMERGENTE()";color(7);
gotoxy(120,23);cout<<"SALTA UN MENSAJE EMERGENTE";
color(3);gotoxy(95,24); cout<<"CARACTERESASCII()";color(7);
gotoxy(120,24);cout<<"MUESTRA TODOS LOS CODIGOS ASCII";
}
void MenuCreditos(){
cursor(false);
color(7);
recuadro(25,19,183,24);
color(3);
gotoxy(28,21); cout<<"FUNDADORES";color(7);
gotoxy(28,22); cout<<"ADRIEL ELIAN RASJIDO";
gotoxy(28,23); cout<<"ALAN GABRIEL VACA";
color(3);
gotoxy(28,26); cout<<"DESARROLLADORES ACTUALES";color(7);
gotoxy(28,27); cout<<"ADRIEL ELIAN RASJIDO";
gotoxy(28,28); cout<<"ALAN GABRIEL VACA";
gotoxy(28,29); cout<<"JOSE ENRIQUE MENENDEZ";
gotoxy(28,30); cout<<"YESICA REGINA LAURENTINO GONCALVES";
color(3);
gotoxy(28,33); cout<<"ASOCIACIONES";color(7);
gotoxy(28,34); cout<<"PROFESORES";
gotoxy(28,35); cout<<"ANGEL SIMON";
gotoxy(28,37); cout<<"TECNICATURA UNIVERSITARIA EN PROGRAMACION";
gotoxy(28,39); cout<<"UTN FRGP";
gotoxy(28,40); cout<<"UNIVERSIDAD TECNOLOGICA NACIONAL";
gotoxy(28,41); cout<<"FACULTAD REGIONAL DE GENERAL PACHECO";
}
void MenuEnlaces(){
cursor(false);
int opcenlace = 0;
color(7);
recuadro(25,19,183,24);
color(3);
gotoxy(28,21); cout<<"SELLECIONA EL LINK QUE QUIERAS VISUALIZAR";color(7);
gotoxy(74,26); cout<<"Descarga ";color(3);cout<<"'Console Manager.h' ";color(7);cout<<"en su repositorio oficial en GITHUB";
gotoxy(74,29); cout<<"Mirate el video introductorio donde te explicamos mas sobre este proyecto a profundidad";
gotoxy(74,32); cout<<"Mirate el video donde te explicamos y probamos todas las funciones de ";color(3);cout<<"'Console Manager.h Version 1.X'";color(7);
gotoxy(74,35); cout<<"Mirate el video donde te explicamos y probamos todas las funciones de ";color(3);cout<<"'Console Manager.h Version 2.X'";color(7);
gotoxy(74,38); cout<<"Unete a nuestro discord Mirate el video ";color(3);cout<<"introductorio";color(7);cout<<" y la ";color(3);cout<<"informacion";color(7);cout<<" para formar parte del equipo";
opcenlace = menuVertical_5(28,25,40,"DESCARGAR CONSOLE MANAGER","VIDEO INTRODUCTORIO","VIDEO VERSION 1.X","VIDEO VERSION 2.X","DISCORD OFICIAL");
switch(opcenlace){
case 1: system("start https://github.com/AdrielRasjidoSBK/ConsoleManager");
break;
case 2: ConsoleManager(0);
break;
case 3: ConsoleManager(1);
break;
case 4: ConsoleManager(2);
break;
case 5: system("start https://discord.gg/NmC7wSjeCT");
break;
}
}
