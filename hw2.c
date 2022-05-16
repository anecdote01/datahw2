#include <stdio.h>
#include <stdlib.h>

//this line is for routes
int routes[7][7] = {{0,1845,0,0,0,1264,0},{0,0,0,7815,0,0,0},{0,0,0,1303,0,8132,11550},{0,0,0,0,5782,0,10838},{0,0,4616,0,0,0,0},{0,0,0,9566,0,0,0},{0,0,0,0,0,5567,0}};
//this line below is for visited cities, whenever function visits a city, it will turn it's number to 1. if it reaches destination city, it will turn all zeros to ones
int visit[7] = {0,0,0,0,0,0,0}; 
//we will print cities with this array
char *cities[7] = {"Prague","Helsinki","Beijing","Tokyo","Jakarta","London","Newyork"};
//this will help us hold city number that were visited respectively.
int printer[7];
//for printer array.
int a = 0;


void    ft_hopping(int fc, int dc, int *distPointer,int *hoppingCount) //this function will search path
{
    visit[fc] = 1; //every visited city will turn 1
    *hoppingCount += 1; //every time function being executed, count will up.
    if(*hoppingCount == 5)
    {
        printf("no path found..");  //if it reaches 5, means there is no path
        *distPointer = 0; //total distance
    }
    for(int k = 0; k < 7; k++)     // the max hopping (from one city to another) is 6. Therefore for loop will turn 6 times
    {
        //if we reach the last city before destination, it will only print the name of the last city.
        if(routes[fc][dc] && !visit[k])
        {
            *distPointer += routes[fc][dc]; //adding distance to dist variable
            printer[a++] = dc; //adding city into printer array. We will use this array to print path later
            for(int i = 0; i < 7; i++) visit[i] = 1; //closing every city entry. 
        }
        // if we are not in the city neighbor to the destionation city, this condiiton will search for every neighbor that city has
        else if(routes[fc][k] && !visit[k])
        {
            *distPointer += routes[fc][k]; //increasing distance        
            printer[a++] = k; //adding next city
            ft_hopping(k,dc,distPointer,hoppingCount); //recalling same function to keep searching
        }
    }
}

int main()
{
    //dist stands for distance
    int dist = 0,firstCity,secondCity, hoppingCounter = 0;
    printf("\tCities:\nPrague\t\t= 0\nHelsinki\t= 1\nBeijing\t\t= 2\nTokyo\t\t= 3\nJakarta\t\t= 4\nLondon\t\t= 5\nNew York\t= 6\n");
    printf("Enter the number of the first city: ");
    scanf("%d",&firstCity);
    printf("Enter the number of the second city: ");
    scanf("%d",&secondCity);
    printer[a++] = firstCity;
    ft_hopping(firstCity,secondCity,&dist,&hoppingCounter); //sending variables to function
    a--;
    if (firstCity != secondCity && hoppingCounter != 5 && dist != 0) // printing condition
    {
        printf("path found: ");
        for(int x = 0; x < a ; x++) printf("%s -> ",cities[printer[x]]); //printing every city that was added to the printer array.
        printf("%s\n",cities[printer[a]]); //adding last city.
        printf("Total distance is: %d\n-------------------------\n",dist);
    }
    else if (firstCity == secondCity)   printf("\nStay in your place.\n");
    return 0;
}