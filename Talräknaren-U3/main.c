#include <stdio.h>
#include <limits.h>
#include <windows.h>
#pragma warning (disable: 4996)

void readNumbers(int *sum, int *min, int *max, int *count);
float calculateAverage(int sum, int count);
void printResults(int min, int max, int sum, float avg, int count);

int main() {
	int input;

	do
	{
		int sum = 0, count = 0;
		float avg = 0;
		int min = INT_MAX;
		int max = INT_MIN;

		system("cls");
		readNumbers(&sum, &min, &max, &count);
		avg = calculateAverage(sum, count);
		system("cls");
		printResults(min, max, sum, avg, count);

		printf("Run program again? (1 for yes, 0 for no) : ");
		while (scanf("%d", &input) != 1)
		{
			printf("\n--- Invalid Input ---\n\n");
			while (getchar() != '\n');
			printf("Run program again? (1 for yes, 0 for no) : ");
		}
	} while (input);

	return 0;
}

void readNumbers(int *sum, int *min, int *max, int *count) {
	int num;

	printf("\x1b[44m--- Numbers counter ---\x1b[m\n\nEnter numbers \x1b[1;41m(ONLY positive numbers!)\x1b[m. Enter -1 to finish!\n\n");
	while (1)
	{
		printf("Enter number: [");
		if (scanf("%d", &num) == 1) {
			if (num < 0) {
				break;
			}

			*sum = *sum + num;

			if (num < *min)
			{
				*min = num;
			}
			if (num > *max)
			{
				*max = num;
			}
			(*count)++;
		}
		else {
			printf("--- INVALID INPUT ---\n\n");
			while (getchar() != '\n');
		}
	}

}

static float calculateAverage(int sum, int count) {
	float avg;
	if (count != 0) {
		avg = (float)sum / count;
		return avg;
	}
	return 0;
}

void printResults(int min, int max, int sum, float avg, int count) {

	if (count == 0) {
		printf("\x1b[41m--- Results ---\x1b[m\n\nNo numbers entered!\n\n");
		return;
	}

	printf("\x1b[42m--- Results ---\x1b[m\n\nMin val: %d \nMax val: %d \nsum: %d \navg: %.2f\n", min, max, sum, avg);
}