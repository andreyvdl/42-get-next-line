# 42-get-next-line

Function name | Files to turn in | External functions | Result
--- | --- | --- | ---
get_next_line | get_next_line.c, get_next_line_utils.c, get_next_line.h, (get_next_line_bonus.c, get_next_line_bonus.h, get_next_line_utils_bonus.c) | read, malloc, free | 125/100%

## Objective
> Write a function that returns a line read from a file descriptor.

### Prototype
```c
char  *get_next_line(int fd);
```

### Simple execution code

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
	int		file_descriptor;
	char	*line;
  
	line = 0x0;
	file_descriptor = open("file_you_wish_to_open", O_RDONLY);
	if (file_descriptor < 0)
		return (printf("Error opening file\n"), 1);
	while (1)
	{
  		line = get_next_line(file_descriptor);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
		line = 0x0;
	}
	close(file_descriptor);
	return (0);
}
```
