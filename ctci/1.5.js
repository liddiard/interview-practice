function compressString(str) {
  var compressed = '';
  var numOccurences = 1;
  for (var i = 0; i < str.length; i++) {
    if (str[i] === str[i+1]) {
      numOccurences++;
    }
    else {
      compressed += (str[i] + numOccurences);
      numOccurences = 1;
    }
  }
  if (compressed.length >= str.length) {
    return str;
  }
  else {
    return compressed; 
  }
}

console.log(compressString('aabcccccaaa'));
console.log(compressString('aaa'));
