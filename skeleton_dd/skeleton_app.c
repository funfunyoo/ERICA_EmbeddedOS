/** System Programming : SKELETON User Application **/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>

static unsigned short flag;

int menu_display(void)
{
    int key;
    char input[2];

    printf("\n\n");
    printf("********** [USER_APP] Menu ***********\n");
    printf("* 1.  USER_APP: Keyboard [1]         *\n");
    printf("* 2.  USER_APP: Keyboard [2]         *\n");
    printf("* 3.  USER_APP: Keyboard [3]         *\n");
    printf("* 4.  USER_APP: Keyboard [4]         *\n");
    printf("* w.  USER_APP: write() execute      *\n");
    printf("* r.  USER_APP: read() execute       *\n");
    printf("*                                   *\n");
    printf("* q.  USER_APP: Quit                 *\n");
    printf("*************************************\n");
    printf("\n\n");

    printf("[USER_APP] Select the command number : ");
    key = getchar();
    getchar();
    printf("\n\n");

    return key;
}

int main(void)
{
    int fd, i;
    int key;
    char *buffer1 = "EFGH";
    char buffer2[256];

    fd = open("/dev/SKELETON", O_RDWR);

    if(fd < 0)
    {
        printf("[SKELETON_APP] /dev/SKELETON isn't opened! \n");
	exit(-1);
    }

    else
        printf("[SKELETON_APP] /dev/SKELETON is opened! \n");

    while((key = menu_display()) != 0)
    {
        switch(key)
	{
	    case '1':
	        printf("[SKELETON_APP] Keyboard [1] is clicked! \n");
		ioctl(fd, 1, flag);
		break;

	    case '2':
	        printf("[SKELETON_APP] Keyboard [2] is clicked! \n");
		ioctl(fd, 2, flag);
		break;

	    case '3':
	        printf("[SKELETON_APP] Keyboard [3] is clicked! \n");
		ioctl(fd, 3, flag);
		break;

	    case '4':
	        printf("[SKELETON_APP] Keyboard [4] is clicked! \n");
		ioctl(fd, 4, flag);
		break;

	    case 'w':
	        printf("[SKELETON_APP] write() is called! \n");
	        write(fd, buffer1, 5);	
		break;

	    case 'r':
	        printf("[SKELETON_APP] read() is called! \n");
	        read(fd, buffer2, 5);	
		printf("[USER_APP] Device read data = %s \n", buffer2);
		break;

            case 'q':
	        printf("[USER_APP] User Application is closed! \n");
		close(fd);
		exit(0);
		break;
	}
    }

    return 0;
}
