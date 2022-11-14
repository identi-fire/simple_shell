#include "main.h"

/**
 * _realloc - reallocates a new block of memory for the caller
 * @old_alloc: Previously allocated block of memory
 * @old_size: size of previously allocated block of memory
 * @new_size: size of reallocated block of memory
 *
 * Return: pointer to the reallocated block of memory
 */
void *_realloc(void *old_alloc, size_t old_size, size_t new_size)
{
	void *new_alloc;
	size_t i;

	if (old_size >= new_size)
		return (old_alloc);
	if ((new_size < old_size) && (old_alloc != NULL))
	{
		free(old_alloc);
		return (NULL);
	}
	new_alloc = malloc(new_size);
	if (new_alloc == NULL)
		return (NULL);
	if (old_alloc == NULL)
		return (new_alloc);
	if (old_size < new_size)
	{
		for (i = 0; i < old_size; i++)
		{
			*((char *) new_alloc + i) = *((char *) old_alloc + i);
		}
		free(old_alloc);
	}
	return (new_alloc);
}
