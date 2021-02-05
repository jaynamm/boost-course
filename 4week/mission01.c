#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 함수 선언하기
void print_anagram(const char* s1, const char* s2); // 결과를 출력해주는 함수
int is_anagram(const char* s1, const char* s2); // 애나그램인지 구별해주는 함수
char* selection_sort(const char* s); // 선택 정렬 함수

int main(int argc, char *argv[]) {
    // 숫자를 입력받는 부분은 따로 구현하지 않고 배열로 선언한다.
    char* input1[2] = {"12345", "54321"};
    char* input2[2] = {"14258", "25431"};
    char* input3[2] = {"11132", "21131"};

    // 결과 출력
    print_anagram(input1[0], input1[1]);
    print_anagram(input2[0], input2[1]);
    print_anagram(input3[0], input3[1]);

    return 0;
}


// 애나그램인지 아닌지 확인 후 출력해주는 함수
void print_anagram(const char* s1, const char* s2) {
    printf("입력값: %s, %s", s1, s2);

    // is_anagram() 함수는 int 타입이고, 0 또는 1을 반환한다.
    if(is_anagram(s1, s2)) { // is_anagram() 함수가 1을 반환하면 True
        printf(" => 출력값: True\n");
    } else { // is_anagram() 함수가 0을 반환하면 False
        printf(" => 출력값: False\n");
    }
}


// 두 문자열이 애나그램인지 확인해주는 함수
int is_anagram(const char* s1, const char* s2) {
    // 두 문자열의 길이 비교
    if(strlen(s1) != strlen(s2)) {
        printf("두 숫자의 길이가 다릅니다. \n");
        return 0;
    }

    // 선택 정렬을 통해 정렬된 문자열 저장
    char* sorted_s1 = selection_sort(s1);
    char* sorted_s2 = selection_sort(s2);

    // strcmp() 함수로 정렬된 두 문자열을 비교해서 같은지 확인
    if (strcmp(sorted_s1, sorted_s2) == 0) {
        // malloc() 로 할당해준 메모리 해제
        free(sorted_s1);
        free(sorted_s2);

        // if() 조건문 안에서 1 이면 True 를 의미하기 때문에 같으면 1 을 반환
        return 1;
    } else {
        // malloc() 로 할당해준 메모리 해제
        free(sorted_s1);
        free(sorted_s2);

        // if() 조건문 안에서 0 이면 False 를 의미하기 때문에 같으면 0 을 반환
        return 0;
    }
}


// 선택 정렬을 해주는 함수
char* selection_sort(const char* s) {
    // 변수 선언
    int index;
    char temp, min;

    // malloc 함수를 사용해 메모리 공간을 할당 받았다.
    // 참고 : https://blockdmask.tistory.com/56
    char *str = malloc(sizeof(char) * strlen(s));
    // strcpy() 함수를 통해 입력받은 문자열 s 를 str 로 복사해서 사용했다.
    // malloc 함수로 할당받은 메모리 공간에 문자열을 입력(복사)해준다.
    strcpy(str, s);

    for(int i=0; i<5; i++) {
        // 현재 위치(i)와 현재 값(min = str[i])을 초기값으로 설정
        index = i;
        min = str[i];

        for (int j=i+1; j<5; j++) {
            // 값을 비교해 최솟값(min = str[j])를 갱신해주고 그 위치(index = j)를 기억한다.
            if (min > str[j] ) {
                min = str[j]; // 최솟값을 저장
                index = j;    // 최솟값 위치를 저장
            }
        }

        // 모든 배열을 비교해 최솟값을 찾고나면
        // 최솟값(min 의 위치(index)를 현재 위치(i)의 값과 바꾼다.
        if (i != index) { // 현재 위치와 다르다면
            temp = str[i]; // 비어있는 문자 temp 에 str[i] 를 넣어준다. temp <- str[i]
            str[i] = str[index]; // str[i] 에 str[index] 의 값을 저장해준다. str[i] <- str[index]
            str[index] = temp; // str[index] 에 temp (str[i]) 의 값을 저장해준다. str[index] <- temp
        }
    }

    // 정렬된 배열 반환
    return str;
}
