#include <time.h>
#include <stdio.h>
#include "TimeHelper.h"

char* get_current_time_str(){
	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	rawtime = rawtime + 7*3600;
	timeinfo = localtime(&rawtime);
	char * date = asctime(timeinfo);
	date[strlen(date) - 1] = '\0';
	return date;
}

char * get_current_day_month_year_str(){
	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	rawtime = rawtime + 7*3600;
	timeinfo = localtime(&rawtime);
	char *date = (char *)malloc(1);
	sprintf(date, "%d_%d_%d", timeinfo->tm_mday, timeinfo->tm_mon+1, timeinfo->tm_year+1900);
	return date;
}

char* get_backward_day_month_year_str(int num_backward){
	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	rawtime = rawtime - num_backward*3600*24;
	timeinfo = localtime(&rawtime);
	char *date = (char *)malloc(1);
	sprintf(date, "%d_%d_%d", timeinfo->tm_mday, timeinfo->tm_mon+1, timeinfo->tm_year+1900);
	return date;
}

