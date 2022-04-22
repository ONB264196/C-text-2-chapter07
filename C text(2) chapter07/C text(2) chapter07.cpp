#include<conio.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdarg.h>
#define _0700


#define MAX_STAGE 10
#define swap(type, x, y)	do { type t = x; x = y; y = t; } while (0)


#ifdef _0700
double vsum(int sw, ...) {
	double sum = 0.0;
	va_list ap = nullptr;

	va_start(ap, sw);

	switch (sw) {
	case 0: sum += va_arg(ap, int);
		sum += va_arg(ap, int);
		break;
	case 1: sum += va_arg(ap, int);
		sum += va_arg(ap, long);
		break;
	case 2: sum += va_arg(ap, int);
		sum += va_arg(ap, long);
		sum += va_arg(ap, double);
		break;
	}
	va_end(ap);

	return sum;
}
//7-3
void luck_num1() {
	int i = 0, j = 0, stage = 0;
	int dgt[9] = { 1,2,3,4,5,6,7,8,9 };
	int a[8] = { 0 };
	double jikan = 0;
	clock_t start = 0, end = 0;

	srand((unsigned)time(NULL));

	printf("欠けている数字を入力してください。\n");

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++) {
		int x = rand() % 9;
		int no = 0;

		i = j = 0;
		while (i < 9) {
			if (i != x) a[j++] = dgt[i];
			i++;
		}

		for (i = 0; i < 8; i++) {
			printf("%d ", a[i]);
		}
		printf(" : ");

		do {
			scanf_s("%d", &no);
		} while (no != dgt[x]);
		putchar('\n');
	}
	end = clock();

	jikan = (double)(end - start) / CLOCKS_PER_SEC;

	printf("%.1f秒かかりました。\n", jikan);

	if (jikan > 25.0) printf("鈍すぎます。\n");
	else if (jikan > 20.0) printf("少し鈍いですね。\n");
	else if (jikan > 17.0) 	printf("まあまあですね。\n");
	else printf("素早いですね。\n");
}
//7-4
void luck_num2() {
	int i = 0, j = 0, stage = 0;
	int dgt[9] = { 1,2,3,4,5,6,7,8,9 };
	int a[8] = { 0 };
	double jikan = 0;
	clock_t start = 0, end = 0;

	srand((unsigned)time(NULL));

	printf("欠けている数字を入力してください。\n");

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++) {
		int x = rand() % 9;
		int no = 0;

		i = j = 0;
		while (i < 9) {
			if (i != x) a[j++] = dgt[i];
			i++;
		}

		for (i = 7; i > 0; i--) {
			int j = rand() % (i + 1);
			if (i != j) swap(int, a[i], a[j]);
		}

		for (i = 0; i < 8; i++) {
			printf("%d ", a[i]);
		}
		printf(" : ");

		do {
			scanf_s("%d", &no);
		} while (no != dgt[x]);
		putchar('\n');
	}
	end = clock();

	jikan = (double)(end - start) / CLOCKS_PER_SEC;

	printf("%.1f秒かかりました。\n", jikan);

	if (jikan > 25.0) printf("鈍すぎます。\n");
	else if (jikan > 20.0) printf("少し鈍いですね。\n");
	else if (jikan > 17.0) 	printf("まあまあですね。\n");
	else printf("素早いですね。\n");
}
//7-5
void double_num1() {
	int i = 0, j = 0, stage = 0;
	int dgt[9] = { 1,2,3,4,5,6,7,8,9 };
	int a[10] = { 0 };
	double jikan = 0;
	clock_t start = 0, end = 0;

	srand((unsigned)time(NULL));

	printf("ダブっている数字を入力してください。\n");

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++) {
		int x = rand() % 9;
		int no = 0;

		i = j = 0;
		while (i < 9) {
			a[j++] = dgt[i];
			if (i == x) a[j++] = dgt[i];
			i++;
		}

		for (i = 9; i > 0; i--) {
			int j = rand() % (i + 1);
			if (i != j) swap(int, a[i], a[j]);
		}

		for (i = 0; i < 10; i++) {
			printf("%d ", a[i]);
		}
		printf(" : ");

		do {
			scanf_s("%d", &no);
		} while (no != dgt[x]);
		putchar('\n');
	}
	end = clock();

	jikan = (double)(end - start) / CLOCKS_PER_SEC;

	printf("%.1f秒かかりました。\n", jikan);

	if (jikan > 25.0) printf("鈍すぎます。\n");
	else if (jikan > 20.0) printf("少し鈍いですね。\n");
	else if (jikan > 17.0) 	printf("まあまあですね。\n");
	else printf("素早いですね。\n");
}
//7-9
void sum() {
	printf("12 + 25        = %.2f\n", vsum(1, 12, 25));
	printf("854 + 1635973L = %.2f\n", vsum(2, 854, 1635973L));
	printf("56 + 8L + 9.72 = %.2f\n", vsum(2, 56, 8L, 9.72));
}
//7-11
void double_num2() {
	int i = 0, j = 0, stage = 0;
	int dgt[9] = { 1,2,3,4,5,6,7,8,9 };
	int a[10] = { 0 };
	double jikan = 0;
	clock_t start = 0, end = 0;

	srand((unsigned)time(NULL));

	puts("ダブっている数字を入力してください。");
	puts("スペースキーで開始します。");
	fflush(stdout);
	while (_getch() != ' ');

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++) {
		int x = rand() % 9;
		int no = 0;

		i = j = 0;
		while (i < 9) {
			a[j++] = dgt[i];
			if (i == x) a[j++] = dgt[i];
			i++;
		}

		for (i = 9; i > 0; i--) {
			int j = rand() % (i + 1);
			if (i != j) swap(int, a[i], a[j]);
		}

		for (i = 0; i < 10; i++) {
			printf("%d ", a[i]);
		}
		printf(" : ");
		fflush(stdout);

		do {
			no = _getch();
			if (isprint(no)) {
				_putch(no);
				if (no != dgt[x] + '0') _putch('\b');
				else putchar('\n');
				fflush(stdout);
			}
		} while (no != dgt[x] + '0');
		putchar('\n');
	}
	end = clock();

	jikan = (double)(end - start) / CLOCKS_PER_SEC;

	printf("%.1f秒かかりました。\n", jikan);

	if (jikan > 25.0) printf("鈍すぎます。\n");
	else if (jikan > 20.0) printf("少し鈍いですね。\n");
	else if (jikan > 17.0) 	printf("まあまあですね。\n");
	else printf("素早いですね。\n");
}
//7-12
void trigraph() {
	const char* qstr[] = { "0123456789",
							"ABCDEFGHIJKLMNOPQRSTUVWXYZ",
							"abcdefghijklmnopqrstuvwxyz" };
	int chmax[] = { 10,26,26 };
	int i = 0, stage = 0;
	int key = 0;
	double jikan = 0;
	clock_t start = 0, end = 0;

	srand((unsigned)time(NULL));

	puts("□連続する3つの数字あるいは英字から");
	puts("□隠されている文字を入力してください。");
	puts("□例えば A ? C : と表示されたらBを");
	puts("□　　　 4 5 ? : と表示されたら6を");
	puts("□入力します。");
	puts("★スペースキーで開始します");
	while (_getch() != ' ');

	start = clock();

	for (stage = 0; stage < MAX_STAGE; stage++) {
		int qtype = rand() % 3;
		int nhead = rand() % (chmax[qtype] - 2);
		int x = rand() % 3;

		putchar('\r');
		for (i = 0; i < 3; i++) {
			if (i != x) printf(" %c", qstr[qtype][nhead + i]);
			else printf(" ?");
		}
		printf(" : ");
		fflush(stdout);

		do {
			key = _getch();
			if (isprint(key)) {
				_putch(key);
				if (key != qstr[qtype][nhead + x]) _putch('\b');
			}
		} while (key != qstr[qtype][nhead + x]);
		putchar('\n');
	}
	end = clock();

	jikan = (double)(end - start) / CLOCKS_PER_SEC;

	printf("%.1f秒かかりました。\n", jikan);

	if (jikan > 25.0) printf("鈍すぎます。\n");
	else if (jikan > 20.0) printf("少し鈍いですね。\n");
	else if (jikan > 17.0) 	printf("まあまあですね。\n");
	else printf("素早いですね。\n");

}

