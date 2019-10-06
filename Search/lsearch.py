def linear_s(nlist, searchItem):
    for i in range(len(nlist)):
        if nlist[i] == searchItem:
            return i
    return -1

print("Enter the list of numbers seperated by space:- ")
nums = [int(x) for x in input().split()]

searchItem = int(input('Enter the number to search for: '))  

x=linear_s(nums, searchItem)

if(x==-1):
    print(searchItem, ' was not found in the list!')
else:
    print(searchItem, ' was found in the list at index [{}]'.format(x))
