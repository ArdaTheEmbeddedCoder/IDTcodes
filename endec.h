#include <time.h>
#include <string.h>

int ready_msg(){
    srand (time(0));
    char check [6] = {0}, input [6] = {0};
    int msg [6] = {0};

    for (int loop=0;loop<=4;loop++){
        msg[loop] = rand()%26;
        check[loop] = msg[loop] + 97;
    }
    printf ("Please confirm that you are ready by\n"
          "entering the code: %s\n", check);

    scanf ("%s", input);

    if (!strcmp (check, input)){
        puts ("Proceeding..");
        return 1;
    }
    else{
        return 0;
    }
}

double power (int x, int y){
    int z=1;
    for (int loop=y;y>0;y--){
        z = z*x;
    }
    return z;
}

FILE *fi_po;

void write (int message[], FILE *fi_po){
    fi_po = fopen ("text.txt", "w");
    int inc=0;

    while (message[inc] != '\0'){
        fputc (message[inc], fi_po);
        inc++;
    }
    fclose (fi_po);
}

int bin_conv (int number, FILE *fi_po){
    int bit[8] = {0};
    static int output[8] = {0};
    for (int loop=0;loop<8;loop++){
        if (number>=power (2, loop)){
            bit[loop] = 1;
            bit[loop-1] = 0;
        }
    }
    int stop_bit = 0;
    for (int loop=0;loop<8;loop++){
        if (bit[loop] == 1){
            stop_bit = loop;
            output[stop_bit] = 1;
        }
    }

    number = number - power (2, stop_bit);

    if (number == 0){
        fi_po = fopen ("text.txt", "a+");
        for (int loop=7;loop>=0;loop--){
            fprintf (fi_po, "%d", output[loop]);
        }
        fclose (fi_po);
        return 0;
    }
    else{
        bin_conv (number, fi_po);
    }
}
