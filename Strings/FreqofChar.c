include <stdio.h> 
#include <string.h> 
  
// Function to print the frequencies 
// of each character of the string 
void printFrequency(int freq[]) 
{ 
    for (int i = 0; i < 26; i++) { 
  
        // If frequency of the 
        // alphabet is non-zero 
        if (freq[i] != 0) { 
  
            // Print the character and 
            // its respective frequency 
            printf("%c - %d\n", 
                   i + 'a', freq[i]); 
        } 
    } 
} 
  
// Function to calculate the frequencies 
// of each character of the string 
void findFrequncy(char S[]) 
{ 
    int i = 0; 
  
    // Stores the frequencies 
    // of each character 
    int freq[26] = { 0 }; 
  
    // Traverse over the string 
    while (S[i] != '\0') { 
  
        // Increment the count of 
        // each character by 1 
        freq[S[i] - 'a']++; 
  
        // Increment the index 
        i++; 
    } 
  
    // Function call to print 
    // the frequencies 
    printFrequency(freq); 
} 
  
// Driver Code 
int main() 
{ 
    char S[100] = "geeksforgeeks"; 
    findFrequncy(S); 
}
