#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

// 함수 선언
void print_result(int length, int locations[]);
int get_center_value(int length, int locations[]);
int get_average_value(int lnegth, int locations[]);
int sum_distance(int length, int locations[], int value);
int* bubble_sort(int length, int locations[]);

int main(int argc, char* argv[]) {
    // 입력값 배열 선언
    int location1[4] = { 2, 2, 2, 4 };
    int location2[5] = { 1, 2, 3, 4, 5 };
    int location3[4] = { 5, 3, 5, 6 };

    // 결과 출력
    print_result(sizeof(location1)/sizeof(int), location1);
    print_result(sizeof(location2)/sizeof(int), location2);
    print_result(sizeof(location3)/sizeof(int), location3);
}

// 결과 출력 함수
void print_result(int length, int locations[]) {
    int center_val = 0;
    int average_val = 0;
    int result;

    printf("입력값: ");

    for (int i=0; i<length; i++) {
        printf("%d", locations[i]);
    }

    center_val = get_center_value(length, locations); // 중앙값
    average_val = get_average_value(length, locations); // 평균값

    int sum_for_center = sum_distance(length, locations, center_val); // 중앙값을 통해 구한 거리의 합
    int sum_for_avg = sum_distance(length, locations, average_val); // 평균값을 통해 구한 거리의 합

    result = (sum_for_center >= sum_for_avg) ? average_val : center_val ;

    printf(" -> 출력값: %d\n", result);
}

// 중앙값을 구하는 함수
int get_center_value(int length, int locations[]) {
    int center = 0; // 중앙 위치
    int center_val = 0; // 중앙 값

    // 중앙 값을 구하기 위해 버블 정렬을 해준다.
    int* sorted_location = bubble_sort(length, locations);

    // 중앙 위치 구하기
    if(length % 2 == 0) { // 배열의 길이가 홀수의 경우
        center = length/2 - 1;
    } else { // 배열의 길이가 홀수의 경우
        center = length/2;
    }

    center_val = sorted_location[center]; // 중앙 위치를 구해 배열의 중앙값을 구한다.

    return center_val;
}

// 평균값을 구하는 함수
int get_average_value(int length, int locations[]) {
    int avg_val = 0;

    // 평균값 구하기
    for (int i=0; i<length; i++) {
        avg_val += locations[i]; // 모든 배열의 값을 더해준다.
    }

    avg_val = avg_val / length; // 다 더해준 값을 배열의 개수로 나누어준다.

    return avg_val;
}

// 거리의 합을 구하는 함수
int sum_distance(int length, int locations[], int value) {
    int sum = 0;

    for (int i=0; i<length; i++) {
        if(locations[i] < value) {         // 값보다 작을 경우
            sum += (value - locations[i]);
        } else {                           // 값보다 클 경우
            sum += (locations[i] - value);
        }
    }

    return sum;
}

// 버블 정렬 함수
int* bubble_sort(int length, int locations[]) {
    int temp;

    for (int i=0; i<length; i++) {
        for (int j=0; j<length-i-1; j++) {
            if(locations[j] > locations[j+1]) {
                temp = locations[j];
                locations[j] = locations[j+1];
                locations[j+1] = temp;
            }
        }
    }

    return locations;
}

