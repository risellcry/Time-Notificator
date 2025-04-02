#include <stdio.h>
#include <stdbool.h>
#include <time.h>

int main()
{
    int services = 1;
    int hrs[7];
    int mns[7];
    int csv = 0;
    printf("Time Notificator by Rise LLC\n");
    printf("How many Services > ");
    scanf("%d", &services);
    for (int i = 0; i < services; i++)
    {
        printf("Time Notification Service #%d\n", i + 1);
        printf("Choose Hour > ");
        scanf("%d", &hrs[csv]);
        printf("Choose Minute > ");
        scanf("%d", &mns[csv]);
        csv++;
    }
    while (true)
    {
        time_t raw = time(NULL);
        struct tm *info = localtime(&raw);
        int rhr = info -> tm_hour;
        int rmn = info -> tm_min;
        for (int i = 0; i < 8; i++)
        {
            if ((hrs[i] != 0 && mns[i] != 0) && (rhr <= hrs[i] && rmn <= mns[i]))
            {
                while (true)
                {
                    rhr = info -> tm_hour;
                    rmn = info -> tm_min;
                    if (rhr >= hrs[i] && rmn >= mns[i])
                    {
                        printf("Completed to Notify Service #%d ...\n", i + 1);
                        break;
                    }
                    else
                    {
                        printf("%d:%d\n", hrs[i], mns[i]);
                    }
                }
            }
        }
        break;
    }
    printf("Thank You for using our Service!");
    return 0;
}