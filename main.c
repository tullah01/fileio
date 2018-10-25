#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int filedescript;
	char buffer [17];
	char * fileName = "hello.txt";
	printf("Opening file '%s' with write access.\n", fileName);
	filedescript = open(fileName, O_CREAT | O_WRONLY, 0700);

	if (filedescript == -1) {
		printf("File creation / opening failed!\n");
		return 1;
	}

	char * myMessage = "Hello!\n";
	printf("Writing to file '%s'.\n", fileName);
	write(filedescript, myMessage, 17);
	printf("Closing file '%s'.\n", fileName);
	close(filedescript);
	printf("Opening file '%s' with read access.\n", fileName);
	filedescript = open(fileName, O_RDONLY);

	if (filedescript == -1) {
		printf("Failed to open file\n");
		return 1;
	}
	
	printf("Reading file '%s':\n", fileName);
	read(filedescript, buffer, 17);
	buffer[17] = '\0';
	printf("%s", buffer);
	return 0;
}