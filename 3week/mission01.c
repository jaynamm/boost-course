#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 점수와 학점 배열 선언
const int NUMBER_OF_GRADES = 9;
const int SCORES[NUMBER_OF_GRADES] = {95, 90, 85, 80, 75, 70, 65, 60, 0};
const char *GRADES[NUMBER_OF_GRADES] = {"A+", "A", "B+", "B", "C+", "C", "D+", "D", "F"};

// 함수 선언
void printScoresAndGrades(int length, const int scores[], const char *grades[]);
char* getGradeForScore(int score, int length, const int scores[], const char *grades[]);

int main(int argc, char *argv[]) {
    int score;

    printf("[학점 프로그램]\n");
    printf("종료를 원하면 \"-1\"를 입력하세요.\n");

    printScoresAndGrades(NUMBER_OF_GRADES, SCORES, GRADES);

    while(1) {
        // 문자를 입력하게 되면 무한루프에 빠지는 이유
        // 참고
        // https://www.inflearn.com/questions/23511
        // https://m.blog.naver.com/smilennv/220781410325

        printf("성적을 입력하세요 (0~100) : ");
        // 문자 입력 방지
        if(!scanf("%d", &score)) {
            printf("성적을 올바르게 입력하세요. 범위는 0 ~ 100 입니다.\n");
            while (getchar()!='\n');
            continue;
        }

        // -1 을 입력하면 프로그램 종료
        if (score == -1) {
            printf("학점 프로그램을 종료합니다.\n");
            return 0;
        }

        // 0 ~ 100 사이의 숫자가 입력될 경우
        if ( 0<= score && score <= 100 ) {
            char *grade = getGradeForScore(score, NUMBER_OF_GRADES, SCORES, GRADES);
            printf("학점은 %s 입니다.\n", grade);
        } else { // 0 ~ 100 이외의 숫자가 입력될 경우
            printf("성적을 올바르게 입력하세요. 범위는 0 ~ 100 입니다.\n");
            continue;
        }
    }

    return 0;
}

// 점수와 학점 테이블 출력하기
void printScoresAndGrades(int length, const int scores[], const char *grades[]) {
    // 점수 테이블 출력
    printf("점수: ");

    for(int i=0; i<length; i++) {
        printf("%d\t", scores[i]);
    }

    // 성적 테이블 출력
    printf("\n성적: ");

    for(int i=0; i<length; i++) {
        printf("%s\t", grades[i]);
    }

    printf("\n");
}

// 점수에 따른 학점 가져오기
char* getGradeForScore(int score, int length, const int scores[], const char *grades[]) {
    char *grade = "";

    for (int i=0; i<length; i++) {
        // 점수가 학점 최소 점수보다 크거나 같을 때
        if(score >= scores[i]) {
            // grade 변수에 grades[i] 크기만큼 메모리 동적 할당
            grade = malloc(sizeof(char)*strlen(grades[i]));

            // strcpy: 문자열을 복사해주는 함수
            // 참고:  https://dojang.io/mod/page/view.php?id=358
            strcpy(grade, grades[i]);

            // for 반복문에서 빠져나감
            break;
        }
    }

    return grade;
}