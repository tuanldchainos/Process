#include "LedProcess.h"
#include <pthread.h>

pthread_t vrts_System_Gpio;

int main(){
	pthread_create(&vrts_System_Gpio,NULL,Led_Thread,NULL);
	pthread_join(vrts_System_Gpio,NULL);

	while(1){

	}
	return 0;
}

