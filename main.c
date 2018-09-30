#include <stdio.h>
#include <stdlib.h>
#include "endec.h"
#include <ctype.h>
#define BINARY 1
#define SHIFT_BINARY 2
#define CAESAR_CIPHER 3
#define ANTI_BRUTE_FORCE 4
#define BRUTE_FORCE_ATTACK 5
#define EXIT 6

/**
@author Arda
*/
void convertBinary();

int main()
{
    // ENDEC //

    FILE *fp;
    puts ("1- binary\n"
          "2- shift binary\n"
          "3- caesar cipher\n"
          "4- anti-brute force\n"
          "5- brute force attack\n"
          "6- exit.");

    int choice = 0, error = 0;
    puts ("Please choose an option to proceed.");
    scanf ("%d", &choice);

    while (error = 0){
        if (choice<1 || choice>5)
            puts ("An error has occurred. Please enter a valid number.");
        else
            error = 1;
    }

    switch (choice){

        case BINARY:
            convertBinary();
            break;

        case SHIFT_BINARY:
        case CAESAR_CIPHER:{
            int increase = 0;
            char msg[500];
            if (!ready_msg()){
                puts ("Incorrect keyword");
                break;
            }
            fp = fopen ("text.txt", "r");
            while (!feof(fp)){
                msg[increase] = fgetc (fp);
                increase++;
            }
            fclose (fp);
            puts ("Please enter the shift number");
            int shift = 0, loop = 0;
            scanf ("%d", &shift);

            fp = fopen ("text.txt", "w");
            while (msg[loop] != EOF){
                if (isalpha(msg[loop])){
                    msg[loop] = msg[loop]+shift;
                    if (msg[loop]-97 > 25){
                        msg[loop] = (msg[loop]-97)%26 + 97;
                    }
                }
                fprintf (fp, "%c", msg[loop]);
                loop++;
            }
            fclose (fp);
            puts ("Encoding process terminated successfully.");
            break;
        }
        case ANTI_BRUTE_FORCE:
        case BRUTE_FORCE_ATTACK:{
            char folder[20] = {0}, temp[500];
            if (!ready_msg()){
                puts ("Incorrect keyword");
                break;
            }
            puts ("Enter the files name to proceed.");
            scanf ("%s", folder);

            int loop = 0;
            while (isalpha(folder[loop])){
                loop++;
            }
            folder[loop] = '.';
            folder[loop+1] = 't';
            folder[loop+2] = 'x';
            folder[loop+3] = folder[loop+1];

            fp = fopen (folder, "r");
            loop = 0;
            while (!feof(fp)){
                temp[loop] = fgetc (fp);
                loop++;
            }
            loop = 0;

            for (int shift=0;shift<26;shift++){
                printf ("Shift %d: ", shift);
                while (temp[loop] != EOF){
                    if (isalpha(temp[loop])){
                        temp[loop] = temp[loop] + shift;
                        if (temp[loop]>25){
                            temp[loop] = (temp[loop]-97)%26 + 97;
                        }
                    }
                }
                printf ("%s\n", temp);
            }
            puts ("..These are the possible translations.");
            fclose (fp);
        }
        case EXIT:
        default:
        break;
    }


    return 0;
}

void convertBinary()
{
        FILE *fp;
        char msg[500];
         int loop=0;
        // READY_MSG
       fp = fopen ("text.txt", "r");
        while (!feof(fp))
        {
           msg[loop] = fgetc(fp);
           loop++;
        }

        fclose (fp);
        int bin[loop], counter = loop-1;

        while (counter>=0)
        {
            bin[counter] = msg[counter];
            counter--;
        }

        fp = fopen ("text.txt", "w");
        fclose (fp);

        for (int looper=0;looper<8;looper++)
        {
                bin_conv (bin[looper], fp);
        }
}
