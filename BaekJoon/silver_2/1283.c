/*
한글 프로그램의 메뉴에는 총 N개의 옵션이 있다. 각 옵션들은 한 개 또는 여러 개의 단어로 옵션의 기능을 설명하여 놓았다.
그리고 우리는 위에서부터 차례대로 각 옵션에 단축키를 의미하는 대표 알파벳을 지정하기로 하였다. 단축키를 지정하는 법은 아래의 순서를 따른다.

먼저 하나의 옵션에 대해 왼쪽에서부터 오른쪽 순서로 단어의 첫 글자가 이미 단축키로 지정되었는지 살펴본다.
만약 단축키로 아직 지정이 안 되어있다면 그 알파벳을 단축키로 지정한다.
만약 모든 단어의 첫 글자가 이미 지정이 되어있다면 왼쪽에서부터 차례대로 알파벳을 보면서 단축키로 지정 안 된 것이 있다면 단축키로 지정한다.
어떠한 것도 단축키로 지정할 수 없다면 그냥 놔두며 대소문자를 구분치 않는다.
위의 규칙을 첫 번째 옵션부터 N번째 옵션까지 차례대로 적용한다.

첫째 줄에 옵션의 개수 N(1 ≤ N ≤ 30)이 주어진다. 둘째 줄부터 N+1번째 줄까지 각 줄에 옵션을 나타내는 문자열이 입력되는데
하나의 옵션은 5개 이하의 단어로 표현되며, 각 단어 역시 10개 이하의 알파벳으로 표현된다. 단어는 공백 한 칸으로 구분되어져 있다.
N개의 줄에 각 옵션을 출력하는데 단축키로 지정된 알파벳은 좌우에 [] 괄호를 씌워서 표현한다.

--------입력--------
5
New
Open
Save
Save As
Save All

--------출력--------
[N]ew
[O]pen
[S]ave
Save [A]s
Sa[v]e All
*/

#include <stdio.h>
#include <string.h>

int make_tmp(char i) {
	int tmp = 0;
	if (i >= 'A'&&i <= 'Z') tmp = i + 32;
	else if (i >= 'a'&&i <= 'z') tmp = i;
	return tmp;
}

int main() {
	char s[31][200];
	int check[200] = { 0 };
	int n, i, j;

	scanf("%d", &n);
	getchar();

	for (i = 0; i < n; i++)
		gets(s[i]);
	
	for (i = 0; i < n; i++) {
		int dan_num = -1;
		for (j = 0; j < strlen(s[i]); j++) {
			if (j == 0) {
				if (s[i][j] != ' ' && check[make_tmp(s[i][j])] == 0) {
					check[make_tmp(s[i][j])] = 1;
					dan_num = j;
					j = 100;
				}
			}
			else if (s[i][j] != ' ' && s[i][j - 1] == ' ') {
				if (check[make_tmp(s[i][j])] == 0) {
					check[make_tmp(s[i][j])]++;
					dan_num = j;
					j = 100;
				}
			}				
		}
		if (dan_num == -1) {			
			for (j = 0; j < strlen(s[i]); j++) {
				if (s[i][j] != ' ') {
					if (check[make_tmp(s[i][j])] == 0) {
						check[make_tmp(s[i][j])]++;
						dan_num = j;
						j = 100;
					}
				}
			}
		}
		for (j = 0; j < strlen(s[i]); j++) {
			if (j == dan_num) printf("[%c]", s[i][j]);
			else printf("%c", s[i][j]);
		}
		printf("\n");
	}
}