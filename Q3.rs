use std::collections::HashMap;
use std::convert::TryInto;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {

        let mut repeat: HashMap<&char, usize> = HashMap::new();
        
        // easier to work with a char vector
        let string: Vec<char> = s.chars().collect();
        let mut i: usize = 0;
        let mut max = 0;
        let mut count = 0;
        
        while i < string.len() { // O(n), at most 2*n
            if repeat.contains_key(&string[i]){
                i = repeat.get(&string[i]).unwrap().clone();
                i+=1;
                if max < count{ // check
                    max = count;
                }
                count = 0;
                repeat.clear();
            }
            else { // add value to the map
                repeat.insert(&string[i], i);
                i+=1;
                count+=1;
            }
        }
    
        if max < count{ // check
            max = count;
        }

        return max;
    }  
}