int main(void) {
	trigraph();

	return 0;
}
#endif


#ifdef _0701
int main(void) {
	int i = 0, j = 0, stage = 0;
	int dgt[9] = { 1,2,3,4,5,6,7,8,9 };
	int a[8] = { 0 };
	double jikan = 0;
	clock_t start = 0, end = 0;

	srand((unsigned)time(NULL));

	printf("欠けている数字を入力してください。\n");

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++) {
		int x = rand() % 9;
		int no = 0;

		i = j = 0;
		while (i < 9) {
			if (i != x) a[j++] = dgt[i];
			i++;
		}

		for (i = 7; i > 0; i--) {
			int j = rand() % (i + 1);
			if (i != j) swap(int, a[i], a[j]);
		}

		for (i = 0; i < 8; i++) {
			printf("%d ", a[i]);
		}
		printf(" : ");
		fflush(stdout);

		do {
			no = _getch();
			if (isprint(no)) {
				_putch(no);
				if (no != dgt[x] + '0') putchar('\b');
				else putchar('\n');
				fflush(stdout);
			}
		} while (no != dgt[x] + '0');
		putchar('\n');
	}
	end = clock();

	jikan = (double)(end - start) / CLOCKS_PER_SEC;

	printf("%.1f秒かかりました。\n", jikan);

	if (jikan > 25.0) printf("鈍すぎます。\n");
	else if (jikan > 20.0) printf("少し鈍いですね。\n");
	else if (jikan > 17.0) 	printf("まあまあですね。\n");
	else printf("素早いですね。\n");

	return 0;
}
#endif

