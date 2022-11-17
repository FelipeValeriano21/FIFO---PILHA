#include <iostream>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
typedef struct nopilha pilha;
struct nopilha
{
 int valor;
 pilha *ant;
};
int cont; // para contar os nós
pilha * topo;


void construtor ( ) { 
 topo = NULL; cont = 0; } 
 
 bool push(int valor)
{
 pilha *newpilha = (pilha*) malloc(sizeof(pilha));
 if (newpilha == NULL) return false;
 newpilha->valor = valor;
 newpilha->ant = topo;
 topo = newpilha; 
 cont ++; // incrementa quantidade de nós 
 return true;
}

bool pop()
{ 
 int valor; pilha *temp;
 temp = topo;
 valor = topo->valor;
 topo = topo->ant;
 free(temp);
 cout << "\nO valor removido foi:" << valor << endl;
 system("sleep 3");
 return true;
}

void exibirpilha()
{
 pilha *temp;
 temp= topo;
 system("clear");
 while ( temp != NULL)
 {
 cout << "\n" << temp->valor << endl;
 temp = temp->ant;
 }
 system("sleep 3");
}

bool vazia()
{ 
 return ( topo == NULL );
}

void destrutor() { 
 pilha *temp;
 while ( topo != NULL ) 
 { temp = topo;
 topo = topo->ant;
 free ( temp ); }
 free ( topo );
 cout << "\PIlha destruida com sucesso!\n" << endl;
 system("sleep 3"); }

int total () { 
 pilha * temp;
 temp = topo;
int cont = 0;
while ( temp != NULL )
 { 
 cont ++;
 temp=temp->ant; 
 }
return cont; } 



void controlarRegistro (){
	
	int tecla;
 cout << "\nMenu\n1 construtor\n2 exibirpilha\n3 destrutor\n4 Sair\nItem:";
   cin >> tecla;
do {
   
    switch ( tecla ) 
    {
    case 1: construtor();
            break;
            
    case 2: exibirpilha(); 
            break;
    case 3: destrutor();
            break;
    }
    
} while ( tecla != 4 );



cout << "\nPrograma Finalizado...!\n"; 
    
    
}

int main(int argc, char** argv) {
	
	controlarRegistro(); 
	
	return 0;
}




