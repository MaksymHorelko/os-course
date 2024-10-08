#include <stdio.h>
#include <math.h>

void process_array(double arr[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    double avg = sum / n;

    int count_greater_than_avg = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > avg) {
            count_greater_than_avg++;
        }
    }

    double sum_abs_after_negative = 0;
    int found_negative = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0 && !found_negative) {
            found_negative = 1;
        } else if (found_negative) {
            sum_abs_after_negative += fabs(arr[i]);
        }
    }

    printf("Кількість елементів більших за середнє: %d\n", count_greater_than_avg);
    printf("Сума абсолютних значень після першого від'ємного: %.2f\n", sum_abs_after_negative);
}

int main() {
    double arr[] = {1.5, -2.0, 3.1, -1.5, 2.3, 4.0, -0.5};
    int n = sizeof(arr) / sizeof(arr[0]);

    process_array(arr, n);

    return 0;
}