#ifdef _0702
int main(void) {
	int i = 0, j = 0, stage = 0;
	int dgt[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int a[9] = { 0 };
	double jikan = 0;
	clock_t start = 0, end = 0;

	srand((unsigned)time(NULL));

	printf("欠けている数字を入力してください。\n");

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++) {
		int x = rand() % 10;
		int no = 0;

		i = j = 0;
		while (i < 10) {
			if (i != x) a[j++] = dgt[i];
			i++;
		}

		for (i = 8; i > 0; i--) {
			int j = rand() % (i + 1);
			if (i != j) swap(int, a[i], a[j]);
		}

		for (i = 0; i < 9; i++) {
			printf("%d ", a[i]);
		}
		printf(" : ");
		fflush(stdout);

		do {
			no = _getch();
			if (isprint(no)) {
				_putch(no);
				if (no != dgt[x] + '0') putchar('\b');
				else putchar('\n');
				fflush(stdout);
			}
		} while (no != dgt[x] + '0');
		putchar('\n');
	}
	end = clock();

	jikan = (double)(end - start) / CLOCKS_PER_SEC;

	printf("%.1f秒かかりました。\n", jikan);

	if (jikan > 25.0) printf("鈍すぎます。\n");
	else if (jikan > 20.0) printf("少し鈍いですね。\n");
	else if (jikan > 17.0) 	printf("まあまあですね。\n");
	else printf("素早いですね。\n");

	return 0;
}
#endif

#ifdef _0703
int main(void) {
	int i = 0, j = 0, stage = 0;
	int dgt[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int a[11] = { 0 };
	double jikan = 0;
	clock_t start = 0, end = 0;

	srand((unsigned)time(NULL));

	puts("ダブっている数字を入力してください。");
	puts("スペースキーで開始します。");
	fflush(stdout);
	while (_getch() != ' ');

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++) {
		int x = rand() % 10;
		int no = 0;

		i = j = 0;
		while (i < 10) {
			a[j++] = dgt[i];
			if (i == x) a[j++] = dgt[i];
			i++;
		}

		for (i = 10; i > 0; i--) {
			int j = rand() % (i);
			if (i != j) swap(int, a[i], a[j]);
		}

		for (i = 0; i < 11; i++) {
			printf("%d ", a[i]);
		}
		printf(" : ");
		fflush(stdout);

		do {
			no = _getch();
			if (isprint(no)) {
				_putch(no);
				if (no != dgt[x] + '0') _putch('\b');
				else putchar('\n');
				fflush(stdout);
			}
		} while (no != dgt[x] + '0');
		putchar('\n');
	}
	end = clock();

	jikan = (double)(end - start) / CLOCKS_PER_SEC;

	printf("%.1f秒かかりました。\n", jikan);

	if (jikan > 25.0) printf("鈍すぎます。\n");
	else if (jikan > 20.0) printf("少し鈍いですね。\n");
	else if (jikan > 17.0) 	printf("まあまあですね。\n");
	else printf("素早いですね。\n");


	return 0;
}
#endif

