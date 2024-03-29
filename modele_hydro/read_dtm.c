#include "main.h"

/**
 * readDTMFromFile - Read the Digital Terrain Model (DTM) from a file.
 *
 * @fileName: The name of the file containing DTM data.
 * @dtm: The array to store the DTM data.
 *
 * Return: 0 on success, -1 on failure.
 */
int readDTMFromFile(const char *fileName, int dtm[DTM_WIDTH][DTM_HEIGHT])
{
	FILE *file = fopen(fileName, "r");
	int i, j;

	if (file == NULL)
	{
		fprintf(stderr, "Error opening file: %s\n", fileName);
		perror("Error opening file");
		return (-1);
	}
	if (fscanf(file, "%*[^\n]\n") == EOF)
	{
		fprintf(stderr, "Error skipping header line in file: %s\n", fileName);
		fclose(file);
		return (-1);
	}
	/* Assume dtm.txt contains DTM_WIDTH * DTM_HEIGHT integers */
	for (i = 0; i < DTM_WIDTH; ++i)
	{
		for (j = 0; j < DTM_HEIGHT; ++j)
		{
			if (fscanf(file, "%d", &dtm[i][j]) != 1)
			{
				fprintf(stderr, "Error reading from file: %s\n", fileName);
				fclose(file);
				exit(1);
			}
		}
	}
	fclose(file);
	printf("File read successfully.\n");

	return (0);
}
