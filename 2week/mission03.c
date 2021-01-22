#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void) {
    // 포인터를 활용해 효율적으로 메모리 공간 사용
    // week 배열에는 월요일부터 일요일까지의 "요일" 값이 순서대로 들어있다.
    char *week[] = {"월요일", "화요일", "수요일", "목요일", "금요일", "토요일", "일요일"};
    // food 배열에는 월요일부터 일요일까지의 "메뉴" 값이 순서대로 들어있다.
    char *food[] = {"청국장", "비빔밥", "된장찌개", "칼국수", "냉면", "소불고기", "오삼불고기"};

    // week 배열의 크기 구하기 - sizeof 사용, byte 단위로 출력한다.
    // sizeof(week) = 8 바이트 문자열 7개의 요소 포함 = 8 * 7 = 56
    // sizeof(week[0]) = 문자열 하나의 크기 8 바이트
    int length = sizeof(week) / sizeof(week[0]);
    
    // 요일 입력하기
    string dayOfWeek = get_string("요일을 입력하세요: ");

    // 반복문을 통해 week 배열의 크기만큼 반복한다.
    for(int i = 0; i < length; i++) {
        // 입력한 요일(dow)과 week 배열에서 같은 값이 있는 지 비교한다.
        if(strcmp(dayOfWeek,week[i]) == 0) {
            // 요일과 메뉴의 배열 위치가 같이 때문에 같은 위치의 배열값을 출력해준다.
            printf("%s: %s\n", week[i], food[i]);
        }
    }

    // main 함수를 정상적으로 종료하겠다는 뜻
    return 0;
}

/*
    strcmp() 함수는 문자열을 비교해
    ASCII 코드 기준으로 두 문자열이 같으면 0,
    ASCII 코드 기준으로 앞 문자열이 크면 1,
    ASCII 코드 기준으로 뒤 문자열이 크면 -1
    을 반환한다.
*/