#ifdef _0704
/*------ 考察 ------
 "if(i != j)"が抜けているため、二つ以上重複する
 数が生成されてしまい欠けた数字も同様に複数発生
 し、問題として成立しない。
							------------------*/
int main(void) {
	int i = 0, j = 0, stage = 0;
	int dgt[9] = { 1,2,3,4,5,6,7,8,9 };
	int a[8] = { 0 };
	double jikan = 0;
	clock_t start = 0, end = 0;

	srand((unsigned)time(NULL));

	printf("欠けている数字を入力してください。\n");

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++) {
		int x = rand() % 9;
		int no = 0;

		i = j = 0;
		while (i < 9) {
			if (i != x) a[j++] = dgt[i];
			i++;
		}

		for (i = 7; i > 0; i--) {
			swap(int, a[i], a[rand() % (i + 1)]);
		}

		for (i = 0; i < 8; i++) {
			printf("%d ", a[i]);
		}
		printf(" : ");

		do {
			scanf_s("%d", &no);
		} while (no != dgt[x]);
		putchar('\n');
	}
	end = clock();

	jikan = (double)(end - start) / CLOCKS_PER_SEC;

	printf("%.1f秒かかりました。\n", jikan);

	if (jikan > 25.0) printf("鈍すぎます。\n");
	else if (jikan > 20.0) printf("少し鈍いですね。\n");
	else if (jikan > 17.0) 	printf("まあまあですね。\n");
	else printf("素早いですね。\n");

	return 0;
}
#endif

#ifdef _0705
void disp(int a[]) {
	char disp[3][12] = {};
	int position[8] = { 0 };
	int i = 0, j = 0, val = 0;
	
	//0～35で表示場所を決定
	for (i = 0; i < 8; i++) {
		do {
			val = rand() % 36;
			for (j = 0; j < i; j++) {
				if (val == position[j]) {
					break;
				}
			}
		} while (j < i);
		position[i] = val;
	}
	//dispに代入
	for (i = 0; i < 8; i++) {
		if (position[i] < 11) disp[0][position[i]] = a[i] + '0';
		else if (position[i] > 23) disp[2][position[i] - 24] = a[i] + '0';
		else disp[1][position[i] - 12] = a[i] + '0';
	}

	//表示
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 12; j++) {
			if (disp[i][j] > '0' && disp[i][j] <= '9') {
				printf("%c ",disp[i][j]);

			}
			else putchar(' ');
		}
		putchar('\n');
	}
	printf("回答 : ");
	fflush(stdout);
}
int main(void) {
	int i = 0, j = 0, stage = 0;
	int dgt[9] = { 1,2,3,4,5,6,7,8,9 };
	int a[8] = { 0 };
	double jikan = 0;
	clock_t start = 0, end = 0;

	srand((unsigned)time(NULL));

	printf("欠けている数字を入力してください。\n");

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++) {
		int x = rand() % 9;
		int no = 0;

		i = j = 0;
		while (i < 9) {
			if (i != x) a[j++] = dgt[i];
			i++;
		}

		for (i = 7; i > 0; i--) {
			int j = rand() % (i + 1);
			if (i != j) swap(int, a[i], a[j]);
		}

		disp(a);

		do {
			no = _getch();
			if (isprint(no)) {
				_putch(no);
				if (no != dgt[x] + '0') putchar('\b');
				else putchar('\n');
				fflush(stdout);
			}
		} while (no != dgt[x] + '0');
		putchar('\n');
	}
	end = clock();

	jikan = (double)(end - start) / CLOCKS_PER_SEC;

	printf("%.1f秒かかりました。\n", jikan);

	if (jikan > 25.0) printf("鈍すぎます。\n");
	else if (jikan > 20.0) printf("少し鈍いですね。\n");
	else if (jikan > 17.0) 	printf("まあまあですね。\n");
	else printf("素早いですね。\n");

	return 0;
}

#endif

