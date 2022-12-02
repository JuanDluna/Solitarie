#include <stack>
#include "classBaraja.hpp"

#define MAX_SOBRANTES 24

using namespace std;

class sobrantes {
	Card buttonStack = Card(0, 0, 930, 10);
	stack <Card> ocultas;
	stack <Card> mostradas;
public:
	inline sobrantes(){}
	sobrantes(Baraja&);

	bool isMostradasEmpty() { return mostradas.empty(); }

	void print();
	bool clickStack(ALLEGRO_EVENT evento);
	void moveTop();

};

sobrantes::sobrantes(Baraja& obj) {
	for (int i = 0; i < MAX_SOBRANTES; i++) {
		this->ocultas.push(obj.popCard());
		this->ocultas.top().setPos(930, 10);
	}
}

void sobrantes::print() {
	buttonStack.print();
	if (!mostradas.empty()) {
		mostradas.top().print();
	}
}

bool sobrantes::clickStack(ALLEGRO_EVENT evento) {
	ALLEGRO_MOUSE_STATE state;
	al_get_mouse_state(&state);
	if (buttonStack.clickAboveButton(evento)) {
		if (ocultas.empty()) {
			for (int i = 0; i < MAX_SOBRANTES; i++) {
				ocultas.push(mostradas.top());
				ocultas.top().Voltear();
				ocultas.top().setPosX(1070, ALLEGRO_ALIGN_LEFT);
				mostradas.pop();
				cout << ocultas.top().getNumber() << '\t' << ocultas.top().getSuit() << endl;
			}
			buttonStack.Voltear();
			return true;
		}
		if (mostradas.size() == MAX_SOBRANTES - 1) {
			buttonStack.Voltear();
		}
		mostradas.push(ocultas.top());
		mostradas.top().Voltear();
		mostradas.top().setPos(780, 10);
		ocultas.pop();
		return true;
	}
	return false;
}

void sobrantes::moveTop() {
	mostradas.top().mover();
}

