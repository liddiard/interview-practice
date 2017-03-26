
function addPermutations(arr, letter) {
  arr.forEach(permutation => {
    for (var i = 0; i <= permutation.length; i++) {
      permutation.substr(0, i) + letter + permutation.substr(i);
    }
  });
}