#ifdef _0706
void disp(int a[]) {
	char disp[3][16] = {};
	int position[10] = { 0 };
	int i = 0, j = 0, val = 0;

	//0～35で表示場所を決定
	for (i = 0; i < 10; i++) {
		do {
			val = rand() % 48;
			for (j = 0; j < i; j++) {
				if (val == position[j]) {
					break;
				}
			}
		} while (j < i);
		position[i] = val;
	}
	//dispに代入
	for (i = 0; i < 10; i++) {
		if (position[i] < 15) disp[0][position[i]] = a[i] + '0';
		else if (position[i] > 31) disp[2][position[i] - 32] = a[i] + '0';
		else disp[1][position[i] - 16] = a[i] + '0';
	}

	//表示
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 16; j++) {
			if (disp[i][j] > '0' && disp[i][j] <= '9') {
				printf("%c ", disp[i][j]);

			}
			else putchar(' ');
		}
		putchar('\n');
	}
	printf("回答 : ");
	fflush(stdout);
}
int main(void) {
	int i = 0, j = 0, stage = 0;
	int dgt[9] = { 1,2,3,4,5,6,7,8,9 };
	int a[10] = { 0 };
	double jikan = 0;
	clock_t start = 0, end = 0;

	srand((unsigned)time(NULL));

	puts("ダブっている数字を入力してください。");
	puts("スペースキーで開始します。");
	fflush(stdout);
	while (_getch() != ' ');

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++) {
		int x = rand() % 9;
		int no = 0;

		i = j = 0;
		while (i < 9) {
			a[j++] = dgt[i];
			if (i == x) a[j++] = dgt[i];
			i++;
		}

		for (i = 9; i > 0; i--) {
			int j = rand() % (i + 1);
			if (i != j) swap(int, a[i], a[j]);
		}

		disp(a);

		do {
			no = _getch();
			if (isprint(no)) {
				_putch(no);
				if (no != dgt[x] + '0') _putch('\b');
				else putchar('\n');
				fflush(stdout);
			}
		} while (no != dgt[x] + '0');
		putchar('\n');
	}
	end = clock();

	jikan = (double)(end - start) / CLOCKS_PER_SEC;

	printf("%.1f秒かかりました。\n", jikan);

	if (jikan > 25.0) printf("鈍すぎます。\n");
	else if (jikan > 20.0) printf("少し鈍いですね。\n");
	else if (jikan > 17.0) 	printf("まあまあですね。\n");
	else printf("素早いですね。\n");

	return 0;
}
#endif

