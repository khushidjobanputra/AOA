#include <stdio.h>
#define MAX_SIZE 100
int set[MAX_SIZE], subset[MAX_SIZE];
int n, sum, found = 0;
// Function to check if a subset with given sum exists
void subset_sum(int index, int current_sum)
{
    int i;
    // If the current subset has the desired sum, print it and set found flag to true
    if (current_sum == sum)
    {
        printf("Subset with sum %d is: ", sum);
        for (i = 0; i < index; i++)
        {
            printf("%d ", subset[i]);
        }
        printf("\n");
        found = 1;
        return;
    }
    // If we have processed all elements of the set or current sum is greater than the desired sum, return
    if (index == n || current_sum > sum)
    {
        return;
    }
    // Recursively generate subsets by including or excluding the current element
    subset[index] = set[index];
    subset_sum(index + 1, current_sum + set[index]);
    subset[index] = 0;
    subset_sum(index + 1, current_sum);
}
int main()
{
    int i;
    // Take input from user to define the set and the desired sum
    printf("Enter the size of the set: ");
    scanf("%d", &n);
    printf("Enter the elements of the set: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &set[i]);
    }
    printf("Enter the desired sum: ");
    scanf("%d", &sum);
    // Call the subset_sum function to check if a subset with the given sum exists
    subset_sum(0, 0);
    // If a subset with the given sum was not found, print an appropriate message
    if (!found)
    {
        printf("No subset found with sum %d.\n", sum);
    }
    return 0;
}
