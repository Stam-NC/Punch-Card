#include "function.h"

void Color_det(int Maxell) { // Color_det mk3
	int Pyral = 0;
	if (Maxell < 0)
		Pyral = 1;
	Maxell = abs(Maxell);

	switch (Maxell) {
	case 1: // red
		printf("\033[0;31m");
		if (Pyral == 1)
			printf("\033[7;31m");
		break;
	case 2: // green
		printf("\033[0;32m");

		if (Pyral == 1)
			printf("\033[1;32m");
		break;
	case 3: // White 
		printf("\033[0;37m");

		if (Pyral == 1)
			printf("\033[1;37m");
		break;
	case 4: // cyan
		printf("\033[0;36m");

		if (Pyral == 1)
			printf("\033[1;36m");
		break;
	case 5: // purple gross
		printf("\033[0;35m");

		if (Pyral == 1)
			printf("\033[1;35m");
		break;
	case 6: // blue
		printf("\033[0;34m");

		if (Pyral == 1)
			printf("\033[1;34m");
		break;
	default:
		printf("\033[0;33m"); // You see yellow, you went wrong fella

		if (Pyral == 1)
			printf("\033[1;33m");
	}
}

void timegetter(int timeworked[6][2], int day) {
	char length[8] = "";
	switch (day) {
	case 0: // Monday
		printf("\nEnter time worked on Monday (hour:minute): ");
		break;
	case 1: // Tuesday
		printf("\nEnter time worked on Tuesday (hour:minute): ");
		break;
	case 2: // Wednesday
		printf("\nEnter time worked on Wednesday (hour:minute): ");
		break;
	case 3: // Thursday
		printf("\nEnter time worked on Thursday (hour:minute): ");
		break;
	case 4: // Friday
		printf("\nEnter the amount of time worked before lunch today \033[0;33m (if you haven't started lunch enter 0:00 )\033[0;37m: ");
		break;
	default:
		Color_det(10);
		printf("\nErr: NOT A DAY\n");
		Color_det(3);
		return;
	}


	scanf("%s", length);
	theSplitter(length, timeworked, &day);

}

void theSplitter(char* str, int timeworked[6][2], int* day) { // splits hours from minutes in hh:mm format
	char* token;
	token = strtok(str, ":");
	timeworked[*day][0] = atoi(token);
	token = strtok(NULL, ":");
	timeworked[*day][1] = atoi(token);
}

int timeCalc(int timeworked[6][2]) {
	int target = 2400;
	int totalmin = 0;
	for (int day = 0; day <= 4; day++) {
		totalmin += timeworked[day][1] + timeworked[day][0] * 60;
	}
	return 2400 - totalmin;
}

void Title_Print() {

	printf("\t   \033[3;37m   Punch Card\n");
	printf("     \t     \033[3;31m %c\033[3;32m %c\033[3;34m %c\033[3;37m COLOR\033[0;37m\n\n\t", 219, 219, 219);
	printf("   By: Calvin Thornberg\n\n\t");

	system("pause"); // comment out for linux or Mac OS
	system("cls"); // comment out for linux or Mac OS
}

void Menu_Print() {
	printf("\nPunch Card| Enter the index number and press return\n");
	LongLineDraw(205);
	printf("1 -- Calculate Friday Clockout\n"
		"2 -- Calculate Today's Clockout\n"
		"3 -- Instructions\n"
		"4 -- Exit\n");

	LongLineDraw(196);
	printf("%c", 178);
	return 0;
}

void Instruction_Print() {
	char useless;
	printf("\n\n\nPunch Card| Instructions\n");
	LongLineDraw(205);
	printf("This program has 2 functions:\n"
		"1. Calculate the time you should clock out on a Friday after completing that days break\n to achieve 40 hours.\n\n"
		"2. Calculate that day's clockout time to achieve 8 hours\n\n");
	Color_det(2);
	printf("Correct entry format for time entry: 8:01   1:30  3:00  0:15\n");
	Color_det(1);
	printf("Incorrect entry format for time entry: 8h1m   1.5  3  0.25\n ");
	Color_det(3);
	system("pause"); // comment out for linux or Mac OS
	system("cls"); // comment out for linux or Mac OS

	//scanf("%c", &useless); // comment in for use in linux
	//scanf("%c", &useless); // comment in for use in linux (yes both lines)
	//printf("\n"); // comment in for linux

}


void LongLineDraw(int ingersoll) { // ingersoll is a number corresponding to ascii value
	int HighStandard = -1; 
	printf("\033[0;37m");
	do {
		printf("%c", ingersoll);
		HighStandard++;
	} while (HighStandard < 90);
	printf("\n");
	return;
}




