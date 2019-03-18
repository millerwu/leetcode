package RepeatedDNASequences;

import java.util.*;

/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG".
When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

Example:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

Output: ["AAAAACCCCC", "CCCCCAAAAA"]

 */

public class RepeatedDNASequences {
    public List<String> findRepeatedDnaSequences(String s) {
        Map<String, Integer> map = new TreeMap<>();
        for (int i = 0; i <= s.length()-10; i++) {
            String substr = s.substring(i, i + 10);
            if (map.get(substr) == null) {
                map.put(substr, 0);
            } else {
                map.put(substr, map.get(substr) + 1);
            }

        }
        List<String> res = new ArrayList<>();
        System.out.println(map);
        for (Map.Entry<String, Integer> entry: map.entrySet()) {
            if (entry.getValue() > 0) {
                res.add(entry.getKey());
            }
        }
        return res;
    }

    public static void main(String[] args) {
        String s = "AAAAAAAAAAA";
        RepeatedDNASequences sequences = new RepeatedDNASequences();
        List<String> res = sequences.findRepeatedDnaSequences(s);
        System.out.println(res);
    }
}
