#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

#define SIZE 30

int main (int argc, char *argv[]) {
    if (argc != 4) {
      printf("Usage:\n\t./a.out <link_type> <target> <link_name>\n");
      printf("\t\tLink Types:\n");
      printf("\t\t\t-h\thard link\n");
      printf("\t\t\t-s\tsymbolic link\n");
      exit(0);
    }
    
    if (argv[1][1] == 'h') {
      if ((link(argv[2], argv[3])) < 0) {
	perror("error creating hard link");
	exit(1);
      }
      printf("hard link created\n");
    } else if (argv[1][1] == 's') {
      if ((symlink(argv[2], argv[3])) < 0) {
	perror("error creating symbolic link");
	exit(1);
      }
      printf("symbolic link created\n");
    }
      
    return 0;
}
