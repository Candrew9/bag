////////////////////////////////////////////////////////
// ECE 2574, Homework 1, Andrew Caldwell
//
// File name:   hw1_test.cpp
// Description: The main files for the ArrayBag
// Date:        2/7/19
//

//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** Implementation file for the class ArrayBag.
 @file ArrayBag.cpp */

#include "ArrayBag.h"
#include <cstddef>

template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}
// end default constructor

template<class ItemType>
ArrayBag<ItemType>::ArrayBag(const ItemType arr[], int size)
{
    maxItems = DEFAULT_CAPACITY;
    itemCount = 0;
    
    
    if(size > 6) {
        size = 6;
        
    }
    
    for (int i = 0; i < size; i++)
    {
        items[i] = arr[i];
        itemCount++;
        
    }
    
    
}

template<class ItemType>
bool ArrayBag<ItemType>::flatten()
{
    //check if the bag is empty
    if(!isEmpty()) {
        
        int found = 0;
        
        for (int i = 0; i < getCurrentSize(); i++) {
            while(getFrequencyOf(items[i]) > 1) {
                remove(items[i]);
                found = 1;
            }
            
        }
        
        if (found == 1) {
            return true;
        }
    }
    
    
    return false; //default return value
    
}

template<class ItemType>
bool ArrayBag<ItemType>::reduce()
{
    //create search var to set t/f value later
    bool found = false;
    
    //check if the bag is empty
    if (!isEmpty()) {
        
        //int freq = getFrequencyOf(items[0]);
        int smallFreq = getFrequencyOf(items[0]);
        ItemType smallItem = items[0];
        for (int i = 0; i < getCurrentSize(); i++) {
            if (getFrequencyOf(items[i]) < smallFreq) {
                smallFreq = getFrequencyOf(items[i]);
                smallItem = items[i];
            }
        }
        while (getFrequencyOf(smallItem) > 0) {
            remove(smallItem);
            found = true;
        }
    }
    
    return found;
}

template<class ItemType>
bool ArrayBag<ItemType>::replace(const ItemType& anEntry, const ItemType& newEntry)
{
    if (getFrequencyOf(anEntry) == 0) {
        return false;
    }
    
    bool result = false;
    
    for (int i = 0; i < getCurrentSize(); i++) {
        if (items[i] == anEntry) {
            items[i] = newEntry;
            result = true;
        }
    }
    
    return result;
}

template<class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::bagUnion(const ArrayBag<ItemType> &bag2) const
{
    ArrayBag<ItemType> unionBag;
    for (int i = 0; i < getCurrentSize(); i++)
    {
        
        unionBag.add(items[i]);
    }
    
    for (int j = 0; j < bag2.getCurrentSize(); j++) {

        unionBag.add(bag2.items[j]);
    
        
    }
    
    return unionBag;
}

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize
template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
    bool hasRoomToAdd = (itemCount < maxItems);
    if (hasRoomToAdd)
    {
        items[itemCount] = newEntry;
        itemCount++;
    } // end if
    
    return hasRoomToAdd;
}  // end add // end add

/*
// STUB
 template<class ItemType>
 bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
 {
    return false; // STUB
 }  // end remove
*/
template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
    int locatedIndex = getIndexOf(anEntry);
    bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
    if (canRemoveItem)
    {
        itemCount--;
        items[locatedIndex] = items[itemCount];
    }  // end if
    
    return canRemoveItem;
}  // end remove


/*
 // STUB
 template<class ItemType>
 void ArrayBag<ItemType>::clear()
 {
    // STUB
 }  // end clear
*/

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
}  // end clear

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int curIndex = 0;       // Current array index
   while (curIndex < itemCount)
   {
      if (items[curIndex] == anEntry)
      {
         frequency++;
      }  // end if
      
      curIndex++;          // Increment to next entry
   }  // end while
   
   return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains

/* ALTERNATE 1: First version
template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& target) const 
{
   return getFrequencyOf(target) > 0;
}  // end contains

// ALTERNATE 2: Second version 
template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
   bool found = false;
   int curIndex = 0;        // Current array index
   while (!found && (curIndex < itemCount))
   {
      if (anEntry == items[curIndex])
      {
         found = true;
      } // end if
      
      curIndex++;           // Increment to next entry
   }  // end while   
   
   return found;
}  // end contains
*/


template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
	std::vector<ItemType> bagContents;
	for (int i = 0; i < itemCount; i++)
		bagContents.push_back(items[i]);
      
   return bagContents;
}  // end toVector


// private
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
	bool found = false;
   int result = -1;
   int searchIndex = 0;
   
   // If the bag is empty, itemCount is zero, so loop is skipped
   while (!found && (searchIndex < itemCount))
   {
      if (items[searchIndex] == target)
      {
         found = true;
         result = searchIndex;
      } 
      else
      {
         searchIndex++;
      }  // end if
   }  // end while
   
   return result;
}  // end getIndexOf
