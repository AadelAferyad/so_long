#include "parser.h"



int	main(int ac, char **av)
{
	int	fd;
	char	**map;
	int	i;

	if (ac < 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		printf("error file does't exist\n");
		exit(1);
	}
	map = parser(fd);
	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	return (0);
}
