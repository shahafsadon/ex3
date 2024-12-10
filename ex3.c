/******************
Name: shahaf sadon
ID: 314941444
Assignment: ex3
*******************/

#include <stdio.h>

#define NUM_OF_BRANDS 5
#define BRANDS_NAMES 15
#define NUM_OF_TYPES 4
#define TYPES_NAMES 10
#define DAYS_IN_YEAR 365
#define addOne  1
#define addAll  2
#define stats  3
#define print  4
#define insights  5
#define deltas  6
#define done  7

char brands[NUM_OF_BRANDS][BRANDS_NAMES] = {"Toyoga", "HyunNight", "Mazduh", "FolksVegan", "Key-Yuh"};
char types[NUM_OF_TYPES][TYPES_NAMES] = {"SUV", "Sedan", "Coupe", "GT"};
// All function use in the program ex3
void printMenu(){
    printf("Welcome to the Cars Data Cube! What would you like to do?\n"
           "1.Enter Daily Data For A Brand\n"
           "2.Populate A Day Of Sales For All Brands\n"
           "3.Provide Daily Stats\n"
           "4.Print All Data\n"
           "5.Provide Overall (simple) Insights\n"
           "6.Provide Average Delta Metrics\n"
           "7.exit\n");
}
//The sumData function is used to add data to the next available day (the day argument)
//for the selected brand chosen by the user.
int sumData(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES],int day){
    //These variables will store the user's inputs, and if a valid car brand is entered,
    //the corresponding values will be added
    //to the cube on the next available day for the chosen car brand.
    int Brand, SUVSales, SedanSales, CoupeSales, GTSales;
    printf("Please complete the data\n");
    scanf("%d" "%d" "%d" "%d" "%d" , &Brand, &SUVSales, &SedanSales, &CoupeSales, &GTSales);
    if (Brand <= 4 && Brand >= 0) {
        cube[day][Brand][0] = SUVSales;
        cube[day][Brand][1] = SedanSales;
        cube[day][Brand][2] = CoupeSales;
        cube[day][Brand][3] = GTSales;
        return Brand;
    }
    else {
        printf("This brand is not valid\n");
        return -1;
    }
}
//The totalSales function is used to display the total sales for a specific day (specified by the day argument).
void totalSales(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES],int day, int numOfBrands, int numOfTypes) {
    int salesSum = 0;
    //There are two nested for loops that iterate over all the types of car brands for
    //the selected day and calculate the total sales for each.
    for (int i = 0; i < numOfBrands; i++) {
        for (int j = 0; j < numOfTypes; j++) {
            salesSum += cube[day][i][j];
        }
    }
    printf("The sales total was %d\n", salesSum);
}
//The bestBrandSold function is used to display the total sales of the top-performing brand for a specific day
//(specified by the day argument).
void bestBrandSold(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES],int day, int numOfBrands, int numOfTypes) {
    int dayMax = 0;
    int bestBrand = -1;
    int brandSum = 0;
   // In these two for loops, we are checking the sales sum for each brand on that day and assigning the value to
   // 'currentMax'. If 'currentMax' is greater than 'brandSum' (which is initially set to 0), we update 'brandSum' with
   // the value of 'currentMax' and set 'bestBrand' to the index of the brand with the higher sales. We then reset
   // 'currentMax' to 0 for the next brand. If 'currentMax' is not greater than 'brandSum', we simply reset 'currentMax'
   // and proceed to check the next brand without changing 'brandSum'.
    for (int i = 0; i < numOfBrands; i++) {
        for (int j = 0; j < numOfTypes; j++) {
            dayMax += cube[day][i][j];
        }
        if (dayMax > brandSum) {
            bestBrand = i;
            brandSum = dayMax;
            dayMax = 0;
        }
        else {
            dayMax = 0;
        }
    }
    printf("The best sold brand with %d sales was %s\n",brandSum, brands[bestBrand]);
}
//The 'bestTypeSold' function is used to display the total sales of the top-selling car type for a specific day
//(specified by the `day` argument).
void bestTypeSold(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES],int day, int numOfBrands, int numOfTypes) {
    int currentMax = 0;
    int typeBest = -1;
    int typeSum = 0;
   //In these two for loops, we are checking the sales sum for each type on that day and assigning the value to
   //'currentMax'. If 'currentMax' is greater than 'typeSum' (which is initially set to 0), we update 'typeSum' with the
   //value of 'currentMax' and set 'bestType' to the index of the type with the higher sales. We then reset 'currentMax'
   //to 0 for the next type. If 'currentMax' is not greater than 'typeSum', we simply reset 'currentMax' and proceed to
   //check the next type without modifying 'typeSum'.
    for (int i = 0; i < numOfTypes; i++) {
        for (int j = 0; j < numOfBrands; j++) {
            currentMax += cube[day][j][i];
        }
        if (currentMax > typeSum) {
            typeBest = i;
            typeSum = currentMax;
            currentMax = 0;
        }
        else {
            currentMax = 0;
        }
    }
    printf("The best sold type with %d sales was %s\n",typeSum, types[typeBest]);
}
//The 'ogCube' function is used to display all the information for each day that has received inputs.
void ogCube(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES],int day, int numOfBrands, int numOfTypes) {
   // The first for loop iterates through the brands and retrieves the total sales for each brand. The second and third
   // nested loops run within the first loop to gather the total sales for that specific day. For each brand, we check
   // if there were any sales. If there were no sales, we simply print "Sales for BrandName" and move on to the next
   // brand as required.
    for (int i = 0; i < numOfBrands; i++) {
        int totalSales = 0;
        for (int j = 0; j < numOfTypes; j++) {
            for (int k = 0; k < day; k++) {
                totalSales += cube[k][i][j];
            }
        }
            if (totalSales == 0){
                printf("Sales for %s:\n", brands[i]);
            }
       // The 'else if' block find that a brand's sales are not 0. Then, for each day, we print the
       // sales for each type of car. The car types are represented by indexes 0-3, and the day to be printed is
       // adjusted by adding 1 to the day, as the program uses a 0-364 range for days (representing days 1-365).
            else {
                printf("Sales for %s:\n", brands[i]);
                for (int t = 0; t < day; t++) {
                    printf("Day %d- SUV: %d Sedan: %d Coupe: %d GT: %d\n", t+1,cube[t][i][0]
                        ,cube[t][i][1],cube[t][i][2],cube[t][i][3]);
                }
            }
    }
}
// The `overallBrand` function is used to display the total sales of the highest-grossing brand up until the last day
// that has data (specified by the `day`).
void overallBrand(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES],int day, int numOfBrands, int NumOfTypes){
    int brandSum = 0;
    int brandBest = -1;
    int BrandSum = 0;
    int SumArr[numOfBrands];
    for (int i = 0; i <numOfBrands; i++) {
        SumArr[i] = 0;
    }
    for (int i = 0; i < numOfBrands; i++) {
        for (int j = 0; j < day; j++) {
            for (int k = 0; k < NumOfTypes; k++) {
                SumArr[i] += cube[j][i][k];
            }
        }
    }
    // We want to find the highest value in the array (the highest-grossing brand). For each iteration,
    // we check if the value at index `i` is greater than `brandSum` (which is initially set to 0).
    // If it is, we assign the index `i` to `bestBrand` and the value at that index to `brandSum`.
    for (int i = 0; i < numOfBrands; i++) {
        if (SumArr[i] > brandSum) {
            brandBest = i;
            brandSum = SumArr[i];
        }
    }
    //After exiting the loop, we have the index of the highest-grossing brand and the corresponding value,
    //which is the sum from the array at that index. At this point, we can print the desired information as requested.
    BrandSum = SumArr[brandBest];
    printf("The best-selling brand overall is %s: %d$ \n",brands[brandBest],BrandSum);
}
//The 'overallType' function is used to display the total sales of the highest-grossing car type up until the last
//day that has data (specified by the 'day').
void overallType(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES],int day, int numOfBrands, int numOfTypes) {
    int typeSum = 0;
    int bestType = -1;
    int totalTypeSum = 0;
    int totalSumArr[numOfTypes];
    for (int i = 0; i <numOfTypes; i++) {
        totalSumArr[i] = 0;
    }
    //In these nested loops, we assign the total sales for each brand to the corresponding index of the
    //'totalSumArr' array.
    for (int i = 0; i < numOfTypes; i++) {
        for (int j = 0; j < day; j++) {
            for (int k = 0; k < numOfBrands; k++) {
                totalSumArr[i] += cube[j][k][i];
            }
        }
    }
      //Here, we want to find the highest value in the array (the highest-grossing type). For each iteration,
      //we check if the value at index 'i' is greater than `typeSum` (which is initially set to 0).
      //If it is, we assign the index 'i' to 'bestType' and the value at that index to 'typeSum'.
    for (int i = 0; i < numOfTypes; i++) {
        if (totalSumArr[i] > typeSum) {
            bestType = i;
            typeSum = totalSumArr[i];
        }
    }
    //After exiting the loop, we have the index of the highest-grossing type and the corresponding value,
    //which is the sum from the array at that index. At this point, we can print the desired information as requested.
    totalTypeSum = totalSumArr[bestType];
    printf("The best-selling type of car is %s: %d$ \n",types[bestType],totalTypeSum);
}
//The 'overallDay' function is used to display the total sales of the highest-grossing day up until the last day that
//has data (specified by the 'day').
void overallDay(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES],int day,int daysInYear, int numOfBrands,
    int numOfTypes) {
    int daySum = 0;
    int bestDay = -1;
    int totalDaySum = 0;
    int totalSumArr[daysInYear];
    for (int i = 0; i < daysInYear; i++) {
        totalSumArr[i] = 0;
    }
    //In these nested loops, we assign the total sales for each day to the corresponding index of 'totalSumArr'.
    //However, we don't necessarily assign values to every day, only up to the last day that has data.
    for (int i = 0; i < day; i++) {
        for (int j = 0; j < numOfBrands; j++) {
            for (int k = 0; k < numOfTypes; k++) {
                totalSumArr[i] += cube[i][j][k];
            }
        }
    }
   //Here, we want to find the highest value in the array (the highest-grossing day).
   //For each iteration, we check if the value at index 'i' is greater than 'daySum' (which is initially set to 0).
   //If it is, we assign the index 'i' to `bestDay` and the value at that index to 'daySum'.
    for (int i = 0; i < numOfTypes; i++) {
        if (totalSumArr[i] > daySum) {
            bestDay = i;
            daySum = totalSumArr[i];
        }
    }
   //After exiting the loop, we have the index of the highest-grossing day and the corresponding value,
   //which is the sum from the array at that index. Now, we can print the desired information as requested.
   totalDaySum = totalSumArr[bestDay];
    printf("The most profitable day was day number %d: %d$ \n",bestDay+1,totalDaySum);
}
//The 'getCube' function is used to calculate and retrieve the average delta metrics for each brand up until the last
//day that has data (specified by the 'day').
void getCube(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int day, int numOfBrands, int numOfTypes){
    if (day>1) {
        for (int i = 0; i < numOfBrands; i++) {
            float delta = 0;
            // In this loop, I iterate through each day starting from day 1 (the second day), and calculate the sum of
            // sales for the current day ('curSales') as well as the sum of sales for the previous day ('prevSales').
            for (int j = 1; j < day; j++) {
                int curSales = 0;
                int prevSales = 0;
                for (int k = 0; k < numOfTypes; k++) {
                    curSales += cube[j][i][k];
                    prevSales += cube[j-1][i][k];
                }
                //The 'delta' will be calculated as 'curSales - prevSales'. Both 'curSales' and 'prevSales' are updated
                //with new values for each day, and the 'delta' accumulates the difference between the current and
                //previous day sales across all days.
                delta += curSales - prevSales;
            }
            float cube = (delta / (day-1));
            printf("Brand: %s, Average Delta: %f\n",brands[i], cube);
            }
        }
    //If the day is not greater than 1, it means there is only one day or fewer with values. In this case, we want to
    //print 0 for the cube of every brand.
    else {
        for (int i = 0; i < numOfBrands; i++) {
            printf("Brand: %s, Average Delta: 0.000000\n",brands[i]);
        }
    }
}

