#include "get_next_line_bonus.h"

int main()
{
	int fd1, fd2;
	char *line1;
	char *line2;

	fd1 = open("txt2.txt", O_RDONLY);
	fd2 = open("txt3.txt", O_RDONLY);

	if (fd1 == -1 || fd2 == -1)
	{
		perror("Error opening");
		exit(EXIT_FAILURE);
	}

	line1 = get_next_line(fd1);
	printf("line 1 : %s", line1);

	line2 = get_next_line(fd2);
	printf("line 1 : %s", line2);

	line1 = get_next_line(fd1);
	printf("line 2 : %s", line1);

	line2 = get_next_line(fd2);
	printf("line 2 : %s", line2);

	line1 = get_next_line(fd1);
	printf("line 3 : %s", line1);

	line2 = get_next_line(fd2);
	printf("line 3 : %s", line2);

	free(line1);
	free(line2);

	close(fd1);
	close(fd2);
}
