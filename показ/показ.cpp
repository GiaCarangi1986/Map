#include "pch.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <cstdio>

const char DLINA = 30, TOTAL = 100; //длина вводимого субъекта, скок всего субъектов
int subcvet[TOTAL][TOTAL]; //массив, который для каждого субъекта хранит возможность цвета
int cvetNaKarte[TOTAL]; //цвет для субъекта
int kolvocvetov = 2; //кол-во использованных цветов
FILE *fsub; //файл с введенными субъектами
FILE *fmatrica; //файл с матрицей смежности
char vvodsubmas[DLINA]; //массив, в который пользователь будет вводить субъекты (из функции vvodsub)
int A[TOTAL][TOTAL]; //матрица смежности
int kolvo; //кол-во введенных субъектов
int bul = 1; //логическая переменная, которая нужна, чтобы пользователь корректно вводил данные

int vvodsub() {
	char sym;
	fsub = fopen("sub.txt", "r+");
	if (fsub) {
		printf("Выберите действие\n");
		printf("1 - создать новую карту\n");
		printf("2 - добавить субъекты в существующую карту\n");
		printf("3 - выйти из операции ввода субъектов\n");
		sym = getchar();
		system("cls");
		switch (sym)
		{
		case '1': fsub = fopen("sub.txt", "w");
			bul = 0;
			break;
		case '2': {
			fsub = fopen("sub.txt", "a");
			fseek(fsub, 0, 2);
			bul = 0;
		}
				  break;
		case '3':
			return  0;
		}
	}
	else fsub = fopen("sub.txt", "w");
	printf("Введите название субъекта (если вы закончили ввод, нажмите '-' и клавишу 'ENTER')\n");
	do {
		scanf("%s", &vvodsubmas);
		if (vvodsubmas[0] != '-') {
			fputs(vvodsubmas, fsub); //пишет данные в файл
			fputs("\n", fsub);
		}
	} while (vvodsubmas[0] != '-');
	fclose(fsub);
	getchar();
	return  0;
}

/*int sos(int *kolvo, int i, char spisokSub[TOTAL][DLINA]) {
	char k[DLINA];
	for (int i = 0; i < DLINA; i++)
		k[i] = 0;
	printf("Выберите через запятую (например, 1,2,10) цифры, под которыми указаны те субъекты, которые граничат с субъектом\n");
	printf("Если субъект ни с кем не граничит, введите цифру, под которой он сам указан\n");
	printf("Для выхода нажмите '0'\n");
	for (int isub = 0; isub < i; isub++) {
		//if (spisokSub[isub][0] != '\0')
		printf("%d)", isub + 1);
		printf("%s", spisokSub[isub]);
		printf("\n");
	}
	printf("\n");
	char y = 0;
	printf("%s: ", spisokSub[(*kolvo)]);
	while (y != '\n') {
		scanf("%s", &k);
		y = getchar();
	}
	int poysnenie[TOTAL];
	for (int n = 0; n < TOTAL; n++)
		poysnenie[n] = -1;
	int posMas = 0;
	for (int p = 0; k[p] != '\0'; p++)
		if (k[p] != ','&&k[p] != ' '&&k[p] != '.'&&k[p] != '/'&&k[p] != 'б'&&k[p] != 'ю') {
			if (k[p] == '0')
				return 0;

			poysnenie[posMas] = k[p] - 49;
			posMas++;
			A[*kolvo][k[p] - 49] = 1;
		}
	printf("%s: ", spisokSub[(*kolvo)]);
	for (int n = 0; poysnenie[n] != -1; n++) {
		printf("%s", spisokSub[poysnenie[n]]);
		if (poysnenie[n + 1] != -1)
			printf(",");
	}
	printf("\n");
	printf("\n");
}*/

