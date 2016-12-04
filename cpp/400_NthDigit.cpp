class Solution 
{
    // date: 2016-09-18     location: Vista Del Lago III Apartments
public:
    int findNthDigit(int n) 
    {
        // step 1. calculate how many digits the number has.
        long base = 9, digits = 1;
        while (n - base * digits > 0)
        {
            n -= base * digits;
            base *= 10;
            digits ++;
        }

        // step 2. calculate what the muber is.
        int index = n % digits;
        if (index == 0)
            index = digits;
        long num = 1;
        for (int i = 1; i < digits; i ++)
            num *= 10;
        num += (index == digits) ? n / digits - 1 : n / digits;;

        // step 3. find out which digit in the number is we want.
        for (int i = index; i < digits; i ++)
            num /= 10;
        return num % 10;
    }
};