/**
 * _malloc - allocates memory for an array, using malloc.
 * @size: Size of each element
 * Return: pointer to the allocated memory, or 0 in fail
 */

void *_malloc(unsigned int size)
{
	char *memorySpace;

	memorySpace = malloc(sizeof(char) * size);
	if (memorySpace == NULL)
	{
		perror("Memory allocation error");
		return (0);
	}
	return (memorySpace);
}