int sos(int *kolvo, int i, char spisokSub[TOTAL][DLINA]) {
	char k[DLINA];
	for (int i = 0; i < DLINA; i++)
		k[i] = 0;
	printf("Выберите через запятую (например, 1,2,10) цифры, под которыми указаны те субъекты, которые граничат с субъектом\n");
	printf("Если субъект ни с кем не граничит, введите цифру, под которой он сам указан\n");
	printf("Для выхода нажмите '0'\n");
	for (int isub = 0; isub < i; isub++) {
		//if (spisokSub[isub][0] != '\0')
		printf("%d)", isub + 1);
		printf("%s", spisokSub[isub]);
		printf("\n");
	}
	printf("\n");
	char y = 0;
	printf("%s: ", spisokSub[(*kolvo)]);
	while (y != '\n') {
		scanf("%s", &k);
		y = getchar();
	}
	int poysnenie[TOTAL];
	for (int n = 0; n < TOTAL; n++)
		poysnenie[n] = -1;
	int posMas = 0;
	for (int p = 0; k[p] != '\0'; p++)
		if (k[p] != ','&&k[p] != ' '&&k[p] != '.'&&k[p] != '/'&&k[p] != 'б'&&k[p] != 'ю') {
			if (k[0] == '0')
				return 0;
			if (k[p + 1] > 48 || k[p + 1] == '0') {
				int p1 = k[p] - 48;
				int p2 = k[p + 1] - 48;
				int t = p1 * 10 + p2;
				poysnenie[posMas] = t - 1;
				posMas++;
				A[*kolvo][t - 1] = 1;
				p++;
			}
			else {
				poysnenie[posMas] = k[p] - 49;
				posMas++;
				A[*kolvo][k[p] - 49] = 1;
			}
		}
	printf("%s: ", spisokSub[(*kolvo)]);
	for (int n = 0; poysnenie[n] != -1; n++) {
		printf("%s", spisokSub[poysnenie[n]]);
		if (poysnenie[n + 1] != -1)
			printf(",");
	}
	printf("\n");
	printf("\n");
}

int vvod(int *kolvo, int i, char spisokSub[TOTAL][DLINA], int Ai) {
	char k[DLINA];
	for (int i = 0; i < DLINA; i++)
		k[i] = 0;
	for ((*kolvo) = Ai; (*kolvo) < i; (*kolvo)++) {
		if (!sos(kolvo, i, spisokSub))
			return 0;
		int kor = 0;
		while (!kor) {
			printf("Проверьте введенные данные. Если все верно, нажмите '1', если нет, нажмите '0'\n");
			scanf("%d", &kor);
			if (!kor) {
				system("cls");
				if (!sos(kolvo, i, spisokSub))
					return 0;
			}
			printf("\n");
		}
		system("cls");
	}
}

void vivod(int kolvo, int kolvo1) {
	for (int i = 0; i < kolvo; i++) {
		for (int j = 0; j < kolvo1; j++) {
			printf("%d", A[i][j]);
			fprintf(fmatrica, "%d", A[i][j]);
		}
		printf("\n");
		fputs("\n", fmatrica);
	}
}

void ready(char spisokSub[TOTAL][DLINA], int *i) {
	for (int i = 0; i < TOTAL; i++)
		for (int j = 0; j < DLINA; j++)
			spisokSub[i][j] = 0;
	while (!feof(fsub)) {
		fgets(spisokSub[(*i)], DLINA, fsub);
		int j = 0;
		for (; spisokSub[(*i)][j] != '\n'; j++);
		spisokSub[(*i)][j] = '\0';
		(*i)++;
	}
}

