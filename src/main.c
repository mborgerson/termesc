#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "termesc.h"

int main(int argc, char *argv[])
{
	termesc_init();
	termesc_hide_cursor(true);

	struct termdim td;
	termesc_get_dimensions(&td);

	termesc_goto(0, td.rows - 4);
	printf(fmt(fg green) "------ prompt sep ------" fmt(plain));


	termesc_set_scroll(1, td.rows - 5);
	termesc_goto(0, 0);
	printf("Begin top scroll\n");
	for (size_t i = 0; i < 100; ++i) {
		usleep(50*1000);
		printf(fmt(fg blue) "%u\n" fmt(plain), i);
	}

	termesc_set_scroll(td.rows - 3, td.rows);
	termesc_goto(0, td.rows - 3);
	printf("Begin prompt scroll\n");
	for (size_t i = 0; i < 10; ++i) {
		usleep(500*1000);
		printf(fmt(fg green) "%u\n" fmt(plain), i);
	}

	termesc_set_scroll(1, td.rows - 5);
	termesc_goto(0, td.rows - 5);
	printf("Begin top scroll\n");
	for (size_t i = 0; i < 100; ++i) {
		usleep(50*1000);
		printf(fmt(fg yellow) "%u\n" fmt(plain), i);
	}


	termesc_close();
}
