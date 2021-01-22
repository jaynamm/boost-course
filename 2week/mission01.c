#include <stdio.h>
#include <cs50.h>

int main(void) {
    int stock = 0; // 재고량
    int price = 0; // 물품 가격
    int order = 0; // 주문량
    double vat = 0; // 부가세
    double priceWithVat = 0; // 부가세 포함 물품 가격
    double priceForOrder = 0; // 매출액 (주문량 * 부가세 포함 물품 가격)
    int remainStock = 0; // 남은 재고량
    double salesTotal = 0; // 총 매출액 (각 매출액을 더한 값)

    stock = get_int("물품의 재고량을 입력해주세요 : "); // 재고량 입력하기
    price = get_int("물품의 가격을 입력해주세요 : "); // 물품의 가격 입력하기

    vat = price * 0.1; // 부가세 계산하기 (물품 가격의 10%)
    priceWithVat = price + vat; // 부가세 포함 물품의 가격 (물품 가격 * 부가세)
    remainStock = stock; // 남은 재고량 (처음에는 남은 재고량 = 재고량)
    
    // 재고가 소진될 때까지 반복
    while (true) {
        // 만약 재고가 0개라면 종료
        if (remainStock == 0) {
            printf("\n%c[1;31m재고가 모두 소진되었습니다.%c[0m\n", 27, 27);
            break;
        }

        // 주문량 입력하기
        order = get_int("\n%c[1;32m주문량을 입력해주세요 : %c[0m", 27, 27);

        // 만약 주문량이 재고량보다 많다면 남아있는 재고량 알려주기
        if (order > remainStock) {
            printf("\n%c[1;33m현재 %d 개의 재고가 남아있습니다.%c[0m\n", 27, remainStock, 27);
        } else { // 주문량보다 재고량이 많다면
            remainStock -= order; // 남은 재고량에서 주문량 빼기
            priceForOrder = order * priceWithVat; // 매출액 계산하기
            salesTotal += priceForOrder; // 총 매출액 더해주기

            printf("\n주문건수 : %d 건\n", order);
            printf("기존 재고량 : %d 개\n", stock);
            printf("남은 재고량 : %d 개\n", remainStock);
            printf("총 매출액(부가세포함) : %.f 원\n", salesTotal);
        }
    }
    
    // main 함수 정상 종료
    return 0;
}

/*
    글씨 색 넣기 - 터미널에서 ESC 코드를 사용해서 글씨에 색을 넣어줄 수 있다.
    사용방법 : printf("%c[1;{색 코드 입력}m {출력할 문자 입력} %c[0m \n", 27, 27);
    27 을 넣는 이유 : 터미널에서 ESC 를 출력해야 하는데 아스키 코드 값(27) 을 사용해서 출력해준다.
*/

