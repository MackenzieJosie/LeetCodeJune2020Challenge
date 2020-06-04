/*
    Author: Mackenzie Josie
    Date: June 3, 2020
*/

int twoCitySchedCost(int** costs, int costsSize, int* costsColSize){
    int i, j, n=1, sum = 0, halfN = costsSize / 2, aCount = 0, bCount = 0, temp;
    int differences[costsSize], lower[costsSize], order[costsSize];
    
    //printf("%d\n", costsSize);
    
    for (i=0;i<costsSize;i++)
    {
        differences[i] = abs(costs[i][0] - costs[i][1]);
        order[i] = i;
        
        if (costs[i][0] < costs[i][1])
        {
            lower[i] = 0;
        }
        else
        {
            lower[i] = 1;
        }
    }
    
    for (i=0;i<costsSize-1;i++)
    {
        for (j=i+1;j<costsSize;j++)
        {
            if (differences[i]<differences[j])
            {
                temp = differences[i];
                differences[i] = differences[j];
                differences[j] = temp;
                
                temp = lower[i];
                lower[i] = lower[j];
                lower[j] = temp;
                
                temp = order[i];
                order[i] = order[j];
                order[j] = temp;
            }
        }
    }
    
    for (i=0;i<costsSize;i++)
    {
        if ((lower[i] == 0 && aCount < halfN) || bCount == halfN)
        {
            aCount++;
            sum += costs[order[i]][0];
        }
        else
        {
            bCount++;
            sum += costs[order[i]][1];
        }
    }
    
    
//     for (i=0;i<costsSize;i++)
//         printf("diff = %d, %d is less\n", differences[i], lower[i]);
    
//      for (i=0;i<costsSize;i++)
//         printf("%d ", order[i]);
    
//     printf("\n");
    
    return sum;
}