#include <vector>
#include "classBaraja.hpp"

#define MAX_SOBRANTES 24

using namespace std;

class sobrantes {
private:
	boton backSobrantes = boton("resources/OwnCards/BackCard.png", "resources/OwnCards/BackCard.png", 10, 710, ALLEGRO_ALIGN_LEFT);
	vector <Card> volteadas;
	vector <Card> ocultas;
public:
	sobrantes();
	sobrantes(Baraja&);
	void print();
	~sobrantes();
};

sobrantes::sobrantes(){
	this->volteadas.clear();
	this->ocultas.clear();
}

sobrantes::sobrantes(Baraja&mazo) {
	/*for (int i = 0; i < MAX_SOBRANTES; i++) {
		ocultas.emplace_back(mazo.popCard());
		ocultas.at(i).setIsHidden(true);
	}
	this->volteadas.clear();*/
}

void sobrantes::print() {
	backSobrantes.print();
	cout << ocultas.size();
	/*if(volteadas.size() > 0)
		for (int i = volteadas.size() - 1; i > MAX_SOBRANTES - 3; i--)
			volteadas.at(i).print();*/
}


sobrantes::~sobrantes() {
	volteadas.clear();
	ocultas.clear();
}
