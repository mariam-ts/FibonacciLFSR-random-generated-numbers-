# include <stdint.h>
#include <stdio.h>
unsigned long lfsr(unsigned long start_state)
{
    unsigned long lfsr =  start_state; //current state starts with start state
    uint32_t tabs; // tabs, that control the procedure

        tabs = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 6) ^ (lfsr >> 7)) & 1; // we have 32, 30, 26, 25 tabs
        lfsr = (lfsr >> 1) | (tabs << 31); // add the output at the top

    return lfsr;
}

    int main()
{
       unsigned long start;
       int num;
       start = lfsr(0x5AA5FF00);

       printf("How many random numbers do you want? \n");
       scanf("%d", &num);

       for(int i = 0; i< num; ++i)
       {
           start = lfsr(start);
           printf("%lu \n", start);
       }

}
