#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
typedef struct          //ESTRUCTURA PARA ALMACENAR LOS DATOS DE 1 USUARIO
{
	char nombre[51];
	char apellido1[51];
	char apellido2[51];
	char contraseña[51];
	char usuario[51];
	int dni;
	int dia;
	int mes;
	int año;
	int voto;
	
}votante;

votante PedirVotante(); // PARA E/S POR CONSOLA
void NuevoVotante(votante voto[],int *num,votante c); //AÑADE EL VOTANTE C
void MostrarResultados(votante voto[],int num); // PARA MOSTAR RESULTADOS POR PANTALLA
void MostrarVoto(votante c);
int PedirUsuario(int b,votante c); //PARA E/S POR CONSOLA
int LeerVotante(FILE *f,votante*c); // PARA E/S POR FICHERO DE TEXTO
int GuardarVotante(FILE *f,votante c);//PASANDO UN FICHERO ABIERTO COMO PARAMETRO
int LeerVoto(char fichero[],votante voto[],int *num); //LEER Y GUARDAR TODOS LOS DATOS EN
int GuardarVoto(char fichero[],votante voto[],int num);//UN FICHERO DE TEXTO
int Menu();//MENÚ PRINCIPAL DE OPCIONES
void Partidos();// MENU DE LOS PARTIDOS A ELEGIR
void main()
{
	votante voto[1000];
	int num_votantes=0;
	int opcion=0;
	votante c;
	int n;
	int b=4;
	LeerVoto("Voto.txt",voto,&num_votantes); //SE LEEN LOS DATOS DEL FICHERO
	do{
	
		opcion=Menu();
		switch(opcion)
		{
		case 0:printf("SALIENDO DEL PROGRAMA\n");
			break;
		case 1: c=PedirVotante();
			break;
			
			
		case 2: Partidos();
			break;
	
		case 3: PedirUsuario(b,c);
			if(PedirUsuario(b,c))
			{
				printf("Introduzca su voto\n");
				scanf("%d",&c.voto);
			}
			else
			{
				printf("Usuario o contraseña incorrecta\n");
			}
			NuevoVotante(voto,&num_votantes,c);
			break;
		case 4: MostrarResultados(voto,num_votantes);
			break;
		}
	}
	

		while(opcion!=0);
		GuardarVoto("Voto.txt",voto,num_votantes);//CUANDO SE SALE DEL PROGRAMA GUARDA AUTOMATICAMENTE EL FICHERO
		printf("Pulse una tecla para continuar\n");
		getch();
		system("cls");

			
			
}
int Menu()
{
	int opcion=-1;
	printf("MENU PRINCIPAL\n");
	printf("ELECCIONES DEL DIA 20 JUNIO 2018\n");
	printf("0-SALIR\n");
	printf("1-NUEVO VOTANTE\n");
	printf("2-PARTIDOS ELECTORALES\n");
	printf("3-VOTAR\n");
	printf("4-MOSTRAR RESULTADOS\n");
	do{
		printf("ELIJA UNA OPCION\n");
		fflush(stdin);
		scanf("%d",&opcion);
	}
	while(opcion<0 || opcion>5);
	return opcion;
}
votante PedirVotante()// SE PIDE UN VOTANTE QUE SE DEVUELVE EN RETURN
{
	votante c;
	fflush(stdin);
	printf("Nombre: \n");
	gets(c.nombre);
	printf("Primer apellido: \n");
	gets(c.apellido1);
	printf("Segundo apellido: \n");
	gets(c.apellido2);
	printf("DNI: \n");
	scanf("%d",&c.dni);
	printf("Dia de nacimiento: \n");
	scanf("%d",&c.dia);
	printf("Mes de nacimiento: \n");
	scanf("%d",&c.mes);
	printf("Año de nacimiento: \n");
	scanf("%d",&c.año);
	printf("Introduzca su usuario:  \n");
	scanf("%s",&c.usuario);
	printf("Introduzca su contraseña:   \n");
	scanf("%s",&c.contraseña);
	
	
	return c;
}
void NuevoVotante(votante voto[],int *num,votante c)// AÑADE A UN NUEVO VOTANTE
{
	int n=*num;
	if(c.año<2000)
	{
		printf("SU VOTO HA REGISTRADO CORRECTAMENTE\n");
		voto[n]=c;// SE AÑADE AL VOTANTE
		n++;// EL NUMERO DE VOTANTES INCREMENTA EN UNO

	*num=n;//ACTUALIZAMOS EL PARAMETRO PASADO POR REFERENCIA
	}
	else
	{
		printf("DEBE SER MAYOR DE EDAD PARA VOTAR\n");
	}
}
void Partidos()
{
	printf("1- PARTIDO POPULAR	\n");
	printf("2- PARTIDO SOCIALISTA OBRERO ESPAÑOL  \n");
	printf("3- CIUDADANOS  \n");
	printf("4- PODEMOS  \n");
	printf("5- VOTO EN BLANCO  \n");
}
int PedirUsuario(int b,votante c)//	COMPRUEBA QUE EL USUARIO Y LA CONTRASEÑA SON CORRECTOS
{
	char usu[51];
	char cont[51];
	int k;
	int l;

	printf("Introduzca su usuario\n");
	scanf("%s",&usu);
	printf("Introduzca su contraseña\n");
	scanf("%s",&cont);
	k=strcmp(usu,c.usuario);
	l=strcmp(cont,c.contraseña);
	if(l==0 && k==0)
	{
		return 1;
	}
	else
	{
		return 0;//SI NO SON CORRECTOS DEVUELVE FALSO
	}
}
void MostrarResultados(votante voto[],int num)//IMPRESION DE LOS RESULTADOS POR PANTALLA RECORRIENDO EL VECTOR QUE SE PASA COMO PARAMETRO
{
	int i;
	for(i=0;i<num;i++)
	{
		printf("HAN VOTADO %d PERSONAS\n",i+1);// NUMERO DE PERSONA QUE HAN VOTADO
		MostrarVoto(voto[i]);// PARTIDOS A LOS QUE SE HA VOTADO
	}
}
void MostrarVoto(votante c)
{
	printf("%d\n",c.voto);
}
int LeerVotante(FILE*f,votante*c)// FUNCION DE E/S POR FICHERO DE TEXTO
{
	if(f==NULL) // SI EL FICHERO NO ESTA ABIERTO
		return 0;// DEVUELVE FALSO
	if(3==fscanf(f,"%s %s %s %d %d %d %d %d",c->nombre,c->apellido1,c->apellido2,&c->dia,&c->mes,&c->año,&c->dni,&c->voto))
		return 1;// SE HAN GUARDADO BIEN LOS CAMPOS
	return 0;
}
int GuardarVotante(FILE*f,votante c)// FUNCION DE E/S POR FICHERO DE TEXTO
{
	if(f==NULL)// SI EL FICHERO NO ESTA ABIERTO
		return 0;// DEVUELVE FALSO
	if(3==fprintf(f,"%s %s %s %d %d %d %d %d",c.nombre,c.apellido1,c.apellido2,c.dia,c.mes,c.año,c.dni,c.voto))
		return 1; // SE HAN GUARDADO BIEN LOS CAMPOS
	return 0;
}
int LeerVoto(char fichero[],votante voto[],int *num)//ABRE UN FICHERO CUYO NOMBRE SE LE PASA COMO PARAMETR0
	                                                //Y LEE TODOS LOS VOTOS DEL FICHERO
{
	votante votan;//VARIABLE TEMPORAL PARA LEER DEL FICHERO
	int n=0;
	FILE *f=fopen(fichero,"r");//SE ABRE EL FICHERO
	if(f==NULL)//SI NO SE ABRE CORRECTAMENTE
		return 0;//SE TERMINA DE LEER
	while(LeerVotante(f,&votan))//SI SE LEE CORRECTAMENTE
	{
		voto[n]=votan;//EL VECTOR 
		n++;//CRECE
	}
	*num=n;//SE ACTUALIZA EL NUMERO DE VOTANTES
	fclose(f);//SE CIERRA EL FICHERO
	return 1;
}
int GuardarVoto(char fichero[],votante voto[],int num)//FUNCION PARA GUARDAR LOS DATOS EN EL FICHERO ESPECIFICADO
{
	int i;
	FILE *f=fopen(fichero,"w");
	if(f==NULL)
		return 0;
	for(i=0;i<num;i++)//SE RECORRE EL VECTOR
	{
		GuardarVotante(f,voto[i]);//GUARDANDO CADA VOTANTE
	}
	fclose(f);
	return 1;
}