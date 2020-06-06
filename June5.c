/*
    Problem:

    Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly picks an index in proportion to its weight.

    Note:
        1 <= w.length <= 10000
        1 <= w[i] <= 10^5
        pickIndex will be called at most 10000 times.

    Example 1:
        Input: 
            ["Solution","pickIndex"]
            [[[1]],[]]
            Output: [null,0]

    Example 2:
        Input: 
            ["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
            [[[1,3]],[],[],[],[],[]]
            Output: [null,0,1,1,1,0]



    Author: Mackenzie Josie
    Date: June 5, 2020
*/

typedef struct {
    int value;
    int lowerWeight;
    int upperWeight;
    int totalWeight;
} Solution;


Solution* solutionCreate(int* w, int wSize) {
    Solution* obj = malloc(sizeof(Solution)*wSize);
    int i, sum = 0;
    
    // printf("size = %d\n", wSize);
    
    for(i=0;i<wSize;i++)
    {
        obj[i].value = i;
        obj[i].lowerWeight = sum + 1;
        obj[i].upperWeight = obj[i].lowerWeight + w[i] - 1;
        obj[i].totalWeight = 0;
        // obj[i]->weight[1] = w[i] + sum;
        sum += w[i];
        
        // printf("lower = %d\tupper = %d\n", obj[i].lowerWeight, obj[i].upperWeight);
    }
    
    obj[0].totalWeight = sum;
    // printf("sum = %d\n", sum);
    
    return obj;
}

int solutionPickIndex(Solution* obj) {
    // time_t t;
    // srand((unsigned) time(&t));
    
    int randomNum = 1 + rand() % (obj[0].totalWeight);
    int i = 0;
    
    // printf("%d ", randomNum);
    
    while (1)
    {
        if (randomNum >= obj[i].lowerWeight && randomNum <= obj[i].upperWeight)
        {
            break;
        }
        else
        {
            i++;
        }
    }
    return i;
}

void solutionFree(Solution* obj) {
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(w, wSize);
 * int param_1 = solutionPickIndex(obj);
 
 * solutionFree(obj);
*/