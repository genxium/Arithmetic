#include <stdio.h> 
#include <stdlib.h>

int arr_to_state(int* arr, int arr_len, int base) {
	int ret = 0;
	int power = 1;
	for (int i = 0; i < arr_len; ++i) {
		int pos = arr_len - 1 - i;
		ret += arr[pos] * power;
		power *= base;	
	}
	return ret;
}

void state_to_arr(int state, int base, int* arr, int arr_len) {
	for (int i = 0; i < arr_len; ++i) {
		int pos = arr_len - 1 - i;
		arr[pos] = (state % base);
		state /= base;
	}
}

void print_arr(int* arr, int arr_len) {
	for (int i = 0; i < arr_len; ++i) {
		printf("%d", arr[i]);
		if (i == arr_len - 1) break;
		printf(", ");
	}
}

int main() {
	int test_base = 7;
	int test_arr[] = {5, 4, 1, 6, 3, 2};
	int test_arr_len = sizeof(test_arr)/sizeof(int);
	printf("test_arr: {");
	print_arr(test_arr, test_arr_len);
	puts("}");
	int test_state = arr_to_state(test_arr, test_arr_len, test_base);
	printf("test_state == %d\n", test_state);	
	int* restored_arr = (int*) calloc(test_arr_len, sizeof(int));
	state_to_arr(test_state, test_base, restored_arr, test_arr_len);
	printf("restored_arr: {");
	print_arr(restored_arr, test_arr_len);
	puts("}");
	free(restored_arr);
	return 0;
}
