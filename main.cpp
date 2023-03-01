#include "simulation.h"


int main() {
		simulation sim = simulation();

		while(sim.isRunning()) {
				sim.run();
		}

		return 0;
}
