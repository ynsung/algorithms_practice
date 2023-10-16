/*

코니는 영어 단어가 적힌 카드 뭉치 두 개를 선물로 받았습니다.

코니는 다음과 같은 규칙으로 카드에 적힌 단어들을 사용해 원하는 순서의 단어 배열을 만들 수 있는지 알고 싶습니다.
- 원하는 카드 뭉치에서 카드를 순서대로 한 장씩 사용합니다.
- 한 번 사용한 카드는 다시 사용할 수 없습니다.
- 카드를 사용하지 않고 다음 카드로 넘어갈 수 없습니다.
- 기존에 주어진 카드 뭉치의 단어 순서는 바꿀 수 없습니다.
- 예를 들어 첫 번째 카드 뭉치에 순서대로 ["i", "drink", "water"],두 번째 카드 뭉치에 순서대로
  ["want", "to"]가 적혀있을 때 ["i", "want", "to", "drink", "water"] 순서의 단어 배열을 만들려고 한다면
  첫 번째 카드 뭉치에서 "i"를 사용한 후 두 번째 카드 뭉치에서 "want"와 "to"를 사용하고 첫 번째 카드뭉치에
  "drink"와 "water"를 차례대로 사용하면 원하는 순서의 단어 배열을 만들 수 있습니다.

문자열로 이루어진 배열 cards1, cards2와 원하는 단어 배열 goal이 매개변수로 주어질 때, cards1과 cards2에 적힌
단어들로 goal를 만들 수 있다면 "Yes"를, 만들 수 없다면 "No"를 return하는 solution 함수를 완성해주세요.

--------입출력--------
cards1	                 cards2	         goal	                                  result
["i", "drink", "water"]	 ["want", "to"]  ["i", "want", "to", "drink", "water"]  "Yes"
["i", "water", "drink"]	 ["want", "to"]	 ["i", "want", "to", "drink", "water"]  "No"

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// cards1_len은 배열 cards1의 길이입니다.
// cards2_len은 배열 cards2의 길이입니다.
// goal_len은 배열 goal의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* cards1[], size_t cards1_len, const char* cards2[], size_t cards2_len, const char* goal[], size_t goal_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int c1 = 0, c2 = 0, g = 0;
    for(int i=0; i<goal_len; i++){
        if(c1 < cards1_len && !strcmp(cards1[c1], goal[i])) c1++;
        else if(c2 < cards2_len && !strcmp(cards2[c2], goal[i])) c2++;
        else return "No";
    }
    return "Yes";
}