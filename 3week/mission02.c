#include <stdio.h>
#define SIZE 500000

int getMissingNumber(int n, int lengh, int arr[]);

int main(int argc, char *argv[]) {
    int n;

    scanf("%d", &n);

    // 1부터 N의 숫자 중 K가 빠진 배열
    int partArr[SIZE];
    int lenghOfPartArr = n - 1;

    for(int i=0; i<lenghOfPartArr; i++) {
        scanf("%d", &partArr[i]);
    }

    // TODO: n과 partArr을 이용하여 K를 구하기
    int missingNumber = getMissingNumber(n, lenghOfPartArr, partArr);

    printf("K = %d\n", missingNumber);

    return 0;
}

// 빠진 숫자를 찾는 함수
int getMissingNumber(int n, int lengh, int arr[]) {
    // 1부터 n까지의 합은 n(n+1)/2 로 구할 수 있다.
    // 참고 : https://en.wikipedia.org/wiki/1_%2B_2_%2B_3_%2B_4_%2B_%E2%8B%AF#Partial_sums
    int totalSum = (n*(n+1))/2;

    // 따라서 총합을 구한 후 모든 숫자를 빼주게 되면 빠져있는 숫자를 알 수 있다.
    for(int i=0; i<lengh; i++) {
        totalSum -= arr[i];
    }

    return totalSum;
}