int vvodsosedey() {
	fsub = fopen("sub.txt", "r");
	if (!fsub) {
		printf("Сначала введите субъекты\n");
		system("pause");
	}
	if (fsub) {
		printf("ВНИМАНИЕ!!! Перед началом ввода убедитесь, что вы перечислили все желаемые субъекты\n");
		printf("Выберете действие\n");
		printf("1 - задать новых соседей\n");
		printf("2 - продолжить ввод соседей\n");
		printf("3 - выйти из операции\n");
		int sum;
		scanf("%d", &sum);
		printf("\n");
		system("cls");
		switch (sum)
		{
		case 1:
		{
			bul = 1;
			fmatrica = fopen("matrica.txt", "w");
			/*int i = 0;
			char spisokSub[TOTAL][DLINA];
			ready(spisokSub, &i);*/

			int i = 0, j;
			char spisokSub[TOTAL][DLINA];
			for (int i = 0; i < TOTAL; i++)
				for (int j = 0; j < DLINA; j++)
					spisokSub[i][j] = 0;
			while (!feof(fsub)) {
				fgets(spisokSub[i], DLINA, fsub);
				for (j = 0; spisokSub[i][j] != '\n'; j++);
				spisokSub[i][j] = '\0';
				i++;
			}
			i--;

			fclose(fsub);
			//i--;
			int kolvo1 = i;
			vvod(&kolvo, i, spisokSub, 0);
			vivod(kolvo, kolvo1);
			system("pause");
			fclose(fmatrica);
		}
		break;
		case 2: {
			fmatrica = fopen("matrica.txt", "r");

			int i = 0, j;
			char spisokSub[TOTAL][DLINA];
			for (int i = 0; i < TOTAL; i++)
				for (int j = 0; j < DLINA; j++)
					spisokSub[i][j] = 0;
			while (!feof(fsub)) {
				fgets(spisokSub[i], DLINA, fsub);
				for (j = 0; spisokSub[i][j] != '\n'; j++);
				spisokSub[i][j] = '\0';
				i++;
			}

			/*int i = 0;
			char spisokSub[TOTAL][DLINA];
			ready(spisokSub, &i);*/
			fclose(fsub);
			int kol = --i;
			int kolKonez = kol - 1;
			int l = kolKonez;
			i = 0;
			int c;
			while (!feof(fmatrica)) {
				kolKonez = l;
				fscanf(fmatrica, "%d", &c);
				if (c >= 0)
					for (int k = 0; k <= kol; k++) {
						A[i][kolKonez] = c % 10;
						c = c / 10;
						kolKonez--;
					}
				i++;
			}

			/*char c;
			while (!feof(fmatrica)) {
				for (int j = 0; j < kol; j++) {
					fscanf(fmatrica, "%c", &c);
					if (c != '\n') {
						c = c - 48;
						A[i][j] = c;
					}
					else break;
				}
				if (c == '\n')
					i--;
				i++;
			}*/

			int Ai = --i;
			//int Ai = i;
			vvod(&kolvo, kol, spisokSub, Ai);
			feof(fmatrica);
			fmatrica = fopen("matrica.txt", "w");
			vivod(kolvo, kol);
			system("pause");
			fclose(fmatrica);
		}
				break;
		case 3:
			fclose(fsub); return  0;
		}
	}
	return 0;
}

void kolvoColors(int color, int *kolvocvetov) {
	if (color + 1 > (*kolvocvetov))
		(*kolvocvetov) = color + 1;
}

void prov(int j, int i, int kol) {
	subcvet[j][cvetNaKarte[i] - 1] = 0;
	for (int color = 0; color < kol; color++)
		if (subcvet[j][color] != 0 && subcvet[j][color] != cvetNaKarte[i]) {
			cvetNaKarte[j] = subcvet[j][color];
			subcvet[j][color] = 0;
			kolvoColors(color, &kolvocvetov);
			break;
		}
}

