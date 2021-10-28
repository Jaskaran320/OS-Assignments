#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<pthread.h>
#include<errno.h>
#include<string.h>
int errno;
char *section[26];
int marks[26][6];
float assgn[6] = {0,0,0,0,0,0};
void * data(void *args){
    int fd = open("student_record.csv", O_RDONLY);
    if(fd == -1){
        printf("Error number: %d\n", errno);
        perror("File open");
        exit(0);
    }
    int i = 0;
    char *lines[27];
    char *ch = (char *)calloc(850, sizeof(char));
    int sz = read(fd, ch, 850);
    if (sz == -1){
        printf("Error number: %d\n", errno);
        perror("File read");
        exit(0);
    }
    char *token = strtok(ch,"\n");
    while (token!=NULL){
        lines[i] = token;
        token = strtok(NULL,"\n");
        i++;
    }
    for (int i = 0; i < 26; i++){
        token = strtok(lines[i+1], ",");
        token = strtok(NULL, ",");
        section[i] = token;
        token = strtok(NULL, ",");
        marks[i][0] = atoi(token);
        token = strtok(NULL, ",");
        marks[i][1] = atoi(token);
        token = strtok(NULL, ",");
        marks[i][2] = atoi(token);
        token = strtok(NULL, ",");
        marks[i][3] = atoi(token);
        token = strtok(NULL, ",");
        marks[i][4] = atoi(token);
        token = strtok(NULL, ",");
        marks[i][5] = atoi(token);
    }
    free(ch);
    close(fd);
}
void *assgn_avg(){
    for(int i = 0; i < 26; i++){
        assgn[0] += marks[i][0];
        assgn[1] += marks[i][1];
        assgn[2] += marks[i][2];
        assgn[3] += marks[i][3];
        assgn[4] += marks[i][4];
        assgn[5] += marks[i][5];
    }
}
int main(){
    float sum = 0;
    char str[1000];
    float avg;
    int fd = open("written_records2.txt", O_WRONLY);
    if(fd == -1){
        printf("Error number: %d\n", errno);
        perror("File open");
        exit(0);
    }
    pthread_t tid, tid1;
    pthread_create(&tid, NULL, data,(void *)NULL);
    pthread_create(&tid1, NULL, data, (void *)NULL);
    pthread_join(tid,NULL);
    write(fd, "The average for section A is\n", 29);
    for (int j = 0; j < 6; j++){
        sum = 0;
        for (int i = 0; i < 26; i++)
            if (!strcmp(section[i], "A"))
                sum += marks[i][j];
        avg = sum/9;
        snprintf(str, 1000, "The average marks for assignment %d is %f\n", (j+1), avg);
        write(fd, str, strlen(str));
    }
    write(fd, "\nThe average for section B is\n", 30);
    for (int j = 0; j < 6; j++){
        sum = 0;
        for (int i = 0; i < 26; i++)
            if (!strcmp(section[i], "B"))
                sum += marks[i][j];
        avg = sum/17;
        snprintf(str, 1000, "The average marks for assignment %d is %f\n", (j+1), avg);
        write(fd, str, strlen(str));
    }
    // printf("\n");
    write(fd,"\nThe average marks for both sections is\n", 40);
    assgn_avg();
    for (int i = 0; i<6; i++){
        // printf("Average marks of Students in Assignment %d is %f\n", (i+1), (assgn[i]/26));
        snprintf(str, 1000, "Average marks of Students in Assignment %d is %f\n", (i+1), (assgn[i]/26));
        write(fd, str, strlen(str));
    }
    pthread_exit(NULL);
}