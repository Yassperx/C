#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//Easier manipulations of strings
typedef char *string;

//Struct for dates
typedef struct {
  int day;
  int month;
  int year;
} Date;

//Get Todays date
Date GetTodayDate() {
    time_t seconds; // Seconds till the epoch
    seconds = time(NULL);
    struct tm* local_time_info; // Struct to get time info

    local_time_info = localtime(&seconds);

    Date Today = {
      .day = local_time_info->tm_mday,
      .month = local_time_info->tm_mon + 1,
      .year = local_time_info->tm_year + 1900,
    };
    return Today;
}

//A simple random integer in a [-range;range]
int RandInt(int range) {
    return rand() % (2 * range + 1) - range;
} 

//Random Date
Date RandomDate() 
{
    Date RandomDate;
    RandomDate.month = (abs(RandInt(11)) + 1); // To get values between 1 and 12

    // Handle months with different days
    switch(RandomDate.month) {
        case 2:
            RandomDate.day = abs(RandInt(27)) + 1; // February: 1-28
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            RandomDate.day = abs(RandInt(29)) + 1; 
            break;
        default:
            RandomDate.day = abs(RandInt(30)) + 1; 
    }

    RandomDate.year = abs(RandInt(800)) + 1600; 
    
    return RandomDate;
}


//Printing a date format from date struct
void Read(Date date)
{
  printf("%d/%d/%d\n", date.day, date.month, date.year);
}

//Printing out the name of a day in a week with i-di interpretation
string dayOfTheWeek(int di)
{
  string day;
  switch (di)
  {
    case 0:
      day = "Sunday";
      break;
    case 1:
      day = "Monday";
      break;
    case 2:
      day = "Tuesday";
      break;
    case 3:
      day = "Wednesday";
      break;
    case 4:
      day = "Thursday";
      break;
    case 5:
      day = "Friday";
      break;
    case 6:
      day = "Saturday";
      break;
  }
  return day;
}

//Get the balise day of the century
int BaliseDay(int year)
{
  year = year % 400;
  if (year >= 0 && year <= 99)
  {
    return 2; // 2000-2099: Tuesday
  }
  else if (year >= 100 && year <= 199)
  {
    return 0; // 2100-2199: Sunday
  }
  else if (year >= 200 && year <= 299)
  {
    return 5; // for 2200-2299
  }
  else if (year >= 300 && year <= 399)
  {
    return 3; // for 2300-2399
  }
  else {
    printf("Error\n");
    return -1;
  }
}

//Calculate Doomsday for a year
int Doomsday(int year)
{
  int YY = year % 100;
  int XX = year / 100;

  int A = YY/12;
  int B = YY % 12;
  int C = B / 4;
  int D = BaliseDay(year);

  return (A+B+C+D)%7;
}

//If a year is bisextile
bool ifBisextile(int year)
{
  if (year % 400 == 0)
  {
    return true;
  }
  else if (year % 100 == 0)
  {
    return false;
  }
  else if (year % 4 == 0)
  {
    return true;
  }
  else 
  {
    return false;
  }
}

//How many days in a month
int DaysInMonth(int month)
{ 
  int days;
  switch(month) 
  {
    case 2:
      days = 28;
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      days = 30;    
      break;
    default:
      days = 31; 
  }
  return days;
}

//How many days between two dates
int DaysBetweenDates(Date date1, Date date2)
{
    if (date1.year > date2.year || 
       (date1.year == date2.year && 
       (date1.month > date2.month || 
       (date1.month == date2.month && date1.day > date2.day))))
    {
        // Swap dates if date1 is after date2
        Date temp = date1;
        date1 = date2;
        date2 = temp;
    }

    int numberofDays = 0;

    // Days for full years in between
    for (int i = date1.year + 1; i < date2.year; i++)
    {
        numberofDays += (ifBisextile(i)) ? 366 : 365;
    }

    // Days for months in the starting year
    for (int i = date1.month; i <= 12; i++)
    {
        int days = DaysInMonth(i);
        if (ifBisextile(date1.year) && i == 2)
            days++;
        numberofDays += days;
    }
    numberofDays -= date1.day;

    // Days for months in the ending year
    for (int i = 1; i < date2.month; i++)
    {
        int days = DaysInMonth(i);
        if (ifBisextile(date2.year) && i == 2)
            days++;
        numberofDays += days;
    }
    numberofDays += date2.day;

    // If both dates are in the same year, the previous calculations double-count days. Correct for that.
    if (date1.year == date2.year)
    {
        for (int i = date1.month; i < date2.month; i++)
        {
            int days = DaysInMonth(i);
            if (ifBisextile(date1.year) && i == 2)
                days++;
            numberofDays -= days;
        }
        numberofDays += date1.day - date2.day;
    }
    
    return numberofDays;
}


int DayWithDoomsday(Date date)
{
    int di = Doomsday(date.year);

    // Define anchor days for each month.
    int anchor_days[12] = {3, 0, 0, 4, 2, 6, 4, 1, 5, 3, 7, 5};
    if (ifBisextile(date.year))
    {
        anchor_days[0] = 4;
        anchor_days[1] = 1;
    }

    int offset = date.day - anchor_days[date.month - 1];
    int new_di = (di + offset) % 7;
    if (new_di < 0)
        new_di += 7;

    return new_di;
}

int main(int argc, char* argv[]) 
{
    srand(time(NULL));
    Date userInput;

    // Check for command-line arguments
    if(argc == 2 && strcmp(argv[1], "game") == 0) {
        // Insert your game logic here
        printf("Guessing game goes here.\n");
        return 0;
    }

    if(argc == 4) { // Expected format: ./conway day month year
        userInput.day = atoi(argv[1]);
        userInput.month = atoi(argv[2]);
        userInput.year = atoi(argv[3]);
        int di = DayWithDoomsday(userInput);
        printf("It's a : %s\n", dayOfTheWeek(di));
        return 0;
    }

    // If no command-line arguments, use the interactive mode
    printf("Date : ");
    scanf("%d/%d/%d", &userInput.day, &userInput.month, &userInput.year);
    int di = DayWithDoomsday(userInput);
    printf("It's a : %s\n", dayOfTheWeek(di));
    while (getchar() != '\n');
    getchar();
}
