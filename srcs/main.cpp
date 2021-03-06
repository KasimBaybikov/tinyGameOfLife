#include "Generation.hpp"
#include "GameOfLife.hpp"


int main(int ac, char **av)
{
	Generation gen;
	int generations[20];
	int index = 0;
	if (ac < 1 || ac > 2)
		return (error(1));
	gen.getMapFromFile(av[1]);
	gen.fillParametrs();
	std::cout << gen.getSurvivors() << std::endl;
	while (gen.getState() != death)
	{
		std::system("clear");
		gen.print_status_game();
		gen.iteration();
		generations[index++] = gen.getSurvivors();
		if (index == 20)
			index = 0;
		if (check_generations(generations) == 0)
			break;
		if (gen.getSurvivors() == 0)
			break;
		usleep(180000);
	}
	gen.theEnd();
	return 0;
}