#ifdef _0707a
int sleep(unsigned long x) {
	clock_t c1 = clock(), c2 = 0;
	do {
		if ((c2 = clock()) == (clock_t)-1) return 0;
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}
int main(void) {
	int i = 0, j = 0, stage = 0;
	int dgt[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int a[9] = { 0 };
	double jikan = 0;
	clock_t start = 0, end = 0;

	srand((unsigned)time(NULL));

	printf("欠けている数字を入力してください。\n");
	puts("スペースキーで開始します。");
	fflush(stdout);
	while (_getch() != ' ');

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++) {
		int x = rand() % 10;
		int no = 0;

		i = j = 0;
		while (i < 10) {
			if (i != x) a[j++] = dgt[i];
			i++;
		}

		for (i = 8; i > 0; i--) {
			int j = rand() % (i + 1);
			if (i != j) swap(int, a[i], a[j]);
		}

		for (i = 0; i < 9; i++) {
			printf("\r%d ", a[i]);
			sleep(250);
		}
		printf("\r ");
		start = clock();

		printf("\r回答 : ");
		fflush(stdout);

		do {
			if (_getch() == ' ') {
				printf("\r%*s", 9, "");
				for (i = 0; i < 9; i++) {
					printf("\r%d ", a[i]);
					sleep(250);
				}
				printf("\r ");
				printf("\r回答 : ");
				fflush(stdout);
			}
			else {
				no = _getch();
				if (isprint(no)) {
					_putch(no);
					if (no != dgt[x] + '0') _putch('\b');
					else putchar('\n');
					fflush(stdout);
				}
			}
		} while (no != dgt[x] + '0');
		putchar('\n');
		end = clock();
		jikan += (double)(end - start) / CLOCKS_PER_SEC;
	}


	printf("%.1f秒かかりました。\n", jikan);

	if (jikan > 12.5) printf("鈍すぎます。\n");
	else if (jikan > 10.0) printf("少し鈍いですね。\n");
	else if (jikan > 8.5) 	printf("まあまあですね。\n");
	else printf("素早いですね。\n");

	return 0;
}
#endif

#ifdef _0707b
int sleep(unsigned long x) {
	clock_t c1 = clock(), c2 = 0;
	do {
		if ((c2 = clock()) == (clock_t)-1) return 0;
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}

int main(void) {
	int i = 0, j = 0, stage = 0;
	int dgt[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int a[11] = { 0 };
	double jikan = 0;
	clock_t start = 0, end = 0;

	srand((unsigned)time(NULL));

	puts("ダブっている数字を入力してください。");
	puts("スペースキーで開始します。");
	fflush(stdout);
	while (_getch() != ' ');

	for (stage = 0; stage < MAX_STAGE; stage++) {
		int x = rand() % 10;
		int no = 0;

		i = j = 0;
		while (i < 10) {
			a[j++] = dgt[i];
			if (i == x) a[j++] = dgt[i];
			i++;
		}

		for (i = 10; i > 0; i--) {
			int j = rand() % (i);
			if (i != j) swap(int, a[i], a[j]);
		}

		for (i = 0; i < 11; i++) {
			printf("\r%d ", a[i]);
			sleep(250);
		}
		printf("\r ");
		start = clock();
		
		printf("\r回答 : ");
		fflush(stdout);

		do {
			if (_getch() == ' ') {
				printf("\r%*s", 9, "");
				for (i = 0; i < 11; i++) {
					printf("\r%d ", a[i]);
					sleep(250);
				}
				printf("\r ");
				printf("\r回答 : ");
				fflush(stdout);
			}
			else {
				no = _getch();
				if (isprint(no)) {
					_putch(no);
					if (no != dgt[x] + '0') _putch('\b');
					else putchar('\n');
					fflush(stdout);
				}
			}
		} while (no != dgt[x] + '0');
		putchar('\n');
		end = clock();
		jikan += (double)(end - start) / CLOCKS_PER_SEC;
	}


	printf("%.1f秒かかりました。\n", jikan);

	if (jikan > 12.5) printf("鈍すぎます。\n");
	else if (jikan > 10.0) printf("少し鈍いですね。\n");
	else if (jikan > 8.5) 	printf("まあまあですね。\n");
	else printf("素早いですね。\n");


	return 0;
}
#endif

#ifdef _0708
int main(void) {
	const char* qstr[] = { "9876543210",
						"ZYXWVUTSRQPONMLKJIHGFEDCBA",
						"zyxwvutsrqponmlkjihgfedcba" };
	int chmax[] = { 10,26,26 };
	int i = 0, stage = 0;
	int key = 0;
	double jikan = 0;
	clock_t start = 0, end = 0;

	srand((unsigned)time(NULL));

	puts("□連続する3つの数字あるいは英字から");
	puts("□隠されている文字を入力してください。");
	puts("□例えば C ? A : と表示されたらBを");
	puts("□　　　 ? 5 4 : と表示されたら6を");
	puts("□入力します。");
	puts("★スペースキーで開始します");
	while (_getch() != ' ');

	start = clock();

	for (stage = 0; stage < MAX_STAGE; stage++) {
		int qtype = rand() % 3;
		int nhead = rand() % (chmax[qtype] - 2);
		int x = rand() % 3;

		putchar('\r');
		for (i = 0; i < 3; i++) {
			if (i != x) printf(" %c", qstr[qtype][nhead + i]);
			else printf(" ?");
		}
		printf(" : ");
		fflush(stdout);

		do {
			key = _getch();
			if (isprint(key)) {
				_putch(key);
				if (key != qstr[qtype][nhead + x]) _putch('\b');
			}
		} while (key != qstr[qtype][nhead + x]);
		putchar('\n');
	}
	end = clock();

	jikan = (double)(end - start) / CLOCKS_PER_SEC;

	printf("%.1f秒かかりました。\n", jikan);

	if (jikan > 25.0) printf("鈍すぎます。\n");
	else if (jikan > 20.0) printf("少し鈍いですね。\n");
	else if (jikan > 17.0) 	printf("まあまあですね。\n");
	else printf("素早いですね。\n");


	return 0;
}
#endif