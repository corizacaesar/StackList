#include <iostream>
#include <stdlib.h>
using namespace std;

/* Konstanta */
#define Nil NULL

/* Deklarasi infotype */
typedef int infotype;

/* Stack dengan representasi berkait dengan pointer */
typedef struct tElmtStack * address;
typedef struct tElmtStack { 
	infotype Info;
	address Next; 
} ElmtStack; 

/* Type stack dengan ciri TOP : */
typedef struct { 
	address TOP;  /* alamat TOP: elemen puncak */
} Stack;

/* Selektor */
#define Top(S) (S).TOP
#define InfoTop(S) (S).TOP->Info 
#define Next(P) (P)->Next
#define Info(P) (P)->Info

/*	----- Prototype Manajemen Memori ----- */
void Alokasi (address * P, infotype X) {
	/* Kamus Lokal */

	/* Algoritma */
	(*P) = (address) malloc (sizeof (ElmtStack));
	if ((*P) != Nil) {
		Info(*P) = X;
		Next(*P) = Nil;
	}
}

void Dealokasi (address P) {
	/* Kamus Lokal */

	/* Algoritma */
	Next(P)=Nil;
}

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
bool IsEmpty (Stack S) {
	/* Kamus Lokal */

	/* Algoritma */
	return (Top(S) == Nil);
}
void CreateEmpty (Stack * S) {
	/* Kamus Lokal */

	/* Algoritma */
	Top(*S) = Nil;
}
/*	----- Operator Dasar Stack ----- */
void Push (Stack * S, infotype X) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	Alokasi(&P,X);
	if (P != Nil) {
		Next(P) = Top(*S);
		Top(*S) = P;
	}
}

void Pop (Stack * S, infotype * X) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	P = Top(*S);
	*X= Info(P);
	if (!IsEmpty(*S)) {
		Top(*S)=Next(P);
		Dealokasi(P);
	}
}

void PrintInfo(Stack S){
	if(!IsEmpty(S)){
		address P = Top(S);
		while(Next(P)!=NULL){
			cout<<Info(P)<<",";
			P = Next(P);
		}
		cout<<Info(P);
	}
}

int main(){
	Stack S;
	CreateEmpty(&S);
	
	infotype n, x;
	
  	while(n!=4){
	   cout<<"MENU\n1.Push\n2.Pop\n3.Print\n4.Exit\n";
       cin>>n;
	   if(n==1){
          cout<<"Masukkan data :  ";
          cin>>x;
          Push(&S,x);
          system("CLS");
       }else if(n==2){
          Pop(&S,&x);
          system("CLS");
       }else if(n==3){
          cout<<"Isi Stack : ";
          PrintInfo(S);
          cout<<endl<<endl;
       }else{
          cout<<"Pilihan MENU salah!!"<<endl;
       }
       
      }
      return 0;                              
}
