#include "simulation.h"


int main() {
		srand(static_cast<unsigned>(time(0)));

		simulation sim = simulation();

		while(sim.isRunning()) {
				sim.run();
		}

		return 0;
}
