#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "common.h"
#include "config.h"
#include "buffer.h"
#include "zcu.h"
#include "etm.h"
#include "tmc.h"


int main(int argc, char* argv[])
{
	clear_buffer(OCM_BASE, BUFFER_SIZE);
	register_components();
	config_components();
	
	pid_t pid = fork();
    
    if (pid == -1)
	{
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
	else if (pid == 0)
	{
		// child process
		// ETM only trace child pid
		uint64_t child_pid = getpid();
		etm_context_id_comparator_value(etm_0, child_pid);
		
		etm_enable(etm_0);
		
		uint32_t val = 1;
		uint32_t *p = &val;
	
		for (uint32_t i = 0; i < 2; i++)
			val += *p;

		printf("Val: %d\n", val);
		sleep(1);
    }
	else
	{
        // Parent process        
		wait(NULL);
		etm_disable(etm_0);
		dump_buffer(OCM_BASE, BUFFER_SIZE);
    }	

	return 0;
}
