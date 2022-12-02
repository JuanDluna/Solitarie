#include <vector>
#include <random>
#include "classCard.hpp"

using namespace std;

class Baraja {
private:
	vector <Card> mazo;
public:
	Baraja();
	void MostrarC(int);
	Card popCard();
};

Baraja::Baraja() {

	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 13; j++) {
			mazo.push_back(Card(i, j, 0 , 0));
		}
	}

	std::random_device rd;
	std::mt19937 s(rd()); //mersenne twister engine for shuffle

	std::shuffle(mazo.begin(), mazo.end(), rd); //vector mezclado
}

void Baraja::MostrarC(int cont) {
	mazo.at(cont).print();
}

Card Baraja::popCard() {
	Card temp = mazo.at(mazo.size());
	mazo.erase( mazo.end() - 1 ) ;
	return temp;
}