void obrabotkaMatrisi() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	fmatrica = fopen("matrica.txt", "r");
	if (fmatrica&&bul) {
		fsub = fopen("sub.txt", "r");

		int i = 0, j;
		char spisokSub[TOTAL][DLINA];
		for (int i = 0; i < TOTAL; i++)
			for (int j = 0; j < DLINA; j++)
				spisokSub[i][j] = 0;
		while (!feof(fsub)) {
			fgets(spisokSub[i], DLINA, fsub);
			for (j = 0; spisokSub[i][j] != '\n'; j++);
			spisokSub[i][j] = '\0';
			i++;
		}

		/*int i = 0, j;
		char spisokSub[TOTAL][DLINA];
		ready(spisokSub, &i);*/
		fclose(fsub);
		int kol = --i;
		int kolKonez = kol - 1;
		int l = kolKonez;
		i = 0, j = 0;
		int c;
		while (!feof(fmatrica)) {
			kolKonez = l;
			fscanf(fmatrica, "%d", &c);
			for (int k = 0; k <= kol; k++) {
				A[i][kolKonez] = c % 10;
				c = c / 10;
				kolKonez--;
			}
			i++;
		}
		fclose(fmatrica);
		for (int i = 0; i < kol; i++)
			for (int j = 1; j <= kol; j++)
				subcvet[i][j - 1] = j;
		for (i = 0; i < kol - 1; i++)
			for (j = i + 1; j < kol; j++)
				if (A[i][j] == 1) {
					if (cvetNaKarte[i] == 0 && cvetNaKarte[j] == 0) {
						cvetNaKarte[i] = subcvet[i][0];
						subcvet[i][0] = 0;
						cvetNaKarte[j] = subcvet[j][1];
						subcvet[j][0] = 0;
						subcvet[j][1] = 0;
					}
					else if (cvetNaKarte[i] == cvetNaKarte[j]) {
						for (int color = 0; color < kol; color++)
							if (subcvet[j][color] != 0) {
								cvetNaKarte[j] = subcvet[j][color];
								subcvet[j][color] = 0;
								kolvoColors(color, &kolvocvetov);
								break;
							}
					}
					else if (cvetNaKarte[j] == 0) {
						prov(j, i, kol);
						/*subcvet[j][cvetNaKarte[i] - 1] = 0;
						for (int color = 0; color < kol; color++)
							if (subcvet[j][color] != 0 && subcvet[j][color] != cvetNaKarte[i]) {
								cvetNaKarte[j] = subcvet[j][color];
								subcvet[j][color] = 0;
								kolvoColors(color, &kolvocvetov);
								break;
							}*/
					}
					else if (cvetNaKarte[i] == 0) {
						prov(i, j, kol);
						/*subcvet[i][cvetNaKarte[j] - 1] = 0;
						for (int color = 0; color < kol; color++)
							if (subcvet[i][color] != 0 && subcvet[i][color] != cvetNaKarte[j]) {
								cvetNaKarte[i] = subcvet[i][color];
								subcvet[i][color] = 0;
								kolvoColors(color, &kolvocvetov);
								break;
							}*/
					}
					else subcvet[j][cvetNaKarte[i] - 1] = 0;
				}
		for (i = 0; i < kol; i++) {
			//if (cvetNaKarte[i] == 0)
				//cvetNaKarte[i] = subcvet[i][0];
			printf("%-20s ", spisokSub[i]);
			switch (cvetNaKarte[i])
			{
			case 1: SetConsoleTextAttribute(hConsole, (WORD)((2 << 4) | 14)); printf("%d", cvetNaKarte[i]); printf("-ЖЕЛТЫЙ");	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | BACKGROUND_GREEN);
				break;
			case 2: SetConsoleTextAttribute(hConsole, (WORD)((2 << 4) | 4)); printf("%d", cvetNaKarte[i]); printf("-КРАСНЫЙ");	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | BACKGROUND_GREEN);
				break;
			case 3: SetConsoleTextAttribute(hConsole, (WORD)((2 << 4) | 7)); printf("%d", cvetNaKarte[i]); printf("-СЕРЫЙ");	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | BACKGROUND_GREEN);
				break;
			case 4:  SetConsoleTextAttribute(hConsole, (WORD)((2 << 4) | 9)); printf("%d", cvetNaKarte[i]); printf("-ГОЛУБОЙ");	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | BACKGROUND_GREEN);
				break;
			}
			printf("\n");
		}
		printf("Было задействовано %d цвета(ов)\n", kolvocvetov);
	}
	else printf("Сначала введите соседей субъектов\n");
	system("pause");
}

