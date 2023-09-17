//Realize un traductor de Ingles a Español y viceversa con un vector de estructuras 

#include <stdio.h>
#include <string.h>
#define n 50

typedef struct 
{
	char eng[n];
    char eps[n];
	int lleno;
}traductor;

traductor trad[n]; //(también se puede agregar aquí, como variable global

void vacio()
{
	
	int i;
	for(i=0; i<n; i++)
	{
		trad[i].lleno=0;
	}
}

void cambio(char palabra[n])
{
	int i; 
	
	for(i=0; i<n; i++)
	{
		if(palabra[i]=='\n');
		{
			palabra[i]=='\0';
		}
	}
}

void anadir()
{
	int i, aux=0;
	
	for(i=0; i<n && aux==0; i++)
	{
		if(trad[i].lleno==0)
		printf("Introduce la palabra en ingles \n");
		fflush(stdin);
		fgets(trad[i].eng,n,stdin);
		cambio(trad[i].eng);
		printf("Introduce la palabra en Espanol \n");
		fflush(stdin);
		fgets(trad[i].eps,n,stdin);
		cambio(trad[i].eps);
		trad[i].lleno=1;
		aux=1;
	}
}

void tradu(int op)
{
	int i,j, temp=0;
	char aux[n];
	
	printf("Introduce la palbra que deseas buscar: \n");
	fflush(stdin);
	fgets(aux,n,stdin);
	
	cambio(aux);
	
	if(op==1)
	{
		for(i=0; i<n && temp==0; i++)
		{
			j=strcmp(aux,trad[i].eng);	
			if(j==0)
			{
				printf("La traduccion de %s es %s. \n", trad[i].eng, trad[i].eps);
				temp=1;
			}
		}
	}
	
	else
	{
		for(i=0; i<n && temp==0; i++)
		{
			j=strcmp(aux,trad[i].eps);	
			if(j==0)
			{
				printf("La traduccion de %s es %s. \n", trad[i].eps, trad[i].eng);
				temp=1;
			}
		}
	}
}

void traducir()
{
	int op;
	
		do
		{
			printf("Elige la opcion que deseas \n");
			printf("Traducir del Ingles a Espaniol.....................1\n");
			printf("Traducir del Espanol al Ingles.....................2\n");
			printf("Salir...........................................3\n");
			scanf("%d", &op);
		}while(op<1 || op>3);
		
		switch(op)
		{
			case 1:
				tradu(op);
				break;
			case 2:
				tradu(op);
				break;
		}
}

int main ()
{
	int op;
	char key;
	
	vacio();
	
	do
	{
		do
		{
			printf("Elige la opcion que deseas \n");
			printf("Añadir palabra al traductor.....................1\n");
			printf("Buscar traduccion de una palabra................2\n");
			printf("Salir...........................................3\n");
			scanf("%d", &op);
		}while(op<1 || op>3);
		
		switch(op)
		{
			case 1:
				anadir();
				break;
			case 2:
				traducir();
				break;
		}
		printf("Introduce si deseas realizar otra operacion \n");
		scanf("%c", &key);
	}while(key=='S' || key== 's');
	system("pause");
}
