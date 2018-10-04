#include "environment.h"

#include <cstdlib>
#include <ctime>





int main() {
	srand(time(NULL));
	Environment env;
	for (int i = 0; i < 20; i++) {
		env.daily();
		std::cout << "===============Day " << i << std::endl;
		env.print(false);
	}

}
