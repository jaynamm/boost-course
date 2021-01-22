#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void) {
    // 2차원 배열에 "요일"과 "메뉴"를 같이 넣어준다.
    // 요일 = menu[][0] , 메뉴 = menu[][1]
    // string 배열은 cs50.h 에 의해서 사용할 수 있다.
    string menu[7][2] = {
        {"월요일", "청국장"},
        {"화요일", "비빔밥"},
        {"수요일", "된장찌개"},
        {"목요일", "칼국수"},
        {"금요일", "냉면"},
        {"토요일", "소불고기"},
        {"일요일", "오삼불고기"}
    };
    
    // 요일 입력하기
    string dayOfWeek = get_string("요일을 입력하세요: ");

    for(int i=0; i<7; i++) {
        if(strcmp(dayOfWeek, menu[i][0]) == 0) {
            printf("%s: %s\n", menu[i][0], menu[i][1]);
        }
    }

    return 0;
}

/*
    strcmp() 함수는 문자열을 비교해
    ASCII 코드 기준으로 두 문자열이 같으면 0,
    ASCII 코드 기준으로 앞 문자열이 크면 1,
    ASCII 코드 기준으로 뒤 문자열이 크면 -1
    을 반환한다.
*/

