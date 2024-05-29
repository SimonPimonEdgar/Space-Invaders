#include "observer.h"
#include <vector>

// Observerable implementation simply realizes how observers are registered and how
// information is distributed.
void Observable::addObserver(Observer* observer) {
	observers.push_back(observer);
};

void Observable::notifyUpdate() {
	for (auto& observer : observers){
		observer->update();
	}
};