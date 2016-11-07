## FlyFromElephant or ElephantFlyFrom task solution

### Algorithm:
  - Transform n-sized dictionary into n^2-sized adjacency matrix of linked (similar) words
  - Map 'from word' and 'to word' onto  adjacency matrix indexes
  - Find path in adjacency matrix unordered graph (breadth-first search)
  - Map indexes back

### Usage (Linux)
```
cmake path/to/project
make
./ffe_run START_AND_END_WORDS_PATH DICTIONARY_PATH
```
`START_AND_END_WORDS_PATH` - path to file with 2 words from dictionary: 'from' and 'to'.

`DICTIONARY_PATH` - path to file with dictionary words.

Files must be in plain text with utf8 encoding, words separated by new line chars


Bikeev Albert.
