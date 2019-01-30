#include<stdio.h>
#include<unistd.h>

#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char* argv[]) {

	if (argc < 2) {
		printf("ingrese tanto el input como el output");
		return(1);
	}

	char *input = argv[1];
	char *output = argv[2];

	struct stat filestat;
	stat(input, &filestat);
	int size = filestat.st_size;
	printf("%d", size);

	int file = open(input, O_RDONLY);

	if (file < 0) {
		return(1);
	}

	char data[size];
	read(file, data, size);
	
	

	int newfile = open(output, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
	

	write(newfile, data, size);

	close(file);
	close(newfile);

	return(0);
}
