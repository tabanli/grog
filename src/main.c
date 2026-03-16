#include "head.h"
#include "utils.h"
#include "basic.h"
#include "tuntap.h"

int main(int argc, char** argv) {
    char dev[IFNAMSIZ] = "tap0";
    int fd;
    unsigned char buf[1600];
    int nread;

    fd = dev_alloc(dev);
    if (fd < 0) {
        fprintf(stderr, "Error: Could not allocate interface %s\n", dev);
        return 1;
    }

    printf("Interface initialized: %s\n", dev);

    while (1) {
        nread = read(fd, buf, sizeof(buf));
        if (nread < 0) {
            print_error("Read error from interface");
            close(fd);
            return 1;
        }

        printf("Size: %d bytes\n", nread);
       
        printf("Dest MAC: %02x:%02x:%02x:%02x:%02x:%02x\n", 
        buf[0], buf[1], buf[2], buf[3], buf[4], buf[5]);
        
        printf("Src MAC:  %02x:%02x:%02x:%02x:%02x:%02x\n", 
        buf[6], buf[7], buf[8], buf[9], buf[10], buf[11]);
    
        printf("EtherType: %02x%02x", buf[12], buf[13]);
        printf("\n------------------------------\n");
    }

    close(fd);
    return 0;
}
