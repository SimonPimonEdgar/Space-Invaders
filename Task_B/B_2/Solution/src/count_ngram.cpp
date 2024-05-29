#include <iostream>

#include "count_ngram.h"

// Function to count the frequency of 1-grams in a given text
// and return them as a map
// Input: a vector of strings (std::vector<std::string> full_text)
//        The vector of strings to count.
// Output: a map of strings to integers
//         (std::map<std::string, int>)
//         The map containing the frequency of each string in the input vector.
std::map<std::string, int> count1gramFromText(const std::vector<std::string> full_text) {
    // Initialize an empty map to store the frequency counts of 1-grams
    std::map<std::string, int> count_1gram;

    // Iterate over each word in the input text
    for (const auto& word : full_text) {
        // Increment the count of the current 1-gram in the map
        count_1gram[word]++;
    }

    // Return the map with the frequency counts of each 1-gram
    return count_1gram;
}


// Function to find the string with the maximum count in a given map
// Input: const reference to a map of strings to integers
//        (const std::map<std::string, int>& count_map)
//        The map to search for the maximum count.
// Output: a string
//         The string with the maximum count in the input map.
std::string findMax1gram(const std::map<std::string, int>& count_map) {
    // Initialize the max string and count to the first entry in the map
    auto max_string = count_map.begin()->first;
    auto max_count = count_map.begin()->second;

    // Iterate over each entry in the map
    for (const auto& entry : count_map) {
        // If the current entry has a count greater than the current max count,
        // update the max string and count to the current entry
        if (entry.second > max_count) {
            max_string = entry.first;
            max_count = entry.second;
        }
    }

    //std::cout << max_string << " : " << max_count << std::endl;
    // Return the string with the maximum count
    return max_string;
}

// Function to get the count of a specific string in a given map
// Input: a const reference to a map of strings to integers
//        (const std::map<std::string, int>& count_map)
//        The map to search for the count of the specified string.
//        a string (const std::string& str)
//        The string to get the count for.
// Output: an integer
//         The count of the specified string in the input map.
int getCountFor1gram(const std::map<std::string, int>& count_Ngram, const std::string& str) {
    // Find the iterator for the specified string in the map
    auto iter = count_Ngram.find(str);

    // If the string is not found in the map, return 0
    if (iter == count_Ngram.end()) {
        return 0;
    }

    // Otherwise, return the count for the string
    return iter->second;
}

std::map<std::pair<std::string,std::string>,int> countBiGramFromText(const std::vector<std::string> full_text ){
  // Counting 2-grams
  std::map<std::pair<std::string,std::string>,int> count_2gram;
  //for(auto it : full_text)
  auto prev_word = full_text.begin();
  if (prev_word != full_text.end()) {
    for (auto current_word = prev_word; current_word != full_text.end(); prev_word = current_word, ++current_word) {
      //auto paar = std::make_pair( "eins", "zwei" );
      //std::cout<< paar.first <<std::endl;

      //count_2gram[paar] = 1;
      count_2gram[std::make_pair( *prev_word, *current_word )] += 1;
    }
  }
  return count_2gram;
}

std::map<std::string,std::map<std::string,int>> countBiGramNestedMapFromText(const std::vector<std::string> full_text ){
  // Counting 2-grams second way -- double map
  std::map<std::string,std::map<std::string,int>> count_nested_2gram;
  //for(auto it : full_text)
  auto prev_word = full_text.begin();
  if (prev_word != full_text.end()) {
    for (auto current_word = prev_word; current_word != full_text.end(); prev_word = current_word, ++current_word) {
      auto* index_map = &count_nested_2gram[*prev_word];
      (*index_map)[*current_word] += 1;
    }
  }
  return count_nested_2gram;
}

void printMaxNgram (std::map<std::pair<std::string,std::string>,int>& count_Ngram) {
  std::string max_ngram;
  int max_count;
  for (auto it = count_Ngram.begin(); it != count_Ngram.end(); ++it) {
    if (it->second > max_count) {
      max_count = it->second;
      max_ngram = it->first.first + " - " + it->first.second;
    }
  }
  std::cout << max_ngram << " : " << max_count << std::endl;
}

void printMaxNgram (std::map<std::string,std::map<std::string,int>>& count_Ngram) {
  std::string max_ngram;
  int max_count;
  for (auto& it : count_Ngram) {
    for (auto& in_it : it.second) {
      /*std::cout << it.first << " " 
              << in_it.first << " " 
              << in_it.second  << "\n";*/
      if (in_it.second > max_count) {
        max_count = in_it.second;
        max_ngram = it.first + " - " + in_it.first;
      }
    }
  }
  std::cout << max_ngram << " : " << max_count << std::endl;
}

std::string returnProbableNextWordInBiGram (std::map<std::string,std::map<std::string,int>>& full_Ngram, 
        std::string start_word) {
  std::string max_next_word;
  int max_count;
  for (auto it = full_Ngram.at( start_word ).begin(); it != full_Ngram.at( start_word ).end(); ++it) {
    if (it->second > max_count) {
      max_count = it->second;
      max_next_word = it->first;
      //std::cout << max_next_word << " : " << max_count << std::endl;
    }
  }
  return std::string(max_next_word);
}
