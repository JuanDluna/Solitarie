#include"classCard.hpp"

struct Nodo {
	Card info;
	struct Nodo* liga;
};

class Lista {
private:

public:
	Nodo* inicio;
	Nodo* fin;

	Lista();
	Lista(Card);
	Nodo* crearNodo(Card);
	void insertar(Card x);
};

Lista::Lista() {
	inicio = fin = NULL;
}

Nodo* Lista::crearNodo(Card x) {
	Nodo* nuevo;
	nuevo->info = x;
	nuevo->liga = NULL;
}

Lista::Lista(Card x) {
	fin = inicio = crearNodo(x);
}

void Lista::insertar(Card x) {
	Nodo *nuevo = crearNodo(x);
	fin->liga = nuevo;
	fin = nuevo;
}

class ListaJuego {
private:
	Lista VecL[7];
public:
	ListaJuego();
	ListaJuego(Card );
	bool insertarJ(Card, Card);

};

ListaJuego::ListaJuego() {
	for (int i = 0; i < 7; i++) {
		VecL[i] = Lista();
	}
}


//las listas se deben inicializar con un cilo dentro del main para poder meter la baraja ya reburujada
ListaJuego::ListaJuego(Card x) {
	int c = 0;
	for (int i = 0; i <= 7; i++) {
		for (int j = 0; j <= i; j++) {
			VecL[i].insertar(x);
				if (j = i) {
					VecL[i].fin->info.Voltear();
			}
		}
	}
}

bool ListaJuego::insertarJ(Card L, Card N) {
	bool colorL = L.getColor();
	int numL = L.getN();
	if (colorL != N.getColor() && numL == (N.getN() - 1)){
		return true;
	}
	return false;
}