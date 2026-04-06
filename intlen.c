    #include "main.h"
    /**
     * intlen - count the number of an int
     * @a: int to count
     * Return: count 
     */
    int intlen(int a)  
    {   
       int count=0;

       while(a != 0)  
       {  
           a = a / 10;  
           count++;  
       }  
         
        return (count);  
    }  