int main()
{
	for (int i = 0; i < TOTAL; i++)
		for (int j = 0; j < TOTAL; j++)
			subcvet[i][j] = 0;
	for (int i = 0; i < TOTAL; i++)
		cvetNaKarte[i] = 0;
	for (int i = 0; i < TOTAL; i++)
		for (int j = 0; j < TOTAL; j++)
			A[i][j] = 0;
	// получение информации о консольном окне
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	HWND hcon = GetConsoleWindow();

	// программная установка консольного шрифта для отображения русского текста
	CONSOLE_FONT_INFO cfi;
	GetCurrentConsoleFont(hConsole, false, &cfi);
	COORD fs = GetConsoleFontSize(hConsole, cfi.nFont);
	PCONSOLE_FONT_INFOEX ccf = new CONSOLE_FONT_INFOEX;
	(*ccf).dwFontSize.X = 12;
	(*ccf).dwFontSize.Y = 20;
	(*ccf).nFont = 11;
	(*ccf).cbSize = sizeof(CONSOLE_FONT_INFOEX);
	ccf->FontWeight = 400;
	lstrcpyW((*ccf).FaceName, L"Lucida Console");
	(*ccf).FontFamily = FF_DONTCARE;
	bool b = SetCurrentConsoleFontEx(hConsole, false, ccf);
	fs = GetConsoleFontSize(hConsole, cfi.nFont);

	// установка кодировки 1251 для отображения русского текста
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n = 5;			//кол-во пунктов меню
	COORD position[5];
	int punkt = 0;
	char names[5][30] = { "Указать субъекты", "Указать соседей для субъектов", "Просмотр карты", "Справка", "Выход" };
	do
	{
		int xmax, ymax;

		// получение параметров окна 
		PCONSOLE_SCREEN_BUFFER_INFO pwi = new CONSOLE_SCREEN_BUFFER_INFO;
		PWINDOWINFO pgwi = new WINDOWINFO;
		GetConsoleScreenBufferInfo(hConsole, pwi);
		GetWindowInfo(hcon, pgwi);
		xmax = pwi->dwSize.X;
		ymax = pwi->dwSize.Y;

		int y0 = 7;
		for (int i = 0; i < n; i++)
		{
			position[i].X = (xmax - strlen(names[i])) / 2;
			position[i].Y = y0 + i;
		}
		SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN); // цвет фона
		system("cls");			// очистка окна
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | BACKGROUND_GREEN); // цвет символов и цвет фона
		char title[] = "КАРТА";
		COORD pos;
		pos.X = (xmax - strlen(title)) / 2;
		pos.Y = 5;
		SetConsoleCursorPosition(hConsole, pos);
		puts(title);
		for (int i = 0; i < 5; i++)
		{
			SetConsoleCursorPosition(hConsole, position[i]);
			puts(names[i]);
		}
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_GREEN);
		SetConsoleCursorPosition(hConsole, position[punkt]);	// выделение текущего пункта ярким цветом
		puts(names[punkt]);
		unsigned char ch;
		do
		{
			// обработка перемещения по меню клавишами со стрелками
			ch = getch();
			if (ch == 224)
			{
				ch = getch();
				switch (ch)
				{
				case 72:
					SetConsoleCursorPosition(hConsole, position[punkt]);
					SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | BACKGROUND_GREEN);
					puts(names[punkt]);
					punkt--;
					if (punkt < 0) punkt = 4;
					SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_GREEN);
					SetConsoleCursorPosition(hConsole, position[punkt]);
					puts(names[punkt]); break;
				case 80:
					SetConsoleCursorPosition(hConsole, position[punkt]);
					SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | BACKGROUND_GREEN);
					puts(names[punkt]);
					punkt++;
					if (punkt > 4) punkt = 0;
					SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_GREEN);
					SetConsoleCursorPosition(hConsole, position[punkt]);
					puts(names[punkt]); break;
				}
			}
		} while (ch != 13);	// enter - выбор пункта меню
		switch (punkt)
		{
		case 0:
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | BACKGROUND_GREEN);
			system("cls");
			vvodsub();// вызов функции
			break;
		case 1:
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | BACKGROUND_GREEN);
			system("cls");
			vvodsosedey();// вызов функции
			break;
		case 2:
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | BACKGROUND_GREEN);
			system("cls");
			obrabotkaMatrisi();// вызов функции
			break;
		case 3:
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | BACKGROUND_GREEN);
			system("cls");
			printf("Уважаемый пользователь, чтобы программа работала без ошибок, внимательно изучите ниже приведенную инструкцию.\n");
			printf("1. Вам необходимо выбрать первый пункт меню (Указать субъекты) и ввести все желаемые субъекты.\n");
			printf("2. Теперь нужно для каждого субъекта ввести соседей (Указать соседей для субъектов). Учтите, что вы должны до этого ввести все желаемые субъекты.\n");
			printf("Во втором пункте меню во время указания соседей вы можете отслеживать введеные вами данные и в случае ошибки корректировать ввод\n");
			printf("3. Чтобы посмотреть, какому субъекту соответствует какой цвет, нужно выбрать третий пункт меню (Просмотр карты).\n");
			printf("\n");
			printf("После выхода из программы все данные сохраняются, поэтому вы можете неоднократно просматривать карту\n");
			printf("Удачи в использовании!\n");
			system("pause");
			break;
		}
	} while (punkt != 4);
	return 0;
}