#include <list>
#define MAX_COLUMNAS 7

class listaCartas {
private:
	std::list <Card> columnas[MAX_COLUMNAS];

public:
	listaCartas();
	listaCartas(Baraja&);

	//bool push(Card&);
	//Card pop();

	void print();

	bool move();



};

listaCartas::listaCartas() {
	for (int i = 0; i < 7; i++)
		columnas[i].clear();
}

listaCartas::listaCartas(Baraja& mazo) {
	for (int i = 0; i < MAX_COLUMNAS; i++) {
		for (int j = 0; j <= i; j++) {
			columnas[i].emplace_back(mazo.popCard());
			columnas[i].back().setPos(10 + (i * 150), 220 + (20 * j));
		}
		columnas[i].back().Voltear();
	}
}

//bool list::push(Card&) {
//	
//}
//Card list::pop() {
//
//}

void listaCartas::print() {
	list<Card> temp;
	for (int i = 0; i < MAX_COLUMNAS; i++) {
		temp = columnas[i];
		while(!temp.empty()){
			temp.front().print();
			temp.pop_front();
		}
	}
}

bool listaCartas::move() {
	for (int i = 0; i < MAX_COLUMNAS; i++) {
		columnas[i].front().mover();
		return true;
	}
	return false;
}