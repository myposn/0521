#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#include "redis_op.h"
#include "make_log.h"


int main(int argc, char *argv[])
{
    int ret = 0; 
    char *ip = "192.168.21.46";
    char *port = "6379";
    char *str = NULL;
    char *key = "name";
    redisContext* conn = NULL;
    conn =rop_connectdb_nopwd(ip,port);
    
    ret = rop_get(conn,key,&str);
    if(ret !=0)
    {
        printf("rop_get error");
        return -1;
    }
    printf("str %s\n",str);
	return 0;
}
