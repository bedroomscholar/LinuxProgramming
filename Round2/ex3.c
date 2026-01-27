#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[]){
	if (argc < 2){
		printf("Usage: %s <name>\n", argv[0]);
		return 1;
	}

	time_t rawtime;
	struct tm *timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	int hour = timeinfo->tm_hour;
	char *greeting;
	
	if (hour >= 5 && hour < 12){
		greeting = "Good Morning";
	} else if (hour >= 12 && hour < 18){
		greeting = "Good Afternoon";
	} else {
		greeting = "Good Night";
	}

	printf("%s %s, now is %02d:%02d.\n", greeting, argv[1], timeinfo->tm_hour, timeinfo->tm_min);

	return 0;
}

