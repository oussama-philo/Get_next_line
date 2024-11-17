#include "get_next_line.h"

int main()
{
	int fd1;
	int rd;

	char buff[8];

	fd1 = open("txt2.txt", O_RDONLY);

	if (fd1 == -1)
	{
		perror("Error opening");
		exit(EXIT_FAILURE);
	}

	while ((rd = read(fd1, buff, 8)) > 0)
	{
		buff[rd] = '\0';
		printf("%s", buff);
	}
	close(fd1);
}
