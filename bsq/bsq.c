#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	int	i;
	int	fd;
	int	word_count;
	int	sz;

	word_count = 0;
	i = 1;
	if (ac != 1)
	{
		while (i < ac)
		{
			char	c;
			fd = open(av[i],O_RDONLY);
			while (sz = read(fd, &c, 1) && (c != EOF || c != '\0') )
			{
				word_count++;
			}
			close (fd);
			//printf("AAAA\n");
			char	*file_string;
			file_string = (char *)malloc(word_count);
			int	ctr = 0;
			printf("\n%i",word_count);
			fd =  open(av[i],O_RDONLY);
			while (ctr < word_count)
			{
				read(fd, &c, 1);
				file_string[ctr] = c;
				ctr++;
			}
			close (fd);
			printf("%s",file_string);
		}
	}
}
