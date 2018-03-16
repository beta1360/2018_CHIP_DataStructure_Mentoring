// Available after Mar 16, 2018

#include <stdio.h>

int strlen(char str[]) {
	int index;
	for (index = 0; ; index++)
		if (str[index] == '\0') break;
	
	return index;
}

void seperate_remover(char input[], char remover[], char output[]) {
	
	int how_to_remove = 0;
	int input_len = strlen(input);
	int remover_len = strlen(remover);
	int counter = 0;

	for (int i = 0; i < (input_len - remover_len); i++) {
		for (int j = 0; j < remover_len; j++) {
			if (input[i + j] == remover[j]) 
				counter++;
			printf("< %d :: %c (%c) >",counter, input[i+j],remover[j]);
		}

		if (counter == remover_len) {
			for (int k = i + remover_len; k < input_len; k++)
				output[k - remover_len * (how_to_remove + 1)] = input[k];
			i += remover_len;
			how_to_remove++;
		}

		counter = 0;
	}

	output[input_len - remover_len * how_to_remove] = '\0';
}

int main(void) {

	char input[100];
	char remover[100];
	char output[100];

	gets(input);
	gets(remover);

	seperate_remover(input, remover, output);
	printf("%s\n", output);

	return 0;
}
