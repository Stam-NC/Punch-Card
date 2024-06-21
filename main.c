// Made by Calvin Thornberg on 14/06/2024 DMY
// Punch Card MkI
// Desc: Calculates the length of time you need to work on Friday to achieve 40 hours of work


int main() {
	int TimeWorked[6][2] = { {0,0}, // hours, minutes format
		{0,0}, // tuesday
		{0,0}, // wed
		{0,0}, // thurs
		{0,0},  // fri
		{0,0} // clock out time
	};
	int YoN = 0, Minuteleft = 0, Hoursleft, Uselec = 0;
	char length[8] = "";
	char Spacer;
	Title_Print();
	while (1) {
		Menu_Print();
		scanf("%d", &Uselec);

		switch (Uselec) {
		case 1:
			timegetter(TimeWorked, 0);
			timegetter(TimeWorked, 1);
			timegetter(TimeWorked, 2);
			timegetter(TimeWorked, 3);
			timegetter(TimeWorked, 4);

			Minuteleft = timeCalc(TimeWorked);
			if (Minuteleft < 0) {
				printf("\nYou already worked 40 hours you can clock out now\n");
				system("pause"); // comment out for linux or Mac OS
				system("cls"); // comment out for linux or Mac OS
				break;
			}
			
			if (TimeWorked[4][0] == 0 && TimeWorked[4][1] == 0) {
				printf("\nHow many minutes will you be on lunch? (enter time in minutes- ex for 1 hr 31 mins enter 91) ");
				scanf("%d", &YoN);

				Minuteleft += YoN; // this adds however long your lunch will be sense lunch isn't paid
				YoN = 0;
				
				printf("\nWhen did you clock in today? \033[0;33m (leave out AM or PM) \033[0;37m \n");
				scanf("%s", length);
			}else {
				printf("\nWhen did you end your lunch? \033[0;33m (leave out AM or PM) \033[0;37m \n");
				scanf("%s", length);
				
			}
			YoN = 5;

			Hoursleft = Minuteleft / 60;

			Minuteleft = Minuteleft - Hoursleft * 60;

			theSplitter(length, TimeWorked, &YoN);
			
			TimeWorked[5][1] += Minuteleft;

			if (TimeWorked[5][1] > 59) {
				TimeWorked[5][0] += 1;
				TimeWorked[5][1] -= 60;
			}

			TimeWorked[5][0] += Hoursleft;
			if (TimeWorked[5][0] > 12) {
				TimeWorked[5][0] -= 12;
			}

			if (TimeWorked[5][1] < 10) {
				printf("\nClock out at %d:0%d pm\n", TimeWorked[5][0], TimeWorked[5][1]); // because C wont print a leading 0
			}else {
				printf("\nClock out at %d:%d pm\n", TimeWorked[5][0], TimeWorked[5][1]);
			}
			
			break;
		case 2: // 8 hr calculator
			printf("\nEnter how many hours you've worked today: (format hour:minutes)\n");
			scanf("%s", length);
			YoN = 0;
			theSplitter(length, TimeWorked, &YoN);

			printf("\nEnter time you ended your lunch break (hour:minute don't include AM/PM)\n");
			scanf("%s", length);
			YoN = 1;
			theSplitter(length, TimeWorked, &YoN);

			Minuteleft = 480 - TimeWorked[0][0] * 60 - TimeWorked[0][1];

			if (Minuteleft < 0) {
				printf("\nYou already worked 8 hours you can clock out now\n");
				system("pause"); // comment out for linux or Mac OS
				system("cls"); // comment out for linux or Mac OS
				break;
			}
			Hoursleft = Minuteleft / 60;
			Minuteleft = Minuteleft - Hoursleft * 60;
			TimeWorked[1][1] += Minuteleft;

			if (TimeWorked[1][1] > 59) {
				TimeWorked[1][0] += 1;
				TimeWorked[1][1] -= 60; // Hr roll over
			}

			TimeWorked[1][0] += Hoursleft; 
			if (TimeWorked[1][0] > 12) {
				TimeWorked[1][0] -= 12;
			}

			if (TimeWorked[1][1] < 10) {
				printf("\nClock out at %d:0%d pm\n", TimeWorked[1][0], TimeWorked[1][1]);
			}else {
				printf("\nClock out at %d:%d pm\n", TimeWorked[1][0], TimeWorked[1][1]);
			}

			system("pause"); // comment out for linux or Mac OS
			system("cls"); // comment out for linux or Mac OS

			break;
		case 3: // instructions
			Instruction_Print();
			break;
		case 4: // exit
			return 0;
			break;
		default:
			system("cls"); // comment out for linux or Mac OS
			break;
		}
	}

}


