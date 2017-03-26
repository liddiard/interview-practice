const fs = require('fs');

const dictionary = fs.readFileSync('enable1.txt', 'utf8').split('\r\n');

class Trie {
  constructor() {
    this.root = new Node('');
  }
}

class Node {
  constructor(symbol) {
    this.symbol = symbol;
    this.pointers = {};
  }
  addNode(symbol, node) {
    this.pointers[symbol] = node;
  }
}

function createTrie(dictionary) {
  const trie = new Trie();
  let node = trie.root;
  dictionary.forEach(word => {
    word
    .split('')
    .forEach(letter => {
      
    });
  });
}

function permuteString(str) {
  if (str.length === 0 || str.length === 1) {
    return [str];
  }
  const permutations = permuteString(str.substr(1));
  const myPermutations = [];
  permutations.forEach(permutation => {
    for (let i = 0; i < str.length; i++) {
      myPermutations.push(permutation.substr(0, i) + str[0] + permutation.substr(i));
    }
  });
  return myPermutations;
}

function inDictionary(start, end, word) {
  if (start > end) {
    return false;
  }
  const mid = Math.floor((start + end) / 2);
  // console.log(start, end, dictionary[mid]);
  if (word > dictionary[mid]) {
    return inDictionary(mid+1, end, word);
  }
  else if (word < dictionary[mid]) {
    return inDictionary(start, mid-1, word);
  }
  else if (word === dictionary[mid]) {
    return true;
  }
}

permuteString('iogsvooely').forEach(str => {
  if (inDictionary(0, dictionary.length, str)) {
    console.log(str); 
  }
});

