#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SALIR 0
#define CARGAR 1
#define RECORRIDO 2
#define BURBUJA 3
#define QUICKSORT 4
#define GRAFICABURBUJA 5
#define GRAFICAARBOL 6
#define GRAFICAQUICK 7
#define GRAFICAQUICK2 8
#define GRAFICABURBU 9
#define GRAFICAAVL 10
#define TRUE 1
#define FALSE 0
#define TAMANO 80
int c;
int lista[100];
int tiempoquicsort;
int elementos;
int tiempoburbuja;
int tiempoARBOL;
int nnodos;
enum {IZQUIERDO, DERECHO};

/* Estructuras y tipos */
typedef struct _nodo {
   int dato;
   int FE;
   struct _nodo *derecho;
   struct _nodo *izquierdo;
   struct _nodo *padre;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Arbol;

/* Funciones con árboles: */
/* Insertar en árbol ordenado: */
void Insertar(Arbol *a, int dat);
/* Borrar un elemento: */
void Borrar(Arbol *a, int dat);
/* Función de búsqueda: */
int Buscar(Arbol a, int dat);
/* Comprobar si el árbol está vacío: */
int Vacio(Arbol r);
/* Comprobar si es un nodo hoja: */
int EsHoja(pNodo r);
/* Contar número de nodos: */
int NumeroNodos(Arbol a, int* c);
/* Calcular la altura de un árbol: */
int AlturaArbol(Arbol a, int* altura);
/* Calcular altura de un dato: */
int Altura(Arbol a, int dat);
/* Aplicar una función a cada elemento del árbol: */
void InOrden(Arbol, void (*func)(int*));
void PreOrden(Arbol, void (*func)(int*));
void PostOrden(Arbol, void (*func)(int*));
// Funciones de equilibrado:
void Equilibrar(Arbol *raiz, pNodo nodo, int, int);
void RSI(Arbol *raiz, pNodo nodo);
void RSD(Arbol *raiz, pNodo nodo);
void RDI(Arbol *raiz, pNodo nodo);
void RDD(Arbol *raiz, pNodo nodo);

/* Funciones auxiliares: */
void Podar(Arbol *a);
void auxContador(Arbol a, int*);
void auxAltura(Arbol a, int, int*);

void Mostrar(int *d);

/* Estructura de la lista enlazada: */

typedef struct nodo{
    int dato;
    struct nodo *sig;
}Nodo;

Nodo *cabeza;

Nodo *insertar(Nodo *cabeza, int dato){
    Nodo *nuevo = (Nodo *)malloc(sizeof( Nodo));
    nuevo->dato = dato;
    if(cabeza==NULL){
        cabeza = nuevo;
    }else{
        Nodo *aux = cabeza;
        while(aux->sig!=NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
    return cabeza;
}

Nodo *ordenarburbuja(Nodo *cabeza){
Nodo *actual, *siguiente;
int n;
actual = cabeza;
while(actual->sig != NULL){

 siguiente = actual->sig;
 while(siguiente!=NULL){
 if(actual->dato > siguiente->dato){
 n = siguiente->dato;
 siguiente->dato = actual->dato;
 actual->dato = n;
 }
siguiente = siguiente->sig;
 }
 actual= actual->sig;
 siguiente = actual->sig;
 }

return cabeza;
 }
/* Estructura de la lista enlazada: */

void intercambio(int *a, int *b){

int temp = *a;
*a = *b;
*b = temp;

}

void ordenarquicksort(int * izq, int *der){
if(der<izq)
return;
int pivote = *izq;
int *ult = der;
int Pri = izq;
while(izq<der){
    while(*izq <= pivote && izq <der+1)
    izq++;
    while(*der > pivote && der > izq-1)
    der--;
    if(izq < der)
    intercambio(izq,der);

}
intercambio(Pri,der);
ordenarquicksort(Pri,der-1);
ordenarquicksort(der+1,ult);

}

int main()
{

    //int lista[Tamanio];
    clock_t inicio, fin;
    Arbol ArbolInt=NULL;
    Nodo *cabeza = NULL;

    int seleccion = 0;
    do{
        system("clear");

        printf("------------ Menu -------------\n");
        printf("0. Salir\n");
        printf("1. Cargar\n");
        printf("2. Recorrido in Orden\n");
        printf("3. Ordenar lista Burbuja\n");
        printf("4. Ordenar lista Quicksort\n");
        printf("5. Graficar eficiencia Burbuja\n");
        printf("6. Graficar eficiencia Arbol\n");
        printf("7. Graficar eficiencia Quicksort\n");
        printf("8. Graficar 2 eficiencia Quicksort\n");
        printf("9. Graficar 2 eficiencia Burbuja\n");
        printf("10. Graficar 2 eficiencia Arbol\n");
        printf("------------ FIN --------------\n");
        if(seleccion==GRAFICAAVL){
        FILE * archivito6;
        archivito6 = fopen("grafica6.txt","w");
        if (archivito6==NULL)
        printf("no se logro crear el archivo");
      fprintf(archivito6,"set title \"Grafica de Eficiencia Arbol AVL\"\n");
fprintf(archivito6,"set ylabel \"Tiempo en ordenar\"\n");
fprintf(archivito6,"set xlabel \"Cantidad elementos Ordenados\"\n");
       fprintf(archivito6,"plot[%d:%f] log(x)\n ", nnodos,tiempoARBOL);

       fprintf(archivito6,"pause mouse");


       fclose(archivito6);

        printf("Esta es mi grafica ");
         system("gnuplot grafica6.txt");

        }
        else if(seleccion==GRAFICABURBU){

        FILE * archivito5;
        archivito5 = fopen("grafica5.txt","w");
        if (archivito5==NULL)
        printf("no se logro crear el archivo");
      fprintf(archivito5,"set title \"Grafica de Eficiencia Burbuja\"\n");
fprintf(archivito5,"set ylabel \"Tiempo en ordenar\"\n");
fprintf(archivito5,"set xlabel \"Cantidad elementos Ordenados\"\n");
       fprintf(archivito5,"plot[%d:%f] x*exp(2)\n ", c,tiempoburbuja);

       fprintf(archivito5,"pause mouse");


       fclose(archivito5);

        printf("Esta es mi grafica ");
         system("gnuplot grafica5.txt");
        }

        else if(seleccion==GRAFICAQUICK2){

        FILE * archivito4;
        archivito4 = fopen("grafica4.txt","w");
        if (archivito4==NULL)
        printf("no se logro crear el archivo");
      fprintf(archivito4,"set title \"Grafica de Eficiencia Quicksort\"\n");
fprintf(archivito4,"set ylabel \"Tiempo en ordenar\"\n");
fprintf(archivito4,"set xlabel \"Cantidad elementos Ordenados\"\n");
       fprintf(archivito4,"plot[%d:%f] log(x)\n ", c,tiempoquicsort);

       fprintf(archivito4,"pause mouse");


       fclose(archivito4);

        printf("Esta es mi grafica ");
         system("gnuplot grafica4.txt");
        }
        else if(seleccion==GRAFICAQUICK){
        printf("Esta es mi grafica ");
         system("gnuplot grafica3.txt");
        }
        else if(seleccion==GRAFICAARBOL){
        FILE * archivito2;
        archivito2 = fopen("grafica2.txt","a");
        if (archivito2==NULL)
        printf("no se logro crear el archivo");


   fprintf(archivito2,"pause mouse");
   fclose(archivito2);
system("gnuplot grafica2.txt");


        }

        else if(seleccion==GRAFICABURBUJA){
        printf("Esta es mi grafica ");
         system("gnuplot grafica1.txt");
        }

        else if(seleccion==QUICKSORT){
        float tim;
        FILE * archivito3;
        archivito3 = fopen("grafica3.txt","w");
        if (archivito3==NULL)
        printf("no se logro crear el archivo");


        printf("los datos de la lista ordenada quicksort son: \n");
        inicio = clock();
        int size = c;
        ordenarquicksort(&lista[0],&lista[size-1]);
        int i;
        for(i=0; i<size;i++)
        printf("%d ", lista[i]);
        fprintf(archivito3,"set title \"Grafica de Eficiencia Quicksort\"\n");
fprintf(archivito3,"set ylabel \"Tiempo en ordenar\"\n");
fprintf(archivito3,"set xlabel \"Cantidad elementos Ordenados\"\n");
        for(i=0; i<size;i++)
        fprintf(archivito3,"plot[%d:%f] log(x)\n ", lista[i],tim);

         fprintf(archivito3,"pause mouse");
         tim =(float)(fin-inicio)/(float)CLOCKS_PER_SEC;
        fin = clock();
        printf("\nSe tardo en ordenar la lista en: %f Segundos\n",(float)(fin-inicio)/(float)CLOCKS_PER_SEC);
        fclose(archivito3);
         tim=tiempoquicsort;
         size = elementos;
        }
        else if(seleccion==BURBUJA){
        float tim;
        FILE * archivito;
        archivito = fopen("grafica1.txt","w");
        if (archivito==NULL)
        printf("no se logro crear el archivo");


        printf("los datos de la lista ordenada burbuja son: ");
        inicio = clock();
        ordenarburbuja(cabeza);
         fprintf(archivito,"set title \"Grafica de Eficiencia Burbuja\"\n");
fprintf(archivito,"set ylabel \"Tiempo en ordenar\"\n");
fprintf(archivito,"set xlabel \"Cantidad elementos Ordenados\"\n");
        while(cabeza!=NULL){
        fprintf(archivito,"plot[%d:%f] x*exp(2)\n ", cabeza->dato,tim);
        printf("%d ", cabeza->dato);
        cabeza=cabeza->sig;

         }
      fprintf(archivito,"pause mouse");
        fin = clock();
        tim =(float)(fin-inicio)/(float)CLOCKS_PER_SEC;
        printf("\nSe tardo en ordenar la lista en: %f Segundos\n",(float)(fin-inicio)/(float)CLOCKS_PER_SEC);
fclose(archivito);
tim=tiempoburbuja;
        }
        else if(seleccion==RECORRIDO){

         printf("InOrden: \n");
         inicio = clock();
         InOrden(ArbolInt, Mostrar);
         printf("N nodos: %d\n", NumeroNodos(ArbolInt, &nnodos));

         printf("\n");
         fin = clock();
         printf("Se tardo en recorrer el arbol en: %f Segundos\n",(float)(fin-inicio)/(float)CLOCKS_PER_SEC);


         }
        else if(seleccion==CARGAR){
        printf("Ingrese la ruta del archivo: \n");
            inicio = clock();
            FILE *archivo; /*area de buffer*/
            char nombre[TAMANO];
            scanf("%s", nombre);
            int numeros;
            int i=0;
            archivo= fopen(nombre,"r");

           if(archivo==NULL)

           printf("Error al abrir archivo o no encontro el archivo \n");

            else{

             printf("este es el contenido de mi archivo: \n ");
             while(feof(archivo) == 0){
             fscanf(archivo, "%d",&numeros);

              lista[c]= numeros;
              c=c+1;
              Insertar(&ArbolInt, numeros);
                cabeza = insertar(cabeza, numeros);

             printf("%d\n",numeros);



   }

             fclose(archivo); /*cerrar archivo*/

             fin = clock();
            printf("Se tardo en leer e insertar al arbol: %f Segundos\n",(float)(fin-inicio)/(float)CLOCKS_PER_SEC);



              }

        }
        scanf("%d", &seleccion);

    }

    while(seleccion!=SALIR);
    printf("el programa termino\n");

    return 0;
}


/* Poda: borrar todos los nodos a partir de uno, incluido */
void Podar(Arbol *a)
{
   /* Algoritmo recursivo, recorrido en postorden */
   if(*a) {
      Podar(&(*a)->izquierdo); /* Podar izquierdo */
      Podar(&(*a)->derecho);   /* Podar derecho */
      free(*a);                /* Eliminar nodo */
      *a = NULL;
   }
}

/* Insertar un dato en el árbol ABB */
void Insertar(Arbol *a, int dat)
{
   pNodo padre = NULL;
   pNodo actual = *a;

   /* Buscar el dato en el árbol, manteniendo un puntero al nodo padre */
   while(!Vacio(actual) && dat != actual->dato) {
      padre = actual;
      if(dat < actual->dato) actual = actual->izquierdo;
      else if(dat > actual->dato) actual = actual->derecho;
   }

   /* Si se ha encontrado el elemento, regresar sin insertar */
   if(!Vacio(actual)) return;
   /* Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será
      el nodo raiz */
   if(Vacio(padre)) {
      *a = (Arbol)malloc(sizeof(tipoNodo));
      (*a)->dato = dat;
      (*a)->izquierdo = (*a)->derecho = NULL;
      (*a)->padre = NULL;
      (*a)->FE = 0;
   }
   /* Si el dato es menor que el que contiene el nodo padre, lo insertamos
      en la rama izquierda */
   else if(dat < padre->dato) {
      actual = (Arbol)malloc(sizeof(tipoNodo));
      padre->izquierdo = actual;
      actual->dato = dat;
      actual->izquierdo = actual->derecho = NULL;
      actual->padre = padre;
      actual->FE = 0;
      Equilibrar(a, padre, IZQUIERDO, TRUE);
   }
   /* Si el dato es mayor que el que contiene el nodo padre, lo insertamos
      en la rama derecha */
   else if(dat > padre->dato) {
      actual = (Arbol)malloc(sizeof(tipoNodo));
      padre->derecho = actual;
      actual->dato = dat;
      actual->izquierdo = actual->derecho = NULL;
      actual->padre = padre;
      actual->FE = 0;
      Equilibrar(a, padre, DERECHO, TRUE);
  }
}

/* Equilibrar árbol AVL partiendo del nodo nuevo */
void Equilibrar(Arbol *a, pNodo nodo, int rama, int nuevo)
{
   int salir = FALSE;

   /* Recorrer camino inverso actualizando valores de FE: */
   while(nodo && !salir) {
      if(nuevo)
         if(rama == IZQUIERDO) nodo->FE--; /* Depende de si añadimos ... */
         else                  nodo->FE++;
      else
         if(rama == IZQUIERDO) nodo->FE++; /* ... o borramos */
         else                  nodo->FE--;
      if(nodo->FE == 0) salir = TRUE; /* La altura de las rama que
                                         empieza en nodo no ha variado,
                                         salir de Equilibrar */
      else if(nodo->FE == -2) { /* Rotar a derechas y salir: */
         if(nodo->izquierdo->FE == 1) RDD(a, nodo); /* Rotación doble  */
         else RSD(a, nodo);                         /* Rotación simple */
         salir = TRUE;
      }
      else if(nodo->FE == 2) {  /* Rotar a izquierdas y salir: */
         if(nodo->derecho->FE == -1) RDI(a, nodo); /* Rotación doble  */
         else RSI(a, nodo);                        /* Rotación simple */
         salir = TRUE;
      }
      if(nodo->padre)
         if(nodo->padre->derecho == nodo) rama = DERECHO; else rama = IZQUIERDO;
      nodo = nodo->padre; /* Calcular FE, siguiente nodo del camino. */
   }
}

/* Rotación doble a derechas */
void RDD(Arbol *raiz, Arbol nodo)
{
   pNodo Padre = nodo->padre;
   pNodo P = nodo;
   pNodo Q = P->izquierdo;
   pNodo R = Q->derecho;
   pNodo B = R->izquierdo;
   pNodo C = R->derecho;

   if(Padre)
     if(Padre->derecho == nodo) Padre->derecho = R;
     else Padre->izquierdo = R;
   else *raiz = R;

   /* Reconstruir árbol: */
   Q->derecho = B;
   P->izquierdo = C;
   R->izquierdo = Q;
   R->derecho = P;

   /* Reasignar padres: */
   R->padre = Padre;
   P->padre = Q->padre = R;
   if(B) B->padre = Q;
   if(C) C->padre = P;

   /* Ajustar valores de FE: */
   switch(R->FE) {
      case -1: Q->FE = 0; P->FE = 1; break;
      case 0:  Q->FE = 0; P->FE = 0; break;
      case 1:  Q->FE = -1; P->FE = 0; break;
   }
   R->FE = 0;
}

/* Rotación doble a izquierdas */
void RDI(Arbol *a, pNodo nodo)
{
   pNodo Padre = nodo->padre;
   pNodo P = nodo;
   pNodo Q = P->derecho;
   pNodo R = Q->izquierdo;
   pNodo B = R->izquierdo;
   pNodo C = R->derecho;

   if(Padre)
     if(Padre->derecho == nodo) Padre->derecho = R;
     else Padre->izquierdo = R;
   else *a = R;

   /* Reconstruir árbol: */
   P->derecho = B;
   Q->izquierdo = C;
   R->izquierdo = P;
   R->derecho = Q;

   /* Reasignar padres: */
   R->padre = Padre;
   P->padre = Q->padre = R;
   if(B) B->padre = P;
   if(C) C->padre = Q;

   /* Ajustar valores de FE: */
   switch(R->FE) {
      case -1: P->FE = 0; Q->FE = 1; break;
      case 0:  P->FE = 0; Q->FE = 0; break;
      case 1:  P->FE = -1; Q->FE = 0; break;
   }
   R->FE = 0;
}

/* Rotación simple a derechas */
void RSD(Arbol *a, pNodo nodo)
{
   pNodo Padre = nodo->padre;
   pNodo P = nodo;
   pNodo Q = P->izquierdo;
   pNodo B = Q->derecho;

   if(Padre)
     if(Padre->derecho == P) Padre->derecho = Q;
     else Padre->izquierdo = Q;
   else *a = Q;

   /* Reconstruir árbol: */
   P->izquierdo = B;
   Q->derecho = P;

   /* Reasignar padres: */
   P->padre = Q;
   if(B) B->padre = P;
   Q->padre = Padre;

   /* Ajustar valores de FE: */
   P->FE = 0;
   Q->FE = 0;
}

/* Rotación simple a izquierdas */
void RSI(Arbol *a, pNodo nodo)
{
   pNodo Padre = nodo->padre;
   pNodo P = nodo;
   pNodo Q = P->derecho;
   pNodo B = Q->izquierdo;

   if(Padre)
     if(Padre->derecho == P) Padre->derecho = Q;
     else Padre->izquierdo = Q;
   else *a = Q;

   /* Reconstruir árbol: */
   P->derecho = B;
   Q->izquierdo = P;

   /* Reasignar padres: */
   P->padre = Q;
   if(B) B->padre = P;
   Q->padre = Padre;

   /* Ajustar valores de FE: */
   P->FE = 0;
   Q->FE = 0;
}

/* Eliminar un elemento de un árbol ABB */
void Borrar(Arbol *a, int dat)
{
   pNodo padre = NULL;
   pNodo actual;
   pNodo nodo;
   int aux;

   actual = *a;
   /* Mientras sea posible que el valor esté en el árbol */
   while(!Vacio(actual)) {
      if(dat == actual->dato) { /* Si el valor está en el nodo actual */
         if(EsHoja(actual)) { /* Y si además es un nodo hoja: lo borramos */
            if(padre) /* Si tiene padre (no es el nodo raiz) */
               /* Anulamos el puntero que le hace referencia */
               if(padre->derecho == actual) padre->derecho = NULL;
               else if(padre->izquierdo == actual) padre->izquierdo = NULL;
            free(actual); /* Borrar el nodo */
            actual = NULL;
            /* El nodo padre del actual puede ser ahora un nodo hoja, por lo
               tanto su FE es cero, pero debemos seguir el camino a partir de
               su padre, si existe. */
            if((padre->derecho == actual && padre->FE == 1) ||
               (padre->izquierdo == actual && padre->FE == -1)) {
               padre->FE = 0;
               actual = padre;
               padre = actual->padre;
            }
            if(padre)
               if(padre->derecho == actual) Equilibrar(a, padre, DERECHO, FALSE);
               else                         Equilibrar(a, padre, IZQUIERDO, FALSE);
            return;
         }
         else { /* Si el valor está en el nodo actual, pero no es hoja */
            padre = actual;
            /* Buscar nodo más izquierdo de rama derecha */
            if(actual->derecho) {
               nodo = actual->derecho;
               while(nodo->izquierdo) {
                  padre = nodo;
                  nodo = nodo->izquierdo;
               }
            }
            /* O buscar nodo más derecho de rama izquierda */
            else {
               nodo = actual->izquierdo;
               while(nodo->derecho) {
                  padre = nodo;
                  nodo = nodo->derecho;
               }
            }
            /* Intercambiar valores de no a borrar u nodo encontrado
               y continuar, cerrando el bucle. El nodo encontrado no tiene
               por qué ser un nodo hoja, cerrando el bucle nos aseguramos
               de que sólo se eliminan nodos hoja. */
            aux = actual->dato;
            actual->dato = nodo->dato;
            nodo->dato = aux;
            actual = nodo;
         }
      }
      else { /* Todavía no hemos encontrado el valor, seguir buscándolo */
         padre = actual;
         if(dat > actual->dato) actual = actual->derecho;
         else if(dat < actual->dato) actual = actual->izquierdo;
      }
   }
}

/* Recorrido de árbol en inorden, aplicamos la función func, que tiene
   el prototipo:
   void func(int*);
*/
void InOrden(Arbol a, void (*func)(int*))
{

   if(a->izquierdo) InOrden(a->izquierdo, func);
   func(&(a->dato));
   if(a->derecho) InOrden(a->derecho, func);


}

/* Recorrido de árbol en preorden, aplicamos la función func, que tiene
   el prototipo:
   void func(int*);
*/
void PreOrden(Arbol a, void (*func)(int*))
{
   func(&a->dato);
   if(a->izquierdo) PreOrden(a->izquierdo, func);
   if(a->derecho) PreOrden(a->derecho, func);
}

/* Recorrido de árbol en postorden, aplicamos la función func, que tiene
   el prototipo:
   void func(int*);
*/
void PostOrden(Arbol a, void (*func)(int*))
{
   if(a->izquierdo) PostOrden(a->izquierdo, func);
   if(a->derecho) PostOrden(a->derecho, func);
   func(&a->dato);
}

/* Buscar un valor en el árbol */
int Buscar(Arbol a, int dat)
{
   pNodo actual = a;

   /* Todavía puede aparecer, ya que quedan nodos por mirar */
   while(!Vacio(actual)) {
      if(dat == actual->dato) return TRUE; /* dato encontrado */
      else if(dat < actual->dato) actual = actual->izquierdo; /* Seguir */
      else if(dat > actual->dato) actual = actual->derecho;
   }
   return FALSE; /* No está en árbol */
}

/* Calcular la altura del nodo que contiene el dato dat */
int Altura(Arbol a, int dat)
{
   int altura = 0;
   pNodo actual = a;

   /* Todavía puede aparecer, ya que quedan nodos por mirar */
   while(!Vacio(actual)) {
      if(dat == actual->dato) return altura; /* encontrado: devolver altura */
      else {
         altura++; /* Incrementamos la altura, seguimos buscando */
         if(dat < actual->dato) actual = actual->izquierdo;
         else if(dat > actual->dato) actual = actual->derecho;
      }
   }
   return -1; /* No está en árbol, devolver -1 */
}

/* Contar el número de nodos */
int NumeroNodos(Arbol a, int *contador)
{
   *contador = 0;

   auxContador(a, contador); /* Función auxiliar */
   return *contador;
}

/* Función auxiliar para contar nodos. Función recursiva de recorrido en
   preorden, el proceso es aumentar el contador */
void auxContador(Arbol nodo, int *c)
{
   (*c)++; /* Otro nodo */
   /* Continuar recorrido */
   if(nodo->izquierdo) auxContador(nodo->izquierdo, c);
   if(nodo->derecho)   auxContador(nodo->derecho, c);
}

/* Calcular la altura del árbol, que es la altura del nodo de mayor altura. */
int AlturaArbol(Arbol a, int *altura)
{
   *altura = 0;

   auxAltura(a, 0, altura); /* Función auxiliar */
   return *altura;
}

/* Función auxiliar para calcular altura. Función recursiva de recorrido en
   postorden, el proceso es actualizar la altura sólo en nodos hojas de mayor
   altura de la máxima actual */
void auxAltura(pNodo nodo, int a, int *altura)
{
   /* Recorrido postorden */
   if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1, altura);
   if(nodo->derecho)   auxAltura(nodo->derecho, a+1, altura);
   /* Proceso, si es un nodo hoja, y su altura es mayor que la actual del
      árbol, actualizamos la altura actual del árbol */
   if(EsHoja(nodo) && a > *altura) *altura = a;
}

/* Comprobar si un árbol es vacío */
int Vacio(Arbol r)
{
   return r==NULL;
}

/* Comprobar si un nodo es hoja */
int EsHoja(pNodo r)
{
   return !r->derecho && !r->izquierdo;
}

/* Función de prueba para recorridos del árbol */
void Mostrar(int *d)
{
clock_t inicio, fin;
float tim;
FILE * archivito2;
        archivito2 = fopen("grafica2.txt","a");
        if (archivito2==NULL)
        printf("no se logro crear el archivo");
inicio = clock();
    fprintf(archivito2,"set title \"Grafica de Eficiencia Arbol AVL\"\n");
    fprintf(archivito2,"set ylabel \"Tiempo en ordenar\"\n");
    fprintf(archivito2,"set xlabel \"Cantidad elementos Ordenados\"\n");
   fprintf(archivito2,"plot[%d:%f] log(x)\n ",*d, tim);



        fin = clock();
        tim =(float)(fin-inicio)/(float)CLOCKS_PER_SEC;

        fclose(archivito2);
        printf("%d, ", *d);
        tim = tiempoARBOL;
}
