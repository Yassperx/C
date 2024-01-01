#include <stdio.h>

#define FILENAMELENGTH 100
#define CONTENTFILELENGTH 10000

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  char filename[FILENAMELENGTH];
  char content[CONTENTFILELENGTH];

  // Copy the filename from the command-line argument
  snprintf(filename, sizeof(filename), "%s", argv[1]);

  FILE *target = fopen(filename, "w");

  if (target == NULL)
  {
    printf("File %s can't be opened!\n", filename);
    return 1;
  }

  // Read content from the file
  size_t bytesRead = fread(content, 1, sizeof(content), target);

  // Check for read errors
  if (ferror(target))
  {
    printf("Error reading file.\n");
    fclose(target);
    return 1;
  }

  // Null-terminate the content to use it as a string
  content[bytesRead] = '\0';

  // Print or process the content as needed
  printf("Content of the file:\n%s\n", content);

  fclose(target);
  return 0;
}
