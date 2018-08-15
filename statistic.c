/* tarea4.c -- analisis de datos y estadisticas
 * Created on: Oct 5, 2017*/
#include <math.h>
#include <stdio.h>

void scanArreglo(int n, int arreglo[]);
void selectionSort(int n, int arreglo[]);
int tablaFrecuencias (int n, int arreglo[], int candidatos[], int frecuencias[]);//FALTA//calculamos y llenamos las tablas de candidatos y frecuencias
void asteriscos (int candidatos[], int frecuencias[], int datosDiferentes);//FALTA
int min(int n, int arreglo[]);
int max(int n, int arreglo[]);
float media (int n, int arreglo[]);
int mediana (int n, int arreglo[]);
int moda (int candidatos[], int frecuencias[], int datosDiferentes);//FALTA

int main()
{
	setbuf(stdout, 0);
	int n;		//n = numero de datos
	int arr[1000];	//ARREGLO ORIGINAL
	int candidatos[1000];	//arreglos vacios que se poblaran
	int frecuencias[1000];	//con la funcion datosDiferentes

	scanf ("%d", &n);
	scanArreglo (n, arr);	//obtener arr
	selectionSort (n, arr);	//ordenar arr
	int datosDiferentes = tablaFrecuencias (n, arr, candidatos, frecuencias);	//guardamos el valor de retorn de la funcion en una nueva variable datosDiferentes
	asteriscos(candidatos, frecuencias, datosDiferentes);	//prints el histograma
	printf ("Min: %d\n", min (n, arr));	//invocamos para print minimo
	printf ("Max: %d\n",  max (n, arr));	//invocamos para print max
	printf ("Media: %.4f\n", media (n, arr));	//invocamos para print media
	printf ("Mediana: %d\n", mediana (n, arr));	//invocamos para print mediana
	if (moda(candidatos, frecuencias, datosDiferentes) == -1)	printf ("No hay moda.\n");
	else
	printf ("Moda: %d", moda(candidatos, frecuencias, datosDiferentes));
}

//implementaion de las otras funciones
void scanArreglo(int n, int arreglo[])
{
	int i;
	for(i = 0; i < n; i++)
	{
		scanf("%i", &arreglo[i]);
	}
}

void selectionSort(int n, int arreglo[])
{
	int i = 0, j = 0, MENOR, k = 0; //i y j son para los fors, k es auxiliar
	for (i = 0; i < n; i++) {	//para cada indice en el arreglo
		MENOR = arreglo [i];	//declaro que el menor es el elemento del indice i del arreglo
		k = i;
		for (j = i + 1; j < n; j++) {
			if (arreglo [j] < MENOR) {	//se el elemento que encuentra es menor que el menor
				MENOR = arreglo [j];		//se realiza el switch
				k = j;
			}	//if
		}	//inner for
		arreglo [k] = arreglo [i];
		arreglo [i] = MENOR;
	}	//for
}

int tablaFrecuencias (int n, int arr[], int candidatos[], int frecuencias[])
{
	candidatos[0] = arr[0];
	frecuencias[0] = 1;
	int i, datosD = 1;
	for(i = 1; i < n; i++)
	{
		if (arr[i] == candidatos[datosD - 1])
			frecuencias[datosD - 1]++;
		else
		{
			candidatos[datosD] = arr[i];
			frecuencias[datosD] = 1;
			datosD++;
		}
	}
	return datosD;
}

void asteriscos (int candidatos[], int frecuencias[], int datosDiferentes)	//muestra la frecuencia de cada datos dif
{
	int i, j;
	for (i = 0; i < datosDiferentes; i++)
	{
		printf ("%i: ", candidatos[i]);
		for (j = 0; j < frecuencias[i]; j++)
			printf ("*");
		printf ("\n");
	}
}

int min(int n, int arreglo[])
{
	int min = arreglo [0];
	return (min);
}

int max(int n, int arreglo[])
{
	int max = arreglo[n-1];
	return (max);
}

float media (int n, int arreglo[])
{
	int i, ac = 0;	//acumulador que almacena la suma los elementos del arreglo
	for(i = 0; i < n; i++)
		ac += arreglo[i];
	float media = ac / (float)n;
	return (media);
}

int mediana (int n, int arreglo[])
{
	int mediana = arreglo [(int)(n/2)];
	return (mediana);
}

int moda (int candidatos [], int frecuencias [], int datosDiferentes)
{
	int i;
	int mayorFrecuenciaActual = 0;
	int moda;
	int repetido = 0;//bandera

	for (i = 0; i < datosDiferentes; i++)
	{
		if (frecuencias[i] > mayorFrecuenciaActual)
		{
			mayorFrecuenciaActual = frecuencias[i];
			moda = candidatos[i];
			repetido = 0;
		}
		else if(mayorFrecuenciaActual == frecuencias[i])
			repetido = 1;
	}
	if (repetido == 1)//moda esta repetida, no hay moda
		return -1;
	else		//moda no esta repetida, si hay moda
		return (moda);
}
