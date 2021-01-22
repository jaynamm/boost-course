#include <stdio.h>
#include <cs50.h>

int main(void) {
    int principal = 0; // 목표금액
    double interest = 0; // 이자
    
    // 목표금액 입력
    principal = get_int("목표금액을 입력하세요(원) : ");
    // 이자 계산
    interest = principal * 0.012;

    printf("만기 금액 : %.0f 원\n", principal + interest);

    return 0;
}