int main() {
    int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES];
    //dayCounter for days
    int dayCounter = 0;
    // initialize the cube
    for (int i = 0; i < DAYS_IN_YEAR; i++) {
        for (int j = 0; j < NUM_OF_BRANDS; j++) {
            for (int k = 0; k < NUM_OF_TYPES; k++) {
                cube[i][j][k] = -1;
            }
        }
    }
    int choice;
    printMenu();
    scanf("%d", &choice);
    //continue until the user choose 7
    while(choice != done){
        switch(choice) {
            case addOne: {
               // sum the data of the brands
                sumData(cube,dayCounter);
                break;
            }
            case addAll: {
                int counter = 0;
                // help to know is there are data's for the brands already
                int isAssigned[NUM_OF_BRANDS] = {-1,-1,-1,-1,-1};
                //print if the user don't put in data
                printf("No data for brands ");
                for (int i = 0; i < NUM_OF_BRANDS; i++) {
                    printf("%s ", brands[i]);
                }
                printf("\n");
                //This while loop is used to enter values for the available day for all brands. The loop will only exit
                //when all 5 brands have received values. The 'counter' will only increment when a brand that didn't
                //have a value previously gets a new value. Once all brands have values, the 'counter' will reach
                //'NUM_OF_BRANDS', signaling that all brands are updated, and the loop can exit.
                while(counter < NUM_OF_BRANDS) {
                    int isFound = 0;
                    int carBrandVal = sumData(cube,dayCounter);
                    for (int i = 0; i < NUM_OF_BRANDS; i++) {
                        if (carBrandVal == isAssigned[i]) {
                            isFound = 1;
                            break;
                        }
                    }
                    if (!isFound) {
                        isAssigned[carBrandVal] = carBrandVal;
                        counter++;
                    }
                    //If the 'counter' reaches 'NUM_OF_BRANDS', it means the last brand has received inputs, and there's
                    //no need to continue the rest of the loop that prints additional lines. Only after all brands have
                    //received inputs for the day can we increment the 'dayCounter' by 1.
                    if (counter == NUM_OF_BRANDS) {
                        dayCounter++;
                        break;
                    }
                    printf("No data for brands ");
                    //Here, we want to print the names of all the brands, but exclude the brands that have already
                    //received their inputs. We only print the brand names whose index was not updated in the
                    //'isAssigned' array.
                    for (int i = 0; i < NUM_OF_BRANDS; i++) {
                        if (isAssigned[i] == -1) {
                            printf("%s ", brands[i]);
                        }
                    }
                    printf("\n");
                }
                break;
            }
            case stats: {
                int checkDay;
                int isDayValid = 1;
                printf("What day would you like to analyze?\n");
                scanf("%d", &checkDay);
                checkDay--;
                //Here, I want to check if the 'checkDay' is invalid. If the 'checkDay' is greater than the last
                //available day ('dayCounter - 1'), it means there are no values for that day, and the 'checkDay'
                //is invalid. Additionally, if the user inputs 0 as the 'checkDay' (which effectively becomes -1 due
                //to the subtraction), that is also considered invalid.
                if (checkDay > dayCounter-1 || checkDay == -1) {
                    isDayValid = 0;
                }
                // This loop continues to run until the user inputs a valid day. Inside the loop, we perform the same
                // checks as before, but now we check if the 'checkDay' is valid. Once a valid day is entered, we set
                // the 'isDayValid' flag to 'true' and exit the loop.
                while (!isDayValid) {
                    printf("Please enter a valid day.\nWhat day would you like to analyze?\n");
                    scanf("%d", &checkDay);
                    checkDay--;
                    if (checkDay <= dayCounter-1 && checkDay != -1) {
                        isDayValid = 1;
                    }

                }
                printf("In day number %d:\n", checkDay+1);
                totalSales(cube,checkDay,NUM_OF_BRANDS,NUM_OF_TYPES);
                bestBrandSold(cube,checkDay,NUM_OF_BRANDS,NUM_OF_TYPES);
                bestTypeSold(cube,checkDay,NUM_OF_BRANDS,NUM_OF_TYPES);
                printf("\n");
                break;
            }
            case print: {
                // we print the requested lines and then call the 'printCube' function with the arguments 'cube'
                // and 'dayCounter'.This ensures that the function knows what data to print
                // and until which day it should display the information.
                printf("*****************************************\n\n");
                ogCube(cube,dayCounter,NUM_OF_BRANDS,NUM_OF_TYPES);
                printf("\n\n*****************************************\n");
                break;
            }
            case insights: {
                //print the information for all the data the user put in
                overallBrand(cube,dayCounter,NUM_OF_BRANDS,NUM_OF_TYPES);
                overallType(cube,dayCounter,NUM_OF_BRANDS,NUM_OF_TYPES);
                overallDay(cube,dayCounter,DAYS_IN_YEAR,NUM_OF_BRANDS,NUM_OF_TYPES);
                break;
            }
            case deltas: {
                // just call the function
                getCube(cube,dayCounter,NUM_OF_BRANDS,NUM_OF_TYPES);
                break;
            }
            default:
                printf("Invalid input\n");

        }
        printMenu();
        scanf("%d", &choice);
    }
        printf("Goodbye!\n");
        return 0;

}
