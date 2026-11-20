#include <stdio.h>

int main()
{
    int start[] = {1, 2, 4, 6};
    int end[]   = {4, 5, 7, 8};

    int n = 4;

    int roomEnd[10];
    int rooms = 0;

    for (int i = 0; i < n; i++)
    {
        int assigned = 0;

        for (int j = 0; j < rooms; j++)
        {
            if (start[i] >= roomEnd[j])
            {
                roomEnd[j] = end[i];

                printf("Activity %d -> Room %d\n",
                       i + 1, j + 1);

                assigned = 1;
                break;
            }
        }

        if (assigned == 0)
        {
            roomEnd[rooms] = end[i];

            printf("Activity %d -> Room %d\n",
                   i + 1, rooms + 1);

            rooms++;
        }
    }

    printf("Total rooms required = %d", rooms);

    return 0;
}