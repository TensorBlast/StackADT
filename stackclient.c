#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

main()
{
	Stack s1 = create_stack();
	Stack s2 = create_stack();

	int i;
	char *test[10];

	for (i=1; i<11; i++) {
		char num[100];
		char msg[100] = "Test Message ";
		sprintf(num, "%d", i);
		strcat(msg,num );

		test[i-1] = malloc(sizeof(msg));
		memcpy(test[i-1], msg,sizeof(msg));
	}

	push(s1, test[0]);
	push(s1, test[1]);
	push(s1, test[2]);


	char * t = pop(s1);
	printf("Popped %s from s1\n",t );

	push(s2, t);

	t = pop(s1);
	push(s2, t);

	destroy(s1);

	while(!is_empty(s2)) {
		printf("Popped %s from s2\n", pop(s2));
	}
}
