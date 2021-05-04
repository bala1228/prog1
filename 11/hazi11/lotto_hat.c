#include <stdio.h>

int main()
{
    int x1 = 1, x2 = 1, x3 = 1, x4 = 1, x5 = 1, x6 = 1;

    for (int i = 0; i < 45; i++)
    {
        if (((x1 * x2 * x3 * x4 * x5 * x6) == 996300) && ((x1 + x2 + x3 + x4 + x5 + x6) == 90))
        {
            break;
        }
        x1++;
        if (x1 > 45)
        {
            x1 = 0;
        }

        for (int i = 0; i < 45; i++)
        {
            if (((x1 * x2 * x3 * x4 * x5 * x6) == 996300) && ((x1 + x2 + x3 + x4 + x5 + x6) == 90))
            {
                break;
            }
            x2++;
            if (x2 > 45)
            {
                x2 = 0;
            }

            for (int i = 0; i < 45; i++)
            {
                if (((x1 * x2 * x3 * x4 * x5 * x6) == 996300) && ((x1 + x2 + x3 + x4 + x5 + x6) == 90))
                {
                    break;
                }
                x3++;
                if (x3 > 45)
                {
                    x3 = 0;
                }

                for (int i = 0; i < 45; i++)
                {
                    if (((x1 * x2 * x3 * x4 * x5 * x6) == 996300) && ((x1 + x2 + x3 + x4 + x5 + x6) == 90))
                    {
                        break;
                    }
                    x4++;
                    if (x4 > 45)
                    {
                        x4 = 0;
                    }

                    for (int i = 0; i < 45; i++)
                    {
                        if (((x1 * x2 * x3 * x4 * x5 * x6) == 996300) && ((x1 + x2 + x3 + x4 + x5 + x6) == 90))
                        {
                            break;
                        }
                        x5++;
                        if (x5 > 45)
                        {
                            x5 = 0;
                        }

                        for (int i = 0; i < 45; i++)
                        {
                            if (((x1 * x2 * x3 * x4 * x5 * x6) == 996300) && ((x1 + x2 + x3 + x4 + x5 + x6) == 90))
                            {
                                break;
                            }
                            x6++;
                            if (x6 > 45)
                            {
                                x6 = 0;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d %d %d %d %d %d\n", x1, x2, x3, x4, x5, x6);

    return 0;
}