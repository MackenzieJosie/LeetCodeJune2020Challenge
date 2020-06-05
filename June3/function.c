/*
    Problem:

    There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0], and the cost of flying the i-th person to city B is costs[i][1].

    Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.

    Example:

    Input: [[10,20],[30,200],[400,50],[30,20]]
    Output: 110
    Explanation: 
    The first person goes to city A for a cost of 10.
    The second person goes to city A for a cost of 30.
    The third person goes to city B for a cost of 50.
    The fourth person goes to city B for a cost of 20.

    The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.



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
